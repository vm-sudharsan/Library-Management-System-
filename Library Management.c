#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    int author;
    float price;
};

void addBook(struct Book library[], int *numBook) {
    if (*numBook < 10) {
        printf("Enter book title: ");
        scanf("%99s", library[*numBook].title);

        printf("Enter author ID: ");
        scanf("%d", &library[*numBook].author);

        printf("Enter price: ");
        scanf("%f", &library[*numBook].price);

        (*numBook)++;
        printf("Book added successfully!\n");
    } else {
        printf("Maximum number of books reached.\n");
    }
}

void displayAllBooks(struct Book library[], int numBook) {
    if (numBook > 0) {
        printf("Book Information:\n");
        for (int i = 0; i < numBook; ++i) {
            printf("Title: %s\nAuthor ID: %d\nPrice: %.2f\n", library[i].title, library[i].author, library[i].price);
            printf("_\n");
        }
    } else {
        printf("No books in the library.\n");
    }
}

void displayBooksOfAuthor(struct Book library[], int numBook, int searchAuthor) {
    int found = 0;
    printf("Books by Author ID %d:\n", searchAuthor);
    for (int i = 0; i < numBook; ++i) {
        if (library[i].author == searchAuthor) {
            printf("Title: %s\nPrice: %.2f\n", library[i].title, library[i].price);
            printf("_\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found for Author ID %d.\n", searchAuthor);
    }
}

void displayTotalBooks(int numBook) {
    printf("Total number of books in the library: %d\n", numBook);
}

int main() {
    struct Book library[10];
    int numBook = 0;
    int choice, searchAuthor;

    do {
        printf("\n1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Display Books of Specific Author\n");
        printf("4. Display Total Number of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid option.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &numBook);
                break;
            case 2:
                displayAllBooks(library, numBook);
                break;
            case 3:
                if (numBook > 0) {
                    printf("Enter Author ID to display books: ");
                    if (scanf("%d", &searchAuthor) != 1) {
                        while (getchar() != '\n');
                        printf("Invalid input. Please enter a valid Author ID.\n");
                        continue;
                    }
                    displayBooksOfAuthor(library, numBook, searchAuthor);
                } else {
                    printf("No books are found to display. Add books first.\n");
                }
                break;
            case 4:
                displayTotalBooks(numBook);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
