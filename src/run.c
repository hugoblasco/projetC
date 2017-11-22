/** 
* Fonctions de déplacements des voitures et gestion des événements
*/


#include "../headers/couleur.h"
#include "../headers/voiture.h"

void bonjour()
{
  printf("coucou");
}

int random_number(uint upper) // Donne un nombre aléatoire en 0 et upper
{
  return (rand() % upper);
}

voiture *create_voiture() //Création d'une voiture
{
  voiture *v = malloc(sizeof(voiture));

  //Choix aléatoire du point de départ ainsi que de la destination
  //v->direction = set_voiture(random_number(4));
  v->from = set_voiture(random_number(4));
  //Choix de la vitesse
  v->vitesse = random_number(2) + 1;

  //Initialise la position en fonction du point de départ
  init_position(v);

  v->next = NULL;

  return v;
}

char set_voiture(uint n) //donne une direction en fonction de n
{
  char l[4] = {NORD, OUEST, SUD, EST};
  return l[n];
}

void init_position(voiture *v) //initialise la position de la voiture v en fonction de v->from
{
  if(v->from == NORD)
    {
      v->posx = 130;
      v->posy = 1;
    }
  else if(v->from == EST)
    {
      v->posx = 175;
      v->posy = 14;
    }
  else if(v->from == SUD)
    {
k      v->posx = 1;
      v->posy = 15;
    }
  else if(v->from == OUEST)
    {
      v->posx = 10;
      v->posy = 61;
    }
}

void run(uint nb_lin, uint nb_col, char board[nb_lin][nb_col], int trafic_mode, int panne_mode, int exit_panne) //Routine du programme
{
  VEHICULE_LIST l = NULL; //liste des véhicules

  while(1)
    {
      if(!random_number(trafic_mode))
	{
	  VEHICULE *v = spawn_vehicule(); //Création d'un véhicule
	  l = append(l, v); //Ajout de v dans la liste
	}

      clrscr(); //Nettoie le terminal
      update_board(l, nb_lin, nb_col, board, panne_mode, exit_panne); //Fait bouger les voitures
      show_board(nb_lin, nb_col, board); //Affiche le rond-point
      usleep(DELAY); //Délai avant de boucler de nouveau
      l = remove_out(l); //Enlève les voitures qui sont sorties
    }
}

void move_vehicule(voiture *v) {
	//tester si un vehicule n'est pas bloqué sur la case devant
	//tester si la voiture est au niveau d'un feu, si c'est le cas, regarder si le feu est rouge ou vert
	//tester si la voiture atteint un carrefour
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



//Fait bouger les voitures, gère les pannes
void update_board(VEHICULE_LIST l, uint nb_lin, uint nb_col,
		  char board[nb_lin][nb_col], int panne_mode, int exit_panne)
{
  VEHICULE *tmp = l;

  while(tmp) //On parcourt la liste des voitures
    {
      board[tmp->pos_i][tmp->pos_j] = EMPTY;

      if(!tmp->panne) //Si pas de panne
	{
	  if(!random_number(panne_mode)) //On creer une panne
	    {
	      tmp->panne = !tmp->panne;
	      board[tmp->pos_i][tmp->pos_j] = PANNE;
	      tmp = tmp->next;
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
	      tmp = tmp->next;
	      continue;
	    }
	}

      if(tmp->is_out) //Si dehors inutile de bouger
	{
	  tmp = tmp->next;
	  continue;
	}

      board[tmp->pos_i][tmp->pos_j] = tmp->to;
      tmp = tmp->next;
    }
}
