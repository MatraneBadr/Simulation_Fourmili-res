
#ifndef FOURMIGUERRIERE_H
#define FOURMIGUERRIERE_H
class FourmisGuerriere
{
    private:
        /* data */
        int _quantiteStocke;
        int _capacite;
        int _vie;
        int _x;
        int _y;
        int _consomation;


    public:
        FourmisGuerriere();
        FourmisGuerriere(int quantiteStocke, int capacite, int vie, int x , int y);
        char direction();
        void seDeplasser(char dir);
        //~FourmisGuerriere();
        int getX(){return _x;};
        int getY(){return _y;};
        void setX(int x){_x=x;};
        void setY(int y){_y=y;};
        int stockage(int capacite, int quantiteStocke, int quantiteDisponible);
        int getVie() { return _vie; };
        void diminutionVie();
        int ravitailler(int vie);
        int getCapacite() { return _capacite;}
        int getQuantiteStocke() { return _quantiteStocke; }





};
#endif