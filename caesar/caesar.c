/**
I like your comments about what the libraries do.
I appreciate the prompt when no key is passed - One improvment could be specifying too few/too many args.
I like how you extrapolated some of the calculations into their own variables  Ex int letter.
On that note it seems like your checking against that variable to know whether you need to wrap around?
If so, I like how you handled that, but at the same time it produces extra variables/memory utilization. It seems as though modulous might be
appropriate and may be shorter in the end because you may not need extra variables/if statement.
Avoid nesting loops if you can - Your for loop insures you touch every character once - running the while loop within the for loop
might be a bit "extra". Also when a human is reading it(yourself included) it adds another layer of complexity to hold in memory
while you try to reason about the code.
I don't know if you employ psuedocode as part of your process - but I find it helpful and it helps me avoid coding myself into a corner.
I also like to analyze patterns before hand - I find that alot of code problems share similar patterns and solutions.
Hopefully this was helpful, if you would like to speak further on any of this let me know.
**/

// program will prompt for a message to be encrypted (plaintext)
// and outputs an encrypted version of that message (cipertext)
// the plaintext is shifted based off the numerical key given in the command line

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
        printf("Error: must include a numerical key after executing program\n"); // tell the user to include a key
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
            if (isupper(plaintext[i])) //if the chars are letters and uppercase
            {
                letter = plaintext[i] - 'A'; //set uppercase A-Z index to 0 by subtracting 65 from all letters

                while (letter + keyAsInt > 25) // if the ASCII # for the char goes over 25 (the full uppercase alphabet)
                {
                    letter -= 26; //subtract when the limit of 26 is reached
                }
                letter += 'A'; //
                ciphertext = letter + keyAsInt; //take the indexed uppercase letter, shift by key# and set = to ciphertext
                printf("%c", ciphertext); //print each shifted char
            }
            else if (islower(plaintext[i])) //or if the chars are letters and lowercase
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