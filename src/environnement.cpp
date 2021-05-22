#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include "../headers/environnement.h"
#include <iostream>
Environnement::Environnement()
{
    largeur=100;
    hauteur=50;
    tauxPheromone=0.95;
    nbreObstacle=1000;
    nbreNourriture=500;
    terrain.resize(hauteur);
    for (int i=0 ; i < terrain.size();i++){
        terrain[i].resize(largeur);
        for (int j = 0 ; j < terrain[i].size(); j++){
            terrain[i][j] = Cellule( i , j , LIBRE);
        }
    }
}

Environnement::Environnement(int nbreO, int nbreN, int l, int h, int tauxPhero)
{
    nbreObstacle=nbreO;
    nbreNourriture=nbreN;
    largeur=l;
    hauteur=h;
    tauxPheromone=tauxPhero;
}

Environnement::~Environnement()
{   
}

void Environnement::affiche(){
    for (int i=0 ; i < terrain.size();i++){
        std::cout<<std::endl;
        for (int j = 0 ; j < terrain[i].size(); j++){
            if(terrain[i][j].getType() == LIBRE)  std::cout<<"_";
            else if (terrain[i][j].getType() == OBSTACLE)  std::cout<<"X";
            else if (terrain[i][j].getType() == NOURRITURE)  std::cout<<"O";
            else if (terrain[i][j].getType() == FOURMILIERE)  std::cout<<"F";
        }
    }
    std::cout<<std::endl;
}

#endif // ENVIRONNEMENT_H