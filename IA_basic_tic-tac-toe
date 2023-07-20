#include <stdio.h>

#define SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

// Structure pour représenter un mouvement
typedef struct {
    int row;
    int col;
} Move;

// Fonction pour afficher le plateau de jeu
void afficherPlateau(char plateau[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", plateau[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----------\n");
        }
    }
}

// Fonction pour vérifier si la case est vide
int estCaseVide(char plateau[SIZE][SIZE], int row, int col) {
    return plateau[row][col] == EMPTY;
}

// Fonction pour vérifier si le jeu est terminé
int estFinJeu(char plateau[SIZE][SIZE]) {
    // Vérifier les lignes
    for (int i = 0; i < SIZE; i++) {
        if (plateau[i][0] == plateau[i][1] && plateau[i][1] == plateau[i][2] && plateau[i][0] != EMPTY) {
            return 1;
        }
    }

    // Vérifier les colonnes
    for (int j = 0; j < SIZE; j++) {
        if (plateau[0][j] == plateau[1][j] && plateau[1][j] == plateau[2][j] && plateau[0][j] != EMPTY) {
            return 1;
        }
    }

    // Vérifier les diagonales
    if (plateau[0][0] == plateau[1][1] && plateau[1][1] == plateau[2][2] && plateau[0][0] != EMPTY) {
        return 1;
    }

    if (plateau[0][2] == plateau[1][1] && plateau[1][1] == plateau[2][0] && plateau[0][2] != EMPTY) {
        return 1;
    }

    // Vérifier s'il y a encore des cases vides
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (plateau[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    // Si aucune des conditions n'est remplie, le jeu est un match nul.
    return -1;
}

// Fonction pour évaluer le score du plateau
int evaluerPlateau(char plateau[SIZE][SIZE]) {
    // Vérifier les lignes
    for (int i = 0; i < SIZE; i++) {
        if (plateau[i][0] == plateau[i][1] && plateau[i][1] == plateau[i][2]) {
            if (plateau[i][0] == PLAYER_X) {
                return 10;
            } else if (plateau[i][0] == PLAYER_O) {
                return -10;
            }
        }
    }

    // Vérifier les colonnes
    for (int j = 0; j < SIZE; j++) {
        if (plateau[0][j] == plateau[1][j] && plateau[1][j] == plateau[2][j]) {
            if (plateau[0][j] == PLAYER_X) {
                return 10;
            } else if (plateau[0][j] == PLAYER_O) {
                return -10;
            }
        }
    }

    // Vérifier les diagonales
    if (plateau[0][0] == plateau[1][1] && plateau[1][1] == plateau[2][2]) {
        if (plateau[0][0] == PLAYER_X) {
            return 10;
        } else if (plateau[0][0] == PLAYER_O) {
            return -10;
        }
    }

    if (plateau[0][2] == plateau[1][1] && plateau[1][1] == plateau[2][0]) {
        if (plateau[0][2] == PLAYER_X) {
            return 10;
        } else if (plateau[0][2] == PLAYER_O) {
            return -10;
        }
    }

    // Si aucune des conditions n'est remplie, retourner 0 pour indiquer un match nul
    return 0;
}

// Fonction récursive pour l'algorithme Minimax
int minimax(char plateau[SIZE][SIZE], int profondeur, int isMax) {
    int score = evaluerPlateau(plateau);

    // Cas de base - retourner le score si le jeu est terminé ou la profondeur maximale atteinte
    if (score == 10 || score == -10) {
        return score;
    }

    if (estFinJeu(plateau) == -1) {
        return 0;
    }

    // Maximiser le score si c'est le tour de l'IA (Maximizing player)
    if (isMax) {
        int meilleurScore = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (estCaseVide(plateau, i, j)) {
                    plateau[i][j] = PLAYER_X;
                    int scoreCourant = minimax(plateau, profondeur + 1, 0);
                    plateau[i][j] = EMPTY;
                    meilleurScore = scoreCourant > meilleurScore ? scoreCourant : meilleurScore;
                }
            }
        }
        return meilleurScore;
    }
    // Minimiser le score si c'est le tour du joueur (Minimizing player)
    else {
        int meilleurScore = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (estCaseVide(plateau, i, j)) {
                    plateau[i][j] = PLAYER_O;
                    int scoreCourant = minimax(plateau, profondeur + 1, 1);
                    plateau[i][j] = EMPTY;
                    meilleurScore = scoreCourant < meilleurScore ? scoreCourant : meilleurScore;
                }
            }
        }
        return meilleurScore;
    }
}

// Fonction pour que l'IA choisisse le meilleur mouvement
Move choisirMeilleurCoup(char plateau[SIZE][SIZE]) {
    int meilleurScore = -1000;
    Move meilleurCoup;
    meilleurCoup.row = -1;
    meilleurCoup.col = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (estCaseVide(plateau, i, j)) {
                plateau[i][j] = PLAYER_X;
                int scoreCourant = minimax(plateau, 0, 0);
                plateau[i][j] = EMPTY;

                if (scoreCourant > meilleurScore) {
                    meilleurScore = scoreCourant;
                    meilleurCoup.row = i;
                    meilleurCoup.col = j;
                }
            }
        }
    }

    return meilleurCoup;
}

int main() {
    char plateau[SIZE][SIZE] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };

    int tour = 0;
    Move coup;

    printf("Bienvenue dans le jeu Tic-Tac-Toe (morpion) !\n");
    printf("Vous jouez contre l'IA. Entrez les coordonnées (ligne, colonne) pour jouer.\n");

    while (estFinJeu(plateau) == -1) {
        if (tour % 2 == 0) {
            // Tour du joueur humain
            int row, col;
            printf("Tour du joueur O. Entrez les coordonnées (ligne, colonne) : ");
            scanf("%d %d", &row, &col);
            if (estCaseVide(plateau, row, col)) {
                plateau[row][col] = PLAYER_O;
                tour++;
            } else {
                printf("Case déjà occupée. Réessayez.\n");
            }
        } else {
            // Tour de l'IA
            coup = choisirMeilleurCoup(plateau);
            plateau[coup.row][coup.col] = PLAYER_X;
            tour++;
        }

        afficherPlateau(plateau);
    }

    int resultat = estFinJeu(plateau);
    if (resultat == 0) {
        printf("Match nul !\n");
    } else if (resultat == 1) {
        printf("Le joueur X (IA) a gagné !\n");
    } else {
        printf("Le joueur O (humain) a gagné !\n");
    }

    return 0;
}
