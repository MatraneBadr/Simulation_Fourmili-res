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

void Reine::reineConsomme(){
    //Discussion avec Badr ce soir
    cout << "consommation" << endl;
}

Oeuf Reine::ponteOeuf()
{
    Oeuf a;
    a = Oeuf();
    return a;
}
