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

int map_loading (v_list* l)
{
  FILE* fp = NULL;
  int actual_char; int x = 0; int y = 0;
  fp = fopen ("./doc/plan.txt", "r");
  if (fp == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier : ");
      return -1;
    }
  else {
    while (actual_char != EOF)
      {
	if (check_pos (l, x, y) != NULL)
	  {
	    afficher_v();
	    fseek (fp, 1, SEEK_CUR);
	  }
	else
	  {
	    actual_char = fgetc (fp);
	    if (actual_char == EOF) break;
	    /*if (actual_char == 'T') // Arbre
	      {
	      printf("🌴");
	      }
	      else if (actual_char == 'B') // Boite aux lettes
	      {
	      printf("📪");
	      }
	      else if (actual_char == 'e') // Caddie
	      {
	      printf("🛒");
	      }
	      else if (actual_char == 'p') // Parabole
	      {
	      printf("📡");
	      }*/
	    if (actual_char == 'w') // Eau
	      {
		couleur("46");
		printf(" ");
		couleur("0");
	      }
	    else if (actual_char == 'q')
	      {
		couleur("4");
		printf(" ");
		couleur("0");
	      }
	    else
	      {
		printf ("%c", actual_char);
	      }
	    /* On lit le caractère */
	  }
	x++;
	if (x > 182)
	  {
	    x = 0;
	    y++;
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
