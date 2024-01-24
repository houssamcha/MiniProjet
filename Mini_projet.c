#include <stdio.h>
#include <stdlib.h>
void add(int Q, int code, int T[][2], int *taille) {
    int produitExiste = 0;

    for (int i = 0; i < *taille; i++) {
        if (code == T[i][0]) {
            T[i][1] += Q;
            produitExiste = 1;
            break;
        }
    }

    if (produitExiste != 1) {
        T[*taille][0] = code;
        T[*taille][1] = Q;
        *taille++;
    }
}
void removeProduct(int Q, int code, int T[][2], int *taille) {
    int produitExiste = 0;

    for (int i = 0; i < *taille; i++) {
        if (code == T[i][0]) {
            if (Q <= T[i][1]) {
                T[i][1] -= Q;
                produitExiste = 1;
            } else {
                printf("Erreur : La quantite a retirer est superieure a la quantite en stock.\n");
            }
            break;
        }
    }
    if (!produitExiste) {
        printf("Erreur : Le produit avec le code %d n'existe pas.\n", code);
    }
}

void displayStock(int T[][2], int taille) {
    printf("Le tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Produit %d : Quantite %d\n", T[i][0], T[i][1]);
    }
}

int main() {
    int stock[3][2] = {{2109,45}, {2222,13}, {0510,10}};
    int code, qua, taille = 3;
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un produit\n");
        printf("2. Retirer un produit\n");
        printf("3. Afficher le stock\n");
        printf("4. Quitter\n");

        printf("Choix : ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':

                printf("Entrer le code du produit : ");
                scanf("%d", &code);
                printf("Entrer la quantite du produit : ");
                scanf("%d", &qua);
                add(qua, code, stock, &taille);
                break;
            case '2':
                
                printf("Entrer le code du produit : ");
                scanf("%d", &code);
                printf("Entrer la quantite du produit a retirer : ");
                scanf("%d", &qua);
                removeProduct(qua, code, stock, &taille);
                break;
            case '3':

                displayStock(stock, taille);
                break;
            case '4':
 
                printf("Au revoir!\n");
                break;
            default:

                printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choice != '4');

    return 0;
}