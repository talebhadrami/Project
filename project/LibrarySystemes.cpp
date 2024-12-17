
#include "LibrarySysteme.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void LibrarySystem::saveBooks() {
    FILE* file = fopen("data/book.txt", "w"); // Remplace le contenu existant
    if (!file) {
        cerr << "Error: Unable to open book.txt for writing.\n";
        return;
    }
    for (const auto& book : books) {
        fprintf(file, "%d|%s|%s|%d|%.2f|%d|%d\n",
                book.id, book.author, book.title, book.stock, book.price, book.year, static_cast<int>(book.category));
    }
    fclose(file);
}


void LibrarySystem::addBook() {
    Book book;
    book.id = ++bookCounter; // Utiliser le compteur pour générer un ID unique

    cout << "Author: ";
    cin.ignore();
    cin.getline(book.author, 40);

    cout << "Title: ";
    cin.getline(book.title, 40);

    cout << "Stock: ";
    cin >> book.stock;

    do {
        cout << "Enter book's price between 100 and 50000: ";
        cin >> book.price;
        if (book.price < 100 || book.price > 50000) {
            cout << "Error: price must be between 100 and 50000. Please try again.\n";
        }
    } while (book.price < 100 || book.price > 50000);

    do {
        cout << "What is the release year of the book? ";
        cin >> book.year;
        if (book.year < 2000 || book.year > 2024) {
            cout << "Please enter the book's release year between 2000 and 2024.\n";
        }
    } while (book.year < 2000 || book.year > 2024);

    int category;
    cout << "Category (0: Fantasy, 1: Fiction, 2: Romance, 3: History): ";
    cin >> category;
    book.category = static_cast<Category>(category);

    books.push_back(book);
    saveBooks();

    cout << "Book added successfully!\n";
}


void LibrarySystem::readBooks() {
    FILE* file = fopen("data/book.txt", "r");
    if (!file) {
        cerr << "Error: Unable to open book.txt for reading.\n";
        return;
    }

    books.clear();
    Book book;
    int category;

    // Réinitialiser le compteur avant de lire les livres
    bookCounter = 0;

    cout << "\nBooks List:\n";
    cout << "ID | Author            | Title             | Stock | Price   | Year | Category\n";
    cout << "--------------------------------------------------------------------------------\n";

    while (fscanf(file, "%d|%39[^|]|%39[^|]|%d|%lf|%d|%d\n",
                  &book.id, book.author, book.title, &book.stock, &book.price, &book.year, &category) != EOF) {
        book.category = static_cast<Category>(category);
        books.push_back(book);

        // Mettre à jour bookCounter avec l'identifiant maximum
        if (book.id > bookCounter) {
            bookCounter = book.id;
        }

        printf("%2d | %-17s | %-17s | %5d | %7.2f | %4d | %d\n",
               book.id, book.author, book.title, book.stock, book.price, book.year, category);
    }

    fclose(file);
}

void LibrarySystem::saveClients() {
    FILE* file = fopen("data/client.txt", "a");
    if (!file) {
        cerr << "Error: Unable to open client.txt for writing.\n";
        return;
    }
    for (const auto& client : clients) {
        fprintf(file, "%d|%s|%d|%.2f\n",
                client.id, client.name, client.age, client.salary);
    }
    fclose(file);
}

void LibrarySystem::addClient() {
    Client client;
    client.id = ++clientCounter;

    cout << "Name: ";
    cin.ignore();
    cin.getline(client.name, 40);

    cout << "Age: ";
    cin >> client.age;
 do{
 cout<<"enter your salary ";
 cin>>client.salary;
 if(client.salary<20000 || client.salary>500000){
   cout<<" hi rich boy enter salary between [20000,500000]";
 }
 }while(client.salary<20000 || client.salary >500000);
    

    clients.push_back(client);
    saveClients();

    cout << "Client added successfully!\n";
}

