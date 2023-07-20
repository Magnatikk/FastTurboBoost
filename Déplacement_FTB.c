#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LONGUEUR_TRAIN 20
#define LONGUEUR_VOITURE 4

int main() {
    int position_train = 0;
    int position_voiture = -LONGUEUR_VOITURE;

    while (1) {
        // Effacer la console pour une animation fluide
        system("clear"); // Pour Linux/macOS
        //system("cls"); // Pour Windows

        // Afficher le train et la voiture
        for (int i = 0; i < LONGUEUR_TRAIN; i++) {
            if (i == position_train) {
                printf("=");
            } else {
                printf(" ");
            }
        }

        printf("\n");

        for (int i = 0; i < LONGUEUR_TRAIN; i++) {
            if (i == position_voiture) {
                printf("-");
            } else {
                printf(" ");
            }
        }

        printf("\n");

        // Faire avancer le train et la voiture
        position_train++;
        position_voiture++;

        // Vérifier si la voiture a dépassé le train
        if (position_voiture > LONGUEUR_TRAIN) {
            position_voiture = -LONGUEUR_VOITURE;
        }

        // Attendre un court instant pour l'animation
        usleep(100000); // 100 ms
    }

    return 0;
}
