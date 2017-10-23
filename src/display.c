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