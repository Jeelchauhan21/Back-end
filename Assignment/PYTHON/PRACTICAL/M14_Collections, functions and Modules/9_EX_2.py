import random

# Generate a random integer between 1 and 100
rand_int = random.randint(1, 100)
print("Random Integer (1-100):", rand_int)

# Generate a random float between 0 and 1
rand_float = random.random()
print("Random Float (0-1):", rand_float)

# Generate a random float between 1 and 10
rand_uniform = random.uniform(1, 10)
print("Random Float (1-10):", rand_uniform)

# Pick a random element from a list
items = [10, 20, 30, 40, 50]
rand_choice = random.choice(items)
print("Random Choice from List:", rand_choice)
