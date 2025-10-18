import requests as rs
import os
from dotenv import load_dotenv
from datetime import datetime
load_dotenv()

PIXELA_TOKEN = os.getenv("PIXELA_API_TOKEN")
USERNAME = os.getenv("USERNAME_PIXELA")
PIXELA_ENDPOINT = "https://pixe.la/v1/users"
GRAPH_ENDPOINT = f"{PIXELA_ENDPOINT}/{USERNAME}/graphs"
USER_PARAMS = {
    "token" : PIXELA_TOKEN,
    "username" : USERNAME,
    "agreeTermsOfService" : "yes",
    "notMinor" : "yes"
}
GRAPH_CONFIG = {
    "id" : "graph2",
    "name" : "Python Tracker",
    "unit" : "day",
    "type" : "int",
    "color" : "ajisai"
}
HEADERS = {
    "X-USER-TOKEN" : PIXELA_TOKEN
}
POST_PIXEL_ENDPOINT = f"{GRAPH_ENDPOINT}/{GRAPH_CONFIG['id']}"
today = datetime.now()
POST_PIXEL_PARAMS = {
    "date" : today.strftime("%Y%m%d"),
    "quantity" : "3",
}
UPDATE_PIXEL_ENDPOINT = f"{POST_PIXEL_ENDPOINT}/{POST_PIXEL_PARAMS['date']}"
UPDATE_PIXEL_PARAMS = {
    "quantity" : "5",
}
# responce = rs.post(url=PIXELA_ENDPOINT, json=USER_PARAMS)
# print(responce.text)

# responce = rs.post(url=GRAPH_ENDPOINT, json=GRAPH_CONFIG, headers=HEADERS)
# print(responce.text)

# responce = rs.post(url=POST_PIXEL_ENDPOINT, json=POST_PIXEL_PARAMS, headers=HEADERS)
# print(responce.text)

responce = rs.put(url=UPDATE_PIXEL_ENDPOINT, json=UPDATE_PIXEL_PARAMS, headers=HEADERS)
print(responce.text)
