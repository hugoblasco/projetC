/** 
 * Classe voiture avec tous ses attributs
 */


#ifndef VOITURE_H
#define VOITURE_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

typedef struct voiture
{
  int id; /* identifiant unique à chaucune des voiture*/
  char from; /* N (NORD), S (SUD), E (EST), O (OUEST) */
  char direction; /* N (NORD), S (SUD), E (EST), O (OUEST) */
  int posx; /* position courante x de la voiture */
  int posy; /* position courante y de la voiture */
  int vitesse; /* vitesse de la voiture : 1 (normale), 2 (rapide) */
  char type; /* type du vehicule : 'v' (voiture), 'c' (camion) */ 
  char custom[30]; /* contient le véhicule customisé */
  int is_out; /* 0 si la voiture est sur la carte, 1 si elle sort de la carte
  char etat; /* actif ou inactif */
} voiture;

typedef struct v_list
{
  voiture* value;
  struct v_list* nxt;
} v_list;

voiture* check_pos (v_list*, int, int);

int random_number (int);

v_list* append (v_list*, voiture*);

v_list* remove_v (v_list*, voiture*);

void afficher_v ();

int length (v_list*);

voiture* create_voiture ();

char set_voiture (int);

void init_position (voiture*);


#endif

  
