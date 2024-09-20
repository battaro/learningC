#include <stdio.h>   // For input/output operations
#include <string.h>  // For string handling functions
#include <stdlib.h>  // For dynamic memory management
#include <time.h>    // For handling dates and times
#include <stdbool.h> // For boolean values
#include <errno.h>   // For error handling in file operations
#include <windows.h> // For console window operations

#pragma region All functions

// book management functions`
void ViewAllBooks();
void AddNewBook();
void SearchBook();
void BorrowBook();
void ReturnBook();
void DeleteBook();
void readBooks();
void writeBooks();
void SectionName(char sectionname[300]);

// User Experience
void progressBar(char messageBefore[1000], char messageAfter[1000], int sleepTime);
void welcome();
void _ExitApplication();
void clearScreen();

// main function
void mainfunction();

#pragma endregion

#pragma region Public Variables
// public variables

typedef struct
{
    char title[100];
    char author[100];
    int quantity;
    int id;
    int status;
} Book;
Book books[1000];
int booksCount;

#pragma endregion

#pragma region Book Management Functions

void ViewAllBooks()
{
    SectionName("Books Available in the Library");
}
void AddNewBook()
{
    SectionName("Add New Book");
}
void SearchBook()
{
    SectionName("Search for a Book");
}
void BorrowBook()
{
    SectionName("Borrow a Book");
}
void ReturnBook()
{
    SectionName("Return a Book");
}
void DeleteBook()
{
}
void readBooks()
{
}
void writeBooks()
{
}
#pragma endregion

#pragma region User Experience

void SectionName(char sectionname[300])
{
    printf("---------------------------------\n");
    printf("%s:\n", sectionname);
    printf("---------------------------------\n");
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}
void _ExitApplication()
{
    progressBar("You data is being saved", "You data is saved successfully", 10);
    printf("\nThank you for using our library management system");
    exit(0);
}

void progressBar(char messageBefore[1000], char messageAfter[1000], int sleepTime)
{
    int i = 0;
    while (i <= 100)
    {
        printf("\r%s %d%%", messageBefore, i);
        Sleep(sleepTime);
        i++;
    }
    printf("\n%s", messageAfter);
}

void welcome() {}

#pragma endregion

void mainfunction()
{
    clearScreen();
    readBooks();
    welcome();

    int choice;
    do
    {

        char choices[7][100] =
            {
                "1. View All Books",
                "2. Add New Boook",
                "3. Search for a Book",
                "4. Borrow a Book",
                "5. Return a Book",
                "6. Exit",
                "---------------------------------\n"};

        // display choices
        for (int i = 0; i < 7; i++)
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
            ViewAllBooks();
            break;

        case 2:
            AddNewBook();
            break;

        case 3:
            SearchBook();
            break;

        case 4:
            BorrowBook();
            break;
        case 5:
            ReturnBook();
            break;
        case 6:
            _ExitApplication();
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 6);
}
int main()
{
    mainfunction();
    return 0;
}