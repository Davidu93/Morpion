#include "morpion.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
  morpion_t partie = creer_partie();
  int vainqueur = VIDE , i = 0;
  while(vainqueur == VIDE && i < 9)
  {
    vainqueur = tour(&partie);
    afficher_plateau(partie);
    changer_joueur(&partie);
    i++;
  }

  if(vainqueur == ROND)
    printf("LE JOUEUR ROND A GAGNÉ\n");
  else if(vainqueur == CROIX)
    printf("LE JOUEUR CROIX A GAGNÉ\n");
  else
    printf("PERSONNE N'A GAGNE\n");

  return EXIT_SUCCESS;

}
