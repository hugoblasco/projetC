/** 
* Toutes les fonctions d'affichage (menu de lancement, map)
*/

#include "../headers/couleur.h"

void menu() 
{
  boolean run = true;
  char lettre = '';
  printf("                                                                       ");
  printf("_______________________________________________________________________");
  printf("_______________________________________________________________________");
  printf("                                                                       ");
  printf("   _______ __           _____ _                 __      __             ");
  printf("  / ____(_) /___  __   / ___/(_)___ ___  __  __/ /___ _/ /_____  _____ ");
  printf(" / /   / / __/ / / /   \__ \/ / __ `__ \/ / / / / __ `/ __/ __ \/ ___/ ");
  printf("/ /___/ / /_/ /_/ /   ___/ / / / / / / / /_/ / / /_/ / /_/ /_/ / /     ");
  printf("\____/_/\__/\__, /   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/\____/_/      ");
  printf("           /____/                                                      ");
  printf("                                                                       ");
  printf("_______________________________________________________________________");
  printf("_______________________________________________________________________");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      ");
  printf("      *                                                         *      ");
  printf("      *                                                         *      ");
  printf("      *     Bienvenue sur notre plateforme de simulation !!     *      ");
  printf("      *                                                         *      ");
  printf("      *                 Choisissez votre mode :                 *      ");
  printf("      *                                                         *      ");
  printf("      *                      > [f] Fluide                       *      ");
  printf("      *                      > [d] Danger                       *      ");
  printf("      *                                                         *      ");
  printf("      *                      > [q] Quitter                      *      ");
  printf("      *                                                         *      ");
  printf("      *                                                         *      ");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");
  printf("                                                                       ");

  /*scanf("%c",lettre);
  while (run) 
  {
    switch (lettre)
    {
      case 'q':
        run = false;
        break;
      case 'f':
        //mode fluide
        break;
      case 'd':
        //mode danger
        break;
  */

}

void affichage_map() 
{
  FILE * fichier = NULL;
  int caractere_actuel = 0;
  fichier = fopen("./plan.txt", "r");
  if (fichier != NULL) 
    {
      do
        {
	  caractere_actuel = fgetc(fichier); // On lit le caractère
	  if (caractere_actuel == 'T') 
            {
	      printf("🌴");
            }
	  else if (caractere_actuel == 'B')
            {
	      printf("📪");
            }
	  else if (caractere_actuel == 'e') 
            {
	      printf("🛒");
	    }
	  else if (caractere_actuel == 'p') 
            {
	      printf("📡");
            }
	  else if (caractere_actuel == 'w') 
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
        } while (caractere_actuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
      printf("\033[60,10H🚘\n");
      fclose(fichier); // On ferme le fichier qui a été ouvert
    }
  else {
    printf("erreur d'ouverture du fichier");
  }
	
}
