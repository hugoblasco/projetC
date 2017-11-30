#ifndef RUN_H
#define RUN_H

#include "../headers/couleur.h"
#include "../headers/voiture.h"
#include "../headers/display.h"
#include "../headers/feu.h"
#include "../headers/tram.h"

void bonjour ();

void free_all (v_list*, feu*);

void run (bool, char[][NBLIN]);

void update (v_list*, int, feu*);

#endif
