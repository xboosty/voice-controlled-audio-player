from flask import Flask, request, jsonify, render_template
import os
from openai import OpenAI

client = OpenAI(api_key="your_openai_api_key")
import whisper

app = Flask(__name__)

# Set up OpenAI API key


# Set up Whisper model
model = whisper.load_model("base")

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/transcribe', methods=['POST'])
def transcribe():
    if 'audio' not in request.files:
        return jsonify({'error': 'No audio file provided'}), 400

    audio_file = request.files['audio']
    audio_path = 'temp_audio.wav'
    audio_file.save(audio_path)

    # Transcribe the audio using Whisper
    result = model.transcribe(audio_path)
    transcription = result['text']

    # Remove the temporary audio file
    os.remove(audio_path)

    return jsonify({'transcription': transcription})

@app.route('/gpt4', methods=['POST'])
def gpt4():
    data = request.get_json()
    transcription = data['transcription']

    # Generate a response using OpenAI GPT-4
    prompt = f"Transcription: {transcription}\nPlease provide a response."
    response = client.completions.create(engine='text-davinci-002',
    prompt=prompt,
    max_tokens=100,
    n=1,
    stop=None,
    temperature=0.7)

    gpt4_response = response.choices[0].text.strip()

    return jsonify({'response': gpt4_response})

if __name__ == '__main__':
    app.run(debug=True)