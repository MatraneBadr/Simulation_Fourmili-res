#include <iostream>
#include <vector>
#include "src/environnement.cpp"
#include "src/cellule.cpp"
#include "src/fourmiliere.cpp"
#include "src/fourmisGuerriere.cpp"
#include "src/reine.cpp"
#include "src/oeuf.cpp"
using namespace std;

int main()
{

    int nbrObstacle, nbrNourriture,nbreFourmis, nbTour, largeur, hauteur;
    bool partieEnCours;
    std::vector<std::vector<Cellule> > terrain;
    char start;
    cout << "----------------------------------------" << std::endl;
    cout << " Menu      FOURMILIERE      PROJET LP73 " << std::endl;
    cout<<"Nombre Obstacle ="<<endl;
    cin>>nbrObstacle;
    cout<<"Nombre Nourriture ="<<endl;
    cin>>nbrNourriture;
    cout<<"Nombre Fourmis ="<<endl;
    cin>>nbreFourmis;
    cout<<"Largeur ="<<endl;
    cin>>largeur;
    cout<<"Hauteur ="<<endl;
    cin>>hauteur;
    cout<<"Start (Y/N)?:"<<endl;
    cin>>start;
    cout << "----------------------------------------" << std::endl;
    if(start=='Y')
    {
        partieEnCours=true ;
    }else{
        partieEnCours=false;
    }
    if(partieEnCours)
    {    
        cout<<"Nombre de tour:"<<endl;
        cin>>nbTour; 
        cout<<"Debut de la partie\n";
        Environnement* monEnv=new Environnement(nbrObstacle,nbrNourriture,nbreFourmis,largeur,hauteur,0.95);
        monEnv->affiche();
        
        for (size_t i = 0; i < nbTour; i++)
        {
            cout <<"TOUR "<<i<<endl; 
            monEnv->testDep();
            monEnv->affiche();
        }
        cout<<"Fin de la partie\n";
    }
    else{
        cout<<"A+\n";
    }
    
    return 0;
}
