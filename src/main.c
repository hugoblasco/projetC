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
	printf("salut");
  v_list* l = malloc (sizeof (v_list));
  printf("salut 2");
  l = append (l, create_voiture());
  printf("salut 3");
  affichage_map(l);
  printf("salut 4");

  return 0;
}
