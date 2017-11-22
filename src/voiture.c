/** 
 * Gestion des véhicules
 * une liste doublement chainée qui contient tous les véhicules (méthode ajoutliste, retirerliste...)
 */

#include "../headers/voiture.h"

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
      
      tmp->nxt->value = v;
    }
  
  return l;
}


v_list* remove (v_list* l, voiture* v)
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

int length (v_list* l)
{
  /*
   * Retourne la taille de la liste l en entier
   */
  int i = 0;
  v_list *tmp = l;

  while (tmp->nxt != NULL)
    {
      tmp = tmp->nxt;
      i++;
    }
  return i;
}

