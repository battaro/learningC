#include <stdio.h> //when we say "std" we are saying standard, "io" stand for input and output
#include <stdbool.h>
#include <string.h>
#include <math.h>
// when we write "//" this is a comment

/*this also a comment*/

/*escape sequence = character combination consisiting of a backslash \ followed by a letter or combination of digits.
                    They specify actions within a line or string of text.
                    \n = new line
                    \t = tab*/
// there is no string in c wtf!
// all datatypes in README.md file
// constant = fixed value that cannot be altered by the progrma during its execution
// you can convert datatypes like this > (_datatype) _nameofvariable

// scanf to get input from user
// fgets to get input with white spaces from user
int main()
{
    int age;

    printf("\nEnter a letter age: ");

    scanf("%d", &age);

    switch (age)
    {
    case 10:
        printf("You are Welcome!\n");
        break;

    case 15:
        printf("You're not Welcome!\n");
        break;

    default:
        printf("Shut the fuck up\n");
        break;
    }

    return 0;
}