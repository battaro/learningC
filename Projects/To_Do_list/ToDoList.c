#include <stdio.h>   // For input/output operations
#include <string.h>  // For string handling functions
#include <stdlib.h>  // For dynamic memory management
#include <time.h>    // For handling dates and times
#include <stdbool.h> // For boolean values
#include <errno.h>   // For error handling in file operations

void welcome();
void addtask();
void viewtasks();
void markTaskAsDone();
void deleteTask();
void editTask();
void exitTask();
void mainfunction();

typedef struct
{
    int taskid;
    char taskname[100];
    char description[1000];
    char date[100];
    bool status;

} Task;

void welcome()
{
    printf("\n-------------------------------\n");
    printf("Welcome to the To-Do List App\n");
    printf("-------------------------------\n");
}
void addTask() {}
void viewTasks() {}
void markTaskAsDone() {}
void deleteTask() {}
void editTask() {}
void exitTask() {}

void mainfunction()
{
    
    welcome();
}

int main()
{
    mainfunction();
    return 0;
}
