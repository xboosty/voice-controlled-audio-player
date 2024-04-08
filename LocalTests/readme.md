# Local Testing - Audio Transcription and GPT-4 Response

This folder contains a local testing setup for uploading a WAV file, transcribing it using Whisper, and generating a response using OpenAI GPT-4.

## Prerequisites

Before running the local tests, ensure that you have the following:

- Python 3.x installed
- Flask web framework installed (`pip install flask`)
- OpenAI Python library installed (`pip install openai`)
- Whisper library installed (`pip install git+https://github.com/openai/whisper.git`)
- OpenAI API key

## Setup

1. Clone or download the project repository to your local machine.

2. Navigate to the "LocalTests" folder.

3. Install the required dependencies by running the following command:
   ```
   pip install -r requirements.txt
   ```

4. Open the `app.py` file and replace `"your_openai_api_key"` with your actual OpenAI API key.

## Usage

1. Start the local web server by running the following command:
   ```
   python app.py
   ```

2. Open a web browser and navigate to `http://localhost:5000`.

3. On the web page, click the "Choose File" button and select a WAV file to upload.

4. Click the "Upload" button to initiate the transcription and response generation process.

5. The transcribed text from Whisper will be displayed in the "Whisper Transcription" section.

6. The generated response from OpenAI GPT-4 will be displayed in the "GPT-4 Response" section.

## Customization

You can customize the local testing setup by modifying the following files:

- `app.py`: Update the OpenAI API key, adjust the Whisper model, or modify the Flask routes and logic.
- `templates/index.html`: Modify the HTML structure and content of the web page.

## Troubleshooting

If you encounter any issues during the local testing process, consider the following:

- Ensure that you have installed all the required dependencies correctly.
- Double-check that you have provided a valid OpenAI API key in the `app.py` file.
- Verify that the uploaded WAV file is in a supported format and meets the requirements of the Whisper library.
- Check the terminal or console for any error messages or exceptions.

If the issue persists, please refer to the project's main README file or contact the project maintainers for further assistance.

## License

This local testing setup is part of the Voice-Controlled Audio Player project and is subject to the same license terms. Please refer to the main project's LICENSE file for more information.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/9693947/c75683b6-a077-449c-98fa-9f6596345d34/paste.txt