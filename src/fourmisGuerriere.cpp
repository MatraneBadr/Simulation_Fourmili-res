#include "../headers/fourmisGuerriere.h"

FourmisGuerriere::FourmisGuerriere()
{
    _quantiteStocke=0;
    _capacite=10;
    _vie=100;
    _x=0;
    _y=0;
}

FourmisGuerriere::FourmisGuerriere(int quantiteStocke, int capacite, int vie, int x , int y)
{
    _quantiteStocke = quantiteStocke;
    _capacite = capacite;
    _vie = vie;
    _x=x;
    _y=y;
}


char FourmisGuerriere::direction(){
  int randNumber = rand();
    int x = (randNumber % 4) + 1;

    if (x = 1)
        return 'h';
    else if (x = 2)
        return 'b';
    else if (x = 3)
        return 'g';
    else
        return 'd';
}

void FourmisGuerriere::seDeplasser(char dir)
{
    switch(dir)
    {
        case 'h': this->_y--; break;
        case 'b': this->_y++; break;
        case 'g': this->_x--; break;
        case 'd': this->_x++; break;
    }
}
int FourmisGuerriere::stockage(int capacite,int quantiteStocke, int quantiteDisponible)
{
    /*
        La fourmis va récupérer de la nourriture sur la case nourriture en fonction de sa capacite
        si elle ne plus plus stocker de nourriture elle va laisser la case 
    */
    if (quantiteStocke == capacite)
    {
        ;
    }
    else
    {
        quantiteStocke = quantiteStocke + capacite;
        if (quantiteStocke>capacite){
            int reste = 0;
            reste = quantiteStocke - capacite;
            quantiteStocke = capacite;
            /* utiliser les pointeur pour modifier la valeur de la nourriture ou la fourmis a agit */

        }
    }
}

void FourmisGuerriere::diminutionVie(){
    /* Diminution de la vie à chaque tour si la vie de la fourmis est a zero elle meurt
     */
    _vie -=  1 ;
}

int FourmisGuerriere::ravitailler(int vie){
    /* Pour ce ravitailler la fourmis doit manger a voir comment ça fonctionne */
}