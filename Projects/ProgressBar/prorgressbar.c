#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void _WriteFile();
void _ProgressBar();
void _ReadFile();
void clearScreen();
void _WriteFile()
{
    FILE *file;         // create file pointer
    char filename[100]; // create filename
    char text[5000];    // create text of the file

    printf("Write the name of the file to write to: ");

    // read filename and if there is any problem print error
    if (fgets(filename, sizeof(filename), stdin) == NULL)
    {
        printf("Error reading filename.\n");
        return;
    }

    filename[strcspn(filename, "\n")] = '\0'; // remove newline character

    file = fopen(filename, "w"); // open the file in write mode

    // if there is any problem print error
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    printf("Enter the contant of the file maximum 5000 characters: ");

    // read the text of the file and if there is any problem print error
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Error reading text.\n");
        fclose(file); // Close the file before exiting
        return;
    }

    _ProgressBar(); // do the progress bar

    fprintf(file, "%s", text);

    printf("File created successfully");
    fclose(file); // close the file
}

void _ProgressBar()
{
    int progress = 0; // start at 0%

    char bar[51] = {0}; // create a progress bar with 50 characters and 1 to be filled
                        // and {0} to insure that the bar is empty at the beginning

    // if the progress is less than 100 fill the bar with percentages
    while (progress <= 100)
    {

        // fill the bar with '='
        // i put progress /2 because the bar is 50 characters and 100/2 = 50 so each 2 progress = 1('=')
        for (int i = 0; i < (progress / 2); i++)
        {
            bar[i] = '='; // replace the empty space with '='
        }
        printf("\rWaiting... [%-50s]%d%%", bar, progress); // print the progress bar with percentages
        Sleep(50);                                         // sleep for 0.05 seconds
        progress++;
    }
    printf("\n");
}

void _ReadFile()
{
    char filename[100];
    FILE *file;
    printf("\nWrite the name of the file to read from: ");

    // read filename and if there is any problem print error
    if (fgets(filename, sizeof(filename), stdin) == NULL)
    {
        printf("Error reading filename.\n");
        return;
    }
    filename[strcspn(filename, "\n")] = '\0';

    char filetext[5000];

    file = fopen(filename, "r"); // open the file in read mode

    printf("File Content:\n");
    // print the content of the file line by line
    while (fgets(filetext, sizeof(filetext), file) != NULL)
    {
        Sleep(10);
        printf("%s", filetext);
    }
    fclose(file);
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}

int main()
{
    char userInfo;

    do
    {
        printf("For reading file R, for writing file W, for exiting press any other key: ");
        scanf(" %c", &userInfo); // Read the input
        getchar();               // Consume the newline character left by scanf

        userInfo = toupper(userInfo); // Convert input to uppercase for easier comparison

        if (userInfo == 'R')
        {
            _ReadFile();
        }
        else if (userInfo == 'W')
        {
            _WriteFile();
        }

        // Give the user time to see the output before clearing the screen
        printf("\nPress Enter to continue...");
        getchar(); // Wait for user to press Enter

        clearScreen(); // Clear screen after user acknowledges
    } while (userInfo == 'R' || userInfo == 'W'); // Continue while input is R or W

    printf("Bye Bye\n");
    return 0;
}

// Initially, I wanted to use the progress bar in a different context,
// but the project evolved into a file reading and writing application.
// Either way, this project was a great way to improve my logic and skills.