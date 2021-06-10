
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

Environnement::Environnement(int nbreO, int nbreN, int nbrF, int l, int h, int tauxPhero)
{
    nbreObstacle=nbreO;
    nbreNourriture=nbreN;
    nbreFourmis=nbrF;
    largeur=l;
    hauteur=h;
    tauxPheromone=tauxPhero;
    initTerrain();
    initObstacle();
    initNourriture();
    initFourmis();
    insereNewFourmiliere(hauteur/2,largeur/2,200,1000,100);
}

Environnement::~Environnement()
{   
}

void Environnement::affiche(){
    for (int i=0 ; i < terrain.size();i++){
        std::cout<<std::endl;
        for (int j = 0 ; j < terrain[i].size(); j++){
            if (contientFourmi(i,j)) std::cout<<"L";
            else if (terrain[i][j].getType() == LIBRE)  std::cout<<"_";
            else if (contientObstacle(i,j))  std::cout<<"X";
            else if (contientNourriture(i,j))  std::cout<<"O";
            else if (terrain[i][j].getType() == FOURMILIERE)  std::cout<<"F";
        }
    }
    std::cout<<std::endl;
}

void Environnement::insereNewFourmiliere(int x, int y, int pm, int nm, int n){
    if (x >= hauteur or x < 0 or y < 0 or y > largeur) throw 0; //out of range
    terrain[x][y] = Fourmiliere(x,y,pm,nm,n); // appel au constructuer de fourmillere ok
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
        nourritures.push_back(Nourriture(x,y)); 
        obstacles.push_back(Obstacle(x,y));
    }
}
void Environnement::initFourmis()
{
    int x,y;
    for (int i = 0; i<nbreFourmis;i++){
        x = rand() % hauteur;
        y = rand() % largeur; 
        fourmis.push_back(FourmisGuerriere(x,y));
    }
}
bool Environnement::contientFourmi(int x,int y)
{
    bool cF=false;
    int k = 0;
    while(k<fourmis.size() and !cF){
        if(fourmis[k].getX() == x and fourmis[k].getY() == y) cF = true;
        k++;
    }
    return cF;

}
void  Environnement::testDep(){
     for (int i = 0; i<nbreFourmis;i++){
            vector<char> domaine=fourmis[i].etudeEnvironnement(terrain,hauteur,largeur);
            char dir =fourmis[i].direction(domaine,terrain);
            std::cout<<"Direction = "<<i<<dir<<std::endl;
            fourmis[i].seDeplacer(terrain,dir,domaine);
     }
}