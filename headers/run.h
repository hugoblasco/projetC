#ifndef RUN_H
#define RUN_H

#include "../headers/couleur.h"
#include "../headers/voiture.h"
#include "../headers/display.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void bonjour ();

void run (int bool);

void up (voiture*);

void down (voiture*);

void left (voiture*);

void right (voiture*);

void update (v_list*, int);

#endif
