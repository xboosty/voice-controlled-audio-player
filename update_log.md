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