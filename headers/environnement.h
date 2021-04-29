//my class environnement.h

class environnement
{
private:
    /* data */
    int nbreObstacle;
    int nbreNourriture;
    int largeur;
    int hauteur;
    int tauxPheromone;


public:
    environnement();
    environnement(int nbreO, int nbreN, int l, int h, int tauxPhero);
    ~environnement();
    int getNbreObstacle() const { return nbreObstacle;}
    void setNbreObstacle(int nbreO) {nbreObstacle=nbreO;}
    int getNbreNourriture() const { return nbreNourriture;}
    void setNbreNourriture(int nbreN) {nbreNourriture=nbreN;}
    int getLargeur() const { return largeur;}
    void setLargeur(int l) {largeur=l;}
    int getHauteur() const { return hauteur;}
    void setHauteur(int h) {hauteur=h;}
    int getTauxPheromone() const { return tauxPheromone;}
    void setTauxPheromone(int tauxPhero) {tauxPheromone=tauxPhero;}

};
