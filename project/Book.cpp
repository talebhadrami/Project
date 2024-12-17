#include "librarySysteme.h"
#include "Book.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Function to update a book
void updateBook(vector<Book>& books) {
    int bookId;
    cout << "Enter the book ID to update: ";
    cin >> bookId;

    for (auto& book : books) {
        if (book.id == bookId) {
            cout << "Book found. Enter new details:\n";

            cout << "New Title: ";
            cin.ignore();
            cin.getline(book.title, 40);

            cout << "New Stock: ";
        cin >> book.stock;

            do {
                cout << "New Price (100-50000): ";
                cin >> book.price;
            } while (book.price < 100 || book.price > 50000);

            do {
                cout << "New Year (2000-2024): ";
                cin >> book.year;
            } while (book.year < 2000 || book.year > 2024);

            int category;
            cout << "New Category (0: Fantasy, 1: Fiction, 2: Romance, 3: History): ";
            cin >> category;
            book.category = static_cast<Category>(category);

            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to delete a book
void deleteBook(vector<Book>& books) {
    int bookId;
    cout << "Enter the book ID to delete: ";
    cin >> bookId;

    auto it = remove_if(books.begin(), books.end(), [bookId](const Book& book) {
        return book.id == bookId;
    });

    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

// Function to sort books
void sortBooks(vector<Book>& books, const string& criterion) {
    if (criterion == "title") {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return strcmp(a.title, b.title) < 0;
        });
    } else if (criterion == "author") {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return std::strcmp(a.author, b.author) < 0;
        });
    } else if (criterion == "price") {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.price < b.price;
        });
    } else if (criterion == "year") {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.year < b.year;
        });
    }
    cout << "Books sorted by " << criterion << ".\n";
}

// Function to search books
void searchBooks(const vector<Book>& books, const string& criterion, const string& value) {
    cout << "Search Results:\n";
    for (const auto& book : books) {
        if ((criterion == "title" && strcmp(book.title, value.c_str()) == 0) ||
            (criterion == "author" && strcmp(book.author, value.c_str()) == 0)) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                      << ", Price: " << book.price << ", Year: " << book.year << "\n";
        }
    }
}
