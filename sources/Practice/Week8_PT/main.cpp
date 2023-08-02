#include "source.h"

int main() {
    book* bookstore = nullptr;

    while (true) {
        int choice;
        cout << "Menu:\n";
        cout << "1. Insert a book\n";
        cout << "2. Sell a book\n";
        cout << "3. Search for a book\n";
        cout << "4. Remove all books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertBook(bookstore);
                break;
            case 2:
                sellaBook(bookstore);
                break;
            case 3:
                searchBook(bookstore);
                break;
            case 4:
                removeAllBook(bookstore);
                break;
            case 5:
                removeAllBook(bookstore);
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }



    return 0;
}