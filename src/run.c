/** 
 * Fonctions de déplacements des voitures et gestion des événements
 */

#include "../headers/run.h"

void bonjour()
{
  /*x
   * Ecrit la chaine de caractère coucou dans la sortie standard
   */ 
  printf("coucou");
}

void attendre(int x) {
  int i = 0;
  while (i < x) {
    i++;
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

void run(bool danger, char map[][NBLIN])
{
  v_list* l = NULL;
  feu* f = NULL;
  tram* t = NULL;
  int timer = 0;
  int random_petit = 0; /* variable pour les très petites probabilités*/
  
  t = init_tram (t);
  f = init_feuTri();
  
  l = spawn_voiture (l);
  
  display_map (l, map, f, t);
  
  while(1)
    {
    random_petit = rand () % 10;
      /*if (danger)
	{
	  l = spawn_voiture (l);
	}
      else
	{
	  if (rand ()%4 == 0)
	    l = spawn_voiture (l);
	}*/

      display_map (l, map, f, t);
      attendre(100000000);
      update (l, timer, f, t);
      system("clear");
      timer++;
      if (random_petit == 0) {
      	l = spawn_voiture (l);
  		}
      if (timer > 10)
	{
	  //t = append_new (t);
	  timer = 0;
	}      
    }
  free_all(l, f); 
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l, int timer, feu* f, tram* t)
{
  v_list* buf = l; /* liste des voitures*/
  voiture* tmp[length_v (l)]; /* tableau de toutes les voitures*/
  voiture* v = NULL;
  int random = 0; /* variable qui va contenir le resultat des fonctions rand() */
  int random_petit = 0; /* variable pour les très petites probabilités*/

  for (int i = 0; i < length_v (l); i++) /* Remplit le tableau de voiture */
    {
      tmp[i] = buf->value;
      buf = buf->nxt;
    }

  if (timer == 5)
    change_etat_f (f);

  move (t);

  for (int i = 0; i < length_v (l); i++) /* On fait avancer les differentes voitures */
    {
      v = tmp[i];
      if(v->is_out) {
        //on enlève la voiture de la liste
      }
      random = rand () % 2;
      random_petit = rand () % 10;
      if (getFeu(f, v->posx, v->posy)) {
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
	  if (v->posx == 70 && v->posy == 38) {
	  	if (random == 0) {
	      v->direction = 'E';
	  	}
	  }
	  if (v->posx == 70 && v->posy == 36) {
	      v->direction = 'O';
	  }
	  
	  if (v->posx == 103 && v->posy == 13) {
	      v->direction = 'O';
	  }
	  if (v->posx == 133 && v->posy == 15) {
	    //continue ou E
	    // rand () % n pour avoir des nombres entre 0 et n-1
	    if (random == 0) {
	      v->direction = 'E';
	  	}
	  }
	  if (v->posx == 133 && v->posy == 13) {
	    //continue ou O
	    if (random == 0) {
	    	v->direction = 'O';
	  	}
	  }
	  if (v->posx == 9 && v->posy == 15) {
	    v->direction = 'E';
	  }
	  if (v->posx == 9 && v->posy == 38) {
	    //continue ou E
	    if (random == 0) {
			v->direction = 'E';
	    }
	  }
	  if (v->posx == 129 && v->posy == 15) {
	    //continue ou O
	    if (random == 0) {
			v->direction = 'O';
	    }
	  }
	    break;
	    
	  case 'S':
	  
	    down(v);
	  
	    if (v->posx == 129 && v->posy == 13) {
	      //continue ou O
	      if (random == 0) {
			v->direction = 'O';
	      }
	    }
	    if (v->posx == 129 && v->posy == 36) {
	      //continue ou O
	      if (random == 0) {
			v->direction = 'O';
	      }
	     }
	     if (v->posx == 129 && v->posy == 38) {
			v->direction = 'E';
	      }
	     
	    if (v->posx == 99 && v->posy == 36) {
	  	if (random == 0) {
	      v->direction = 'E';
	  	}
	  }
	  if (v->posx == 99 && v->posy == 36) {
	  	
	      v->direction = 'O';
	  	
	  }
	    if (v->posx == 129 && v->posy == 15) {
	      //continue ou E
	      if (random_petit == 0) {
		v->direction = 'E';
	      }
	    }
	    if (v->posx == 5 && v->posy == 38) {
	  	if (random_petit == 0) {
	      v->direction = 'E';
	  	}
	  }
	    break;
	  case 'E':
	  
	    right(v);
		
	    if (v->posx == 139 && v->posy == 38) {
	      v->direction = 'S';
	    }
	    if (v->posx == 70 && v->posy == 57) {
	      v->direction = 'N';
	    }
	    if (v->posx == 133 && v->posy == 36) {
	      //continue ou N
	      if (random == 0) {
		v->direction = 'N';
	      }
	    }
	    if (v->posx == 5 && v->posy == 15) {
	      //continue ou S
	      if (random == 0) {
		v->direction = 'S';
	      }
	    }
	    if (v->posx == 99 && v->posy == 15) {
	  	if (random == 0) {
	      v->direction = 'S';
	  	}
	  }
	    break;
	  case 'O':
	  
	    left(v);
		
	    if (v->posx == 9 && v->posy == 36) {
	    	if (random == 0) {
			v->direction = 'N';
	      }
	    }
	    if (v->posx == 9 && v->posy == 36) {
	    	if (random == 0) {
			v->direction = 'N';
	      }
	    }
	    if (v->posx == 5 && v->posy == 36) {
	      //continue ou N
			v->direction = 'S';
	      
	    }
	    if (v->posx == 5 && v->posy == 13) {
	  	if (random_petit == 0) {
	      v->direction = 'S';
	  	}
	  }
	    if (v->posx == 99 && v->posy == 13) {
	      //continue ou N
	      if (random == 0) {
		v->direction = 'S';
	      }
	    }
	    if (v->posx == 103 && v->posy == 36) {
	      //continue ou N
	      if (random == 0) {
		v->direction = 'N';
	      }
	    }
	    break;
	  }
	}
}
}

