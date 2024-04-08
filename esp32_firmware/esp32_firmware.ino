#include <WiFi.h>
#include <HTTPClient.h>
#include <AudioFileSourceHTTPStream.h>
#include <AudioFileSourceBuffer.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2S.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* azureFunctionsEndpoint = "your_azure_functions_endpoint";

AudioGeneratorMP3 *mp3;
AudioFileSourceHTTPStream *file;
AudioFileSourceBuffer *buff;
AudioOutputI2S *out;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize audio output
  out = new AudioOutputI2S();
  out->SetPinout(26, 25, 22);
  out->SetGain(0.125);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(azureFunctionsEndpoint);

    // Send GET request to trigger audio playback
    int httpResponseCode = http.GET();
    if (httpResponseCode == 200) {
      // Parse the audio file URL from the response
      String audioUrl = http.getString();

      // Create audio file source and buffer
      file = new AudioFileSourceHTTPStream(audioUrl.c_str());
      buff = new AudioFileSourceBuffer(file, 2048);

      // Create MP3 decoder
      mp3 = new AudioGeneratorMP3();
      mp3->begin(buff, out);

      // Play the audio
      while (mp3->isRunning()) {
        if (!mp3->loop()) {
          mp3->stop();
        }
      }
    }

    http.end();
  }

  delay(5000);
}
