/** 
* Gestion des véhicules
* une liste doublement chainée qui contient tous les véhicules (méthode ajoutliste, retirerliste...)
*/


/*VEHICULE_LIST append(VEHICULE_LIST l, VEHICULE *v)
// methode pour ajouter une voiture à la liste chainée l
{
  if(!l)
    return v;
  else
    {
      VEHICULE *tmp = l;

      while(tmp->next != NULL)
	tmp = tmp->next;

      tmp->next = v;

      return l;
    }
}

VEHICULE_LIST remove_out(VEHICULE_LIST l)
// methode pour retirer une voiture de la liste chainée l
{
  if(!l)
    return NULL;

  VEHICULE *head = l;

  if(head->is_out)
    {
      VEHICULE *tmp = head;

      head = head->next;
      free(tmp);

      return head;
    }

  VEHICULE *tmp = head->next, *prec = head;

  while(tmp)
    {
      if(tmp->is_out)
        {
	  tmp = tmp->next;
	  free(prec->next);
	  prec->next = tmp;
        }

      prec = tmp;
      tmp = tmp->next;
    }

  return head;
  }*/
