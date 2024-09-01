#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

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
        printf("result: %.1lf", result);
        break;
    default:
        printf("Wrong argument");
    }

    return 0;
}