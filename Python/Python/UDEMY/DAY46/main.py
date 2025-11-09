import spotipy, requests
from spotipy.oauth2 import SpotifyOAuth
from datetime import datetime
from bs4 import BeautifulSoup
from dotenv import load_dotenv
import os

load_dotenv()

# You must get your OWN credentials from developer.spotify.com
CLIENT_ID = os.getenv("CLIENT_ID") 
CLIENT_SECRET = os.getenv("CLIENT_SECRET")

def get_date():
    valid_format = False
    user_date = "" # Define user_date here
    while not valid_format:
        user_date = input('Which year do you want to travel to? Type the date in this format YYYY-MM-DD: ')
        date_format = '%Y-%m-%d'
        try:
            valid_format = bool(datetime.strptime(user_date, date_format))
        except ValueError:
            print("Please type the date in this format YYYY-MM-DD")

    billboard_url = f"https://www.billboard.com/charts/hot-100/{user_date}/"
    # Return both the URL and the date
    return billboard_url, user_date


def get_soup(billboard_url):
    response = requests.get(billboard_url)
    songs_site = response.text
    soup = BeautifulSoup(songs_site, 'html.parser')

    # FIX: This is the correct selector
    song_tags = soup.select("ul li h3[class*='c-title']")
    
    # This checks for a different, known layout on the archive site
    if len(song_tags) == 0:
        song_tags = soup.find_all(name='h3', class_="c-title")

    song_names = [song.getText().strip() for song in song_tags]
    return song_names


# FIX: Pass the variables as arguments
def create_playlist(song_names, date):
    sp = spotipy.Spotify(
        auth_manager=SpotifyOAuth(
            scope="playlist-modify-private",
            redirect_uri="https://example.com",
            client_id=CLIENT_ID,         # FIX: Use your real ID
            client_secret=CLIENT_SECRET, # FIX: Use your real secret
            show_dialog=True,
            cache_path="token.txt"
        )
    )
    user_id = sp.current_user()["id"]
    print(f"Logged in as {user_id}")

    # Searching Spotify for songs by title
    song_uris = []
    year = date.split("-")[0]
    for song in song_names:
        result = sp.search(q=f"track:{song} year:{year}", type="track")
        # print(result) # Optional: uncomment to see the full search result
        try:
            uri = result["tracks"]["items"][0]["uri"]
            song_uris.append(uri)
        except IndexError:
            print(f"{song} doesn't exist in Spotify. Skipped.")

    # Creating a new private playlist in Spotify
    playlist = sp.user_playlist_create(user=user_id, name=f"{date} Billboard 100", public=False)
    print(f"Created playlist '{playlist['name']}'")

    # Adding songs found into the new playlist
    if song_uris:
        sp.playlist_add_items(playlist_id=playlist["id"], items=song_uris)
        print(f"Added {len(song_uris)} songs to your playlist.")
    else:
        print("No songs found to add.")


# --- Main Script ---
url, travel_date = get_date()
song_list = get_soup(url)
if song_list:
    print(f"Found {len(song_list)} songs.")
    create_playlist(song_list, travel_date)
else:
    print("Could not find any songs. The website layout may have changed.")