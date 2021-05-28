#ifndef FOURMILIERE_H
#define FOURMILIERE_H
#endif
#include "../headers/fourmiliere.h"

Fourmiliere::Fourmiliere(int populationMax, int nourritureMax, int nourriture){  
    x = 0;
    y = 0;
    _popMax = populationMax;
    _nourritureMax = nourritureMax;
    _nourriture = nourriture;
    
}

Fourmiliere::~Fourmiliere(){
}

int Fourmiliere::consommationNourriture(int consommation){
    _nourriture = _nourriture - consommation;
}

void Fourmiliere::generationFourmis(){
}