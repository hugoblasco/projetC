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

void run(int bool)
{
  //int compteur = 0;
  v_list* l = NULL;
  //int timer = 0;
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);

  v_list* tmp = l;
  for (int i = 0; i < length (l); i++)
    {
      printf ("id : %d -> pos : (%d,%d)\n", tmp->value->id, tmp->value->posx, tmp->value->posy);
      tmp = tmp->nxt;
    }
  
  map_loading (l);
	  
  
  /*
     if (! bool)
     {
     if (rand ()%4 == 0)
     spawn_voiture (l, v);
     }
     else
     {
     spawn_voiture (l, v);
     }

     while(1)
     {
     if (timer == 10)
     spawn_tram(0);
     if (timer == 20){
     spawn_tram(1);
     timer = 0;
     map_loading (l);
     //while (compteur <= 1000000000) compteur++;
     //compteur = 0;
     sleep (1);
     update (l);
     system("clear");
     timer++;
      
     }*/
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l)
{
  v_list* buf = l;
  voiture* tmp[length (l)];

  for (int i = 0; i < length (l); i++)
    {
      tmp[i] = buf->value;
      buf = buf->nxt;
    }

  for (int i = 0; i < length (l); i++)
    {
      switch (buf->value->direction)
	{
	case 'N':
	  up (buf->value);
	  break;
	case 'S':
	  down (buf->value);
	  break;
	case 'E':
	  right (buf->value);
	  break;
	case 'O':
	  left (buf->value);
	  break;
	}
      buf = buf->nxt;
    }

  for (int i = 0; i < length (l); i++)
    {
      for (int j = i; j < length (l); j++)
	{
	  if (tmp[i]->posx == tmp[j]->posy && tmp[i]->posy == tmp[j]->posy)
	    destroy (l, tmp[i], tmp[j]);
	}
    }
}
