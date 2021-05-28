class Fourmiliere
{
private:
    int _popMax;
    int _nourritureMax;
    int x;
    int y;
    int _nourriture;

public:
    Fourmiliere(int populationMax, int nourritureMax, int nourriture);
    ~Fourmiliere();
    int consommationNourriture(int consommation);
    void generationFourmis();

};