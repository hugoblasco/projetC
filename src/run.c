/** 
 * Fonctions de déplacements des voitures et gestion des événements
 */

#include "../headers/run.h"

const int DELAY = 1000; 

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

void run(int nb_lin, int nb_col, char board[nb_lin][nb_col],
	 int trafic_mode, int panne_mode, int exit_panne)
{
  v_list* l = NULL; //liste des véhicules

  while(1)
    {
      /*if(! random_number(trafic_mode))
	{
	voiture *v = spawn_vehicule(); //Création d'un véhicule
	l = append(l, v); //Ajout de v dans la liste
	}*/

      system("cls");  //Nettoie le terminal
      update_board(l, nb_lin, nb_col, board, panne_mode, exit_panne); //Fait bouger les voitures
      sleep(DELAY); //Délai avant de boucler de nouveau
    }
}

//Fait bouger les voitures, gère les pannes
void update_board(v_list* l, int nb_lin, int nb_col,
		  char board[nb_lin][nb_col], int panne_mode, int exit_panne)
{
  v_list* tmp = l;

  while(tmp) //On parcourt la liste des voitures
    {
      board[tmp->pos_i][tmp->pos_j] = EMPTY;

      if(!tmp->panne) //Si pas de panne
	{
	  if(!random_number(panne_mode)) //On creer une panne
	    {
	      tmp->panne = !tmp->panne;
	      board[tmp->pos_i][tmp->pos_j] = PANNE;
	      tmp = tmp->nxt;
	      continue;
	    }
	  else //Si on ne crée pas de panne
	    {
	      if(!tmp->sur_rp) //Si pas sur le RP
		move_vehicule(tmp, nb_lin, nb_col, board);
	      else //Si sur le RP
		turn_around(tmp, nb_lin, nb_col, board);
	    }
	}
      else //Si panne
	{
	  if(!random_number(exit_panne)) //On enleve la panne
	    tmp->panne = !tmp->panne;
	  else
	    {
	      board[tmp->pos_i][tmp->pos_j] = PANNE;
	      tmp = tmp->nxt;
	      continue;
	    }
	}

      if(tmp->is_out) //Si dehors inutile de bouger
	{
	  tmp = tmp->nxt;
	  continue;
	}

      board[tmp->pos_i][tmp->pos_j] = tmp->to;
      tmp = tmp->nxt;
    }
}
