# How to Use Voice-Controlled ESP32 Audio Player with Azure OpenAI GPT-4 Integration

This guide provides step-by-step instructions on how to set up and use the Voice-Controlled ESP32 Audio Player with Azure OpenAI GPT-4 Integration.

## Prerequisites

Before getting started, ensure you have the following:

- ESP32 development board
- INMP441 I2S digital microphone
- MAX98357A I2S audio amplifier
- 4 ohm, 3 watt speaker
- Arduino IDE installed
- Azure account with access to Azure OpenAI GPT-4

## Hardware Setup

1. Connect the INMP441 microphone to the ESP32 board:
   - VDD to 3.3V
   - GND to GND
   - SCK to GPIO14
   - WS to GPIO15
   - SD to GPIO32

2. Connect the MAX98357A amplifier to the ESP32 board:
   - VIN to 5V
   - GND to GND
   - DIN to GPIO25
   - BCLK to GPIO27
   - LRC to GPIO26

3. Connect the speaker to the MAX98357A amplifier:
   - Positive lead to the positive output
   - Negative lead to the negative output

## Software Setup

1. Open the Arduino IDE and install the ESP32 board package:
   - Go to File -> Preferences
   - In the "Additional Board Manager URLs" field, enter: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Click "OK" to save the preferences
   - Go to Tools -> Board -> Boards Manager
   - Search for "esp32" and install the "ESP32 by Espressif Systems" package

2. Clone the project repository:
   ```
   git clone https://github.com/xboosty/voice-controlled-audio-player.git
   ```

3. Open the `esp32_firmware/esp32_firmware.ino` file in the Arduino IDE.

4. Update the Wi-Fi credentials in the code:
   - Replace `your_wifi_ssid` with your Wi-Fi network name
   - Replace `your_wifi_password` with your Wi-Fi password

5. Set up the Azure OpenAI GPT-4 resource:
   - Create an Azure OpenAI resource in the Azure portal
   - Obtain the API key and endpoint for your Azure OpenAI resource
   - Update the `openaiEndpoint` and `openaiApiKey` variables in the `azure_functions/openai_api/__init__.py` file with your API key and endpoint

6. Deploy the Azure Functions code:
   - Install the Azure Functions Core Tools
   - Navigate to the `azure_functions` directory
   - Run the following command to deploy the functions:
     ```
     func azure functionapp publish <your-function-app-name>
     ```
     Replace `<your-function-app-name>` with the name of your Azure Functions app

7. Update the `web_interface/script.js` file with the URL of your deployed Azure Functions app.

## Usage

1. Connect the ESP32 board to your computer via USB.

2. In the Arduino IDE, select the appropriate board and port under the Tools menu.

3. Click the "Upload" button to flash the firmware to the ESP32 board.

4. Once the upload is complete, open the Serial Monitor to view the device's IP address.

5. Access the web interface by entering the IP address in a web browser.

6. Use the web interface to:
   - Upload WAV files for playback
   - Record audio using the connected microphone
   - View the transcribed text and generated responses from Azure OpenAI GPT-4

7. Interact with the audio player using voice commands. The device will process the audio, send it to Azure OpenAI GPT-4 for transcription and response generation, and play back the generated audio response.

## Troubleshooting

- If the device fails to connect to Wi-Fi, double-check the Wi-Fi credentials in the code and ensure your network is accessible.
- If the audio playback or recording is not working, verify the connections between the ESP32, microphone, amplifier, and speaker.
- If the Azure OpenAI GPT-4 integration is not functioning properly, ensure the API key and endpoint are correctly set in the `azure_functions/openai_api/__init__.py` file and that your Azure OpenAI resource is active.

For additional support or to report issues, please visit the project's GitHub repository: [https://github.com/xboosty/voice-controlled-audio-player](https://github.com/xboosty/voice-controlled-audio-player)
