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
        int getConsommation(){return _consommation;};
        Oeuf ponteOeuf();
        void reineConsomme();

};
#endif