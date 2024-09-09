#include <stdio.h> //when we say "std" we are saying standard, "io" stand for input and output
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
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
// ternary opertator = shortcut to if/else when assigning/returning a value.
//(condition) ? value if true : value if false.
//   for example return(a>b) ? a : b;

// Function prototype, Ensures that calls to a function are made with the correct arguments.
// Use the Function that you want up like : void FunctionName(arg1,arg2);
// for and while loop same as c#
// do while loop same as c#
// arrays almost same as c# though <3

// struct = collection of related members ("variables")
//          they can be different data types
//          listed under one name in a block of memory
//          very similar to classes in other languages (but no methods)

//typedef almost same to struct

struct Student
{
    char name[12];
    float gpa;
};

int main()
{
    struct Student st1 = {"battar",3.0};
    struct Student st2 = {"brother",2.0};
    struct Student st3 = {"me",4.0};
    struct Student st4 = {"hamza",5.0};

    struct Student students[] = {st1,st2,st3,st4};
    int studentslength = sizeof(students) / sizeof(students[0]); 
    for (int i = 0; i < studentslength; i++)
    {
        printf("%s",students[i].name);
        printf("%f\n",students[i].gpa);
    }
    
    return 0;
}