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

void run(bool danger, char map[][NBLIN])
{
  v_list* l = NULL;
  feu* f = NULL;
  int timer = 0;
  
  l = spawn_voiture (l);
  l = spawn_voiture (l);

  f = init_feuTri();

  //print (l);
  

  display_map (l, map, f);
  /*
    while(1)
    {
    if (danger)
    {
    l = spawn_voiture (l);
    }
    else
    {
    if (rand ()%4 == 0)
    l = spawn_voiture (l);
    }
    printf("SALUT");
    display_map (l, map, f);
    sleep (1);
    update (l, timer, f);
    system("clear");
    timer++;
    if (timer > 5)
    timer = 0;
      
    }
  free_all(l, f); */
}

//Fait bouger les voitures, gère les pannes
void update(v_list* l, int timer, feu* f)
{
  v_list* buf = l; /* liste des voitures*/
  voiture* tmp[length_v (l)]; /* tableau de toutes les voitures*/
  voiture* v = NULL;
  int a = 0;
  int random =0; /* variable qui va contenir le resultat des fonctions rand() */

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
      random = rand () % 2;
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
        v->direction = 'E';
      }
      if (v->posx == 103 && v->posy == 15) {
        v->direction = 'E';
      }
      if (v->posx == 133 && v->posy == 15) {
        //continue ou E
        // rand () % n pour avoir des nombres entre 0 et n-1
        random = rand () % 2;
        if (random == 0) {
          v->direction = 'E';
        }
      }
      if (v->posx == 133 && v->posy == 13) {
        //continue ou O

        if (random == 0) {
          v->direction = 'E';
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
      if (v->posx == 63 && v->posy == 36) {
        //vers le magasin
        if (random == 0) {
          v->direction = 'N';
        }
      }
      if (v->posx == 99 && v->posy == 36) {
        v->direction = 'O';
      }
      if (v->posx == 129 && v->posy == 15) {
        //continue ou E
        if (random == 0) {
          v->direction = 'E';
        }
      }
      if (v->posx == 139 && v->posy == 56) {
        //vers l'immeuble
        //continue ou E
        if (random == 0) {
          v->direction = 'O';
        }
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
  	  break;
  	case 'O':
      left(v);
      if (v->posx == 9 && v->posy == 36) {
        v->direction = 'N';
      }
      if (v->posx == 64 && v->posy == 36) {
        //continue ou N
        if (random == 0) {
          v->direction = 'N';
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
