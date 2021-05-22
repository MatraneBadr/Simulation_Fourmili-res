#ifndef CELLULE_H
#define CELLULE_H
typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;
class Cellule {
    private:
        int x;
        int y;
        T_TYPE_CELLULE type;
    public :
        Cellule();
        Cellule( int coordX, int coordY, T_TYPE_CELLULE type );
    
        
        T_TYPE_CELLULE getType() const;
        void setType(T_TYPE_CELLULE type);

        Cellule getSuivant() const;//droite puis retour à la ligne puis retour a premiere cellule
        Cellule getDessus() const;
        Cellule getDessous() const;
        Cellule getDroite() const;
        Cellule getGauche() const;
};
#endif // CELLULE_H