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

void run(bool danger, char map[][NBLIN])
{
  v_list* l = NULL;
  feu* f = NULL;
  int timer = 0;
  
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  f = init_feuTri();

  display_map (l, map, f);
  /*while(1)
    {
      if (! bool)
	{
	  if (rand ()%4 == 0)
	    spawn_voiture (l);
	}
      else
	{
	  spawn_voiture (l);
	}
      display_map (l, map);
      sleep (1);
      update (l, timer, f);
      system("clear");
      timer++;
      
      }*/
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l, int timer, feu* f)
{
  v_list* buf = l; /* liste des voitures*/
  voiture* tmp[length_v (l)]; /* tableau de toutes les voitures*/
  voiture* v = NULL;
  int a = 0;

  for (int i = 0; i < length_v (l); i++) /* Remplit le tableau de voiture */
    {
      tmp[i] = buf->value;
      buf = buf->nxt;
    }

  for (int i = 0; i < length_v (l); i++) /* On fait avancer les differentes voitures */
    {
      v = tmp[i];
      switch (v->direction)
	{
	case 'N':
	  break;
	case 'S':
	  break;
	case 'E':
	  break;
	case 'O':
	  break;
	}
    }
}
