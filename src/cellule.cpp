
#include "../headers/cellule.h"

Cellule::Cellule(){
    x = 0;
    y = 0;
    _pheromones=0;
    type=LIBRE;
}
Cellule::Cellule(int coordX, int coordY,int pheromone, T_TYPE_CELLULE type){
    x = coordX;
    y = coordY;
    _pheromones=pheromone;
    this->type = type;
}

T_TYPE_CELLULE Cellule::getType() const {
    return type;
}

void Cellule::setType(T_TYPE_CELLULE type) {
    this->type = type;
}


void Cellule::setX(int newX)
{
    this->x = newX;
}

void Cellule::setY(int newY)
{
    this->y = newY;
}