#include "../headers/environnement.h"

environnement::environnement()
{
    this->largeur=100;
    this->hauteur=50;
    this->tauxPheromone=0.95;
    this->nbreObstacle=1000;
    this->nbreNourriture=500;
}

environnement::environnement(int nbreObstacle, int nbreNourriture, int largeur, int hauteur, int tauxPheromone)
{
    this->nbreObstacle=nbreObstacle;
    this->nbreNourriture=nbreNourriture;
    this->largeur=largeur;
    this->hauteur=hauteur;
    this->tauxPheromone=tauxPheromone;
}

environnement::~environnement()
{
}

int getLargeur()
{
    return this->largeur;
}

int getHauteur()
{
    return this->hauteur;
}

int getNbreNourriture()
{
    return this->nbreNourriture;
}

int getTauxPheromone()
{
    return this->tauxPheromone;
}

int getNbreObstacle()
{
    return this->nbreObstacle;
}

void setNbreObstacle(int nbreObstacle)
{
    this->nbreObstacle = nbreObstacle;
}

void setNbreNourriture(int nbreNourriture)
{
    this->nbreNourriture = nbreNourriture;
}

void setHauteur(int hauteur)
{
    this->hauteur = hauteur;
}

void setLargeur(int largeur)
{
    this->largeur = largeur;
}

void setTauxPheromone(int tauxPheromone)
{
    this->tauxPheromone = tauxPheromone;
}
