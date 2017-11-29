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

<<<<<<< HEAD
void up(voiture *v) {
  if(v->posy > 0) {
    v->posy = v->posy-1;
  }
  else {
    //on passe la variable is_out à 1 pour indiquer que la voiture sort de la map
    v->is_out = 1;
  }
}

void down(voiture *v) {
  if(v->posy < 61) {
    v->posy = v->posy+1;
  }
  else {
    //on passe la variable is_out à 1 pour indiquer que la voiture sort de la map
    v->is_out = 1;
  }
}

void left(voiture *v) {
  if(v->posx > 0) {
    v->posy = v->posy-1;
  }
  else {
    //on passe la variable is_out à 1 pour indiquer que la voiture sort de la map
    v->is_out = 1;
  }
}

void right(voiture *v) {
  if(v->posx < 174) {
    v->posy = v->posy+1;
  }
  else {
    //on passe la variable is_out à 1 pour indiquer que la voiture sort de la map
    v->is_out = 1;
  }
}


void run(bool danger, char map[][NBLIN])

{
  v_list* l = NULL;
  feu* f = NULL;
  int timer = 0;
  
  l = spawn_voiture (l);
<<<<<<< HEAD
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);

 printf("%d\n", length_v (l));
  //display_map (l, map);
  /*while(1)
=======
  f = init_feuTri();
  
  display_map (l, map, f);
  while(1)
>>>>>>> f3a6f198d8bea96c37b3385e50b8403b0de4b11e
    {
      /*if (danger)
	{
	spawn_voiture (l);
	}
	else
	{
	if (rand ()%4 == 0)
	spawn_voiture (l);
	}*/
      display_map (l, map, f);
      sleep (1);
      update (l, timer, f);
      system("clear");
      timer++;
      if (timer > 5)
	timer = 0;
      
    }
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

  if (timer == 5)
    change_etat_f (f);

  for (int i = 0; i < length_v (l); i++) /* On fait avancer les differentes voitures */
    {
      v = tmp[i];
      if(v->is_out==1) {
        //on enlève la voiture de la liste
      }
      switch (v->direction)
	{
	case 'N':
    up(v);
    if (v->posx == 143 && v->posy == 36) {
      v->direction = 'O';
    }
    if (v->posx == 9 && v->posy == 57) {
      v->direction = 'E';
    }
    if (v->posx == 133 && v->posy == 15) {
      //continue ou E
    }
    if (v->posx == 133 && v->posy == 13) {
      //continue ou O
    }
    if (v->posx == 9 && v->posy == 15) {
      v->direction = 'E';
    }
    if (v->posx == 9 && v->posy == 38) {
      //continue ou E
    }
    if (v->posx == 129 && v->posy == 15) {
      //continue ou O
    }
	  break;
	case 'S':
    down(v);
    if (v->posx == 129 && v->posy == 13) {
      //continue ou O
    }
    if (v->posx == 129 && v->posy == 15) {
      //continue ou E
    }
	  break;
	case 'E':
    right(v);
    if (v->posx == 140 && v->posy == 38) {
      v->direction = 'S';
    }
    if (v->posx == 70 && v->posy == 57) {
      v->direction = 'N';
    }
    if (v->posx == 133 && v->posy == 36) {
      //continue ou N
    }
    if (v->posx == 5 && v->posy == 15) {
      //continue ou S
    }
	  break;
	case 'O':
    left(v);
    if (v->posx == 9 && v->posy == 36) {
      v->direction = 'N';
    }
    if (v->posx == 64 && v->posy == 36) {
      //continue ou N
    }
    if (v->posx == 103 && v->posy == 36) {
      //continue ou N
    }
	  break;
	}
    }
}
