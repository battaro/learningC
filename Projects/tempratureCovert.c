#include <stdio.h> //when we say "std" we are saying standard, "io" stand for input and output
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
    char unit;
    double temp, newtemp;

    printf("\nIs the temprature in F or on C: ");
    scanf("%c", &unit);
    char unitUpercase = toupper(unit);

    printf("\nWrite the temp: ");
    scanf("%lf", &temp);

    switch (unitUpercase) {

        case 'C':
            newtemp = (temp * (9.0 / 5.0)) + 32.0;
            printf("%.1lfC is: ", temp);
            printf("%.1lfF", newtemp);
            break;
            
        case 'F':

            newtemp = (temp - 32.0) * (5.0 / 9.0);
            printf("%.1lfF is: ", temp);
            printf("%.lfC", newtemp);
            break;
        default:
        printf("Wrong argument");
    }

    return 0;
}