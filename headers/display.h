#ifndef DISPLAY_H
#define DISPLAY_H

#define NBLIN 61
#define NBCOL 176

#include "../headers/couleur.h"
#include "../headers/voiture.h"

char menu ();

int map_loading (char[][NBLIN]);

void display_map (v_list*, char[][NBLIN], feu* f);

#endif
