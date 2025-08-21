my_string =input("Enter a String :")
char_counts = {}

for char in my_string:
    char_counts[char] = char_counts.get(char, 0) + 1

print(char_counts)
