#ifndef RUN_H
#define RUN_H

#include "../headers/couleur.h"
#include "../headers/voiture.h"
#include "../headers/display.h"
#include "../headers/feu.h"
#include "../headers/tram.h"

void bonjour ();

void attendre (int);

void free_all (v_list*, feu*, tram*);

void run (bool, char[][NBLIN]);

void update (v_list*, int, feu*, tram*);

void update_danger (v_list*, int, feu*, tram*);

void panne (voiture*);

#endif
