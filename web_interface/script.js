// Function to handle file upload
function handleFileUpload(event) {
    event.preventDefault();
    const fileInput = document.getElementById('fileInput');
    const file = fileInput.files[0];
    
    const formData = new FormData();
    formData.append('audio', file);
  
    fetch('/upload', {
      method: 'POST',
      body: formData
    })
    .then(response => {
      if (response.ok) {
        console.log('File uploaded successfully');
        // TODO: Update UI to reflect successful upload
      } else {
        console.error('File upload failed');
        // TODO: Display error message to the user
      }
    })
    .catch(error => {
      console.error('Error:', error);
      // TODO: Display error message to the user
    });
  }
  
  // Function to handle audio recording
  function handleAudioRecording() {
    // TODO: Implement audio recording logic using Web Audio API or a library like RecordRTC
    // Example using RecordRTC:
    const recordButton = document.getElementById('recordButton');
    const recordingStatus = document.getElementById('recordingStatus');
  
    if (recordButton.textContent === 'Record') {
      // Start recording
      navigator.mediaDevices.getUserMedia({ audio: true })
        .then(stream => {
          const recorder = RecordRTC(stream, {
            type: 'audio',
            mimeType: 'audio/wav'
          });
          recorder.startRecording();
          recordButton.textContent = 'Stop';
          recordingStatus.textContent = 'Recording...';
        })
        .catch(error => {
          console.error('Error accessing microphone:', error);
          // TODO: Display error message to the user
        });
    } else {
      // Stop recording
      recorder.stopRecording(function() {
        const audioBlob = recorder.getBlob();
        const audioUrl = URL.createObjectURL(audioBlob);
        recordButton.textContent = 'Record';
        recordingStatus.textContent = 'Recording stopped';
        // TODO: Upload the recorded audio to the server or process it with Azure OpenAI GPT-4
      });
    }
  }
  
  // Function to handle audio playback
  function handleAudioPlayback(audioUrl) {
    const audio = new Audio(audioUrl);
    audio.play()
      .then(() => {
        console.log('Audio playback started');
      })
      .catch(error => {
        console.error('Error playing audio:', error);
        // TODO: Display error message to the user
      });
  }
  
  // Function to send audio to Azure OpenAI GPT-4 for processing
  function processAudioWithOpenAI(audioUrl) {
    fetch('https://projectdoohickyfunctionapp.azurewebsites.net/api/openai_api', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({ audioUrl: audioUrl })
    })
    .then(response => response.json())
    .then(data => {
      const response = data.response;
      const openaiResponse = document.getElementById('openaiResponse');
      openaiResponse.textContent = response;
    })
    .catch(error => {
      console.error('Error processing audio with Azure OpenAI GPT-4:', error);
      // TODO: Display error message to the user
    });
  }
  
  // Event listeners
  document.getElementById('uploadForm').addEventListener('submit', handleFileUpload);
  document.getElementById('recordButton').addEventListener('click', handleAudioRecording);
  
  // Event listener for audio playback
  document.getElementById('audioList').addEventListener('click', function(event) {
    if (event.target.tagName === 'LI') {
      const audioUrl = event.target.dataset.audioUrl;
      handleAudioPlayback(audioUrl);
    }
  });
  
  // Event listener for Azure OpenAI GPT-4 processing
  document.getElementById('audioList').addEventListener('click', function(event) {
    if (event.target.tagName === 'BUTTON') {
      const audioUrl = event.target.dataset.audioUrl;
      processAudioWithOpenAI(audioUrl);
    }
  });