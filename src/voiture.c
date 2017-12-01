/** 
 * Gestion des véhicules
 * une liste chainée qui contient tous les véhicules (méthode ajoutliste, 
 *  retirer liste...)
 */

#include "../headers/voiture.h"

static int id = 1;

voiture* check_pos (v_list* l, int x, int y)
{
  /*
   * Verifie s'il existe une voiture dans la liste à la position x y 
   * et la renvoie si elle existe.
   */
  
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

void print (v_list* l)
{
  v_list* tmp = l;
  while (tmp != NULL)
    {
      printf(" %d -> \n", tmp->value->id);
      tmp = tmp->nxt;
    }
  printf("\n");
}

void up(voiture *v) {
  if(v->posy > 0) {
    v->posy = v->posy-1;
  }
  else
    v->is_out = true;
}

void down(voiture *v) {
  if(v->posy < 61) {
    v->posy = v->posy+1;
  }
  else
    v->is_out = true;
}

void left(voiture *v) {
  if(v->posx > 0) {
    v->posx = v->posx-1;
  }
  else
    v->is_out = true;
}

void right(voiture *v) {
  if(v->posx < 173) {
    v->posx = v->posx+1;
  }
  else
    v->is_out = true;
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
      return l;
    }
  else
    {
      v_list *tmp = l;
      v_list* buf = l;
      if (tmp->value->id == v->id)
	{
	  tmp = tmp->nxt;
	  free(buf);
	  return tmp;
	}
      else
	{
	  while (tmp->nxt != NULL && tmp->nxt->value->id != v->id)
	    {
	      tmp = tmp->nxt;
	    }
	  if (tmp->nxt == NULL)
	    return l;
	  else
	    {
	      buf = tmp->nxt;
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
    }
  return l;
}

v_list* clear_v (v_list* v)
{
  /*
   * Supprime les voitures dont les valeurs out sont à true
   */
  v_list* tmp = v;
  while (tmp->nxt != NULL)
    {
      if (tmp->nxt->value->is_out)
	{
	  tmp = remove_v(v, tmp->nxt->value);
	}
      tmp = tmp->nxt;
    }
  return v;
}

void afficher_v ()
{
  /*
   * Affiche le caractère "V" représentant une voiture dans l'entrée standard
   */
  printf ("V");
}

int length_v (v_list* l)
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
  /*
   * Créé une voiture aléatoirement et l'ajoute a la liste de voiture l
   */
  l = append (l, create_voiture());
  return l;
}

voiture* create_voiture()
{
  /*
   * Créé une struct voiture et la renvoie
   */
  voiture* v = malloc (sizeof (voiture));
  v->id = id;
  id++;
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
      v->posx = 129;
      v->posy = 1;
    }
  else if(v->from == 'E')
    {
      v->posx = 173;
      v->posy = 13;
    }
  else if(v->from == 'S')
    {
      v->posx = 9;
      v->posy = 61;
    }
  else if(v->from == 'O')
    {
      v->posx = 0;
      v->posy = 15;
    }
}

void destroy (v_list* l, voiture* x, voiture* y)
{
  /*
   * Supprime de la liste l les voitures ayant participé à un accident
   */
  l = remove_v (l, x);
  l = remove_v (l, y);
}

