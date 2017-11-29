/** 
* Pour modifier la couleur d'un caractère ascii
*/

#ifndef COULEUR_H
#define COULEUR_H

// Sélection de couleurs
#define couleur(param) printf("\033[%sm",param)
/*   param devant être un const char *, vide (identique à "0") ou formé
     d'une où plusieurs valeurs séparées par des ; parmi
     0  réinitialisation         1  haute intensité (des caractères)
     5  clignotement             7  video inversé
     30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
     40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
     les couleurs, suivant la logique RGB, étant respectivement
     noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

#endif
