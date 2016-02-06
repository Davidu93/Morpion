#include "morpion.h"

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
}