void LibrarySystem::readClients() {
    FILE* file = fopen("data/client.txt", "r");
    if (!file) {
        cerr << "Error: Unable to open client.txt for reading.\n";
        return;
    }

    clients.clear();
    Client client;

    cout << "\nClients List:\n";
    cout << "ID | Name             | Age | Salary\n";
    cout << "-------------------------------------\n";

    while (fscanf(file, "%d|%39[^|]|%d|%lf\n",
                  &client.id, client.name, &client.age, &client.salary) != EOF) {
        clients.push_back(client);

        printf("%2d | %-17s | %3d | %.2f\n",
               client.id, client.name, client.age, client.salary);
    }

    fclose(file);
}
void LibrarySystem::updateBook() {
    int bookId;
    cout << "Enter the book ID that you want to update: ";
    cin >> bookId;
    cin.ignore(); // Consomme le '\n' restant

    // Recherche du livre dans le vecteur books
    bool bookFound = false;
    for (auto &book : books) {
        if (book.id == bookId) {
            bookFound = true;
            cout << "The book was found. Update information:\n";

            cout << "New Title: ";
            cin.getline(book.title, 40);

            cout << "New Stock: ";
            cin >> book.stock;

            do {
                cout << "New Price (between 100 and 50000): ";
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

            saveBooks();
            cout << "The book was updated successfully!\n";
            return;
        }
    }

    if (!bookFound) {
        cout << "We didn't find the book.\n";
    }
}


void LibrarySystem::deleteBook(){
    readBooks();
    int bookId;
    cout<<"enter the id of book :";
    cin>>bookId;
   
   auto it=remove_if(books.begin(),books.end(),[bookId]( Book& book){
    return book.id==bookId;
   });
   if(it!=books.end()){
    books.erase(it,books.end());
    saveBooks();
    cout<<"the books was deleted successfuly.\n";
   }else{
    cout<<"we didnt found the books k sajelenia.\n";
   }
}
void LibrarySystem::updateClient() {
    int clientId;
    cout << "Enter the client id that you want to update: ";
    cin >> clientId;
    cin.ignore(); // Consomme le '\n' restant

    // Recherche du client dans le vecteur clients
    for (auto &client : clients) {
        if (client.id == clientId) {
            cout << "Client found. Update the information:\n";
            cout << "New Name: ";
            cin.getline(client.name, 40);
            cout << "New Age: ";
            cin >> client.age;

            do {
                cout << "New Salary (between 20000 and 500000): ";
                cin >> client.salary;
            } while (client.salary < 20000 || client.salary > 500000);

            saveClients();
            cout << "The client was updated successfully!\n";
            return;
        }
    }

    cout << "We didn't find the client.\n";
}

void LibrarySystem::deleteClient() {
    int clientId;
    cout << "Enter the client id to delete: ";
    cin >> clientId;
 

    auto it = remove_if(clients.begin(), clients.end(), [clientId](const Client& client) {
        return client.id == clientId;
    });

    if (it != clients.end()) {
        clients.erase(it, clients.end());
        saveClients();
        cout << "The client was deleted successfully.\n";
    } else {
        cout << "We didn't find the client.\n";
    }
}
///////////////////
void LibrarySystem::addOrder() {
    Order order;
    order.id = ++orderCounter; // ID unique pour chaque commande

    // Sélectionner un client
    cout << "Enter Client ID: ";
    int clientId;
    cin >> clientId;

    auto clientIt = find_if(clients.begin(), clients.end(), [clientId](const Client& c) {
        return c.id == clientId;
    });

    if (clientIt == clients.end()) {
        cout << "Error: Client not found.\n";
        return;
    }
    order.client = *clientIt;

    // Ajouter des livres
    char moreBooks;
    do {
        OrderDetail detail;

        cout << "Enter Book ID: ";
        int bookId;
        cin >> bookId;

        auto bookIt = find_if(books.begin(), books.end(), [bookId](const Book& b) {
            return b.id == bookId;
        });

        if (bookIt == books.end()) {
            cout << "Error: Book not found.\n";
            continue;
        }

        detail.book = *bookIt;

        cout << "Enter Quantity: ";
        cin >> detail.quantity;

        if (detail.quantity > detail.book.stock) {
            cout << "Error: Not enough stock available.\n";
            continue;
        }

        detail.subtotal = detail.book.price * detail.quantity;
        order.details.push_back(detail);
        order.total += detail.subtotal;

        // Réduire le stock
        bookIt->stock -= detail.quantity;

        cout << "Add another book? (y/n): ";
        cin >> moreBooks;

    } while (moreBooks == 'y' || moreBooks == 'Y');

    orders.push_back(order);
    saveOrders();
    saveBooks();

    cout << "Order added successfully!\n";
}
void LibrarySystem::readOrders() {
    if (orders.empty()) {
        cout << "No orders found.\n";
        return;
    }

    cout << "\nOrders List:\n";
    cout << "ID | Client Name     | Total    | Number of Items\n";
    cout << "-----------------------------------------------\n";

    for (const auto& order : orders) {
        cout << order.id << " | " << order.client.name << " | " << order.total << " | " << order.details.size() << "\n";

        for (const auto& detail : order.details) {
            cout << "   - " << detail.book.title << " (x" << detail.quantity << "): " << detail.subtotal << "\n";
        }
    }
}
void LibrarySystem::saveOrders() {
    FILE* file = fopen("data/order.txt", "w");
    if (!file) {
        cerr << "Error: Unable to open order.txt for writing.\n";
        return;
    }

    for (const auto& order : orders) {
        fprintf(file, "%d|%d|%lu|%.2f\n", order.id, order.client.id, order.details.size(), order.total);
        for (const auto& detail : order.details) {
            fprintf(file, "%d|%d|%.2f\n", detail.book.id, detail.quantity, detail.subtotal);
        }
    }

    fclose(file);
}
void LibrarySystem::deleteOrder() {
    readOrders();
    cout << "Enter the Order ID to delete: ";
    int orderId;
    cin >> orderId;

    auto it = find_if(orders.begin(), orders.end(), [orderId](const Order& o) {
        return o.id == orderId;
    });

    if (it != orders.end()) {
        // Restaurer le stock
        for (const auto& detail : it->details) {
            auto bookIt = find_if(books.begin(), books.end(), [&detail](const Book& b) {
                return b.id == detail.book.id;
            });

            if (bookIt != books.end()) {
                bookIt->stock += detail.quantity;
            }
        }

        orders.erase(it);
        saveOrders();
        saveBooks();
        cout << "Order deleted successfully!\n";
    } else {
        cout << "Order not found.\n";
    }
}


