#include"cellule.h"

class Nourriture : public Cellule{
    private:
        int _valeur;
    public:
    Nourriture(int x,int y,int val):Cellule(x,y,NOURRITURE){
        this->_valeur=val;
    };
    int getValeur(){return this->_valeur;};
    void setValeur(int val){
        this->_valeur=val;
    };

};