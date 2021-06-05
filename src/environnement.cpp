
#include "../headers/environnement.h"
#include <iostream>

Environnement::Environnement()
{
    largeur=100;
    hauteur=50;
    tauxPheromone=0.95;
    nbreObstacle=1000;
    nbreNourriture=500;

    
    //initObstacleNourriture(true);
   // insereNewFourmiliere(hauteur/2,largeur/2,200,1000,100);
}

Environnement::Environnement(int nbreO, int nbreN, int l, int h, int tauxPhero)
{
    nbreObstacle=nbreO;
    nbreNourriture=nbreN;
    largeur=l;
    hauteur=h;
    tauxPheromone=tauxPhero;
    initTerrain();
    initObstacle();
    initNourriture();
    insereNewFourmiliere(hauteur/2,largeur/2,200,1000,100);
}

Environnement::~Environnement()
{   
}

void Environnement::affiche(int x,int y){
    for (int i=0 ; i < terrain.size();i++){
        std::cout<<std::endl;
        for (int j = 0 ; j < terrain[i].size(); j++){
            if (i==x && j==y) std::cout<<"L";
            if(terrain[i][j].getType() == LIBRE)  std::cout<<"_";
            else if (terrain[i][j].getType() == OBSTACLE)  std::cout<<"X";
            else if (terrain[i][j].getType() == NOURRITURE)  std::cout<<"O";
            else if (terrain[i][j].getType() == FOURMILIERE)  std::cout<<"F";
        }
    }
    std::cout<<std::endl;
}
/*
void Environnement::initObstacleNourriture(bool cellulesSontLibres){
    if(!cellulesSontLibres) {
        //ajouter traitement remise à libre de toutes les cellules
    }
    int x,y;
    for (int i = 0; i<nbreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        getCelluleLibre(x,y).setType(OBSTACLE);
    }
    for (int i = 0; i<nbreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        Cellule* retenue = & getCelluleLibre(x,y);
        retenue->setType(NOURRITURE);
        retenue->setNourriture(500);
    }
}
*/
void Environnement::insereNewFourmiliere(int x, int y, int pm, int nm, int n){
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    terrain[x][y] = Fourmiliere(x,y,pm,nm,n);
}

Cellule& Environnement::getCellule(int x, int y) {
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    return terrain[x][y];
}

Cellule& Environnement::getCelluleLibre(int x, int y) {
    while (terrain[x][y].getType() != LIBRE){
        if (y<largeur-1) y++;
        else if (x<hauteur-1) { x++; y=0;}
        else { x=0 ; y=0;}
    }
    return terrain[x][y];
}

bool Environnement::contientNourriture(int x,int y)
{
    bool cR=false;
    if(terrain[x][y].getType()==NOURRITURE)
        cR=true;
    return cR;

}
bool Environnement::contientObstacle(int x,int y)
{
    bool cO=false;
    if(terrain[x][y].getType()==OBSTACLE)
        cO=true;
    return cO;

}
void Environnement::initTerrain()
{
    terrain.resize(hauteur);
    for (int i=0 ; i < terrain.size();i++){
        terrain[i].resize(largeur);
        for (int j = 0 ; j < terrain[i].size(); j++){
            terrain[i][j] = Cellule( i , j , LIBRE);
        }
    }
}
void Environnement::initObstacle()
{
    int x,y;
    for (int i = 0; i<nbreObstacle;i++){
        x = rand() % hauteur;
        y = rand() % largeur;
        getCelluleLibre(x,y).setType(OBSTACLE);
    }
}
void Environnement::initNourriture()
{
    int x,y;
    for (int i = 0; i<nbreNourriture;i++){
        x = rand() % hauteur;
        y = rand() % largeur; 
        getCelluleLibre(x,y).setType(NOURRITURE);
    }
}
