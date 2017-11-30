/*
 * Fonctions de gestion du tramway (affichage, déplacement...)
 */

#include "../headers/tram.h"

void afficher_t ()
{
  couleur ("34");
  printf("■■■■■■■■■■■■");
  couleur ("0");
}

bool check_tram (tram* t, int x, int y)
{
  /*
   * Verifie s'il existe un tram dans la liste t ayant les coordonnées
   * x et y
   */
  tram* tmp = t;
  while (tmp != NULL)
    {
      if (tmp->posx == x && tmp->posy == y)
	{
	  afficher_t ();
	  return true;
	}
      tmp = tmp->nxt;
    }
  return false;
}

tram* init_tram (tram* t)
{
  tram* new = malloc (sizeof (tram));
  tram* new2 = malloc (sizeof (tram));
  new->posx = 0;
  new->posy = 7;
  new->direction = true;
  new->moving = true;
  new->is_out = false;
  
  new2->posx = 172;
  new2->posy = 5;
  new2->direction = false;
  new2->moving = true;
  new2->is_out = false;

  t = append_t (t, new);
  t = append_t (t, new2);
  
  return t;
}

tram* append_t (tram* t, tram* u)
{
  tram* tmp = t;
  while (tmp->nxt != NULL) /* Ajout à la liste */
    tmp = tmp->nxt;
  
  tmp->nxt = u;
  return t;
}

tram* append_new (tram* t)
{
  /*
   * Créé un nouvel objet tram et l'ajoute à la liste
   */
  tram* new = malloc (sizeof (tram));

  if (rand ()%1) /* Initialisation du nouveau tram */
    {
      new->posx = 0;
      new->posy = 7;
      new->direction = true;
    }
  else
    {
      new->posx = 172;
      new->posy = 5;
      new->direction = false;
    }
  new->moving = true;
  new->is_out = false;

  return append_t (t, new);
 
}

tram* clear_t (tram* t)
{
  /*
   * Supprime les tram dont les valeurs out sont à true
   */
  tram* tmp = t;
  while (tmp->nxt != NULL)
    {
      if (tmp->nxt->is_out)
	tmp->nxt = tmp->nxt->nxt;
      tmp = tmp->nxt;
    }
  return t;
}


