#ifndef RUN_H
#define RUN_H

#include "../headers/couleur.h"
#include "../headers/voiture.h"
#include "../headers/display.h"

void bonjour ();

void run (bool, char[][NBLIN]);

void update (v_list*, int, feu*);

#endif
