/** 
 * Gestion des véhicules
 * une liste chainée qui contient tous les véhicules (méthode ajoutliste, 
 *  retirerliste...)
 */

#include "../headers/voiture.h"

static int ident = 1;

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
}

void down(voiture *v) {
  if(v->posy < 61) {
    v->posy = v->posy+1;
  }
}

void left(voiture *v) {
  if(v->posx > 0) {
    v->posy = v->posy-1;
  }
}

void right(voiture *v) {
  if(v->posx < 175) {
    v->posy = v->posy+1;
  }
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
  v->id = ident;
  ident++;
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

void free_all (v_list* l, feu* f)
{
  v_list* tmp = l;

  while (l != NULL)
    {
      tmp = l->nxt;
      free (l->value);
      free (l);
      l = tmp;
    }

  free (f);
  
}

void destroy (v_list* l, voiture* x, voiture* y)
{
  /*
   * Supprime de la liste l les voitures ayant participé à un accident
   */
  l = remove_v (l, x);
  l = remove_v (l, y);
}

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
  if (f == NULL)
    printf ("ESPECE DE RETARD T'AS PAS INITIALISE F\n");
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
  for (int i = 0; i < 9; i++)
    {
      f[i].etat = ! f[i].etat;
    }
}
/*
void spawn_tram (int i)
{ 
   * TO DO : SPAWN TRAM + MOVEMENT
   
}*/

