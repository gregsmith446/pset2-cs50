from cs50 import get_string

string = get_string("Type your name: ")
initials = ""
for c in string:
    if c.isupper():
        initials += c
print(initials)