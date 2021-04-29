#include "../headers/environnement.h"

environnement::environnement()
{
    largeur=100;
    hauteur=50;
    tauxPheromone=0.95;
    nbreObstacle=1000;
    nbreNourriture=500;
}

environnement::environnement(int nbreO, int nbreN, int l, int h, int tauxPhero)
{
    nbreObstacle=nbreO;
    nbreNourriture=nbreN;
    largeur=l;
    hauteur=h;
    tauxPheromone=tauxPhero;
}

environnement::~environnement()
{   
}