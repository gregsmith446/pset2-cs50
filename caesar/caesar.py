# run program by typing 'python caesar.py' and an int that will serve as a key
# program will prompt for a message to be encrypted (plaintext)
# and outputs an encrypted version of that message (cipertext)
# the plaintext is shifted based off the numerical key given in the command line

import cs50
import sys

def main():
    # check that user provided a key in cmd line argument
    if len(sys.argv) != 2:
        print("Provide a key after running the program")
        exit(1)
# 1 get the key, cast key to integer
    key = int(sys.argv[1])
# 2 get the plaintext
    plaintext = cs50.get_string("Message to Encrypt: ")
    # initialize variable to hold ciphertext
    ciphertext = []
    print("ciphertext: ", end="")

# check characters for alpha + case, preserving case
# 3 once checked, encypher the text
    for x in range(len(plaintext)): # loop through plaintext string
        if plaintext[x].isalpha(): # check char is alpha
            if plaintext[x].isupper(): # check char is uppercase
                charIndex = ord(plaintext[x]) - 65 # set uppercase A-Z index to 0, by subtract 65
                ciphertext = chr((charIndex + key) % 26 + 65) # shift the char by they key, re-adding 65
                print(ciphertext, end="") # print shifted uppercase chars
            elif plaintext[x].islower(): # if lowercase
                charIndex = ord(plaintext[x]) - 97 # set lowercase a-z index to 0, by subtracting 97
                ciphertext = chr((charIndex + key) % 26 + 97) # shift the char by the key, re-adding 97
                print(ciphertext, end="") # print shifted lowercase chars
        else: # if not alpha, rpint as is
            ciphertext = plaintext[x]
            print(ciphertext, end="")
    # 4 print completed ciphertext on a new line
    print()

if __name__ == "__main__":
    main()

#Python Built In Functions Used

# ord(c)
# Given a string representing one Unicode character,
# return an integer representing the Unicode code point of that character.
# For example, ord('a') returns the integer 97 and ord('€') (Euro sign) returns 8364.
# This is the inverse of chr().


# chr(i)
# Return the string representing a character whose Unicode code point is the integer i.
# For example, chr(97) returns the string 'a', while chr(8364) returns the string '€'.
# This is the inverse of ord().

