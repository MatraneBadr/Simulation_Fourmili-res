#ifndef REINE_H
#define REINE_H


#include "fourmiliere.h"
#include "oeuf.h"

class Reine
{
    private:
        int _consommation;
    
    public:
        Reine();
        ~Reine();
        int getConsommation(){return _consommation;};
        void ponteOeuf(vector<Oeuf*>& listOeuf);
        void consommerNourriture(Fourmiliere maisonFourmis);

};
#endif