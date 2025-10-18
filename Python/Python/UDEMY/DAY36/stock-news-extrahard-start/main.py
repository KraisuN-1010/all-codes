import requests as rs
import os
import json
from dotenv import load_dotenv
from twilio.rest import Client
import random as rd

load_dotenv()

STOCK = "TSLA"
COMPANY_NAME = "Tesla Inc"
STOCK_API_KEY = os.getenv("STOCK_API_KEY")
NEWS_API_KEY = os.getenv("NEWS_API_KEY")
STOCK_API_PARAMS = {
    "function" : "TIME_SERIES_DAILY",
    "symbol" : STOCK,
    "outputsize" : "compact",
    "apikey" : STOCK_API_KEY
}
NEWS_API_PARAMS = {
    "apiKey" : NEWS_API_KEY,
    "q" : "tesla",
    "searchin" : "title",
    
}
TWILIO_ACCOUNT_ID = os.getenv("TWILIO_ACCOUNT_SID")
TWILIO_ACCOUNT_AUTH = os.getenv("TWILIO_AUTH_TOKEN")
TWILIO_PHONE = os.getenv("TWILIO_PHONE_NUMBER")
MY_PHONE = os.getenv("MY_PHONE_NUMBER")

## STEP 1: Use https://www.alphavantage.co
# When STOCK price increase/decreases by 5% between yesterday and the day before yesterday then print("Get News").

stock_responce = rs.get(url="https://www.alphavantage.co/query", params=STOCK_API_PARAMS)
stock_responce.raise_for_status()
stock_data = stock_responce.json()["Time Series (Daily)"]

data_list = [value for (key, value) in stock_data.items()]
yesterday_data = data_list[0]
yesterday_data_closing = yesterday_data["4. close"]

daybefore_data = data_list[1]
daybefore_data_closing = daybefore_data["4. close"]

difference = float(yesterday_data_closing) - float(daybefore_data_closing)
up_down = None
if difference > 0:
    up_down = "🔺"
else:
    up_down = "🔻"

diff_percent = round((abs(difference) / float(daybefore_data_closing)) * 100)

if diff_percent > 0:
    ## STEP 2: Use https://newsapi.org
    # Instead of printing ("Get News"), actually get the first 3 news pieces for the COMPANY_NAME.
    news_responce = rs.get(url="https://newsapi.org/v2/everything", params=NEWS_API_PARAMS)
    news_data = news_responce.json()["articles"]
    three_articles = news_data[:3]

    ## STEP 3: Use https://www.twilio.com
    # Send a seperate message with the percentage change and each article's title and description to your phone number.
    formatted_articles = [f"{STOCK}: {up_down}{diff_percent}%\nHeadline: {article['title']}" for article in three_articles]

    twilio_client = Client(TWILIO_ACCOUNT_ID, TWILIO_ACCOUNT_AUTH)

    # validate required values so the "to" parameter is definitely a str (not None)
    if MY_PHONE is None:
        raise EnvironmentError("MY_PHONE_NUMBER environment variable is not set.")
    if TWILIO_PHONE is None or TWILIO_ACCOUNT_ID is None or TWILIO_ACCOUNT_AUTH is None:
        raise EnvironmentError("Twilio configuration (account SID, auth token, or phone) is not fully set.")

    for article in formatted_articles:
        message = twilio_client.messages.create(
            body=article,
            from_=TWILIO_PHONE,
            to=MY_PHONE
        )
        print(message.status)



#Optional: Format the SMS message like this: 
"""
TSLA: 🔺2%
Headline: Were Hedge Funds Right About Piling Into Tesla Inc. (TSLA)?. 
Brief: We at Insider Monkey have gone over 821 13F filings that hedge funds and prominent investors are required to file by the SEC The 13F filings show the funds' and investors' portfolio positions as of March 31st, near the height of the coronavirus market crash.
or
"TSLA: 🔻5%
Headline: Were Hedge Funds Right About Piling Into Tesla Inc. (TSLA)?. 
Brief: We at Insider Monkey have gone over 821 13F filings that hedge funds and prominent investors are required to file by the SEC The 13F filings show the funds' and investors' portfolio positions as of March 31st, near the height of the coronavirus market crash.
"""

