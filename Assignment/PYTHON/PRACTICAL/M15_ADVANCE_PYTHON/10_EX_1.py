import re

# Input string
text = "Python is a powerful programming language."

# Word to search
word = "powerful"

# re.search() looks for the word anywhere in the string
match = re.search(word, text)

if match:
    print(f"Word '{word}' found at position {match.start()}")
else:
    print(f"Word '{word}' not found in the string.")
