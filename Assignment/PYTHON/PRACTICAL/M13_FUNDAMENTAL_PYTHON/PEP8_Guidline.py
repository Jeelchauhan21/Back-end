"""
A simple Python program following PEP 8 style guidelines.
Demonstrates indentation, comments, and variable naming conventions.
"""

# Function to calculate the area of a rectangle
def calculate_area(length, width):
    """Return the area of a rectangle."""
    return length * width


# Main program execution starts here
if __name__ == "__main__":
    # Define variables using snake_case
    rectangle_length = 5
    rectangle_width = 3

    # Calculate area
    area = calculate_area(rectangle_length, rectangle_width)

    # Print result
    print("Rectangle Area:", area)
