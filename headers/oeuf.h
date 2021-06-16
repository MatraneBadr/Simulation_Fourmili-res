#ifndef OEUF_H
#define OEUF_H
#include "fourmiliere.h"
typedef enum { LARVE , OEUF  } T_ETAT_OEUF ;
class Oeuf{
    private:
        int _consommation;
        int _age;
        T_ETAT_OEUF _etat ;
    public:
        Oeuf();
        ~Oeuf();
        int getConsommation(){return _consommation;};
        int getAge(){return _age;};
        void Vieillir();
        void consommerNourriture(Fourmiliere maisonFourmis);
        void setEtat(T_ETAT_OEUF r){this->_etat=r;};
        T_ETAT_OEUF getEtat(){return _etat;};

};

#endif