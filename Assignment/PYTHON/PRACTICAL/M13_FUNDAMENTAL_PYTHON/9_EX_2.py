# Original string
text = "  hello world  "

print("Original String:", repr(text))

# 1. Remove leading and trailing spaces
print("strip()      ->", text.strip())

# 2. Convert to uppercase
print("upper()      ->", text.upper())

# 3. Convert to lowercase
print("lower()      ->", text.lower())

# 4. Capitalize first letter
print("capitalize() ->", text.capitalize())

# 5. Title case (first letter of each word capitalized)
print("title()      ->", text.title())

# 6. Replace a word
print("replace()    ->", text.replace("world", "Python"))

# 7. Find a substring position
print("find('world')->", text.find("world"))

# 8. Check if string starts with "hello"
print("startswith('hello') ->", text.strip().startswith("hello"))

# 9. Check if string ends with "world"
print("endswith('world')    ->", text.strip().endswith("world"))

# 10. Count occurrences of 'l'
print("count('l')  ->", text.count("l"))

# 11. Split into words
print("split()     ->", text.strip().split())

# 12. Join words with a dash
words = ["Python", "is", "fun"]
print("join()      ->", "-".join(words))
