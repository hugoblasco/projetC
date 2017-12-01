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

void attendre(int x) {
  int i = 0;
  while (i < x) {
    i++;
  }
}

void run(bool danger, char map[][NBLIN])
{
	int max = 0;
  v_list* l = NULL;
  feu* f = NULL;
  tram* t = NULL;
  int timer = 0;
  int random_petit = 0; /* variable pour les très petites probabilités*/
  
  t = init_tram (t);
  f = init_feuTri();
  
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);
  l = spawn_voiture (l);

  display_map (l, map, f, t);
  
  while(1)
    {
    	random_petit = rand () % 25;
      /* int random_petit = rand () % 25;
	 
	 if (danger)
	 {
	 l = spawn_voiture (l);
	 }
	 else
	 {
	 if (rand ()%4 == 0)
	 l = spawn_voiture (l);
	 }
      */
      if (timer > 190)
	{
	  t = reset_t (t);
	}

      display_map (l, map, f, t);
      attendre(100000000);
      if (danger == false) {
      	update (l, timer, f, t);
      }
      else {
      	update_danger (l, timer, f, t);
      }
      system("clear");
      timer++;
       if (random_petit == 0 && max<30) {
      l = spawn_voiture (l);
      max++;
      }
      if (timer > 200)
	{
	  timer = 0;
	}
    }
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

  if (tram_feu_sync (t))
    feu_tram_stop(f, false);
  else
    feu_tram_stop (f, true);
  
  if (timer%20 == 0)
    change_etat_f (f);
  
  move (t);

  for (int i = 0; i < length_v (l); i++) /* On fait avancer les differentes voitures */
    {
      v = tmp[i];
      
		
	  		/*if(v->is_out == true) 
        		l = remove_v (l, v);*/
		buf = l;
	   		tmp[i] = buf->value;
	    	buf = buf->nxt;

	  	
      
      random = rand () % 2;
      random_petit = rand () % 10;
      if (getFeu(f, v->posx, v->posy)) {
	switch (v->direction)
	  {
	  case 'N':
	    if (check_pos(l,v->posx,v->posy-1) == NULL && v->etat==true) {
	      up(v);
	    }
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
	    if (check_pos(l,v->posx,v->posy+1) == NULL && v->etat==true) {
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
	    }
	    break;
	  case 'E':
	    if (check_pos(l,v->posx+1,v->posy) == NULL && v->etat==true) {
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
	    }
	    break;
	  case 'O':
	    if (check_pos(l,v->posx-1,v->posy) == NULL && v->etat==true) {
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
	    }
	    break;
	  }
      }
    }
}

void panne(voiture* v) {
	v->etat = false;
}

void update_danger(v_list* l, int timer, feu* f, tram* t)
//fonctionne de la même manière que update mais les voitures ne respectent plus les feux
{
  v_list* buf = l; /* liste des voitures*/
  voiture* tmp[length_v (l)]; /* tableau de toutes les voitures*/
  voiture* v = NULL;
  int random = 0; /* variable qui va contenir le resultat des fonctions rand() */
  int random_petit = 0; /* variable pour les très petites probabilités*/
  int random_panne = 0; 

  for (int i = 0; i < length_v (l); i++) /* Remplit le tableau de voiture */
    {
      tmp[i] = buf->value;
      buf = buf->nxt;
    }

  if (tram_feu_sync (t))
    feu_tram_stop(f, false);
  else
    feu_tram_stop (f, true);
  
  if (timer%20 == 0)
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
      random_panne = rand () % 100;
      if (random_panne == 0) {
      	panne(v);
      }
      switch (v->direction)
  	{
  	case 'N':
  		if (check_pos(l,v->posx,v->posy-1) == NULL) {
  			if (v->etat==true) {
  				up(v);
  			}
  		}
  		/*else {
  			destroy(l,v,check_pos(l,v->posx,v->posy-1));
  		}*/
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
	  if (check_pos(l,v->posx,v->posy+1) == NULL) {
	    if (v->etat==true) {
  				down(v);
  			}
	  	/*else {
  			destroy(l,v,check_pos(l,v->posx,v->posy+1));
  		}*/
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
	}
	    break;
	  case 'E':
	  if (check_pos(l,v->posx+1,v->posy) == NULL) {
	    if (v->etat==true) {
  				right(v);
  			}
		/*else {
  			destroy(l,v,check_pos(l,v->posx+1,v->posy));
  		}*/
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
	}
	    break;
	  case 'O':
	  if (check_pos(l,v->posx-1,v->posy) == NULL) {
	    if (v->etat==true) {
  				left(v);
  			}
		/*else {
  			destroy(l,v,check_pos(l,v->posx-1,v->posy));
  		}*/
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
	}
	    break;
	  }
      
    }
}


