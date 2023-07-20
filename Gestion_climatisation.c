#include <stdio.h>

int main() {
    int temperature;

    printf("Choisissez la température entre 12 et 25 degrés : ");
    scanf("%d", &temperature);

    // Vérifier si la température est dans la plage valide (12 <= température <= 25)
    if (temperature >= 12 && temperature <= 25) {
        printf("Vous avez choisi %d degrés. Bonne température !\n", temperature);
    } else {
        printf("Température invalide. Veuillez choisir une température entre 12 et 25 degrés.\n");
    }

    return 0;
}
