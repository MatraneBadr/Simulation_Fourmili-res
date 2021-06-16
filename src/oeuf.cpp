#include "../headers/oeuf.h"
#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::endl;

Oeuf::Oeuf()
{
    _consommation = 1;
    _age = 0;
    _etat=OEUF;
}

Oeuf::~Oeuf()
{
}

void Oeuf::Vieillir()
{
    _age++;
}

void Oeuf::consommerNourriture(Fourmiliere maisonFourmis)
{
    maisonFourmis.consommationNourriture(_consommation);
}