#include "../headers/reine.h"
#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::endl;


Reine::Reine()
{
    _consommation = 30 ;
}

Reine::~Reine()
{
}

void Reine::consommerNourriture(Fourmiliere maisonFourmis){
    maisonFourmis.consommationNourriture(_consommation);
    cout << "consommation" << endl;
}

void Reine::ponteOeuf(vector<Oeuf*>& listOeuf)
{
    /*
        A chaque fois que la fonction est appelé la reine va pondre un oeuf
        L'oeuf nouvellement crée est alors stocké dans la variable listOeuf
        Tableau dynamique
    */
    Oeuf* newOeuf;
    newOeuf = new Oeuf();
    listOeuf.push_back(newOeuf);
}
