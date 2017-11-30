#ifndef DISPLAY_H
#define DISPLAY_H

#define NBLIN 62
#define NBCOL 175

#include "../headers/couleur.h"
#include "../headers/voiture.h"
#include "../headers/feu.h"
#include "../headers/tram.h"

char menu ();

int map_loading (char[][NBLIN]);

void display_map (v_list*, char[][NBLIN], feu* f, tram* t);

#endif
