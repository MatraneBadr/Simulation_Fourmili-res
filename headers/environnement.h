#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <vector>
#include "cellule.h"
#include "fourmisGuerriere.h"
#include "fourmiliere.h"
#include "nourriture.h"
#include "obstacle.h"
#include <algorithm>
class Environnement
{
private:
    /* data */
    int nbreObstacle;
    int nbreFourmis;
    int nbreNourriture;
    int largeur;
    int hauteur;
    int tauxPheromone;
    std::vector<std::vector<Cellule> > terrain;
    std::vector<Nourriture> nourritures;
    std::vector<Obstacle> obstacles;
    std::vector<FourmisGuerriere> fourmis;
    Fourmiliere* toto;
public:
    Environnement();
    Environnement(int nbreO, int nbreN, int nbrF,int l, int h, int tauxPhero);
    ~Environnement();
    int getNbreObstacle() const { return nbreObstacle;}
    void setNbreObstacle(int nbreO) {nbreObstacle=nbreO;}
    int getNbreNourriture() const { return nbreNourriture;}
    void setNbreNourriture(int nbreN) {nbreNourriture=nbreN;}
    int getLargeur() const { return largeur;}
    std::vector<std::vector<Cellule> >  getTerrain() const { return terrain;}
    void setLargeur(int l) {largeur=l;}
    int getHauteur() const { return hauteur;}
    void setHauteur(int h) {hauteur=h;}
    int getTauxPheromone() const { return tauxPheromone;}
    void setTauxPheromone(int tauxPhero) {tauxPheromone=tauxPhero;}
    void affiche();
    void insereNewFourmiliere(Fourmiliere& maisonFourmis);
    void initObstacleNourriture(bool cellulesSontLibres);
    bool contientNourriture(int x,int y);
    bool contientObstacle(int x,int y);
    void initTerrain();
    void initObstacle();
    void initNourriture();
    void initFourmis();
    bool contientFourmi(int x,int y);
    void testDep();
    void newObsatcle(int nbrNewObstacle);
    void newNourriture(int nbrNewNourriture);
    Cellule& getCellule(int x, int y);
    Cellule& getCelluleLibre(int x, int y);
    void checkSimulation();
    void checkFourmis();

};
#endif