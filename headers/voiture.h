/** 
 * Classe voiture avec tous ses attributs
 */


#ifndef VOITURE_H
#define VOITURE_H

#include "../headers/couleur.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

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

  int is_out; /* 0 quand la voiture est sur la map, 1 quand elle sort de la map */
  bool etat; /* actif ou inactif */
} voiture;

typedef struct v_list
{
  voiture* value;
  struct v_list* nxt;
} v_list;

typedef struct feuTri
{
  int posx;
  int posy;
  bool etat; /* rouge = false, vert = true */
} feu;

voiture* check_pos (v_list*, int, int);

void print (v_list*);

void up (voiture*);

void down (voiture*);

void left (voiture*);

void right (voiture*);

int random_number (int);

v_list* append (v_list*, voiture*);

v_list* remove_v (v_list*, voiture*);

void afficher_v ();

int length_v (v_list*);

v_list* spawn_voiture (v_list*);

voiture* create_voiture ();

char set_voiture (int);

void init_position (voiture*);

void free_all (v_list*, feu*);

void destroy (v_list*, voiture*, voiture*);

feu* init_feuTri();

void check_feu (feu*, int, int);

void afficher_f (feu*);

void change_etat_f (feu*);

#endif

  
