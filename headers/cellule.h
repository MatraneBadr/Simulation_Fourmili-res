#ifndef CELLULE_H
#define CELLULE_H
typedef enum { LIBRE, OBSTACLE, NOURRITURE, FOURMILIERE } T_TYPE_CELLULE ;
class Cellule {
    private:
        int x;
        int y;
        T_TYPE_CELLULE type;
    protected:
        double _pheromones;
    public :
        Cellule();
        Cellule( int coordX, int coordY,int pheromone, T_TYPE_CELLULE type );
        void setX(int newX);
        void setY(int newY);
        
        T_TYPE_CELLULE getType() const;
        void setType(T_TYPE_CELLULE type);
        void addPheromone(int qte){
            _pheromones+=qte;
        }
        void evaporationPheromone(double taux)
        {
            _pheromones=_pheromones*taux;
        }
        double getPheromone(){return _pheromones;}
};
#endif // CELLULE_H