#ifndef TRAM_H
#define TRAM_H

#include "../headers/voiture.h"

typedef struct tram
{
  int posx;
  int posy;
  bool direction; /* true = vers la droite, false = vers la gauche*/
  bool moving;
  bool is_out;
  struct tram* nxt;
} tram;

void afficher ();

bool check_tram (tram*, int, int);

tram* init_tram (tram*);

tram* append_t (tram*, tram*);

tram* append_new (tram*);

tram* clear_t (tram*);

#endif
