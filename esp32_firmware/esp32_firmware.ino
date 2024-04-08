#include <WiFi.h>
#include <HTTPClient.h>
#include <AudioFileSourceHTTPStream.h>
#include <AudioFileSourceBuffer.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2S.h>
#include <SD.h>
#include <driver/i2s.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* azureFunctionsEndpoint = "https://projectdoohickyfunctionapp.azurewebsites.net/api/openai_api";

AudioGeneratorMP3 *mp3;
AudioFileSourceHTTPStream *file;
AudioFileSourceBuffer *buff;
AudioOutputI2S *out;

const int buttonPin = 4; // Touch-enabled GPIO pin for button
const int sdCardCS = 5; // SD card chip select pin

void setup() {
  Serial.begin(115200);

  // Initialize touch button
  pinMode(buttonPin, INPUT);

  // Initialize I2S for INMP441 microphone
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, NULL);

  // Initialize SD card
  if (!SD.begin(sdCardCS)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize I2S for MAX98357A amplifier
  i2s_config_t i2s_config_amp = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };
  i2s_driver_install(I2S_NUM_1, &i2s_config_amp, 0, NULL);
  i2s_set_pin(I2S_NUM_1, NULL);
}

void loop() {
  // Check for button press
  if (touchRead(buttonPin) < 40) {
    // Start recording audio from INMP441
    int16_t *buffer = (int16_t *)malloc(1024);
    size_t bytesRead = 0;
    File audioFile = SD.open("/recording.wav", FILE_WRITE);
    while (touchRead(buttonPin) < 40) {
      i2s_read(I2S_NUM_0, buffer, 1024, &bytesRead, portMAX_DELAY);
      audioFile.write((uint8_t *)buffer, bytesRead);
    }
    free(buffer);
    audioFile.close();

    // Send audio file to Azure Speech-to-Text API
    HTTPClient http;
    http.begin(azureFunctionsEndpoint);
    http.addHeader("Content-Type", "audio/wav");
    int httpResponseCode = http.POST(SD.open("/recording.wav", FILE_READ));
    if (httpResponseCode == 200) {
      String response = http.getString();
      
      // Save transcribed text to SD card
      File textFile = SD.open("/transcription.txt", FILE_WRITE);
      textFile.print(response);
      textFile.close();

      // Generate audio response using Azure Text-to-Speech API
      http.begin(azureFunctionsEndpoint);
      http.addHeader("Content-Type", "application/json");
      String requestBody = "{\"text\":\"" + response + "\"}";
      httpResponseCode = http.POST(requestBody);
      if (httpResponseCode == 200) {
        String audioUrl = http.getString();

        // Save audio response to SD card
        File responseFile = SD.open("/response.mp3", FILE_WRITE);
        http.begin(audioUrl);
        http.GET();
        http.writeToStream(&responseFile);
        responseFile.close();

        // Play audio response using MAX98357A amplifier
        file = new AudioFileSourceHTTPStream(audioUrl.c_str());
        buff = new AudioFileSourceBuffer(file, 2048);
        mp3 = new AudioGeneratorMP3();
        mp3->begin(buff, out);
        while (mp3->isRunning()) {
          if (!mp3->loop()) {
            mp3->stop();
          }
        }
      }
    }
    http.end();
  }

  delay(100);
}