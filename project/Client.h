#ifndef CLIENT_H
#define CLIENT_H

struct Client {
    int id;
    char name[40];
    int age;
    double salary;
};
 void addClient();
    void readClients();
    void updateClient();
    void deleteClient();

#endif // CLIENT_H
