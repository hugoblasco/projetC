/** 
* Toutes les fonctions d'affichage (menu de lancement, map)
*/
#include "../headers/display.h"

void menu() 
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
  printf(" / /   / / __/ / / /   \__ \/ / __ `__ \/ / / / / __ `/ __/ __ \/ ___/ \n");
  printf("/ /___/ / /_/ /_/ /   ___/ / / / / / / / /_/ / / /_/ / /_/ /_/ / /     \n");
  printf("\____/_/\__/\__, /   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/\____/_/      \n");
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
      break;
    case 'f': //mode fluide
      //LANCER FONCTION MODE FLUIDE
      break;
    case 'd': //mode danger
      //LANCER FONCTION MODE DANGER
      break;
    default:
      printf ("Entrée invalide\n");
      menu ();
    }
}

void affichage_map(v_list* l) 
{
  /*
   * Fonction d'affichage de la map
   */
  
  FILE* fd = NULL;
  int x = 0; int y = 0;
  int caractere_actuel = 0;
  fd = fopen("./doc/plan.txt", "r");
  if (fd == NULL)
    {
      perror ("Erreur lors de l'ouverture du fichier ");
      exit (-1);
    }
  else
    {
      do
        {
	  caractere_actuel = fgetc(fd); /* On lit le caractère */
	  if (caractere_actuel == 'T') /* Arbre */
            {
	      printf("🌴");
            }
	  else if (caractere_actuel == 'B') /* Boite aux lettes */
            {
	      printf("📪");
            }
	  else if (caractere_actuel == 'e') /* Caddy */
            {
	      printf("🛒");
	    }
	    else if (caractere_actuel == 'p') /* Parabole */
            {
	      printf("📡");
            }
	    else if (caractere_actuel == 'w') /* Eau */
            {
	      couleur("46");
	      printf(" ");
	      couleur("0");
            }
	  else if (caractere_actuel == 'q')
            {
	      couleur("4");
	      printf(" ");
	      couleur("0");
            }
	  else 
            {
	      printf("%c", caractere_actuel); // On l'affiche
            }
	  /* AFFICHAGE DES VOITURES */
	  if (check_pos(l, x, y) != NULL)
	    {
	      afficher_v();
	    } 
	  x++;
	  if (x >= 175)
	    {
	      x = 0;
	      y++;
	    }
        } while (caractere_actuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
      fclose(fd); // On ferme le fichier qui a été ouvert
    }	
}
