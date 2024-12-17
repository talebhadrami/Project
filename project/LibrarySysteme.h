#ifndef LIBRARY_SYSTEME_H
#define LIBRARY_SYSTEME_H

#include "Book.h"
#include "Client.h"
#include "Order.h"
#include <vector>

class LibrarySystem {
private:
    std::vector<Book> books;
    std::vector<Client> clients;
    std::vector<Order> orders;
    int bookCounter = 0;
    int clientCounter = 0;
    int orderCounter = 0;

    void saveBooks();
    void saveClients();
    void saveOrders();

public: 
    void addBook();
    void readBooks();
    void updateBook();
    void deleteBook();
    void sortBooks();
    void searcheBooks();

    void addClient();
    void readClients();
    void updateClient();
    void deleteClient();

    void addOrder();
    void readOrders();
    void  deleteOrder();
    void updateOrder();

   
    
};

#endif // LIBRARY_SYSTEM_H
