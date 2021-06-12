#ifndef CELLULE_H
#define CELLULE_H
typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;
class Cellule {
    private:
        int x;
        int y;
        T_TYPE_CELLULE type;
    protected:
        int nourriture;
    public :
        Cellule();
        Cellule( int coordX, int coordY, T_TYPE_CELLULE type );
        void setX(int newX);
        void setY(int newY);
        
        T_TYPE_CELLULE getType() const;
        void setType(T_TYPE_CELLULE type);
        
         void setNourriture(int n);
};
#endif // CELLULE_H