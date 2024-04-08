// Function to handle file upload
function handleFileUpload(event) {
    event.preventDefault();
    const fileInput = document.getElementById('fileInput');
    const file = fileInput.files[0];
    
    const formData = new FormData();
    formData.append('audio', file);
  
    fetch('/transcribe', {
      method: 'POST',
      body: formData
    })
    .then(response => response.json())
    .then(data => {
      const transcription = data.transcription;
      const transcriptionElement = document.getElementById('transcription');
      transcriptionElement.textContent = transcription;
  
      // Send transcription to GPT-4 for response generation
      fetch('/gpt4', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({ transcription: transcription })
      })
      .then(response => response.json())
      .then(data => {
        const gpt4Response = data.response;
        const gpt4ResponseElement = document.getElementById('gpt4Response');
        gpt4ResponseElement.textContent = gpt4Response;
      })
      .catch(error => {
        console.error('Error:', error);
      });
    })
    .catch(error => {
      console.error('Error:', error);
    });
  }
  
  // Event listener
  document.getElementById('uploadForm').addEventListener('submit', handleFileUpload);