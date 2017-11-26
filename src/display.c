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

int map_loading (char map[][61])
{
  FILE* fp = NULL;
  char actual_char; int x = 0, y = 0;
  fp = fopen ("./doc/plan.txt", "r");
  if (fp == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier : ");
      return -1;
    }
  else {
    do
      {
	actual_char = fgetc(fp); /* On lit le caractère */
	if (actual_char != EOF)
	  map[x][y] = actual_char;
	x++;
	if (x > 175)
	  {
	    x = 0;
	    y++;
	  }
      }
    while (actual_char != EOF);
  }
  if (fclose (fp) == EOF)
    {
      perror ("Erreur lors de la fermeture du fichier : ");
      return -1;
    }
  return 0;
}

void affichage_map(char map[][61]) 
{
  /*
   * Fonction d'affichage de la map
   */
  for (int j = 0; j < 61; j++)
    {
      for (int i = 0; i < 175; i++)
	{
	  if (map[i][j] == 'T') // Arbre
            {
	      printf("🌴");
            }
	  else if (map[i][j] == 'B') // Boite aux lettes
            {
	      printf("📪");
            }
	  else if (map[i][j] == 'e') // Caddie
            {
	      printf("🛒");
	    }
	  else if (map[i][j] == 'p') // Parabole
            {
	      printf("📡");
            }
	  else if (map[i][j] == 'w') // Eau
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
	  else if (map[i][j] == 'v')
	    {
	      afficher_v();
	    }
	  else
	    {
	      printf ("%c", map[i][j]);
	    }
	}
    }
}
