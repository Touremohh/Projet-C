#ifndef STRUCTURE_H
#define STRUCTURE_H

// Voiture
typedef struct voiture {
    int id;
    int x;
    int y;
    int vitesse;
    struct voiture *next;   // liste chaînée
} Voiture;


Voiture *ajouter_voiture(Voiture *head, int id, int x, int y, int vitesse);
Voiture *supprimer_voiture(Voiture *head, int id);
void liberer_voitures(Voiture *head);


// Parking
typedef struct {
    int lignes;
    int colonnes;
    char **grille;       
} Parking;


// 
Parking *creer_parking(int lignes, int colonnes);
void detruire_parking(Parking *p);
void charger_plan(Parking *p, const char *fichier);

#endif
