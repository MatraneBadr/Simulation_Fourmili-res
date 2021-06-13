#include "../headers/fourmiliere.h"

Fourmiliere::Fourmiliere(int populationMax, int nourritureMax, int nourriture,int x,int y):Cellule(x,y,FOURMILIERE){  
    _popMax = populationMax;
    _nourritureMax = nourritureMax;
    _nourriture = nourriture;
    _population = 1;

}

Fourmiliere::~Fourmiliere(){
}

bool Fourmiliere::consommationNourriture(int n){
    if(_nourriture - n < 0) {
        return false;
    } else {
        _nourriture -= n;
        return true;
    }
}

void Fourmiliere::ajoutNourriture(int n){
    if(_nourriture + n >= _nourritureMax) {
        _nourriture = _nourritureMax;
    } else {
        _nourriture += n;
    }
}

void Fourmiliere::setNourriture(int n)
{
    this->nourriture = n;
}

void Fourmiliere::setNourMax(int nm)
{
    this->_nourritureMax = nm;
}

void Fourmiliere::setPopmax(int pm)
{
    this->_popMax = pm;
}