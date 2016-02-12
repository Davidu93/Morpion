#include "morpion.h"
#include <stdio.h>

morpion_t creer_partie()
{
  morpion_t res;
  int i , j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      res.plateau[i][j] = VIDE;
    }
    res.joueur = ROND;
  }
  return res;
}

void afficher_plateau(morpion_t m)
{
  int i , j;
  for(i=0;i<3;i++)
  {
    printf("\t -------\n");
    printf("\t |");
    for(j=0;j<3;j++)
    {
      if(m.plateau[i][j] == ROND)
        printf("O|");
      else if(m.plateau[i][j] == CROIX)
        printf("X|");
      else
        printf(" |");
    }
    printf("\n");
  }
  printf("\t ------- \n");
}

void changer_joueur(morpion_t * m)
{
  m->joueur = (m->joueur + 1) % 2;
}

int saisie_coup()
{
  int res = -1;
  while(res<0||res>2)
  {
    printf("Entrer une valeur entre 0 et 2 : ");
    scanf("%d",&res);
  }
  return res;
}

int game_over(morpion_t m)
{
  int res = VIDE;
  /* Première ligne */
  if(m.plateau[0][0] == m.joueur && m.plateau[0][1] == m.joueur && m.plateau[0][2] == m.joueur)
    res = m.joueur;
  /* Deuxième ligne */
  if(m.plateau[1][0] == m.joueur && m.plateau[1][1] == m.joueur && m.plateau[1][2] == m.joueur)
    res = m.joueur;
    /* Troisième ligne */
  if(m.plateau[2][0] == m.joueur && m.plateau[2][1] == m.joueur && m.plateau[2][2] == m.joueur)
    res = m.joueur;
    /* Première colonne */
  if(m.plateau[0][0] == m.joueur && m.plateau[1][0] == m.joueur && m.plateau[2][0] == m.joueur)
    res = m.joueur;
    /* Deuxième colonne */
  if(m.plateau[0][1] == m.joueur && m.plateau[1][1] == m.joueur && m.plateau[2][1] == m.joueur)
    res = m.joueur;
    /* Troisième colonne */
  if(m.plateau[0][2] == m.joueur && m.plateau[1][2] == m.joueur && m.plateau[2][2] == m.joueur)
    res = m.joueur;
    /* Première diagonale */
  if(m.plateau[0][0] == m.joueur && m.plateau[1][1] == m.joueur && m.plateau[2][2] == m.joueur)
    res = m.joueur;
    /* Deuxième diagonale */
  if(m.plateau[2][0] == m.joueur && m.plateau[1][1] == m.joueur && m.plateau[0][2] == m.joueur)
    res = m.joueur;
  return res;
}

int tour(morpion_t * m)
{
  int ligne , colonne;
  do{
    if(m->joueur == ROND)
      printf("JOUEUR ROND\n");
    else
      printf("JOUEUR CROIX\n");
    printf("Entrer l'indice de la ligne\n");
    ligne = saisie_coup();
    printf("Entrer l'indice de la colonne\n");
    colonne = saisie_coup();
  }while(m->plateau[ligne][colonne] != VIDE);
  m->plateau[ligne][colonne] = m->joueur;
  return game_over(*m);
}
