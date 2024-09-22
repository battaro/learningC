#include <stdio.h>   // For input/output operations
#include <string.h>  // For string handling functions
#include <stdlib.h>  // For dynamic memory management
#include <time.h>    // For handling dates and times
#include <stdbool.h> // For boolean values
#include <errno.h>   // For error handling in file operations
#include <windows.h> // For console window operations
#include <ctype.h>   // For character handling functions

#pragma region All functions

// book management functions`
void ViewAllBooks();
void AddNewBook();
void SearchBook();
void BorrowBook();
void ReturnBook();
char *GenerateBookID();
void readBooks();
void InitializeBooks();
void SectionName(char sectionname[300]);
void toLowerCase(char str[]);

// User Experience
void progressBar(char messageBefore[1000], char messageAfter[1000], int sleepTime);
void welcome();
void _ExitApplication();
void clearScreen();

// main function
void mainfunction();

// coloring
void red();
void blue();
void green();
void yellow();
void reset();

#pragma endregion

#pragma region Public Variables
// public variables

typedef struct
{
    char title[100];
    char author[100];
    char id[100];
    int quantity;
    int maxQuantity;
} Book;

Book books[100];
int booksCount = 0;
#pragma endregion

#pragma region Book Management Functions
void ViewAllBooks()
{
    if (booksCount == 0)
    {
        red();
        printf("no books found. \n");
        return;
    }

    blue();
    SectionName("Books Available in the Library");

    green();
    for (int i = 0; i < booksCount; i++)
    {
        Sleep(50); // for animation
        if (books[i].quantity >= 1)
        {
            printf("%d. Title: %s\n   Author: %s\n   ID: %s\n   Quantity: %d\n",
                   i + 1,
                   books[i].title,
                   books[i].author,
                   books[i].id,
                   books[i].quantity);
            printf("\n");
        }
    }
    Sleep(1000);
}
void AddNewBook()
{
    if (booksCount >= (sizeof(books) / sizeof(books[0])))
    {
        red();
        printf("Book limit reached. Cannot add more books. \n");
        return;
    }

    blue();
    SectionName("Add New Book");
    Book newbook;

    green();
    printf("Books Title: ");
    if (fgets(newbook.title, sizeof(newbook.title), stdin) == NULL)
    {
        printf("Error Entering Title.\n");
        return;
    }
    newbook.title[strcspn(newbook.title, "\n")] = '\0'; // remove newline character

    printf("Enter Book Author: ");
    if (fgets(newbook.author, sizeof(newbook.author), stdin) == NULL)
    {
        printf("Error Entering Author.\n");
        return;
    }
    newbook.author[strcspn(newbook.author, "\n")] = '\0'; // remove newline character

    printf("Enter Book Max Quantity \" must be a Natural Number\": ");
    scanf("%d", &newbook.maxQuantity);
    newbook.quantity = newbook.maxQuantity;
    while (getchar() != '\n') // remove newline character
        ;

    strcpy(newbook.id, GenerateBookID());

    books[booksCount++] = newbook;

    progressBar("Adding Book", "Book Added Successfully\n", 10);

    Sleep(1000);
}
void toLowerCase(char str[])
{
    char lowerStr[100];
    // Convert str to lowercase
    for (int i = 0; str[i] != '\0'; i++) // i use '\0' to indicate the end of the string
    {
        lowerStr[i] = tolower(str[i]);
    }

    lowerStr[strlen(str)] = '\0'; // Add '\0' to the end of the string

    // Copy lowerStr back to the original string
    for (int i = 0; lowerStr[i] != '\0'; i++)
    {
        str[i] = lowerStr[i];
    }
    Sleep(1000);
}

void SearchBook()
{
    if (booksCount == 0)
    {
        red();
        printf("There are no books in the library.");
        return;
    }

    blue();
    SectionName("Search for a Book");

    green();
    printf("Write the title or the author of the book you want to search: ");
    char search[100];
    if (fgets(search, sizeof(search), stdin) == NULL)
    {
        red();
        printf("Error Entering \"Title\" or \"Author\".\n");
        return;
    }
    search[strcspn(search, "\n")] = '\0'; // Remove newline character

    // Convert search string to lowercase
    for (int j = 0; search[j]; j++)
    {
        search[j] = tolower(search[j]);
    }

    bool found = false;
    progressBar("Searching Books...", "Books after search: ", 10);

    green();

    for (int i = 0; i < booksCount; i++)
    {
        // Create a lowercase version of the title and author
        char titleLower[100], authorLower[100];

        strcpy(titleLower, books[i].title);
        strcpy(authorLower, books[i].author);

        // Convert title and author to lowercase
        for (int j = 0; titleLower[j]; j++)
        {
            titleLower[j] = tolower(titleLower[j]);
        }
        for (int j = 0; authorLower[j]; j++)
        {
            authorLower[j] = tolower(authorLower[j]);
        }

        if (strstr(titleLower, search) != NULL || strstr(authorLower, search) != NULL)
        {
            found = true;
            printf("%d.", i + 1);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ID: %s\n", books[i].id);
            printf("Quantity: %d\n", books[i].quantity);
            printf("\n");
        }
    }

    if (!found)
    {
        red();
        printf("No books found. with %s\n \n", search);
    }
    Sleep(1000);
}

