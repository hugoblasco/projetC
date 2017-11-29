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
  v_list* l = NULL;
  v_list* tmp = NULL;
  int timer = 0;
  l = spawn_voiture (l);
  /*l = spawn_voiture (l);
    l = spawn_voiture (l);*/

  tmp = l;
  for (int i = 0; i < length (l); i++)
    {
      printf ("id : %d -> pos : (%d,%d)\n", tmp->value->id, tmp->value->posx, tmp->value->posy);
      tmp = tmp->nxt;
    }
  
  map_loading (l);
	  
  /*while(1)
    {
      /*if (! bool)
	{
	  if (rand ()%4 == 0)
	    spawn_voiture (l);
	}
      else
	{
	  spawn_voiture (l);
	}
      map_loading (l);
      sleep (1);
      update (l);
      system("clear");
      timer++;
      
    }*/
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l, int timer)
{
  v_list* buf = l; /* liste des voitures*/
  voiture* tmp[length (l)]; /* tableau de toutes les voitures*/
  voiture* v = NULL;
  int a = 0;

  for (int i = 0; i < length (l); i++) /* Remplit le tableau de voiture */
    {
      tmp[i] = buf->value;
      buf = buf->nxt;
    }

  for (int i = 0; i < length (l); i++) /* On fait avancer les differentes voitures */
    {
      v = tmp[i];
      switch (v->direction)
	{
	case 'N':
	  up (v);
	  break;
	case 'S':
	  a = rand ()%2;
	  if (v->posx == 138 && v->posy == 1 && timer >= 5) //si la voiture est au feu vert
	    down (v); // la voiture passe au feu vert
	  else if (v->posx == 138 && v->posy == 1 && timer < 5) //si la voiture est au feu rouge
	    {} //la voiture attend au feu
	  else if (v->posx == 138 && v->posy == 10 && timer < 5) //si la voiture est au feu vert
	    down (v); // la voiture passe au feu vert
	  else if (v->posx == 138 && v->posy == 10 && timer >= 5) //si la voiture est au feu rouge
	    {}  //la voiture attend au feu
	  else if (v->posx == 148 && v->posy == 33 && timer >= 5) //si la voiture est au feu vert
	    down (v); // la voiture passe au feu vert
	  else if (v->posx == 148 && v->posy == 33 && timer < 5) //si la voiture est au feu rouge
	    {} //la voiture attend au feu
	  else if (v->posx == 130 && v->posy == 12 && a == 0)
	    left (v);
	  else if (v->posx == 130 && v->posy == 12 && a == 1) 
	    down (v);
	  else if (v->posx < 130 && v->posy == 12)
	    left (v);
	  else if (v->posx >= 130 && v->posy == 12) 
	    down (v);
	  break;
	case 'E':
	  right (v);
	  break;
	case 'O':
	  left (v);
	  break;
	}
    }
}
