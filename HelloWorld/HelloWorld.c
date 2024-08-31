#include <stdio.h> //when we say "std" we are saying standard, "io" stand for input and output
#include <stdbool.h>
// when we write "//" this is a comment

/*this also a comment*/

/*escape sequence = character combination consisiting of a backslash \ followed by a letter or combination of digits. 
                    They specify actions within a line or string of text.
                    \n = new line
                    \t = tab*/ 
// there is no string in c wtf!
int main()
{


    int age = 14;
    char name[] = "Bro";
    float c = 3.14592653589793;
    double d = 3.14592653589793;
    bool x = false;
    
    printf("%d\n",x);

    // printf("c = %f \n",c);
    //printf("d = %lf",d);
    return 0;
}