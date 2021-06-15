#include "../headers/fourmisGuerriere.h"
#include "../headers/cellule.h"
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
FourmisGuerriere::FourmisGuerriere()
{
    _quantiteStocke=0;
    _capacite=10;
    _vie=150;
    _age=0;
    _x=0;
    _y=0;
}

FourmisGuerriere::FourmisGuerriere( int x , int y)
{
    _quantiteStocke = 0;
    _capacite = 10;
    _vie = 15;
    _age = 0;
    _x=x;
    _y=y;
}


char FourmisGuerriere::direction(vector<char> domainedeplacement,vector<vector<Cellule> >& vect){

    srand((unsigned int)time(NULL));
    int x = rand() % domainedeplacement.size() ; 
    char dir=domainedeplacement[x];
    return dir;

}
void FourmisGuerriere::eviteObstacleChercheNourriture(vector<vector<Cellule> >& vect,int x, int y, char dir,vector<char> domainedeplacement)
{

        if(vect[x][y].getType()==OBSTACLE){
            domainedeplacement.erase(std::remove(domainedeplacement.begin(),domainedeplacement.end(),dir),domainedeplacement.end());
            char dir= direction(domainedeplacement,vect);
            seDeplacer(vect,dir,domainedeplacement);
        }
        if(vect[x][y].getType()==NOURRITURE){
            stockage(vect,x,y);
            vect[x][y].addPheromone(1);
            cout<<"nbr pheromone dans la cellule ("<<x<<","<<y<<")="<<vect[x][y].getPheromone()<<endl;
        }
        else if(vect[x][y].getType()==LIBRE)
        {
            this->_x=x;
            this->_y=y;
        }
}

vector<char> FourmisGuerriere::etudeEnvironnement(vector<vector<Cellule> >& vect,int hauteur,int largeur)
{

    vector<char> direction;
    int positionX,positionY;
    positionX = this->getX();
    positionY = this->getY();


   if (positionX ==0)
   {
       if (positionY==0) //Si la fourmis est dans le coin supérieur gauche
       {
            direction.push_back('d');
            direction.push_back('b');
       }
       else if (positionY == largeur-1) //Si la fourmis est dans le coin supérieur droit
       {
            direction.push_back('g');
            direction.push_back('b');
       }
       else //colonne 0
       {
            direction.push_back('g');
            direction.push_back('d');
            direction.push_back('b');
       }
   }
   else if(positionY==0)
   {
       if(positionX == hauteur-1) //Si la fourmis est dans le coin inférieur gauche
       {
            direction.push_back('d');
            direction.push_back('h');
       }
       else //ligne 0
       {
            direction.push_back('h');
            direction.push_back('d');
            direction.push_back('b');
       }
   }
   else if (positionX == hauteur-1)
   {
       if (positionY ==largeur-1) //Si la fourmis est dans le coin inférieur droit
       {
            direction.push_back('g');
            direction.push_back('h');
       }
       else//colonne max
       {
            direction.push_back('g');
            direction.push_back('d');
            direction.push_back('h');
       }
   }
    else if (positionY == largeur-1) //ligne max
   {
            direction.push_back('g');
            direction.push_back('h');
            direction.push_back('b');
   }
   else //Nimporte quel autre cas
   {
        direction.push_back('g');
        direction.push_back('d');
        direction.push_back('h');
        direction.push_back('b');
   }

    return direction;
}
void FourmisGuerriere::seDeplacer(vector<vector<Cellule> >& vect,char dir,vector<char> domainedeplacement)
{
    
    int positionX,positionY;
    positionX = this->getX();
    positionY = this->getY();

    switch(dir)
    {
        case 'h':positionX--; eviteObstacleChercheNourriture(vect,positionX,positionY,dir,domainedeplacement);break;
        case 'b':positionX++; eviteObstacleChercheNourriture(vect,positionX,positionY,dir,domainedeplacement);break;
        case 'g':positionY--; eviteObstacleChercheNourriture(vect,positionX,positionY,dir,domainedeplacement);break;
        case 'd':positionY++; eviteObstacleChercheNourriture(vect,positionX,positionY,dir,domainedeplacement);break;
    }
    
}
void FourmisGuerriere::stockage(vector<vector<Cellule> >& vect, int positionXFood, int positionYFood)
{
    int hauteur,largeur;
    if (this->_capacite > this->_quantiteStocke)
    {
        cout << "Fourmi  stock" << endl ;
        this->_quantiteStocke = this->_quantiteStocke + 1 ;
        vect[positionXFood][positionYFood].setType(LIBRE);
        this->_x = positionXFood;
        this->_y = positionYFood;
    }
    /*
    else
    {
        cout << "Fourmi c" << endl;
    }
*/
    
}

bool FourmisGuerriere::diminutionVie(){
    /* Diminution de la vie à chaque tour si la vie de la fourmis est a zero elle meurt
     */
    bool Fourmimorte=false;
   if(_vie==0)
   {
       Fourmimorte=true;
   }
   else{
       _vie--;
       _age++;
   }
   return Fourmimorte;
}

void FourmisGuerriere::ravitailler(int vie){
    /* Pour ce ravitailler la fourmis doit manger a voir comment ça fonctionne */
}

void FourmisGuerriere::destockage(Fourmiliere& maisonFourmis)
{
    maisonFourmis.ajoutNourriture(this->_quantiteStocke);
    this->_quantiteStocke = 0 ;
}

void FourmisGuerriere::retourMaison(int hauteur, int largeur)
{
    std::cout << "La fourmis va a la maison" << std::endl;
    this->_x = hauteur/2 ;
    this->_y = largeur/2;
}