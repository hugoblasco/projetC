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
