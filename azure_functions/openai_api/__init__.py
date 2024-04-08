import logging
import azure.functions as func
import openai

# Set up OpenAI API key and endpoint
openai.api_key = "7a09ef8e60b74b6e9a108c2a5f4277c5"
openai.api_base = "https://azureopenaiinstancemcjb.openai.azure.com/"

def main(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Python HTTP trigger function processed a request.')

    # Get the user's request from the query parameters
    user_request = req.params.get('request')

    if not user_request:
        return func.HttpResponse("No user request provided.", status_code=400)

    # Initialize the conversation history
    conversation_history = [
        {"role": "system", "content": "You are an AI assistant that continuously asks questions to engage the user in a conversation."},
        {"role": "user", "content": user_request}
    ]

    # Generate questions and responses using Azure OpenAI GPT-4
    while True:
        response = openai.ChatCompletion.create(
            engine="gpt-4",
            messages=conversation_history,
            max_tokens=100,
            n=1,
            stop=None,
            temperature=0.7,
        )

        # Get the generated question or response
        assistant_response = response.choices[0].message.content.strip()

        # Add the assistant's response to the conversation history
        conversation_history.append({"role": "assistant", "content": assistant_response})

        # Check if the assistant's response is a question
        if assistant_response.endswith("?"):
            # Return the question to the user
            return func.HttpResponse(assistant_response)
        else:
            # Generate a follow-up question
            follow_up_question = openai.ChatCompletion.create(
                engine="gpt-4",
                messages=conversation_history + [{"role": "user", "content": "Can you ask a follow-up question?"}],
                max_tokens=50,
                n=1,
                stop=None,
                temperature=0.7,
            )

            # Get the generated follow-up question
            follow_up_question_text = follow_up_question.choices[0].message.content.strip()

            # Add the follow-up question to the conversation history
            conversation_history.append({"role": "assistant", "content": follow_up_question_text})

            # Return the follow-up question to the user
            return func.HttpResponse(follow_up_question_text)
