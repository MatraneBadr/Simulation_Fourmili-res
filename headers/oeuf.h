#ifndef OEUF_H
#define OEUF_H

class Oeuf{
    private:
        int _consommation;
        int _age;

    public:
        Oeuf();
        int getConsommation(){return _consommation;};
        int getAge(){return _age;};
        void setAge();

};

#endif