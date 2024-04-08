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
4. Configure the Azure OpenAI GPT-4 resource and obtain the API key and endpoint.
5. Update the configuration files with your Wi-Fi credentials, Azure OpenAI API key, and endpoint.
6. Upload the firmware to the ESP32 microcontroller using the Arduino IDE.
7. Deploy the Azure Functions code using the Azure CLI.
8. Access the web interface to interact with the voice-controlled audio player.

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

---

This README.md file provides an overview of Project Doohicky, including its features, hardware and software components, getting started instructions, project structure, contributing guidelines, license information, and contact details.

Feel free to customize and expand upon this README.md file based on your specific project requirements and additional information you want to include.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/9693947/c75683b6-a077-449c-98fa-9f6596345d34/paste.txt