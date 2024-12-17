#include "client.h"
#include <cstdio>
#include <cstring>

void updateClient() {
    int codeToUpdate;
    printf("Entrez le code du client à mettre à jour : ");
    scanf("%d", &codeToUpdate);

    FILE *inFile = fopen("data/client.txt", "r");
    if (!inFile) {
        printf("Erreur : fichier introuvable.\n");
        return;
    }

    FILE *tempFile = fopen("data/temp_client.txt", "w");
    if (!tempFile) {
        printf("Erreur : impossible de créer un fichier temporaire.\n");
        fclose(inFile);
        return;
    }

    Client client;
    bool found = false;
    while (fscanf(inFile, "%d;%40[^;];%d;%lf\n", &client.id, client.name, 
                  &client.age, &client.salary) != EOF) {
        if (client.id == codeToUpdate) {
            found = true;
            printf("Client trouvé : %s. Entrez les nouvelles informations.\n", client.name);
            printf("Nouveau nom : ");
            scanf(" %[^\n]s", client.name);
            printf("Nouvel âge : ");
            scanf("%d", &client.age);
            printf("Nouveau salaire : ");
            scanf("%lf", &client.salary);
        }
        fprintf(tempFile, "%d;%s;%d;%.2lf\n", client.id, client.name, client.age, client.salary);
    }

    fclose(inFile);
    fclose(tempFile);

    if (found) {
        remove("data/client.txt");
        rename("data/temp_client.txt", "data/client.txt");
        printf("Mise à jour réussie !\n");
    } else {
        remove("data/temp_client.txt");
        printf("Client introuvable.\n");
    }
}
#include "client.h"
#include <cstdio>
#include <cstring>

void deleteClient() {
    int codeToDelete;
    printf("Entrez le code du client à supprimer : ");
    scanf("%d", &codeToDelete);

    FILE *inFile = fopen("data/client.txt", "r");
    if (!inFile) {
        printf("Erreur : fichier client.txt introuvable.\n");
        return;
    }

    FILE *tempFile = fopen("data/temp_client.txt", "w");
    if (!tempFile) {
        printf("Erreur : impossible de créer un fichier temporaire.\n");
        fclose(inFile);
        return;
    }

    Client client;
    bool found = false;

    // read file client.txt ligne par ligne read file ligne by ligne
    while (fscanf(inFile, "%d;%40[^;];%d;%lf\n", &client.id, client.name, &client.age, &client.salary) != EOF) {
        if (client.id == codeToDelete) {
            found = true;  // client found , dont write it agin in tamporories file
            printf("Client supprimé : %s (Code %d).\n", client.name, client.id);
        } else {
            //  writing in temperory file for those  client we want to conserve
            fprintf(tempFile, "%d;%s;%d;%.2lf\n", client.id, client.name, client.age, client.salary);
        }
    }

    fclose(inFile);
    fclose(tempFile);

    
    if (found) {
        remove("data/client.txt");                
        rename("data/temp_client.txt", "data/client.txt");  
        printf("Client supprimé avec succès !\n");
    } else {
        remove("data/temp_client.txt"); 
        printf("Client introuvable.\n");
    }
}

