#ifndef DISPLAY_H
#define DISPLAY_H

#define NBLIN 61
#define NBCOL 175

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/couleur.h"
#include "../headers/voiture.h"

char menu ();

int map_loading (char[][NBLIN]);

void display_map (v_list*, char[][NBLIN]);

#endif
