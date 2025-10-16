import requests
from twilio.rest import Client
import os
from dotenv import load_dotenv

load_dotenv()

API_KEY = os.getenv("OWM_API_KEY")
ACCOUNT_SID = os.getenv("TWILIO_ACCOUNT_SID")
AUTH_TOKEN = os.getenv("TWILIO_AUTH_TOKEN")
TWILIO_PHONE_NUMBER = os.getenv("TWILIO_PHONE_NUMBER")
MY_PHONE_NUMBER = os.getenv("MY_PHONE_NUMBER")

MY_LAT = 22.559752
MY_LONG = 72.931928
URL = "https://api.openweathermap.org/data/2.5/forecast"

api_params = {
    "lat": MY_LAT,
    "lon": MY_LONG,
    "appid": API_KEY,
    "cnt": 4,
}

try:
    response = requests.get(URL, params=api_params)
    response.raise_for_status()
    weather_data = response.json()
    
    will_rain = False
    for hour_data in weather_data["list"]:
        condition_code = hour_data["weather"][0]["id"]
        if int(condition_code) < 700:
            will_rain = True
            
    if will_rain:
       if MY_PHONE_NUMBER is None:
           raise EnvironmentError("MY_PHONE_NUMBER environment variable is not set")
       client = Client(ACCOUNT_SID, AUTH_TOKEN)
       message = client.messages.create(
           body="It is going to rain today, bring an umbrella ☂️",
           from_=TWILIO_PHONE_NUMBER,
           to=MY_PHONE_NUMBER
       )
       print(message.status)

except requests.exceptions.HTTPError as http_err:
    print(f"HTTP error occurred: {http_err}")
    print(f"Response content: {http_err.response.content}")
except requests.exceptions.RequestException as err:
    print(f"An error occurred: {err}")