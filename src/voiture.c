/** 
 * Gestion des véhicules
 * une liste chainée qui contient tous les véhicules (méthode ajoutliste, 
 *  retirerliste...)
 */

#include "../headers/voiture.h"

static int id = 0;

voiture* check_pos (v_list* l, int x, int y)
{
  /*
   * Verifie s'il existe une voiture dans la liste à la position x y 
   * et la renvoie si elle existe.
   */
  if (l == NULL)
    return NULL;
  
  v_list* tmp = l;
  while (tmp != NULL)
    {
      if(tmp->value->posx == x && tmp->value->posy == y)
	{
	  return tmp->value;
	}
      else tmp = tmp->nxt;
    }
  return NULL;
}

int random_number(int upper)
{
  /*
   * Retourne un entier aléatoire entre 0 et upper
   */
  return (rand () % upper);
}

v_list* append (v_list* l, voiture* v)
{
  /*
   * Ajoute l'élément voiture v à la liste chainée l
   */
  if (l == NULL)
    {
      l = malloc (sizeof (v_list));
      l->value = v;
    }
  else
    {
      v_list *tmp = l;
      while (tmp->nxt != NULL)
	tmp = tmp->nxt;

      tmp->nxt = malloc (sizeof (v_list));
      tmp->nxt->value = v;
    }
  
  return l;
}

v_list* remove_v (v_list* l, voiture* v)
{
  /*
   * Retire l'élément v de la liste l.
   */
  if (l == NULL)
    {
      l = malloc (sizeof (v_list));
      return l;
    }
  else
    {
      v_list *tmp = l;
      
      while (tmp->nxt->value->id != v->id || tmp->nxt == NULL)
	tmp = tmp->nxt;

      if (tmp->nxt == NULL)
	return l;
      else
	{
	  v_list* buf = tmp->nxt;
	  if (buf->nxt != NULL)
	    {
	      tmp->nxt = buf->nxt;
	      free (buf);
	    }
	  else
	    {
	      free (buf);
	      tmp->nxt = NULL;
	    }
	}
    }
  return l;
}

void afficher_v ()
{
  /*printf("🚘");*/
  printf ("V");
}

int length (v_list* l)
{
  /*
   * Retourne la taille de la liste l en entier
   */
  int i = 0;
  v_list *tmp = l;

  while (tmp != NULL)
    {
      tmp = tmp->nxt;
      i++;
    }
  return i;
}

v_list* spawn_voiture (v_list* l)
{
  l = append (l, create_voiture());
  return l;
}

voiture* create_voiture()
{
  /*
   * Créé une struct voiture et la renvoie
   */
  voiture* v = malloc (sizeof (voiture));
  v->id = ++id;
  v->from = set_voiture (random_number (4)); /*Assignation aléatoire de la provenance de la voiture*/
  switch (v->from)
    {
    case 'N':
      v->direction = 'S';
      break;
    case 'S':
      v->direction = 'N';
      break;
    case 'E':
      v->direction = 'O';
      break;
    case 'O':
      v->direction = 'E';
      break;
    }
  init_position(v);
  v->vitesse = random_number(2) + 1;

  return v;
}

char set_voiture (int n)
{
  /*
   * Renvoie un caractère aléatoire entre N, O, S et E en fonction de n  
   */
  char l[4] = {'N', 'O', 'S', 'E'};
  return l[n];
}

void init_position (voiture *v)
{
  /*
   * Initialise les variables posx et posy de la voiture v en fonction v->from
   */
  if(v->from == 'N')
    {
      v->posx = 131;
      v->posy = 0;
    }
  else if(v->from == 'E')
    {
      v->posx = 174;
      v->posy = 12;
    }
  else if(v->from == 'S')
    {
      v->posx = 12;
      v->posy = 60;
    }
  else if(v->from == 'O')
    {
      v->posx = 1;
      v->posy = 14;
    }
}

void destroy (v_list* l, voiture* x, voiture* y)
{
  l = remove_v (l, x);
  l = remove_v (l, y);
}
/*
void spawn_tram (int i)
{ 
   * TO DO : SPAWN TRAM + MOVEMENT
   
}*/

