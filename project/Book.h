#ifndef BOOK_H
#define BOOK_H

#include <vector>   // Inclure la bibliothèque vector
#include <string>   // Inclure la bibliothèque string

enum class Category { Fantasy, Fiction, Romance, History };

struct Book {
    int id;
    char author[40];
    char title[40];
    int stock;
    double price;
    int year;
    Category category;
};

// Déclaration des fonctions
void updateBook(std::vector<Book>& books);
void deleteBook(std::vector<Book>& books);
void sortBook(std::vector<Book>& books, const std::string& criterion);
void searchBook(const std::vector<Book>& books, const std::string& criterion, const std::string& value);

#endif // BOOK_H
