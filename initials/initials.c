//program that takes a user's first and last name, separated by a space
//then returns the 2 initials in uppercase

#include<stdio.h>
#include<cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    //initialize string as "name" and prompt user for name
    string name = get_string("First and Last Name: ");
    //for loop to iterate through name string
    for (int i = 0; i < strlen(name); i++)
    {
        // if i = the first letter(0) || i = the first letter after a space, space = 32 in ASCII
        // name[i - 1] == 32 in human terms is; if the char - 1 is a space, print that char
        // if the user forgets a space, it will only print the first intial
        if (i == 0 || name[i - 1] == 32)
        {
            printf("%c", toupper(name[i])); //print the 2 chars in uppercase
        }
    }
    printf("\n"); //print the 2 initials on new line
}