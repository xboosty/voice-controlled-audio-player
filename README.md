# Project Doohicky: Voice-Controlled ESP32 Audio Player with Azure OpenAI GPT-4 Integration

Project Doohicky is an innovative voice-controlled audio player that combines an ESP32 microcontroller, INMP441 microphone, MAX98357A audio amplifier, and a speaker to create an interactive audio experience. The project integrates with Azure OpenAI GPT-4 to provide natural language processing capabilities and generate contextually relevant responses.

## Features
- Upload and play WAV files through a web interface
- Record audio using the INMP441 microphone
- Process recorded audio with Azure OpenAI GPT-4
- Generate intelligent responses based on the recorded audio
- User-friendly web interface for easy interaction

## Hardware Components
- ESP32 WROOM-32 microcontroller
- INMP441 I2S digital microphone
- MAX98357A I2S audio amplifier
- 4 ohm, 3 watt speaker

## Software Components
- Arduino IDE
- ESP32 Arduino Core
- Azure Functions
- Azure OpenAI GPT-4
- Web technologies (HTML, CSS, JavaScript)

## Getting Started
1. Clone the repository:
   ```
   git clone https://github.com/xboosty/voice-controlled-audio-player.git
   ```
2. Set up the hardware components as described in the project documentation.
3. Install the necessary software dependencies:
   - Arduino IDE
   - ESP32 Arduino Core
   - Azure CLI
   - Node.js
4. Create an Azure OpenAI resource:
   - Sign in to the Azure portal and navigate to the Azure OpenAI service.
   - Create a new Azure OpenAI resource with the desired configuration.
   - Obtain the API key and endpoint for your Azure OpenAI resource.
5. Update the configuration files:
   - Open the `azure_functions/openai_api/__init__.py` file and update the `openai.api_key` and `openai.api_base` variables with your Azure OpenAI API key and endpoint.
   - Open the `esp32_firmware/esp32_firmware.ino` file and update the Wi-Fi credentials (`ssid` and `password`) with your network details.
6. Deploy the Azure Functions code:
   - Open a terminal and navigate to the `azure_functions` directory.
   - Run the following command to deploy the Azure Functions code:
     ```
     func azure functionapp publish <function-app-name>
     ```
     Replace `<function-app-name>` with the name of your Azure Functions app.
7. Upload the firmware to the ESP32 microcontroller:
   - Open the `esp32_firmware/esp32_firmware.ino` file in the Arduino IDE.
   - Select the appropriate board and port for your ESP32 microcontroller.
   - Click the "Upload" button to compile and upload the firmware to the ESP32.
8. Access the web interface:
   - Open a web browser and navigate to the URL of your deployed Azure Functions app.
   - The web interface should load, allowing you to interact with the voice-controlled audio player.

## Project Structure
- `esp32_firmware/`: Contains the Arduino code for the ESP32 microcontroller.
- `azure_functions/`: Contains the Azure Functions code for audio processing and OpenAI integration.
- `web_interface/`: Contains the HTML, CSS, and JavaScript files for the web interface.
- `README.md`: Provides an overview of the project and instructions for getting started.
- `LICENSE`: Specifies the license under which the project is distributed.
- `CONTRIBUTING.md`: Guidelines for contributing to the project.

## Contributing
Contributions to Project Doohicky are welcome! However, please note that this project is a subsidiary of AiLive Solutions LLC, and all rights are reserved by Mario Coronado and Justin Buchel. Before making any contributions, please review the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines and contact information.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or inquiries, please contact:
- Mario Coronado: mario.coronado@ailivestudio.com
- Justin Buchel: justin.buchel@ailivestudio.com

## Acknowledgments
We would like to thank the open-source community for their valuable contributions and the developers of the libraries and frameworks used in this project.

## Troubleshooting
If you encounter any issues while setting up or running the project, please refer to the following troubleshooting tips:

- Ensure that you have correctly installed all the necessary software dependencies and have the latest versions.
- Double-check the configuration files to make sure the API keys, endpoints, and credentials are correctly set.
- Verify that the hardware components are properly connected and functioning as expected.
- Check the serial monitor in the Arduino IDE for any error messages or debugging information.
- Consult the project documentation and README file for detailed instructions and troubleshooting steps.

If the issue persists, please open an issue on the project's GitHub repository or contact the project maintainers for further assistance.

## Future Enhancements
We have exciting plans for future enhancements to Project Doohicky, including:

- Support for additional audio formats and codecs.
- Integration with popular voice assistants like Amazon Alexa and Google Assistant.
- Improved natural language understanding and context-aware responses.
- Customizable wake words and voice commands.
- Offline processing capabilities for enhanced privacy and reduced latency.

Stay tuned for updates and new releases as we continue to improve and expand the capabilities of Project Doohicky.
