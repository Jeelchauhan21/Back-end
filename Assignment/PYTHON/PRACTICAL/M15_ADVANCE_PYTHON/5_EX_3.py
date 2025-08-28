try:
    
    file = open("example.txt", "r")
    content = file.read()
    print("File Content:\n", content)

except FileNotFoundError:
    print("Error: The file does not exist.")

except PermissionError:
    print("Error: You don't have permission to access this file.")

except Exception as e:
    print("An unexpected error occurred:", e)

finally:
    try:
        file.close()
        print("File closed successfully.")
    except NameError:
        print("File was never opened, so nothing to close.")
