#include <iostream>
#include "src/environnement.cpp"
#include "src/cellule.cpp"

#include "src/fourmisGuerriere.cpp"
using namespace std;

int main()
{
    
    
    Environnement monEnv;
    int Xfoumis=monEnv.getHauteur()/2;
    int Yfourmis=monEnv.getLargeur()/2;
    FourmisGuerriere* fourmi =new FourmisGuerriere(0,10,100,Xfoumis,Yfourmis);
    //monEnv.affiche(fourmi);
    cout<<fourmi->getX()<<endl;
    cout<<fourmi->getY()<<endl;
    char d=fourmi->direction();
    cout<<"directionnnn"<<d<<endl;
    fourmi->seDeplasser(d);
    //monEnv.affiche(fourmi);
    cout<<fourmi->getX()<<endl;
    cout<<fourmi->getY()<<endl;
    return 0;
}
