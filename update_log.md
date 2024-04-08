## Apr 8 9:15 Mario
Added the necessary libraries for SD card and I2S.
Defined the button pin (GPIO4) and SD card chip select pin.
Initialized the touch button in the setup() function.
Initialized the I2S interface for the INMP441 microphone and MAX98357A amplifier.
Initialized the SD card.
In the loop() function:
Check for button press using touchRead().
Start recording audio from the INMP441 microphone when the button is pressed.
Write the recorded audio data to a file on the SD card.
Send the audio file to the Azure Speech-to-Text API.
Save the transcribed text to a file on the SD card.
Generate an audio response using the Azure Text-to-Speech API.
Save the audio response to a file on the SD card.
Play the audio response using the MAX98357A amplifier.

## Apr 8 9:24 Mario
In this updated code:
The main function retrieves the user's request from the query parameters.
The conversation history is initialized with a system message that instructs the assistant to continuously ask questions to engage the user in a conversation.
Inside a while loop, the code generates questions and responses using Azure OpenAI GPT-4 by sending the conversation history to the openai.ChatCompletion.create method.
The generated response from the assistant is added to the conversation history.
If the assistant's response is a question (i.e., ends with a question mark), it is returned to the user.
If the assistant's response is not a question, the code generates a follow-up question by appending a user message asking for a follow-up question to the conversation history and sending it to the openai.ChatCompletion.create method.
The generated follow-up question is added to the conversation history and returned to the user.
This code ensures that the GPT assistant continuously asks questions to engage the user in a conversation. The assistant will either ask a direct question or generate a follow-up question based on the previous conversation history.
Remember to update the openai.api_key and openai.api_base with your actual Azure OpenAI API key and endpoint, respectively.
Note: This code assumes that the user's request is provided as a query parameter named request. Make sure to modify the ESP32 firmware code to send the user's request accordingly.