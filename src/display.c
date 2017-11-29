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

int map_loading (v_list* l)
{
  FILE* fp = NULL;
  int* n;
  int actual_char = 0, x = 0, y = 0, compteur = 0, a = 0, b = 0;
  fp = fopen ("./doc/plan.txt", "r");
  if (fp == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier : ");
      return -1;
    }
  else {
    
    do /*Compte le nombre de retour chariot*/
      {
	actual_char = fgetc (fp);
	if (actual_char == '\n')
	  {
	    compteur++;
	  }
      } while (actual_char != EOF);

    actual_char = 0;
    fseek (fp, 0, SEEK_SET);

    n = malloc (compteur * sizeof(int)); /*alloue le tableau de la position des \n */
 
    do /* case i -> taille la ligne i*/
      {
	actual_char = fgetc (fp);
	if (actual_char == '\n')
	  {
	    n[b] = a -1;
	    a = 0;
	    b++;
	  }
	a++;
      } while (actual_char != EOF); 

    actual_char = 0;
    fseek (fp, 0, SEEK_SET);
    
    do 
      {
	/*if (check_pos (l, x, y) != NULL)
	  {
	    afficher_v();
	    fseek (fp, 1, SEEK_CUR);
	    }*/
	if (x == 7  && y == 12)
	  {
	    afficher_v();
	    fseek (fp, 1, SEEK_CUR);
	  }
	else
	  {
	    actual_char = fgetc (fp); 	    /* On lit le caractère */
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
      else if (actual_char == 'i') 
      {
        printf("═");
      }
      else if (actual_char == 'F') 
      {
        printf("║");
      }
      else if (actual_char == 'l') 
      {
        printf("─");
      }
      else if (actual_char == 't') 
      {
        printf("╝");
      }
      else if (actual_char == 'R') 
      {
        printf("╦");
      }
      else if (actual_char == 'g') 
      {
        printf("╩");
      }
      else if (actual_char == 'K') 
      {
        printf("╔");
      }
      else if (actual_char == 'k') 
      {
        printf("╚");
      }
      else if (actual_char == 'u') 
      {
        printf("╝");
      }
      else if (actual_char == 'y') 
      {
        printf("╗");
      }
      else if (actual_char == 'j') 
      {
        printf("│");
      }
      else if (actual_char == 'X') 
      {
        printf("┼");
      }
      else if (actual_char == 'Y') 
      {
        printf("┤");
      }
      else if (actual_char == 'Z') 
      {
        printf("├");
      }
      else if (actual_char == 'z') 
      {
        printf("┐");
      }
      else if (actual_char == 'L') 
      {
        printf("└");
      }
      else if (actual_char == 'W') 
      {
        printf("┘");
      }
      else if (actual_char == 'Q') 
      {
        printf("┌");
      }
      else if (actual_char == 'h') 
      {
        printf("┴");
      }
      else if (actual_char == 'H') 
      {
        printf("┬");
      }

	    else
	      {
		printf ("%c", actual_char);
	      }
	  }
	x++;
	if (x > n[y])
	  {
	    x = 0;
	    y++;
	  }
      } while (actual_char != EOF);
  }
  if (fclose (fp) < 0)
    {
      perror ("Erreur lors de la fermeture du fichier : ");
      return -1;
    }
  return 0;
}
