#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Structure for Student
struct Student {
    int id;
    string name;
    int status; // 0 - scholarship, 1 - contract
    int mathScore, physicsScore, programmingScore;
    double averageScore;
};

// Structure for Client
struct Client {
    int id;
    string name;
    int age;
    char gender; // M or F
    string address;
    double income;
};

// Global client list
vector<Client> clients;

// Function prototypes
void manageStudents();
void manageClients();
void manageOrders();

// Utility functions
bool compareByName(const Student &a, const Student &b) {
    return a.name < b.name;
}

bool compareByAverageDescending(const Student &a, const Student &b) {
    return a.averageScore > b.averageScore;
}

// Student Management
void manageStudents() {
    vector<Student> students;
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    students.resize(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].id = i + 1;
        cout << "Name: ";
        cin >> ws;
        getline(cin, students[i].name);
        cout << "Status (0 - Scholarship, 1 - Contract): ";
        cin >> students[i].status;
        cout << "Math score: ";
        cin >> students[i].mathScore;
        cout << "Physics score: ";
        cin >> students[i].physicsScore;
        cout << "Programming score: ";
        cin >> students[i].programmingScore;

        students[i].averageScore = (students[i].mathScore + students[i].physicsScore + students[i].programmingScore) / 3.0;
    }

    // Sort alphabetically
    sort(students.begin(), students.end(), compareByName);
    cout << "\nStudents sorted alphabetically:\n";
    for (const auto &student : students) {
        cout << student.name << endl;
    }

    // Top 3 students by average score
    sort(students.begin(), students.end(), compareByAverageDescending);
    cout << "\nTop 3 students by average score:\n";
    for (int i = 0; i < min(3, n); ++i) {
        cout << students[i].name << " - Average: " << students[i].averageScore << endl;
    }
}

// Client Management
void manageClients() {
    int choice;
    do {
        cout << "\nClient Management:\n1. Add Client\n2. List Clients\n3. Search Client by Name\n4. Sort Clients Alphabetically\n5. Update Client\n6. Delete Client\n7. Show Client with Highest Income\n0. Back to Main Menu\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Client newClient;
                newClient.id = clients.size() + 1;
                cout << "Enter name: ";
                cin >> ws;
                getline(cin, newClient.name);
                cout << "Enter age: ";
                cin >> newClient.age;
                cout << "Enter gender (M/F): ";
                cin >> newClient.gender;
                cout << "Enter address: ";
                cin >> ws;
                getline(cin, newClient.address);
                do {
                    cout << "Enter income (100000 - 500000): ";
                    cin >> newClient.income;
                } while (newClient.income < 100000 || newClient.income > 500000);
                clients.push_back(newClient);
                cout << "Client added successfully.\n";
                break;
            }
            case 2: {
                cout << "\nClient List:\n";
                for (const auto &client : clients) {
                    cout << "ID: " << client.id << ", Name: " << client.name << ", Income: " << client.income << endl;
                }
                break;
            }
            case 3: {
                string searchName;
                cout << "Enter name to search: ";
                cin >> ws;
                getline(cin, searchName);
                for (const auto &client : clients) {
                    if (client.name == searchName) {
                        cout << "ID: " << client.id << ", Name: " << client.name << ", Income: " << client.income << endl;
                    }
                }
                break;
            }
            case 4: {
                sort(clients.begin(), clients.end(), [](const Client &a, const Client &b) {
                    return a.name < b.name;
                });
                cout << "Clients sorted alphabetically.\n";
                break;
            }
            case 5: {
                int id;
                cout << "Enter client ID to update: ";
                cin >> id;
                for (auto &client : clients) {
                    if (client.id == id) {
                        cout << "Update name: ";
                        cin >> ws;
                        getline(cin, client.name);
                        cout << "Update age: ";
                        cin >> client.age;
                        cout << "Update gender (M/F): ";
                        cin >> client.gender;
                        cout << "Update address: ";
                        cin >> ws;
                        getline(cin, client.address);
                        do {
                            cout << "Update income (100000 - 500000): ";
                            cin >> client.income;
                        } while (client.income < 100000 || client.income > 500000);
                        cout << "Client updated successfully.\n";
                    }
                }
                break;
            }
            case 6: {
                int id;
                cout << "Enter client ID to delete: ";
                cin >> id;
                clients.erase(remove_if(clients.begin(), clients.end(), [&](const Client &c) { return c.id == id; }), clients.end());
                cout << "Client deleted successfully.\n";
                break;
            }
            case 7: {
                auto maxIncomeClient = max_element(clients.begin(), clients.end(), [](const Client &a, const Client &b) {
                    return a.income < b.income;
                });
                if (maxIncomeClient != clients.end()) {
                    cout << "Client with highest income: \nID: " << maxIncomeClient->id << ", Name: " << maxIncomeClient->name << ", Income: " << maxIncomeClient->income << endl;
                }
                break;
            }
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        cout << "\nMain Menu:\n1. Manage Students\n2. Manage Clients\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manageStudents();
                break;
            case 2:
                manageClients();
                break;
        }
    } while (choice != 0);

    return 0;
}
