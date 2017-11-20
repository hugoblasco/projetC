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

void init_position(VEHICULE *v) //initialise la position de la voiture v en fonction de v->from
{
  if(v->from == NORD)
    {
      v->posx = 0;
      v->posy = 130;
    }
  else if(v->from == EST)
    {
      v->posx = 13;
      v->posy = 175;
    }
  else if(v->from == SUD)
    {
k      v->posx = 15;
      v->posy = 0;
    }
  else if(v->from == OUEST)
    {
      v->posx = 61;
      v->posy = 10;
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

      clrscr(); //Nettoye le terminal
      update_board(l, nb_lin, nb_col, board, panne_mode, exit_panne); //Fait bouger les voitures
      show_board(nb_lin, nb_col, board); //Affiche le rond-point
      usleep(DELAY); //Délai avant de boucler de nouveau
      l = remove_out(l); //Enlève les voitures qui sont sorties
    }
}



void move_vehicule(VEHICULE *v, uint nb_lin, uint nb_col, char board[nb_lin][nb_col]) //Fait bouger les voitures sur les 16 lignes droites
{
  unsigned char d = (v->from == NORD || v->from == SUD) ? v->vitesse : v->vitesse * 2;

  if(v->from == OUEST && (v->pos_i == 38 || v->pos_i == 40))
    {
      if(v->vitesse == 2)
	{
	  if(v->pos_j + d > 50)
	    {
	      if(v->pos_j + d - 6 > 50)
		return;
	      else
		d -= 2;
	    }

	  if(board[v->pos_i][v->pos_j + d] == EMPTY
	     && board[v->pos_i][v->pos_j + d - 2] == EMPTY)
	    {
	      v->pos_j += d;
	    }
	  else if(board[v->pos_i][v->pos_j + d] != EMPTY
		  && board[v->pos_i][v->pos_j + d - 2] == EMPTY)
	    {
	      v->pos_j += (d - 2);
	    }

	  if(v->pos_j == 54)
	    {
	      v->sur_rp = true;
	      return;
	    }
	}

      if(v->vitesse == 1 && v->pos_j + d <= 50)
	{
	  if(board[v->pos_i][v->pos_j + d] == EMPTY)
	    {
	      v->pos_j += d;

	      if(v->pos_j == 50)
		{
		  v->sur_rp = true;
		  return;
		}
	    }
	}
    }
  else if(v->from == SUD && (v->pos_j == 74 || v->pos_j == 78))
    {
      if(v->vitesse == 2)
	{
	  if(v->pos_i - d < 49)
	    {
	      if(v->pos_i - d + 3 < 49)
		return;
	      else
		d -= 1;
	    }

	  if (board[v->pos_i - d][v->pos_j] == EMPTY
	      && board[v->pos_i - d + 1][v->pos_j] == EMPTY)
	    {
	      v->pos_i -= d;
	    }
	  else if (board[v->pos_i - d][v->pos_j] != EMPTY
		   && board[v->pos_i - d + 1][v->pos_j] == EMPTY)
	    {
	      v->pos_i -= (d - 1);
	    }

	  if(v->pos_i == 47)
	    {
	      v->sur_rp = true;
	      return;
	    }
	}

      if(v->vitesse == 1 && v->pos_i - d >= 49)
	{
	  if (board[v->pos_i - d][v->pos_j] == EMPTY)
	    {
	      v->pos_i -= d;

	      if(v->pos_i == 49)
		{
		  v->sur_rp = true;
		  return;
		}
	    }
	}
    }
  else if(v->from == EST && (v->pos_i == 34 || v->pos_i == 36))
    {
      if(v->vitesse == 2)
	{
	  if(v->pos_j - d < 94)
	    {
	      if(v->pos_j - d + 6 < 94)
		return;
	      else
		d -= 2;
	    }

	  if (board[v->pos_i][v->pos_j - d] == EMPTY
	      && board[v->pos_i][v->pos_j - d + 2] == EMPTY)
	    {
	      v->pos_j -= d;
	    }
	  else if (board[v->pos_i][v->pos_j - d] != EMPTY
		   && board[v->pos_i][v->pos_j - d + 2] == EMPTY)
	    {
	      v->pos_j -= (d - 2);
	    }

	  if(v->pos_j == 90)
	    {
	      v->sur_rp = true;
	      return;
	    }
	}

      if(v->vitesse == 1 && v->pos_j - d >= 94)
	{
	  if (board[v->pos_i][v->pos_j - d] == EMPTY)
	    {
	      v->pos_j -= d;

	      if(v->pos_j == 94)
		{
		  v->sur_rp = true;
		  return;
		}
	    }
	}
    }
  else if(v->from == NORD && (v->pos_j == 66 || v->pos_j == 70))
    {
      if(v->vitesse == 2)
	{
	  if(v->pos_i + d > 25)
	    {
	      if(v->pos_i + d - 3 > 25)
		return;
	      else
		d -= 1;
	    }

	  if (board[v->pos_i + d][v->pos_j] == EMPTY
	      && board[v->pos_i + d - 1][v->pos_j] == EMPTY)
	    {
	      v->pos_i += d;
	    }
	  else if (board[v->pos_i + d][v->pos_j] != EMPTY
		   && board[v->pos_i + d - 1][v->pos_j] == EMPTY)
	    {
	      v->pos_i += (d - 1);
	    }

	  if(v->pos_i == 27)
	    {
	      v->sur_rp = true;
	      return;
	    }
	}

      if(v->vitesse == 1 && v->pos_i + d <= 25)
	{
	  if(board[v->pos_i + d][v->pos_j] == EMPTY)
	    {
	      v->pos_i += d;

	      if(v->pos_i == 25)
		{
		  v->sur_rp = true;
		  return;
		}
	    }
	}
    }

  if(v->to == SUD && v->pos_i >= 48 && (v->pos_j == 66 || v->pos_j == 70))
    {
      if(v->vitesse == 1 && board[v->pos_i + 1][v->pos_j] == EMPTY)
	v->pos_i += 1;
      else if(v->vitesse == 2 && board[v->pos_i + 1][v->pos_j] == EMPTY)
	{
	  if(board[v->pos_i + 2][v->pos_j] == EMPTY)
	    v->pos_i += 2;
	  else if(board[v->pos_i + 2][v->pos_j] != EMPTY)
	    v->pos_i += 1;
	}

      if(v->pos_i >= 74)
	{
	  v->is_out = true;
	  return;
	}
    }
  else if(v->to == OUEST && v->pos_j <= 94 && (v->pos_i == 34 || v->pos_i == 36))
    {
      if(v->vitesse == 1 && board[v->pos_i][v->pos_j - 2] == EMPTY)
	v->pos_j -= 2;
      else if(v->vitesse == 2 && board[v->pos_i][v->pos_j - 2] == EMPTY)
	{
	  if(board[v->pos_i][v->pos_j - 4] == EMPTY)
	    v->pos_j -= 4;
	  else if(board[v->pos_i][v->pos_j - 4] != EMPTY)
	    v->pos_j -= 2;
	}

      if(v->pos_j <= 0)
	{
	  v->is_out = true;
	  return;
	}
    }
  else if(v->to == NORD && v->pos_i <= 26 && (v->pos_j == 74 || v->pos_j == 78))
    {
      if(v->vitesse == 1 && board[v->pos_i - 1][v->pos_j] == EMPTY)
	v->pos_i -= 1;
      else if(v->vitesse == 2 && board[v->pos_i - 1][v->pos_j] == EMPTY)
	{
	  if(board[v->pos_i - 2][v->pos_j] == EMPTY)
	    v->pos_i -= 2;
	  else if(board[v->pos_i - 2][v->pos_j] != EMPTY)
	    v->pos_i -= 1;
	}

      if(v->pos_i <= 0)
	{
	  v->is_out = true;
	  return;
	}
    }
  else if(v->to == EST && v->pos_j >= 50 && (v->pos_i == 38 || v->pos_i == 40))
    {
      if(v->vitesse == 1 && board[v->pos_i][v->pos_j + 2] == EMPTY)
	v->pos_j += 2;
      else if(v->vitesse == 2 && board[v->pos_i][v->pos_j + 2] == EMPTY)
	{
	  if(board[v->pos_i][v->pos_j + 4] == EMPTY)
	    v->pos_j += 4;
	  else if(board[v->pos_i][v->pos_j + 4] != EMPTY)
	    v->pos_j += 2;
	}

      if(v->pos_j >= 146)
	{
	  v->is_out = true;
	  return;
	}
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
