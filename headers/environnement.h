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
    environnement(int nbreObstacle, int nbreNourriture, int largeur, int hauteur, int tauxPheromone);
    ~environnement();
    int getNbreObstacle();
    void setNbreObstacle(int nbreObstacle);
    int getNbreNourriture();
    void setNbreNourriture(int nbreNourriture);
    int getLargeur();
    void setLargeur(int largeur);
    int getHauteur();
    void setHauteur(int hauteur);
    int getTauxPheromone();
    void setTauxPheromone(int tauxPheromone);

};
