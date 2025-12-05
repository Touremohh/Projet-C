#include "parking.h"

char plan[200][300];       // stockage du plan ASCII
int occupe[200][300];      // tableau logique pour les collisions
int lignes = 0;
int colonnes = 0;

/* On charge le plan/*

void charger_plan(const char *fichier) {
    FILE *f = fopen(fichier, "r");
    if (!f) {
        perror("Erreur ouverture plan");
        exit(1);
    }

    char buffer[300];
    while (fgets(buffer, sizeof(buffer), f)) {
        strcpy(plan[lignes], buffer);

        // enregistrer la longueur max d’une ligne
        int len = strlen(buffer);
        if (len > colonnes) colonnes = len;

        lignes++;
    }
    fclose(f);

    // Initialiser la matrice des collisions
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (plan[i][j] == ' ' || plan[i][j] == '[' || plan[i][j] == ']')
                occupe[i][j] = 0; // libre
            else
                occupe[i][j] = 1; // murailles, texte, obstacles
        }
    }
}

/*----------------------------------------------------------
 * On affiche le plan
 *----------------------------------------------------------*/
void afficher_plan() {
    for (int i = 0; i < lignes; i++)
        printf("%s", plan[i]);
}

int case_libre(int x, int y) {
    if (x < 0 || y < 0 || x >= lignes || y >= colonnes)
        return 0; // hors limites → bloqué
    return (occupe[x][y] == 0);
}


void occuper_case(int x, int y) {
    occupe[x][y] = 1;
}


void liberer_case(int x, int y) {
    occupe[x][y] = 0;
}
