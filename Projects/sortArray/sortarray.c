#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void sort(int array[], int length);
void SortedArray(int array[], int length);

void sort(int array[], int length)
{

    for (int i = 0; i < length - 1; i++) // length - 1 because in programming 0 is the first number in list
    {   
        //length - 1 - i because no need repeat numbers if the list is big i mean just for optimization
        for (int j = 0; j < length - 1 -  i; j++) 
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j]; //store the largest number 

                 //replace the largest number with the smalest number
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//take the new sorted list and print it number by number
void SortedArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int numbers[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; //A list of numbers
    int length = sizeof(numbers) / sizeof(numbers[0]); //length of the list 
    sort(numbers, length); // call the function that will sort the list
    SortedArray(numbers, length); //print the sorted list
    return 0;
}
