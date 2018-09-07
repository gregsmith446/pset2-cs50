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
# 1 get the key
# cast key to integer
    key = int(sys.argv[1])
# 2 get the plaintext
    ciphertext = []
    plaintext = cs50.get_string("Message to Encrypt: ")
    # print("Starting message is:", plaintext)

# checking characters
# preserve case
    for letter in plaintext:
        if letter.isalpha():
            ciphertext.append(caesar(char, key))
        else:
            ciphertext.append(letter)

        print("".join(ciphertext))
        exit(0)

# 3 encypher text
#ASCII <--> alphabetical
# ord, chr
# shift char by key
# 4 print ciphertext
# print()

    def caesar(char, key):
        if char.isupper():
            return chr(((ord(char) - 65 + key) % 26) + 65)
        else:
            return chr(((ord(char) - 97 + key) % 26) + 97)


if __name__ == "__main__":
    main()