from bs4 import BeautifulSoup

content = None  # Initialize content to None (or "")
soup = None     # Initialize soup to None

try:
    with open("website.html", "r", encoding="utf-8") as web_html:
        content = web_html.read()
except FileNotFoundError:
    print("Error: The file 'website.html' was not found.")
except Exception as e:
    print(f"An error occurred: {e}")

# This 'if' block will only run if 'content' was successfully read
if content:
    soup = BeautifulSoup(content, "html.parser")
    # Now you can work with the soup object
    # print(soup.title)
    # print(soup.find('h1'))
else:
    print("Could not parse the file because it was not read.")

