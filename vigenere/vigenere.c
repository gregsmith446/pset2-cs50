// program prompts user for a message to be encrypted (plaintext)
// and outputs an encrypted version of that message (ciphertext)
// the encrypted text is shifted based on the text key given in the command line

#include<stdio.h> // printf
#include<cs50.h> // get_string
#include <string.h> // strlen
#include <ctype.h> // isupper, islower
#include <stdlib.h> // atoi

int main(int argc, string argv[])
{
    //emit error message if the command line argument isn't ./vigenere keyword
    if (argc != 2)
    {
        printf("Error: must include a keyword\n");
        return 1;
    }

    // assign the keyword from the command line argv[1], to the string keyword
    string keyword = argv[1];

    // continue error trapping process --> iterate through the provided keyword
    // if keyword isn't fully alpha, reprompt the user for another with instructions
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i])) //if the keyword has nums, symbols, etc.
        {
            printf("Error: Keyword can only contain letters/alpha characters\n");
            return 1;
        }
    }

    // after a valid keyword has been provided
    // prompt user for the message to be encrypted
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: "); // print out the "ciphertext: " portion before the below processes

    // int k to hold the keyword position
    int k = 0;

    //loop through plaintext but convert only alpha chars
    for (int j = 0; j < strlen(plaintext); j++)
    {
        //if the plaintext is alpha chars
        if (isalpha(plaintext[j]))
        {
            // modulo var to store keyword index
            int modulo = k % strlen(keyword);

            //if lowercase letters
            if (islower(plaintext[j]))
            {

                keyword[modulo] = tolower(keyword[modulo]);

                // cues the wraparound for the lowercase alpha set
                if (plaintext[j] + ((keyword[modulo]) - 'a') > 'z')
                {
                    plaintext[j] = ('a' - 1) + ((plaintext[j] + (keyword[modulo] - 'a')) % 'z');
                }
                else
                {
                    plaintext[j] += (keyword[modulo] - 'a');
                }
            }
            else
            {
                //
                keyword[modulo] = toupper(keyword[modulo]);

                if (plaintext[j] + (keyword[modulo] - 'A') > 'Z')
                {
                    plaintext[j] = ('A' - 1) + ((plaintext[j] + (keyword[modulo] - 'A')) % 'Z');
                }
                else
                {
                    plaintext[j] += (keyword[modulo] - 'A');
                }
            }

            //increment the keyword index only after 1 alpha char has completed being enciphered
            k++;
        }
    }
    printf("%s\n", plaintext);
}



