/** 
 * Fonctions de déplacements des voitures et gestion des événements
 */

#include "../headers/run.h"

void bonjour()
{
  /*
   * Ecrit la chaine de caractère coucou dans la sortie standard
   */ 
  printf("coucou");
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

void run(int bool, char map[][61])
{
  //int compteur = 0;
  v_list* l = NULL;
  voiture* v = NULL;
  
  srand (time (NULL));
  if (! bool)
    {
      if ( rand()%4 == 0)
	spawn_voiture (l, v);
    }
  else
    {
      spawn_voiture (l, v);
    }
  affichage_map (map);
  /*while(1)
    {
      affichage_map (map);
      //while (compteur <= 1000000000) compteur++;
      //compteur = 0;
      sleep (1);
      update (l, map);
      system("clear");  //Nettoie le terminal
      }*/
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l, char map[][61])
{
  v_list* tmp = l;

  for (int i = 0; i < length (l); i++)
    {
      map[tmp->value->posx][tmp->value->posy] = 'v';
      tmp = tmp->nxt;
    }

  tmp = l;
  for (int i = 0; i < length (l); i++)
    {
      switch (tmp->value->direction)
	{
	case 'N':
	  up (tmp->value);
	  break;
	case 'S':
	  down (tmp->value);
	  break;
	case 'E':
	  right (tmp->value);
	  break;
	case 'O':
	  left (tmp->value);
	  break;
	}
      tmp = tmp->nxt;
    }
}
