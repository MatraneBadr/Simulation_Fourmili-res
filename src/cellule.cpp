
#include "../headers/cellule.h"

Cellule::Cellule(){
    x = 0;
    y = 0;
}
Cellule::Cellule(int coordX, int coordY, T_TYPE_CELLULE type){
    x = coordX;
    y = coordY;
    this->type = type;
}

T_TYPE_CELLULE Cellule::getType() const {
    return type;
}

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}
void Cellule::setNourriture(int n){
    this->nourriture = n;
}