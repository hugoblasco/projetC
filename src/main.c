/** 
* Point d'entré du programme
*/


//printf("\033[]60,10H🚘\n");
#include <stdio.h>
#include <stdlib.h>
#include "../headers/couleur.h"
#include "../headers/display.h"

//taille du tableau
#define NBLIN 61
#define NBCOL 175


int main() 
{
  v_list* l = NULL;
  voiture* v = create_voiture ();
  l = append (l, v);
  affichage_map(l);

  return 0;
}
