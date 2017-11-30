/*
 * Fonctions de gestion du tramway (affichage, déplacement...)
 */

#include "../headers/tram.h"

void afficher_t (int i)
{
  /*
   * Affiche le tram
   */
  switch (i){
    
  case 1:
    couleur ("33");
    printf("■■■■■■■■■■■■");
    couleur ("0");
    break;
  case 2:
    couleur ("33");
    printf("■■■■■■■■■■■");
    couleur ("0");
    break;
  case 3:
    couleur ("33");
    printf("■■■■■■■■■■");
    couleur ("0");
    break;
  case 4:
    couleur ("33");
    printf("■■■■■■■■■");
    couleur ("0");
    break;
  case 5:
    couleur ("33");
    printf("■■■■■■■■");
    couleur ("0");
    break;
  case 6:
    couleur ("33");
    printf("■■■■■■■");
    couleur ("0");
    break;
  case 7:
    couleur ("33");
    printf("■■■■■■");
    couleur ("0");
    break;
  case 8:
    couleur ("33");
    printf("■■■■■");
    couleur ("0");
    break;
  case 9:
    couleur ("33");
    printf("■■■■");
    couleur ("0");
    break;
  case 10:
    couleur ("33");
    printf("■■■");
    couleur ("0");
    break;
  case 11:
    couleur ("33");
    printf("■■");
    couleur ("0");
    break;
  case 12:
    couleur ("33");
    printf("■");
    couleur ("0");
    break;
  }
}

bool check_tram (tram* t, int x, int y)
{
  /*
   * Verifie s'il existe un tram dans le tableau t ayant les coordonnées
   * x et y
   */
  for (int i = 0; i < 2; i++)
    {
      if (x > 171)
	return false;
      if (t[i].posx == x && t[i].posy == y)
	return true;
    }
  return false;
}

bool tram_feu_sync (tram* t)
{
  for (int i = 0; i < 2; i++)
    {
      if (t[i].posx > 105 && t[i].posx < 145)
	return true;
    }
  return false;
}

void move (tram* t)
{
  /*
   * Fait bouger les trams en fonction de leurs directions
   */
  for (int i = 0; i < 2; i++)
    {
      if (! t[i].moving)
	{
	  t[i].tmpStop++;
	  if (t[i].tmpStop > 5)
	    {
	      t[i].moving = true;
	      t[i].tmpStop = 0;
	    }
	}
      if (t[i].direction && t[i].moving)
	{
	  t[i].posx++;
	}
      else if (! t[i].direction && t[i].moving)
	{
	  t[i].posx--;
	}
      if (t[i].posx == 24 || t[i].posx == 146)
	t[i].moving = false;
    }
}

tram* init_tram (tram* t)
{
  /*
   * Initialise le tableau t
   */
  t = malloc (2 * sizeof (tram));
  
  t[0].posx = 0;
  t[0].posy = 7;
  t[0].direction = true;
  t[0].moving = true;
  t[0].tmpStop = 0;
  
  t[1].posx = 172;
  t[1].posy = 5;
  t[1].direction = false;
  t[1].moving = true;
  t[1].tmpStop = 0;
  
  return t;
}

tram* reset_t (tram* t)
{
  t[0].posx = 0;
  t[0].posy = 7;
  t[0].direction = true;
  t[0].moving = true;
  t[0].tmpStop = 0;
  
  t[1].posx = 172;
  t[1].posy = 5;
  t[1].direction = false;
  t[1].moving = true;
  t[1].tmpStop = 0;
  
  return t;
}
