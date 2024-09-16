#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
void WriteFile()
{
    FILE *file;         // create file pointer
    char filename[100]; // create filename
    char text[5000];    // create text of the file

    printf("Write the name of the file: ");

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

    fprintf(file, "%s", text);
    fclose(file); // close the file
}

int main()
{
    WriteFile();
    return 0;
}