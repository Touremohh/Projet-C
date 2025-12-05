#include "parking.h"

Voiture *ajouter_voiture(Voiture *head) {
    static int next_id = 1;

    Voiture *v = malloc(sizeof(Voiture));
    if (!v) { perror("malloc"); exit(1); }

    v->id = next_id++;
    v->x = 3;
    v->y = 5;
    v->vitesse = 1;
    v->direction = 'S';
    v->next = head;
    return v;
}

void deplacer_voitures(Voiture *head) {
    while (head) {
        head->y += head->vitesse;
        head = head->next;
    }
}
