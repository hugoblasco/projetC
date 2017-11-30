/** 
 * Toutes les fonctions d'affichage (menu de lancement, map)
 */
#include "../headers/display.h"

char menu() 
{
  /* 
   * Fonction d'affichage du menu et de sélection du mode de jeu.
   */
  
  char buffer; //buffer pour récupérer l'entrée du joueur.
  
  printf("                                                                       \n");
  printf("_______________________________________________________________________\n");
  printf("_______________________________________________________________________\n");
  printf("                                                                       \n");
  printf("   _______ __           _____ _                 __      __             \n");
  printf("  / ____(_) /___  __   / ___/(_)___ ___  __  __/ /___ _/ /_____  _____ \n");
  printf(" / /   / / __/ / / /  \\__\\/ / __ `__\\/ / / / / __ `/ __/ __\\/ ___/ \n");
  printf("/ /___/ / /_/ /_/ /   ___/ / / / / / / / /_/ / / /_/ / /_/ /_/ / /     \n");
  printf("\\____/_/\\__/\\__, /   /____/_/_/ /_/ /_/\\__,_/_/\\__,_/\\__/\\____/_/      \n");
  printf("           /____/                                                      \n");
  printf("                                                                       \n");
  printf("_______________________________________________________________________\n");
  printf("_______________________________________________________________________\n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      \n");
  printf("      *                                                         *      \n");
  printf("      *                                                         *      \n");
  printf("      *     Bienvenue sur notre plateforme de simulation !!     *      \n");
  printf("      *                                                         *      \n");
  printf("      *                 Choisissez votre mode :                 *      \n");
  printf("      *                                                         *      \n");
  printf("      *                      > [f] Fluide                       *      \n");
  printf("      *                      > [d] Danger                       *      \n");
  printf("      *                                                         *      \n");
  printf("      *                      > [q] Quitter                      *      \n");
  printf("      *                                                         *      \n");
  printf("      *                                                         *      \n");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");
  printf("                                                                       \n");

  scanf ("%c\n", &buffer);
  switch (buffer)
    {
    case 'q':
      return 'q';
    case 'f': //mode fluide
      return 'f';
    case 'd': //mode danger
      return 'd';
    default:
      printf ("Entrée invalide\n");
      menu ();
    }
  system ("clear");
  return '1';
  
}

int map_loading (char map[][NBLIN])
{
  /*
   * Charge le plan dans le tableau map
   */
  FILE* fp = NULL;
  int actual_char = 0;
  fp = fopen ("./doc/plan.txt", "r");
  if (fp == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier : ");
      return -1;
    }
  else {
    for (int j = 1; j < NBLIN; j++)
      {
	for (int i = 0; i < NBCOL; i++)
	  {
	    actual_char = fgetc(fp);
	    map[i][j] = actual_char;
	  }
      }
  }
  if (fclose (fp) < 0)
    {
      perror ("Erreur lors de la fermeture du fichier : ");
      return -1;
    }
  return 0;
}


void display_map (v_list* l, char map[][NBLIN], feu* f, tram* t)
{
  /*
   * Affiche la carte stockée dans le tableau map
   */

  for (int j = 1; j < NBLIN; j++)
    {
      for (int i = 0; i < NBCOL; i++)
	{
	  if (check_pos (l, i, j) != NULL)
	    {
	      afficher_v ();
	    }
	  else if (check_tram (t, i, j))
	    {
	      if (j == 7)
		{
		  switch (i)
		    {		    
		    case 161 :
		      afficher_t(2);
		      i+=11;
		      break;
		    case 162 :
		      afficher_t(3);
		      i+=10;
		      break;
		    case 163 :
		      afficher_t(4);
		      i+=9;
		      break;
		    case 164 :
		      afficher_t(5);
		      i+=8;
		      break;
		    case 165 :
		      afficher_t(6);
		      i+=7;
		      break;
		    case 166 :
		      afficher_t(7);
		      i+=6;
		      break;
		    case 167 :
		      afficher_t(8);
		      i+=5;
		      break;
		    case 168 :
		      afficher_t(9);
		      i+=4;
		      break;
		    case 169 :
		      afficher_t(10);
		      i+=3;
		      break;
		    case 170 :
		      afficher_t(11);
		      i+=2;
		      break;
		    case 171 :
		      afficher_t(12);
		      i+=1;
		      break;
		    default:
		      afficher_t(1);
		      i+=12;
		      break;
		    }
		}
	      else if (j == 5)
		{
		  switch (i)
		    {		    
		    case 161 :
		      afficher_t(2);
		      i+=11;
		      break;
		    case 162 :
		      afficher_t(3);
		      i+=10;
		      break;
		    case 163 :
		      afficher_t(4);
		      i+=9;
		      break;
		    case 164 :
		      afficher_t(5);
		      i+=8;
		      break;
		    case 165 :
		      afficher_t(6);
		      i+=7;
		      break;
		    case 166 :
		      afficher_t(7);
		      i+=6;
		      break;
		    case 167 :
		      afficher_t(8);
		      i+=5;
		      break;
		    case 168 :
		      afficher_t(9);
		      i+=4;
		      break;
		    case 169 :
		      afficher_t(10);
		      i+=3;
		      break;
		    case 170 :
		      afficher_t(11);
		      i+=2;
		      break;
		    case 171 :
		      afficher_t(12);
		      i+=1;
		      break;
		    default:
		      afficher_t(1);
		      i+=12;
		      break;
		    }
		}
	    }
	  else
	    {
	      switch (map[i][j])
		{
		case 'w': // Eau
		  couleur("46");
		  printf(" ");
		  couleur("0");
		  break;
		case 'q':
		  couleur("4");
		  printf(" ");
		  couleur("0");
		  break;
		case 'i': 
		  printf("═");
		  break;
		case 'F': 
		  printf("║");
		  break;
		case 'l': 
		  printf("─");
		  break;
		case 't': 
		  printf("╝");
		  break;
		case 'R': 
		  printf("╦");
		  break;
		case 'g': 
		  printf("╩");
		  break;
		case 'K': 
		  printf("╔");
		  break;
		case 'k': 
		  printf("╚");
		  break;
		case 'u': 
		  printf("╝");
		  break;
		case 'y': 
		  printf("╗");
		  break;
		case 'j': 
		  printf("│");
		  break;
		case 'X': 
		  printf("┼");
		  break;
		case 'Y': 
		  printf("┤");
		  break;
		case 'Z': 
		  printf("├");
		  break;
		case 'z': 
		  printf("┐");
		  break;
		case 'L': 
		  printf("└");
		  break;
		case 'W': 
		  printf("┘");
		  break;
		case 'Q': 
		  printf("┌");
		  break;
		case 'h': 
		  printf("┴");
		  break;
		case 'H':
		  printf("┬");
		  break;
		case 'f':
		  check_feu (f, i, j);
		  break;
		default:
		  printf ("%c", map[i][j]);
		  break;
		}
	    }
	}
    }
  printf("\n");
}
