import re

# Input string
text = "Python is a powerful programming language."

# Word to match
word = "Python"

# re.match() checks only from the **beginning** of the string
match = re.match(word, text)

if match:
    print(f"Word '{word}' matched at the beginning of the string.")
else:
    print(f"Word '{word}' not found at the beginning of the string.")
