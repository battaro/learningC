#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    //new variable
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