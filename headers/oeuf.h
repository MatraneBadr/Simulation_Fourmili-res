#ifndef OEUF_H
#define OEUF_H
#include "fourmiliere.h"

class Oeuf{
    private:
        int _consommation;
        int _age;

    public:
        Oeuf();
        ~Oeuf();
        int getConsommation(){return _consommation;};
        int getAge(){return _age;};
        void Vieillir();
        void consommerNourriture(Fourmiliere maisonFourmis);

};

#endif