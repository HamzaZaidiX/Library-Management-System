#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAXNUM 100
#define MAXLENGTH 50

int num, i;
FILE *ptr = NULL;

// Structure for members
struct member {
    char memberName[MAXLENGTH];
    int memberID;
} membersList[MAXNUM];

// Structure for books
struct books {
    char bookName[MAXLENGTH];
    char authorName[MAXLENGTH];
    int day, month, year;
} booksList[MAXNUM];

// Register new members
void registerMembers() {
    printf("Enter Number of Members to register: ");
    scanf("%d", &num);

    ptr = fopen("members.txt", "a");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Enter Member Name: ");
        scanf("%s", membersList[i].memberName);
        printf("Enter Member Id: ");
        scanf("%d", &membersList[i].memberID);
        printf("Member Name: %s, Member Id: %d is successfully registered.\n", membersList[i].memberName, membersList[i].memberID);
        fprintf(ptr, "%d. Member Name: %s, Member Id: %d.\n", i + 1, membersList[i].memberName, membersList[i].memberID);
    }
    fclose(ptr);

    printf("Members successfully registered. Press any key to continue...");
    _getch();  // Wait for a key press
}

// View registered members
void registeredMembers() {
    char line[256];

    ptr = fopen("members.txt", "r");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    printf("\nRegistered Members:\n");
    while (fgets(line, sizeof(line), ptr)) {
        printf("%s", line);
    }
    fclose(ptr);

    printf("Press any key to continue...");
    _getch();  // Wait for a key press
}

// Search members
void searchMembers() {
    char searchTerm[MAXLENGTH];
    char line[256];
    int found = 0;

    printf("Enter Member Name or ID to Search: ");
    scanf("%s", searchTerm);

    ptr = fopen("members.txt", "r");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, searchTerm) != NULL) {
            printf("Found: %s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No member found with the term: %s\n", searchTerm);
    }

    fclose(ptr);
    printf("Press any key to continue...");
    _getch();  // Wait for a key press
}

// Register new books
void registerBooks() {
    printf("Enter Number of Books to Register: ");
    scanf("%d", &num);

    ptr = fopen("books.txt", "a");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Enter Name of Book %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Enter Author Name: ");
        scanf("%s", booksList[i].authorName);
        printf("Enter Published Date (day month year): ");
        scanf("%d %d %d", &booksList[i].day, &booksList[i].month, &booksList[i].year);
        printf("Book Name: %s\n", booksList[i].bookName);
        printf("Author Name: %s\n", booksList[i].authorName);
        printf("Published Date: %d-%d-%d\n", booksList[i].day, booksList[i].month, booksList[i].year);

        fprintf(ptr, "%d. Book Name: %s, Author: %s, Published Date: %d-%d-%d\n", i + 1, booksList[i].bookName, booksList[i].authorName, booksList[i].day, booksList[i].month, booksList[i].year);
    }

    fclose(ptr);
    printf("Books successfully registered. Press any key to continue...");
    _getch();  // Wait for a key press
}

// Checkout books
void checkoutBooks() {
    printf("Enter Number of Books to Checkout: ");
    scanf("%d", &num);

    ptr = fopen("checkoutBooks.txt", "a");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Enter Name of Book %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Enter Author Name: ");
        scanf("%s", booksList[i].authorName);
        printf("%s Book Checkout Successfully.\n", booksList[i].bookName);
        printf("Author Name: %s\n", booksList[i].authorName);

        fprintf(ptr, "Book Name: %s, Author: %s (Checked Out)\n", booksList[i].bookName, booksList[i].authorName);
    }

    fclose(ptr);
    printf("Books successfully checked out. Press any key to continue...");
    _getch();  // Wait for a key press
}

// Return books
void returnBooks() {
    printf("Enter Number of Books to Return: ");
    scanf("%d", &num);

    ptr = fopen("returnBooks.txt", "a");
    if (ptr == NULL) {
        perror("Error opening file.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Enter Name of Book %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Enter Author Name: ");
        scanf("%s", booksList[i].authorName);
        printf("%s Book Returned Successfully.\n", booksList[i].bookName);
        printf("Author Name: %s\n", booksList[i].authorName);

        fprintf(ptr, "Book Name: %s, Author: %s (Returned)\n", booksList[i].bookName, booksList[i].authorName);
    }

    fclose(ptr);
    printf("Books successfully returned. Press any key to continue...");
    _getch();  // Wait for a key press
}

// Main menu function
int main() {

    int choice = 1;  // Initialize choice

    while (choice != 0) {  // Adding an exit condition
        system("cls");  // Clears the screen (works in Dev C++)

        printf("\nLibrary Management System\n");
        printf("1. Register New Members\n");
        printf("2. View Registered Members\n");
        printf("3. Search Members\n");
        printf("4. Register New Books\n");
        printf("5. Checkout Books\n");
        printf("6. Return Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerMembers();
                break;
            case 2:
                registeredMembers();
                break;
            case 3:
                searchMembers();
                break;
            case 4:
                registerBooks();
                break;
            case 5:
                checkoutBooks();
                break;
            case 6:
                returnBooks();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice. Press any key to continue...\n");
                _getch();
                break;
        }
    }

    return 0;
}

