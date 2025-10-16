import requests as rs

responce = rs.get(url="http://api.open-notify.org/iss-now.json")
responce.raise_for_status()
data = responce.json()

longitude = data["iss_position"]["longitude"]
latitude = data["iss_position"]["latitude"]

print(data)
