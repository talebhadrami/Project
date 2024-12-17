#include "LibrarySysteme.h"
#include "LibrarySystemes.cpp"
#include "Book.h"
#include "Client.h"
#include "Order.h"



#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// int main() {
//     LibrarySystem librarySystem;
//     int choice;

//     do {
//         cout << "\nLibrary System Menu:\n";
//         cout << "1. Add Book\n";
//         cout << "2. View Books\n";
//         cout << "3. Update Book\n";
//         cout << "4. Delete Book\n";
//         cout << "5. Add Client\n";
//         cout << "6. View Clients\n";
//         cout << "7. Update Client\n";
//         cout << "8. Delete Client\n";
//         cout << "9. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 librarySystem.addBook();
//                 break;
//             case 2:
//                 librarySystem.readBooks();
//                 break;
//             case 3:
//                 librarySystem.updateBook();
//                 break;
//             case 4:
//                 librarySystem.deleteBook();
//                 break;
//             case 5:
//                 librarySystem.addClient();
//                 break;
//             case 6:
//                 librarySystem.readClients();
//                 break;
//             case 7:
//                 librarySystem.updateClient();
//                 break;
//             case 8:
//                 librarySystem.deleteClient();
//                 break;
//             case 9:
//                 cout << "Exiting program.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 9);

//     return 0;
// }

int main(){
LibrarySystem librarySystem;
 int choice;


do {
    cout << "\nLibrary System Menu:\n";
    cout << "1. Add Book\n";
    cout << "2. View Books\n";
    cout << "3. Update Book\n";
    cout << "4. Delete Book\n";
    cout << "5. Add Client\n";
    cout << "6. View Clients\n";
    cout << "7. Update Client\n";
    cout << "8. Delete Client\n";
    cout << "9. Add Order\n";
    cout << "10. View Orders\n";
    cout << "11. Delete Order\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            librarySystem.addBook();
            break;
        case 2:
            librarySystem.readBooks();
            break;
        case 3:
            librarySystem.updateBook();
            break;
        case 4:
            librarySystem.deleteBook();
            break;
        case 5:
            librarySystem.addClient();
            break;
        case 6:
            librarySystem.readClients();
            break;
        case 7:
            librarySystem.updateClient();
            break;
        case 8:
            librarySystem.deleteClient();
            break;
        case 9:
            librarySystem.addOrder();
            break;
        case 10:
            librarySystem.readOrders();
            break;
        case 11:
            librarySystem.deleteOrder();
            break;
        case 12:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
} while (choice != 12);

return 0;
}