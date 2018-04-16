// program will prompt for a message to be encrypted (plaintext)
// and outputs an encrypted version of that message (cipertext) shifted based off the key given in the command line

#include<stdio.h> // printf
#include<cs50.h> // get_string
#include <string.h> // strlen
#include <ctype.h> // isupper, islower
#include <stdlib.h> // atoi

int main(int argc, string argv[])
{
    //if the command line argument isn't ./caesar #
    if (argc != 2)
    {
        printf("Error: must include a key after executing program\n"); // tell the user to include a key
        return 1; // return the error code
    }

    // the key from command line comes through as a string, so atoi converts it to an int
    int keyAsInt = atoi(argv[1]); //the key is how many places to shift the chars

    string plaintext = get_string("Message to Encrypt: ");

    printf("ciphertext: "); // have to print "ciphertext" before the shifting process below

    for (int i = 0, n = strlen(plaintext); i < n; i++) //iterate through the plaintext string message
    {
        int letter; //holds the indexed uppercase + lowercase letters as an int
        char ciphertext; //holds the shifted letters

        if (isalpha(plaintext[i])) //if the chars are letters
        {
            if(isupper(plaintext[i])) //if the chars are letters and uppercase
            {
                letter = plaintext[i] - 'A'; //set uppercase A-Z index to 0 by subtracting 65 from all letters

                while (letter + keyAsInt > 25) // if the ASCII # for the char goes over 25 (the full uppercase alphabet)
                {
                    letter -=26; //subtract when the limit of 26 is reached
                }
                    letter += 'A'; //
                    ciphertext = letter + keyAsInt; //take the indexed uppercase letter, shift by key# and set = to ciphertext
                    printf("%c", ciphertext); //print each shifted char
                }
                else if(islower(plaintext[i])) //or if the chars are letters and lowercase
                {
                    letter = plaintext[i] - 'a'; //set lowercase a-z index to 0 by subtracting 97 from all letters

                    while (letter + keyAsInt > 25) // while the char's ASCII# is more than 25
                    {
                        letter -= 26; //go back down 1 at a time or wrap back around
                    }
                        letter += 'a';
                        ciphertext = letter + keyAsInt; //take the indexed lowercase letter, shift by key# and set = to ciphertext
                        printf("%c", ciphertext); //print each shifted char
                    }
                }
                else //if any of the the plaintext is not letters(uppercase or lowercase), print them as is - including spaces, symbols, numbers
                {
                    ciphertext = plaintext[i]; //set the shifted message letters = ciphertext
                    printf("%c", ciphertext); //print the cipher as chars
                }
            }
            printf("\n"); //print the final result on a new line
}