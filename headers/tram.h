#ifndef TRAM_H
#define TRAM_H

#include "../headers/voiture.h"

typedef struct tram
{
  int posx;
  int posy;
  struct tram* nxt;
} tram;

#endif
