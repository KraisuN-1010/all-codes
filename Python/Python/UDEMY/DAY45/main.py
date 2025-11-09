import requests
from bs4 import BeautifulSoup

response = requests.get("https://news.ycombinator.com/news")

if response.status_code == 200:
    soup = BeautifulSoup(response.text, "html.parser")
    articles = soup.select("span.titleline > a")
    
    article_texts = []
    article_links = []

    if not articles:
        print("Could not find any articles. The HTML structure might have changed.")
    else:
        for article in articles:
            text = article.get_text()
            link = article.get('href')
            article_texts.append(text)
            article_links.append(link)

        print("--- Article Texts ---")
        print(article_texts)
        print("\n--- Article Links ---")
        print(article_links)

        article_upvotes = [int(score.getText().split()[0]) for score in soup.find_all(name="span",class_="score")]
        print("_____________________________________")
        print(article_upvotes)

else:
    print(f"Failed to retrieve the page. Status code: {response.status_code}")