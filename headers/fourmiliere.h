#ifndef FOURMILIERE_H
#define FOURMILIERE_H
#include <vector>
#include "cellule.h" 

class Fourmiliere : public Cellule
{
private:
    int _popMax;
    int _nourriture;
    int _nourritureMax;
    int _population;


public:
    Fourmiliere();
    Fourmiliere(int populationMax, int nourritureMax, int nourriture,int x, int y);
    ~Fourmiliere();
    bool consommationNourriture(int n);
    void ajoutNourriture(int n);
    void setPopmax(int pm);
    void setNourMax(int nm);
    void setNourriture(int n);
    int getNourriture(){return _nourriture;};
    int getPopulation(){return _population;};

};
#endif