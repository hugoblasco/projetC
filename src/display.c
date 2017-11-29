/** 
 * Toutes les fonctions d'affichage (menu de lancement, map)
 */
#include "../headers/display.h"

//essayer d'afficher l'emoji suivi d'un espace pour egler les problemes de décallages


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
  FILE* fp = NULL;
  int actual_char = 0, i = 0, j = 0;
  fp = fopen ("./doc/plan.txt", "r");
  if (fp == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier : ");
      return -1;
    }
  else {
    fseek (fp, 0, SEEK_SET);
    do 
      {
	do{
	  actual_char = fgetc (fp); 	    /* On lit le caractère */
	  map[i][j] = actual_char;
	  i++;
	} while (i < NBCOL);
	j++;
	i = 0;
      } while (actual_char != EOF);
  }
 
  if (fclose (fp) < 0)
    {
      perror ("Erreur lors de la fermeture du fichier : ");
      return -1;
    }
  return 0;
}


void display_map (v_list* l, char map[][NBLIN])
{
  /*
   * Affiche la carte stockée dans le tableau map
   */

  for (int j = 0; j < NBLIN; j++)
    {
      if (j >= 1){
	for (int i = 0; i < NBCOL; i++)
	  {
	  
	    if (check_pos (l, i, j) != NULL)
	      {
		afficher_v();
	      }
	    if (map[i][j] == 'w') // Eau
	      {
		couleur("46");
		printf(" ");
		couleur("0");
	      }
	    else if (map[i][j] == 'q')
	      {
		couleur("4");
		printf(" ");
		couleur("0");
	      }
	    else if (map[i][j] == 'i') 
	      {
		printf("═");
	      }
	    else if (map[i][j] == 'F') 
	      {
		printf("║");
	      }
	    else if (map[i][j] == 'l') 
	      {
		printf("─");
	      }
	    else if (map[i][j] == 't') 
	      {
		printf("╝");
	      }
	    else if (map[i][j] == 'R') 
	      {
		printf("╦");
	      }
	    else if (map[i][j] == 'g') 
	      {
		printf("╩");
	      }
	    else if (map[i][j] == 'K') 
	      {
		printf("╔");
	      }
	    else if (map[i][j] == 'k') 
	      {
		printf("╚");
	      }
	    else if (map[i][j] == 'u') 
	      {
		printf("╝");
	      }
	    else if (map[i][j] == 'y') 
	      {
		printf("╗");
	      }
	    else if (map[i][j] == 'j') 
	      {
		printf("│");
	      }
	    else if (map[i][j] == 'X') 
	      {
		printf("┼");
	      }
	    else if (map[i][j] == 'Y') 
	      {
		printf("┤");
	      }
	    else if (map[i][j] == 'Z') 
	      {
		printf("├");
	      }
	    else if (map[i][j] == 'z') 
	      {
		printf("┐");
	      }
	    else if (map[i][j] == 'L') 
	      {
		printf("└");
	      }
	    else if (map[i][j] == 'W') 
	      {
		printf("┘");
	      }
	    else if (map[i][j] == 'Q') 
	      {
		printf("┌");
	      }
	    else if (map[i][j] == 'h') 
	      {
		printf("┴");
	      }
	    else if (map[i][j] == 'H') 
	      {
		printf("┬");
	      }
	    else
	      {
		printf ("%c", map[i][j]);
	      }
	  }
      }
    }
  printf("\n");
}
