
#ifndef FOURMIGUERRIERE_H
#define FOURMIGUERRIERE_H

#include "cellule.h"
#include <vector>
#include <string>
#include "environnement.h"
using std::vector;
using std::string;
class FourmisGuerriere
{
    private:
        /* data */
        int _quantiteStocke;
        int _capacite;
        int _vie;
        int _age;
        int _x;
        int _y;
        int _consomation;


    public:
        FourmisGuerriere();
        FourmisGuerriere(int x , int y);
        char direction(vector<char> domainedeplacement,vector<vector<Cellule> >& vect);
        void seDeplacer(vector<vector<Cellule> >& vect,char dir,vector<char> domainedeplacement);
        //~FourmisGuerriere();
        int getX(){return _x;};
        int getY(){return _y;};
        void setX(int x){_x=x;};
        void setY(int y){_y=y;};
        void stockage(vector<vector<Cellule> >& vect, int positionXFood, int positionYFood);
        int getVie() { return _vie; };
        void diminutionVie();
        int ravitailler(int vie);
        int getCapacite() { return _capacite;}
        int getQuantiteStocke() { return _quantiteStocke; }
        vector<char> etudeEnvironnement(vector<vector<Cellule> >& vect,int x,int y);
        void eviteObstacleChercheNourriture(vector<vector<Cellule> >& vect,int x,int y,char dir,vector<char> domainedeplacement);






};
#endif