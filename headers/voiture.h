#ifndef VOITURE_H
#define VOITURE_H

typedef struct
{
    char direction; /* N (NORD), S (SUD), E (EST), O (OUEST) */
    char from; /* N (NORD), S (SUD), E (EST), O (OUEST) */
    int posx; /* position courante x de la voiture */
    int posy; /* position courante y de la voiture */
    int vitesse; /* vitesse de la voiture : 1 (rnormale), 2 (rapide) */
    char alignement; /* 'g' (gauche), 'd' (droite) */
    char type; /* type du vehicule : 'v' (voiture), 'c' (camion) */ 
    char custom[30]; /* contient le véhicule customisé */
    char etat; /* actif ou inactif */
    struct voiture* NXT; /* pointe vers la prochaine voiture de la liste chainée */
} voiture;


#endif

  
