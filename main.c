#include "header.h"

int main()
{
    liste *liste = NULL;
    int  choix;
    liste = malloc(sizeof(liste));
    liste->nbelem = 0;

    while (1)
    {
    choix =0;
    menuP(&choix);
    switch(choix)
    {

case 1:

    ajout(liste);
printf("bite");
    break;
case 2:

    break;
case 3:

    break;
case 4:

    break;
case 5:

    break;
case 6:
    affichage(liste);
    break;
case 7:
    exit(0);
    break;
    }
    }
}
