#ifndef RUN_H
#define RUN_H

#include "../headers/couleur.h"
#include "../headers/voiture.h"

void bonjour ();

void run (uint, uint, char, int, int, int);

void up (voiture*);

void down (voiture*);

void left (voiture*);

void right (voiture*);

void update_board (v_list*, uint, uint, char, int, int);

#endif
