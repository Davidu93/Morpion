#ifndef _MORPION_H
#define _MORPION_H

#define ROND 0
#define CROIX 1
#define VIDE 2

typedef struct{
  int plateau[3][3];
  int joueur;
}morpion_t;

morpion_t creer_partie();
void afficher_plateau(morpion_t m);
void changer_joueur(morpion_t * m);
int game_over(morpion_t m);
int tour(morpion_t * m);

#endif
