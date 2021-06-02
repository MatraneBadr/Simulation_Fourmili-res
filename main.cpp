#include <iostream>
#include <vector>
#include "src/environnement.cpp"
#include "src/cellule.cpp"
#include "src/fourmiliere.cpp"
#include "src/fourmisGuerriere.cpp"
using namespace std;

int main()
{
    
    
    Environnement monEnv;
    int Xfoumis=monEnv.getHauteur()/2;
    int Yfourmis=monEnv.getLargeur()/2;
    
    std::vector<std::vector<Cellule> > terrain=monEnv.getTerrain();
    FourmisGuerriere* fourmi =new FourmisGuerriere(0,10,100,10,0,0);
    monEnv.affiche(fourmi);
    cout<<fourmi->getX()<<endl;
    cout<<fourmi->getY()<<endl;
    vector<char> domaine=fourmi->etudeEnvironnement(terrain,monEnv.getHauteur(),monEnv.getLargeur());
    for(int i=0;i<domaine.size();i++)
    {
        cout<<domaine[i]<<endl;
    }
    char dir =fourmi->direction(domaine,terrain);
    cout<<"directionnnn\n"<<dir<<endl;
    
    fourmi->seDeplacer(terrain,dir,domaine);
    monEnv.affiche(fourmi);
    cout<<fourmi->getX()<<endl;
    cout<<fourmi->getY()<<endl;
    
    return 0;
}
