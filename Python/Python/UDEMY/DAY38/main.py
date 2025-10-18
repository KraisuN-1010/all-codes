import requests as rs
import os
from dotenv import load_dotenv

load_dotenv()

WEIGHT_KG = 62
HEIGHT_CM = 179
AGE = 20
NUTR_API_KEY = os.getenv("NUTR_API_KEY")
NUTR_API_ID = os.getenv("NUTR_API_ID")
NUTR_HEADERS = {
    "x-app-id" : NUTR_API_ID,
    "x-app-key" : NUTR_API_KEY
}
NUTR_PARAMS = {
    "query" : input("How much did you exercise today?:"),
    "weight_kg" : WEIGHT_KG,
    "height_cm" : HEIGHT_CM,
    "age" : AGE
}
NUTR_ENDPOINT = "https://trackapi.nutritionix.com/v2/natural/exercise"
SHEETY_API_AUTH = os.getenv("SHEETY_API_AUTH")
SHEETY_ENDPOINT = f"https://api.sheety.co/781438680974c2b3a0146faf4c0ca299/myWorkouts/workouts"
SHEETY_HEADER = {
    "Authorization" : SHEETY_API_AUTH,
}


def ensure_env(var_name):
    val = os.getenv(var_name)
    if not val:
        raise EnvironmentError(f"Environment variable {var_name} is not set")
    return val


try:
    # validate env
    ensure_env("NUTR_API_KEY")
    ensure_env("NUTR_API_ID")
    ensure_env("SHEETY_API_AUTH")

    nutr_response = rs.post(url=NUTR_ENDPOINT, json=NUTR_PARAMS, headers=NUTR_HEADERS)
    nutr_response.raise_for_status()
    nutr_data = nutr_response.json()

    exercises = nutr_data.get("exercises", [])
    if not exercises:
        print("No exercises detected by Nutritionix for the given input.")

    from datetime import datetime
    today_date = datetime.now().strftime("%d/%m/%Y")
    now_time = datetime.now().strftime("%H:%M:%S")

    for ex in exercises:
        sheet_payload = {
            "workout": {
                "date": today_date,
                "time": now_time,
                "exercise": ex.get("name", "").title(),
                "duration": ex.get("duration_min", 0),
                "calories": ex.get("nf_calories", 0)
            }
        }

        sheety_resp = rs.post(url=SHEETY_ENDPOINT, json=sheet_payload, headers=SHEETY_HEADER)
        try:
            sheety_resp.raise_for_status()
        except Exception:
            print("Failed to post to Sheety:", sheety_resp.status_code, sheety_resp.text)
        else:
            print("Posted workout to sheet:", sheet_payload["workout"]) 

except rs.exceptions.HTTPError as http_err:
    print("HTTP error from Nutritionix:", http_err)
    if hasattr(http_err, 'response') and http_err.response is not None:
        print(http_err.response.text)
except Exception as e:
    print("Error:", e)