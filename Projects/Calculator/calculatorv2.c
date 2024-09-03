#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

double add(double num1, double num2) { return num1 + num2; }      // adding opertation
double subtract(double num1, double num2) { return num1 - num2; }       // subtracting opertation
double multiply(double num1, double num2) { return num1 * num2; } // multipling opertation
double divide(double num1, double num2) { return num1 / num2; }   // dividing opertation

//main code 
void calculator()
{

    
    double num1, num2, result;
    printf("\nwrite the first number: ");
    scanf("%lf", &num1); //input first number

    bool _continue = true;

    while (_continue)
    {
        //input the operation
        char operation;
        printf("\nPick an operation (/,*,-,+): ");
        scanf(" %c", &operation);
        
        //input t he second number 
        printf("\nWrite the second number: ");
        scanf("%lf", &num2);

        //operation select if + add etc..
        switch (operation)
        {
        case '+':
            result = add(num1, num2);
            break;

        case '-':
            result = subtract(num1, num2);
            break;

        case '*':
            result = multiply(num1, num2);
            break;

        case '/':
            result = divide(num1, num2);
            break;
        }
        
        //input the user status if he need to continue or not
        char user_status;
        printf("\nType \"Y\" to continue calculating with %.1lf or type \"N\" to start a new calculation: ", result);
        scanf(" %c", &user_status);
        
        //let the user status input be Upercase
        user_status = toupper(user_status);


        //check the user's status
        switch (user_status)
        {
        case 'Y':
            num1 = result;
            _continue= true;
            break;
        case 'N':
            _continue = false;
            printf("Bye Bye");
            break;
        }
    }

    return 0;
}

int main()
{
    printf("Welcome to Calculator version 2\n");
    printf("--------------------------------\n");
    calculator();
}

//it wasn't hard to make this project but if u didn't use the calculator well the console will crash
//i had problem with whitespaces characters but chatgpt helped me solving this issue by giving space before %c