void BorrowBook()
{
    if (booksCount == 0)
    {
        red();
        printf("There are no books in the library.");
        return;
    }

    blue();
    SectionName("Borrow a Book");

    int id;
    char idString[5];
    bool found = false;

    green();
    printf("Enter Book ID: ");
    scanf("%d", &id);

    sprintf(idString, "%03d", id); // convert integer to string and use 3 digits format

    for (int i = 0; i < booksCount; i++)
    {
        // Compare the string versions of the IDs
        if (strcmp(idString, books[i].id) == 0 && books[i].quantity >= 1)
        {
            books[i].quantity--;
            found = true;
            break;
        }
    }

    // Show result using progressBar
    progressBar("Borrowing Book...", found ? "Book Borrowed\n" : "Book Not Found\n", 10);
    Sleep(1000);
}
void ReturnBook()
{
    if (booksCount == 0)
    {
        red();
        printf("There are no books in the library.");
        return;
    }

    blue();
    SectionName("Return a Book");
    int id;
    char idString[5];
    bool found = false;

    green();
    printf("Enter Book ID: ");
    scanf("%d", &id);

    sprintf(idString, "%03d", id); // convert integer to string and use 3 digits format

    for (int i = 0; i < booksCount; i++)
    {
        // Compare the string versions of the IDs
        if (strcmp(idString, books[i].id) == 0 && books[i].quantity < books[i].maxQuantity)
        {
            books[i].quantity++;
            found = true;
            break;
        }
    }

    // Show result using progressBar
    progressBar("Returning Book...", found ? "Book Returned\n" : "Book Not Found\n", 10);
    Sleep(1000);
}
char *GenerateBookID()
{
    static char newid[100];
    int lastNum = 0;

    // algorithm explained in README.md
    if (booksCount > 0) // if the array is not empty
    {
        for (int i = 0; i < 3; i++) // get the last 3 digits of the id
        {
            //
            lastNum = lastNum * 10 + (books[booksCount - 1].id[i] - '0');
        }
    }
    else // if the array is empty
    {
        red();
        printf("No books found. Please add a book first.\n");
        return NULL;
    }

    lastNum++;

    // add '0' to convert int to char
    // this algorithm explained in README.md
    newid[0] = '0' + (lastNum / 100 % 10);
    newid[1] = '0' + (lastNum / 10 % 10);
    newid[2] = '0' + (lastNum % 10);
    return newid;
}
void readBooks()
{
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) // Correct the condition
    {
        red();
        printf("Error Opening File for Reading\n");
        return;
    }

    Book book; // Temporary struct to hold each task read
    while (fscanf(file, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d\n",
                  book.id,
                  book.title,
                  book.author,
                  &book.quantity,
                  &book.maxQuantity) != EOF) // eof is end of file
    {
        if (booksCount < 100)
        {
            books[booksCount++] = book;
        }
    }
}

void InitializeBooks()
{
    FILE *file = fopen("books.txt", "w"); // Create or overwrite the file
    if (file == NULL)
    {
        red();
        printf("Error Opening File\n");
        return;
    }
    for (int i = 0; i < booksCount; i++)
    {
        // Write each book to the file, separating fields with tabs
        fprintf(file, "%s\t%s\t%s\t%d\t%d\n",
                books[i].id,
                books[i].title,
                books[i].author,
                books[i].quantity,
                books[i].maxQuantity);
    }
    fclose(file);
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
    clearScreen();
    progressBar("You data is being saved", "You data is saved successfully", 10);
    printf("\nThank you for using our library management system");
    InitializeBooks();
    Sleep(300);
    reset();
    exit(0);
}

void progressBar(char messageBefore[1000], char messageAfter[1000], int sleepTime)
{
    yellow();
    int i = 0;
    while (i <= 100)
    {
        printf("\r%s %d%%", messageBefore, i);
        Sleep(sleepTime);
        i++;
    }
    printf("\n%s\n", messageAfter);
}

void welcome()
{
    blue();
    printf("====================================\n");
    printf("Welcome to the Library Management System\n");
    printf("====================================\n");
    Sleep(1000);
}

#pragma endregion

#pragma region Coloring

void red()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void green()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

void blue()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

void yellow()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
}

void reset()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#pragma endregion

#pragma region Main Functions
void mainfunction()
{

    clearScreen();
    readBooks();
    welcome();

    int choice;
    do
    {
        blue();
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
            Sleep(100);
            printf("%s\n", choices[i]);
        }

        green();
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
#pragma endregion

// this is the version 1 of the library manager
// alot of problems were encountered in this project but i solved them in this version
// i don't think this program will be fine for any OS else than windows
