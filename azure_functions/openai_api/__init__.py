import logging
import azure.functions as func
import openai

# Set up OpenAI API key and endpoint
openai.api_key = "7a09ef8e60b74b6e9a108c2a5f4277c5"
openai.api_base = "https://azureopenaiinstancemcjb.openai.azure.com/"

def main(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Python HTTP trigger function processed a request.')

    # Get the audio file from the request
    audio_file = req.files.get('audio')

    if not audio_file:
        return func.HttpResponse("No audio file provided.", status_code=400)

    # Save the audio file temporarily
    audio_file_path = "/tmp/audio.wav"
    audio_file.save(audio_file_path)

    # Process the audio file with Azure OpenAI
    with open(audio_file_path, "rb") as audio:
        transcript = openai.Audio.transcribe("whisper-1", audio)

    # Generate a response using Azure OpenAI
    prompt = f"Transcription: {transcript}\nPlease provide a response."
    response = openai.Completion.create(
        engine="text-davinci-002",
        prompt=prompt,
        max_tokens=100,
        n=1,
        stop=None,
        temperature=0.7,
    )

    # Get the generated response
    generated_response = response.choices[0].text.strip()

    return func.HttpResponse(generated_response)