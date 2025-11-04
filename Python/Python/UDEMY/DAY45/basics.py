from bs4 import BeautifulSoup

with open("website.html", "r") as file:
    content = file.read()

soup = BeautifulSoup(content, "html.parser")
print("=" * 60)
print("1. SOUP OBJECT CREATED")
print("=" * 60)
print(f"Type: {type(soup)}\n")


# 2. FINDING ELEMENTS
print("=" * 60)
print("2. FINDING ELEMENTS")
print("=" * 60)

# find() - finds the FIRST matching element
first_paragraph = soup.find("p")
print(f"First <p> tag: {first_paragraph}")
print()

# find_all() - finds ALL matching elements (returns a list)
all_paragraphs = soup.find_all("p")
print(f"All <p> tags: {all_paragraphs}")
print(f"Number of paragraphs: {len(all_paragraphs)}")
print()


# 3. FINDING BY ID
print("=" * 60)
print("3. FINDING BY ID")
print("=" * 60)

# Find element by id attribute
name_element = soup.find(id="name")
print(f"Element with id='name': {name_element}")
print(f"Text content: {name_element.getText()}")
print()


# 4. FINDING BY CLASS
print("=" * 60)
print("4. FINDING BY CLASS")
print("=" * 60)

# Find elements by class attribute (note: class_ with underscore)
headings = soup.find_all(class_="heading")
print(f"Elements with class='heading':")
for heading in headings:
    print(f"  - {heading.getText()}")
print()


# 5. EXTRACTING TEXT
print("=" * 60)
print("5. EXTRACTING TEXT")
print("=" * 60)

# getText() or .text - extracts text without HTML tags
for i, paragraph in enumerate(all_paragraphs, 1):
    print(f"Paragraph {i}: {paragraph.getText()}")
print()


# 6. FINDING LINKS (ANCHOR TAGS)
print("=" * 60)
print("6. FINDING LINKS")
print("=" * 60)

all_links = soup.find_all("a")
print("All links found:")
for link in all_links:
    # Access attributes using dictionary-like syntax or .get()
    href = link.get("href")
    text = link.getText()
    print(f"  Text: '{text}' -> URL: {href}")
print()


# 7. ACCESSING ATTRIBUTES
print("=" * 60)
print("7. ACCESSING ATTRIBUTES")
print("=" * 60)

# Get attributes using dictionary notation or .get() method
h1_tag = soup.find("h1")
print(f"H1 tag: {h1_tag}")
print(f"ID attribute: {h1_tag.get('id')}")
print(f"Alternative: {h1_tag['id']}")
print()


# 8. NAVIGATING THE TREE
print("=" * 60)
print("8. NAVIGATING THE TREE")
print("=" * 60)

# Find parent, children, and siblings
ul_tag = soup.find("ul")
print(f"UL tag: {ul_tag.name}")

# Get all list items (children)
list_items = ul_tag.find_all("li")
print(f"\nList items (children of <ul>):")
for item in list_items:
    print(f"  - {item.getText()}")
print()


# 9. FINDING NESTED ELEMENTS
print("=" * 60)
print("9. FINDING NESTED ELEMENTS")
print("=" * 60)

# Find elements within elements
first_p = soup.find("p")
strong_in_p = first_p.find("strong")
print(f"First paragraph: {first_p.getText()}")
print(f"Strong tag inside: {strong_in_p.getText() if strong_in_p else 'None'}")

# Find anchor tag inside the strong tag
link_in_strong = strong_in_p.find("a") if strong_in_p else None
if link_in_strong:
    print(f"Link in strong: {link_in_strong.getText()} -> {link_in_strong.get('href')}")
print()


# 10. USING CSS SELECTORS
print("=" * 60)
print("10. USING CSS SELECTORS (select)")
print("=" * 60)

# select() - uses CSS selectors (more powerful)
h3_headings = soup.select(".heading")
print("Headings using CSS selector '.heading':")
for h3 in h3_headings:
    print(f"  - {h3.getText()}")

# Select by ID
name_by_css = soup.select("#name")
print(f"\nElement with id='name' using CSS: {name_by_css[0].getText()}")
print()


# 11. READING FROM FILE (YOUR ORIGINAL USE CASE)
print("=" * 60)
print("11. READING FROM FILE")
print("=" * 60)
print("To read from a file, use:")
print("""
with open("website.html", "r") as file:
    content = file.read()
soup = BeautifulSoup(content, "html.parser")
""")
print()


# 12. SUMMARY OF COMMON METHODS
print("=" * 60)
print("12. SUMMARY OF KEY METHODS")
print("=" * 60)
print("""
find(tag)              - Find first matching element
find_all(tag)          - Find all matching elements
find(id="value")       - Find by ID
find(class_="value")   - Find by class
getText() or .text     - Extract text content
.get("attr")           - Get attribute value
select("css")          - Find using CSS selectors
.name                  - Get tag name
.parent                - Get parent element
.children              - Get child elements
""")