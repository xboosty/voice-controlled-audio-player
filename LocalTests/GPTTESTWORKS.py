import os
import openai

openai.api_type = "azure"
openai.api_key = "84e4e72aca8a47bc8f01ab61b9b64975"
openai.api_version = "2023-03-15-preview"
openai.api_base = "https://ai-supermariocoronadoai832469182523.openai.azure.com/"

deployment_id = "gpt-4"

def chat_with_gpt4(messages):
    response = openai.ChatCompletion.create(
        engine=deployment_id,
        messages=messages
    )
    return response.choices[0].message.content

def main():
    messages = [{"role": "system", "content": "You are a endlessly curious and helpful assistant."}]

    while True:
        user_input = input("User: ")
        if user_input.lower() == 'quit':
            break

        messages.append({"role": "user", "content": user_input})
        assistant_response = chat_with_gpt4(messages)
        messages.append({"role": "assistant", "content": assistant_response})

        print(f"Assistant: {assistant_response}")

if __name__ == "__main__":
    main()
