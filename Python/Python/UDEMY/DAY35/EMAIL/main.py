import requests
import smtplib

API_KEY = "c6b71b530193c5bf2e8f891f57c8d3ea"
MY_LAT = 22.559752
MY_LONG = 72.931928
MY_EMAIL = "udaygadhavi2410@gmail.com"
MY_PASSWORD = "nypchuynpmunqxts"
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
        with smtplib.SMTP("smtp.gmail.com", 587) as connection:
            connection.starttls()
            connection.login(MY_EMAIL, MY_PASSWORD)
            connection.sendmail(
                from_addr=MY_EMAIL,
                to_addrs=MY_EMAIL,
                msg="Subject:Bring an Umbrella!\n\nIt's going to rain today, remember to bring an umbrella ☂️"
            )
            print("Rain alert email sent!")

except requests.exceptions.HTTPError as http_err:
    print(f"HTTP error occurred: {http_err}")
    print(f"Response content: {http_err.response.content}")
except requests.exceptions.RequestException as err:
    print(f"An error occurred: {err}")