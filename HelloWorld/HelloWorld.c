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
// logical operators same to c#
int main()
{
    char operator;
    double num1, num2, result;

    printf("\nEnter an operator: ");
    scanf("%c", &operator);

    printf("\nWrite the first number :");
    scanf("%lf", &num1);

    printf("\nWrite the second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {

    case '+':
        result = num1 + num2;
        printf("%.1lf", result);
        break;

    case '-':
        result = num1 - num2;
        printf("%.1lf", result);
        break;

    case '/':

        result = num1 / num2;
        printf("%.1lf", result);
        break;
    case '*':

        result = num1 * num2;
        printf("%.1lf", result);
        break;
    default:
        printf("Wrong argument");
    }

    return 0;
}