struct voiture 
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
    struct voiture * NXT; /* pointe vers la prochaine voiture de la liste chainée */
}

/* VEHICULE_LIST append(VEHICULE_LIST l, VEHICULE *v)
// methode pour ajouter une voiture à la liste chainée l
{
    if(!l)
        return v;
    else
    {
        VEHICULE *tmp = l;

        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = v;

        return l;
    }
}

VEHICULE_LIST remove_out(VEHICULE_LIST l)
// methode pour retirer une voiture de la liste chainée l
{
    if(!l)
        return NULL;

    VEHICULE *head = l;

    if(head->is_out)
    {
        VEHICULE *tmp = head;

        head = head->next;
        free(tmp);

        return head;
    }

    VEHICULE *tmp = head->next, *prec = head;

    while(tmp)
    {
        if(tmp->is_out)
        {
            tmp = tmp->next;
            free(prec->next);
            prec->next = tmp;
        }

        prec = tmp;
        tmp = tmp->next;
    }

    return head;
} */
