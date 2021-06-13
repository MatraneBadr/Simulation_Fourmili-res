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

    int nbrObstacle, nbrNourriture,nbreFourmis, nbTour, largeur, hauteur,newNbrObstacle,newNbrNourriture;
    bool partieEnCours;
    std::vector<std::vector<Cellule> > terrain;
    char start,newON;
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
    cout<<"Nombre de tour:"<<endl;
    cin>>nbTour; 
    cout<<"Start (Y/N)?:"<<endl;
    cin>>start;
    cout << "----------------------------------------" << std::endl;
    if(start=='Y' || start=='y')
    {
        partieEnCours=true ;
    }else{
        partieEnCours=false;
    }
    if(partieEnCours)
    {    
        cout<<"Debut de la partie\n";
        Environnement* monEnv=new Environnement(nbrObstacle,nbrNourriture,nbreFourmis,largeur,hauteur,0.95);
        monEnv->affiche();
        
        for (size_t i = 0; i < nbTour; i++)
        {
            if(i==nbTour/2)
            {
               cout<<"Voulez vous ajouter de nouveaux Obstacles et Nourritures (Y/N)?:"<<endl; 
               cin>>newON;
                   if(newON=='Y')
                    {
                            cout<<"Nombre Obstacle ="<<endl;
                            cin>>newNbrObstacle;
                            cout<<"Nombre Nourriture ="<<endl;
                            cin>>newNbrNourriture;
                            monEnv->newNourriture(newNbrNourriture);
                            monEnv->newObsatcle(newNbrObstacle);
                    }

            }
            cout <<"Tour number:"<<i<<endl; 
            monEnv->testDep();
            monEnv->affiche();
            monEnv->checkSimulation();
            monEnv->checkFourmis();
        }
        cout<<"Fin de la partie" << endl;
    }
    else{
        cout<<"FERMETURE DU PROGRAMME" << endl;
    }
    
    return 0;
}
