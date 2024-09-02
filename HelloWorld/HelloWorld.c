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
// functions and arguments also same as c#
//ternary opertator = shortcut to if/else when assigning/returning a value.
//(condition) ? value if true : value if false.
//   for example return(a>b) ? a : b;

// Function prototype, Ensures that calls to a function are made with the correct arguments.
// Use the Function that you want up like : void FunctionName(arg1,arg2);
int findMax(int a,int b)
{
    return (a>b) ? a : b;
}
int main()
{
    int max = findMax(3,4);
    printf("%d",max);
    return 0;
}