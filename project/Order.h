#ifndef ORDER_H
#define ORDER_H

#include "Book.h"
#include "Client.h"
#include <vector>

struct OrderDetail {
    Book book;
    int quantity;
    double subtotal; // prix * quantité
};

struct Order {
    int id;
    Client client;
    std::vector<OrderDetail> details;
    double total; // Somme des subtotaux
};

#endif // ORDER_H
