#include <stdio.h>   // For input/output operations
#include <string.h>  // For string handling functions
#include <stdlib.h>  // For dynamic memory management
#include <time.h>    // For handling dates and times
#include <stdbool.h> // For boolean values
#include <errno.h>   // For error handling in file operations
#include <windows.h> // For console window operations

// User Experience
void welcome();
void progressBar(int percent);

// Task Management
void addtask();
void viewtasks();
void markTaskAsDone();
void deleteTask();
void exitTask();

void mainfunction();
void clearScreen();
int generateTaskId();

// file management functions
void ReadTaksFile();
void WriteTaksFile();

// global variables
typedef struct
{
    int taskid;
    char taskname[100];
    char description[1000];
    char date[100];
    bool status;

} Task;

Task tasks[1000];  // array to store staks
int taskCount = 0; // global integer to track the number of tasks

void welcome()
{
    printf("====================================\n");
    printf("Welcome to the To-Do List App\n");
    printf("====================================\n");
}
void addTask()
{
    if (taskCount >= (sizeof(tasks) / sizeof(tasks[0])))
    {
        printf("Task limit reached. Cannot add more taks. \n");
        return;
    }

    Task newtask = {}; // create new task

    printf("Enter Task Name: ");
    if (fgets(newtask.taskname, sizeof(newtask.taskname), stdin) == NULL)
    {
        printf("Error Entering name.\n");
        return;
    }
    newtask.taskname[strcspn(newtask.taskname, "\n")] = '\0'; // remove newline character

    printf("Enter Task Description: ");
    if (fgets(newtask.description, sizeof(newtask.description), stdin) == NULL)
    {
        printf("Error Entering Description.\n");
        return;
    }
    newtask.description[strcspn(newtask.description, "\n")] = '\0'; // remove newline character

    printf("Enter Task Date: ");
    if (fgets(newtask.date, sizeof(newtask.date), stdin) == NULL)
    {
        printf("Error Entering date.\n");
        return;
    }
    newtask.date[strcspn(newtask.date, "\n")] = '\0'; // remove newline character

    newtask.taskid = generateTaskId(); // generate task id

    newtask.status = false;     // set status to incomplete by default
    tasks[taskCount] = newtask; // add new task to tasks array
    taskCount++;                // increment task count

    progressBar(10); // display progress bar

    printf("Task added successfully. \n");
    printf("---------------------------------\n");
}

void viewTasks()
{
    progressBar(5); // display progress bar

    // check if there are any tasks
    if (taskCount == 0)
    {
        printf("No tasks to display.\n");
        return;
    }

    char Screen[3][100] =
        {
            "\n=================================",
            "          Your Tasks List         ",
            "================================="};

    // display scree
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", Screen[i]);
    }

    // print all tasks
    for (int i = 0; i < taskCount; i++)
    {
        printf("Task ID: %d\n", tasks[i].taskid);
        printf("Task Name: %s\n", tasks[i].taskname);
        printf("Description: %s\n", tasks[i].description);
        printf("Date: %s\n", tasks[i].date);
        printf("Status: %s\n", tasks[i].status ? "Completed" : "Incomplete");
        printf("=================================\n");
    }
    printf("\nPress Enter to continue...");
    getchar(); // Wait for user to press Enter
}
void markTaskAsDone()
{

    if (taskCount == 0)
    {
        printf("No tasks to mark as done.\n");
        return;
    }

    printf("Enter Task ID: ");
    int taskId;
    scanf("%d", &taskId);

    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].taskid == taskId)
        {
            tasks[i].status = true;
        }
    }

    progressBar(5); // display progress bar

    printf("Task marked as done. \n");
    printf("---------------------------------\n");
}
void deleteTask()
{
    if (taskCount == 0)
    {
        printf("No tasks to delete.\n");
        return;
    }

    int taskId;
    printf("Enter Task ID to delete: ");
    scanf("%d", &taskId);
    while (getchar() != '\n')
        ;
    bool found = false;

    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].taskid == taskId)
        {
            // move all tasks after the deleted task to the left
            for (int j = i; j < taskCount - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            found = true;
            break;
        }
    }

    progressBar(5); // display progress bar

    if (found)
    {
        printf("Task deleted successfully. \n");
        printf("---------------------------------\n");
    }
    else
    {
        printf("Task with ID %d not found. \n", taskId);
        printf("---------------------------------\n");
    }
}
void exitTask()
{
    printf("Thank you for using the To-Do List App your data saved successfully, Goodbye..... \n");
    WriteTaksFile();
    progressBar(5);
    exit(0);
}
void progressBar(int sleepTime)
{
    int i = 0;
    while (i <= 100)
    {
        printf("Loading....%d%%\r", i);
        Sleep(sleepTime);
        i += 1;
    }
}
int generateTaskId()
{
    srand(time(NULL));
    int id = rand() % 1000;
    for (int i = 0; i < 1000; i++)
    {
        while (id == tasks[i].taskid)
        {
            id = rand() % 1000;
        }
    }

    return id;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}

void mainfunction()
{
    clearScreen();
    ReadTaksFile(); // read tasks from file if there is no when you exit new file will be created
    welcome();

    int choice;
    do
    {

        char choices[6][100] =
            {
                "1. Add Task",
                "2. View Tasks",
                "3. Mark Task As Done",
                "4. Delete Task",
                "5. Exit",
                "---------------------------------\n"};

        // display choices
        for (int i = 0; i < 6; i++)
        {
            printf("%s\n", choices[i]);
        }

        printf("Enter Your Choice: ");

        scanf("%d", &choice);

        while (getchar() != '\n')
            ; // clear the input buffer

        // pick Function according to user choice
        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            markTaskAsDone();
            break;

        case 4:
            deleteTask();
            break;
        case 5:
            exitTask();
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 5);
}

void WriteTaksFile()
{
    FILE *file = fopen("tasks.txt", "w"); // the file will be created in the current directory
    if (file == NULL)
    {
        printf("Error Opening File\n");
        return;
    }
    for (int i = 0; i < taskCount; i++)
    {
        // Write each task to the file, separating fields with tabs
        fprintf(file, "%d\t%s\t%s\t%s\t%d\n",
                tasks[i].taskid,
                tasks[i].taskname,
                tasks[i].description,
                tasks[i].date,
                tasks[i].status ? 1 : 0);
    }
    fclose(file);
}

void ReadTaksFile()
{
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) // Correct the condition
    {
        printf("Error Opening File for Reading\n");
        return;
    }

    Task task; // Temporary struct to hold each task read
    while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%d\n",
                  &task.taskid,
                  task.taskname,
                  task.description,
                  task.date,
                  // convert the status from boolean to int
                  (int *)&task.status) != EOF) // eof is end of file
    {
        tasks[taskCount++] = task; // Add the task to the tasks array and increment taskCount
    }
}

int main()
{
    mainfunction();
    return 0;
}

// I worked on this project for 3 hours, and it made me feel like a hacker 💀
// But honestly, I'm really proud of it. I learned a lot, and this was great practice.
// Insha'Allah, I'll do even better in my next project!
// There are some parts of the code, like ReadTaskFile and WriteTaskFile, that I didn't fully understand and got help from ChatGPT on.
// If you're not using Windows, you might encounter some issues.