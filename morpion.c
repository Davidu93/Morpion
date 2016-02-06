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
      res.tab[i][j] = VIDE;
    }
    res.joueur = ROND;
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
      if(m.tab[i][j] == ROND)
        printf("X|");
      else if(m.tab[i][j] == CROIX)
        printf("O|);
      else
        printf(" |");
    }
  printf("\n");
  }
printf("\t ------- \n);
}

void changer_joueur(morpion_t * m)
{
  m->joueur = (m->joueur + 1) % 2;
}

int saisie_coup()
{
  int res = 1;
  while(res<0||res>2)
  {
    printf("Entrer une valeur entre 0 et 2 : ");
    scanf("%d",&res);
  }
  return res;
}

int tour(morpion_t * m)
{
  int ligne , colonne;
  do{
    printf("Entrer l'indice de la ligne : ");
    ligne = saisie_coup();
    orintf("Entrer l'indice de la colonne : ");
    colonne = saisie_coup();
  }while(m->tab[ligne][colonne] != VIDE);
  m->tab[ligne][colonne] = m->joueur;
  return game_over;
}

int game_over(morpion_t m)
{
  int res = VIDE;
  /* Première ligne*/
  if(m.tab[0][0] == m.joueur && m.tab[0][1] == m.joueur && m.tab[0][2] == m.joueur)
    res = m.joueur;
  /* Deuxième ligne */
  if(m.tab[1][0] == m.joueur && m.tab[1][1] == m.joueur && m.tab[1][2] == m.joueur)
    res = m.joueur;
    /* Troisième ligne */
  if(m.tab[2][0] == m.joueur && m.tab[2][1] == m.joueur && m.tab[2][2] == m.joueur)
    res = m.joueur;
    /* Première colonne */
  if(m.tab[0][0] == m.joueur && m.tab[1][0] == m.joueur && m.tab[2][0] == m.joueur)
    res = m.joueur;
    /* Deuxième colonne */
  if(m.tab[0][1] == m.joueur && m.tab[1][1] == m.joueur && m.tab[2][1] == m.joueur)
    res = m.joueur;
    /* Troisième colonne */
  if(m.tab[0][2] == m.joueur && m.tab[1][2] == m.joueur && m.tab[2][2] == m.joueur)
    res = m.joueur;
    /* Première diagonale */
  if(m.tab[0][0] == m.joueur && m.tab[1][1] == m.joueur && m.tab[2][2] == m.joueur)
    res = m.joueur;
    /* Deuxième diagonale */
  if(m.tab[2][0] == m.joueur && m.tab[1][1] == m.joueur && m.tab[0][2] == m.joueur)
    res = m.joueur;
  return res;
}
