import requests
from bs4 import BeautifulSoup

responce = requests.get("https://news.ycombinator.com/news")
soup = BeautifulSoup(responce.text, "html.parser")

articles = soup.select("span.titleline > a")
for article in articles:
    print(article.get_text())