#ifndef FEU_H
#define FEU_H

#include "../headers/voiture.h"

typedef struct feuTri
{
  int posx;
  int posy;
  bool etat; /* rouge = false, vert = true */
} feu;

feu* init_feuTri();

void check_feu (feu*, int, int);

feu* get_feu_pos (feu*, int, int);

bool getFeu (feu*, int, int);

void afficher_f (feu*);

void change_etat_f (feu*);

void free_all (v_list*, feu*);



#endif
