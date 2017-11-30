/*
 * Fonction d'initalisation et de gestion des feux tricolores
 */

#include "../headers/feu.h"

feu* init_feuTri ()
{
  /*
   * Initialise la liste f de feu tricolore
   */
  int n = 9; /* nombre de feu tricolore sur la carte */
  feu* tabf = malloc (n * sizeof (feu));

  for (int i = 0; i < n; i++)
    {
      switch (i)
	{
	case 0:
	  tabf[i].posx = 127;
	  tabf[i].posy = 3;
	  tabf[i].etat = false;
	  break;
	case 1:
	  tabf[i].posx = 135;
	  tabf[i].posy = 9;
	  tabf[i].etat = false;
	  break;
	case 2:
	  tabf[i].posx = 127;
	  tabf[i].posy = 12;
	  tabf[i].etat = false;
	  break;
	case 3:
	  tabf[i].posx = 135;
	  tabf[i].posy = 12;
	  tabf[i].etat = true;
	  break;
	case 4:
	  tabf[i].posx = 105;
	  tabf[i].posy = 16;
	  tabf[i].etat = true;
	  break;
	case 5:
	  tabf[i].posx = 127;
	  tabf[i].posy = 16;
	  tabf[i].etat = true;
	  break;
	case 6:
	  tabf[i].posx = 135;
	  tabf[i].posy = 16;
	  tabf[i].etat = false;
	  break;
	case 7:
	  tabf[i].posx = 97;
	  tabf[i].posy = 35;
	  tabf[i].etat = false;
	  break;
	case 8:
	  tabf[i].posx = 127;
	  tabf[i].posy = 35;
	  tabf[i].etat = true;
	  break;
	}
    }

  return tabf;
}

void check_feu (feu* f, int x, int y)
{
  /*
   * Verifie s'il y a un feu à la position x,y et appelle la fonction d'affichage
   * si c'est le cas.r
   */
  if (f == NULL)
    {
      exit(-1);
    }
  for (int i = 0; i < 9; i++)
    {
      if (f[i].posx == x && f[i].posy == y)
	{
	  afficher_f(&f[i]);
	}
    }
}

feu* get_feu_pos (feu* f, int x, int y)
{
  for (int i = 0; i < 9; i++)
    {
      if (f[i].posx == x && f[i].posy == y)
	return &f[i];
    }
  return NULL;
}

bool getFeu (feu* f, int x, int y)
{
  if (x == 129 && y == 2)
    return get_feu_pos (f, 127, 3)->etat;
  else if (x == 133 && y == 10)
    return get_feu_pos (f, 135, 9)->etat;
  else if (x == 129 && y == 11)
    return get_feu_pos (f, 127, 12)->etat;
  else if (x == 125 && y == 15)
    return get_feu_pos (f, 127, 16)->etat;
  else if (x == 133 && y == 17)
    return get_feu_pos (f, 135, 16)->etat;
  else if (x == 137 && y == 13)
    return get_feu_pos (f, 135, 12)->etat;
  else if (x == 103 && y == 17)
    return get_feu_pos (f, 105, 16)->etat;
  else if (x == 99 && y == 34)
    return get_feu_pos (f, 97, 35)->etat;
  else if (x == 129 && y == 34)
    return get_feu_pos (f, 127, 35)->etat;
  
  return true;
}

void afficher_f (feu* f)
{
  /* 
   * Affiche le feu en fonction de son état
   * false = rouge et true = vert
   */
  if (f->etat)
    {
      couleur("32");
      printf("■");
      couleur("0");
    }
  else
    {
      couleur("31");
      printf("■");
      couleur("0");
    }
}

void change_etat_f (feu* f)
{
  /*
   * Inverse l'état de tous les feux dans la liste
   */
  for (int i = 0; i < 9; i++)
    {
      f[i].etat = ! f[i].etat;
    }
}
