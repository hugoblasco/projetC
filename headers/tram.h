#ifndef TRAM_H
#define TRAM_H

#include "../headers/voiture.h"

typedef struct tram
{
  int posx;
  int posy;
  int tmpStop;
  bool direction; /* true = vers la droite, false = vers la gauche*/
  bool moving;
} tram;

void afficher_t ();

bool check_tram (tram*, int, int);

bool tram_feu_sync (tram*);

void move (tram*);

tram* init_tram (tram*);

tram* reset_t (tram*);

#endif
