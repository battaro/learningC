# Library Manager

This project is a simple **Library Management System** that allows users to manage books within a library. It includes functionalities to add, delete, borrow, and return books, and maintains a record of these operations using a text file database.

Through this project, I gained valuable experience in **file management** and developed a deeper understanding of algorithms, particularly in the context of generating unique book IDs.

## Features

- Add new books to the library
- Delete books from the library
- Borrow books
- Return books
- Track book quantities and availability status
- Store and retrieve library data from a file-based database `(books.txt)`

## Important Notes

- The books.txt file is a database for the library, first column for _'ID'_ then _'Title'_, _'Author'_, _'Quantity'_, _'Status'_
- **IF** you want to make your own library you should follow this **Conditions** :
- **First** be sure that you are creating a txt file with named books so the full name will be `books.txt`
- **Second** be sure that you are separating between each element and other with tabs, not 4 spaces, you can do this by editing on notpad++ original edition without editing the preferences or by changing the tab formatting in vs code's text editor like this :
- ![alt text](Images//image.png)
- **Third** be sure that you are in the limit on the number of books in the original code, the maximum number of books was 100.
- **Last Thing** don't follow these conditions if you already edited `LibraryManager.c`

## Algorithms Used

### ID Generation Algorithm

- So this is the first algorithm used here :

```c
	//This is just an example.
 	char id[100] = "007";
    int lastNum = 0;

    for (int i = 0; i < 3; i++)
    {
        lastNum = lastNum * 10 + (id[i] - '0');
    }

    lastNum++;
	return lastNum;
```

this code will return the last number and ignore all zeros but how? lets go into the loop and see each loop what exactly do :

```
10 * 0 + 0,
10 * 0 + 0,
10 * 0 + 7,
++ add more number to get the newID
= 8 so the lastnumber will be 8
```

so what happened here that we skipped all zeros and added 1 to the last number to get the new id which is `8`. But how we can return this into `008` not only integer `8`

- We should use the next algorithm in ID generation which is this :

```c
	//This is just an example.
 	id[0] = '0' + (lastNum / 100 % 10);
    id[1] = '0' + (lastNum / 10 % 10);
    id[2] = '0' + (lastNum % 10);

    return id;
```

this code will return the real `ID` which should be in this example `008` but how? lets see this simple explaining :

```
8 / 100 =  0.08, ignore decimal will be 0, then % 10 = 0 and we use '0' to make it string so the first digit will be "0"
8 / 10 = 0.8, ignore decimal will be 0, then % 10 = 0 and we use '0' to make it string so the second digit will be "0"
8 % 10 = 8, no decimal to ignore so its still 8, then % 10 = 8 and also we use '0' to make it string so the third digit will be "8"
so the full id will be 008
```

this algorithm should work for all numbers between 000 and 100.

### Searching Algorithm

- I wanted to use [Binary Search](https://www.geeksforgeeks.org/binary-search/) for `SearchBook` function but i used [Linear Search](https://www.geeksforgeeks.org/linear-search/) instead, because linear searching logic is more efficient for this project after thinking.
- Its simple and i clarified how i make it in code using [strstr()](https://www.geeksforgeeks.org/strstr-in-ccpp/) function.
- I also used a function call `toLowerCase()` to change the title and the author's name to lowercase using [tolower()](https://www.geeksforgeeks.org/tolower-function-in-c/) function, to implement the searching in lowercase.

## Conclusion

- This is the best project i made in the `C` language for now and i will improve my skills to be better int he next project 💪 Inshallah.
