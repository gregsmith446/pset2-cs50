// program prompts user for a message to be encrypted (plaintext)
// and outputs an encrypted version of that message (ciphertext)
// the encrypted text is shifted based on the text key given in the command line

/**
Nice error checking - I like programs to say explicitly how many args are needed -but it's not neccesaary in this case.
I love the comments - but remember good code is can be self documenting, your variable k would not need a comment explaining what
it does if it was name something like keywordIndex. It can be difficult to name things appropriately while trying to solve an algorithm.
I typically go back at the end and look at the context.
The extrapolation of certain calculations in varibles like modulo can make code easier to reason about.
The caveat with that from what I heard to proffesionals is that it is situational.
In C where space can be a concern you may want to give up readability for performance - I don think it matter for this exercise though.
On the flipside if this is running on a resource rich env like a browser - I would much rather read your code here, than have it "cleverly"
done in one line where it takes me 20 minutes to reason what is going on.
Other than some minor philosophical considerations, I feel like the code is well crafted - Good Job.
 **/

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
    int keywordIndex = 0;

    //loop through plaintext but convert only alpha chars
    for (int j = 0; j < strlen(plaintext); j++)
    {
        //if the plaintext is alpha chars
        if (isalpha(plaintext[j]))
        {
            // modulo var to store keyword index
            int modulo = keywordIndex % strlen(keyword);

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
            keywordIndex++;
        }
    }
    printf("%s\n", plaintext);
}



