/** 
 * Classe voiture avec tous ses attributs
 */


#ifndef VOITURE_H
#define VOITURE_H

#include <stdlib.h>

typedef struct voiture
{
  int id; /* identifiant unique à chaucune des voiture*/
  char direction; /* N (NORD), S (SUD), E (EST), O (OUEST) */
  char from; /* N (NORD), S (SUD), E (EST), O (OUEST) */
  int posx; /* position courante x de la voiture */
  int posy; /* position courante y de la voiture */
  int vitesse; /* vitesse de la voiture : 1 (normale), 2 (rapide) */
  char type; /* type du vehicule : 'v' (voiture), 'c' (camion) */ 
  char custom[30]; /* contient le véhicule customisé */
  char etat; /* actif ou inactif */
} voiture;

typedef struct v_list
{
  voiture* value;
  struct v_list* nxt;
} v_list;

v_list* append (v_list*, voiture*);

v_list* remove (v_list*, voiture*);

int length (v_list*);


#endif

  
