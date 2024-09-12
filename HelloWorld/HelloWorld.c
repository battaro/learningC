#include <stdio.h> //when we say "std" we are saying standard, "io" stand for input and output
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
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

// typedef almost same to struct

// Bitwise AND (&)
// Compares each bit of a and b. If both bits are 1, the result is 1; otherwise, it is 0.
// 0101 & 0011 = 0001 (1 in decimal)

// Bitwise OR (|)
// Compares each bit of a and b. If at least one bit is 1, the result is 1; otherwise, it is 0.
// 0101 | 0011 = 0111 (7 in decimal)

// Bitwise XOR (^)
// Compares each bit of a and b. If the bits are different, the result is 1; otherwise, it is 0.
// 0101 ^ 0011 = 0110 (6 in decimal)

// Bitwise NOT (~)
// Inverts all the bits of a number (i.e., 1 becomes 0 and 0 becomes 1).
// ~0101 = 1010 (in a system with 32 bits, this is represented as a two's complement negative number)
// Note: Result is machine dependent because it works on all bits of the integer.

// Left Shift (<<)

// Right Shift (>>)
// Shifts the bits of a number to the right by the specified number of positions.
// Right shifting 0101 (5) by 1 position gives 0010 (2 in decimal)

// pointer = a "variable-like" reference that holds a memory address to another variable, array etc..
//              some tasks are performed more easily with pointers
//              * = indirection operator (value of address)
int main()
{
    srand(time(0));
    int r,c;
    int rowValues[3] = {0, 2, 4};
    int ColumnValues[3] = {1, 5, 9};

    int randRowIndex = rand() % 3;
    int randColumnIndex = rand() % 3;

    r = rowValues[randRowIndex];
    c = ColumnValues[randColumnIndex];

    printf("Row : %d Column: %d",r,c);
}