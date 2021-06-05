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
    vector<Oeuf*> listOeuf;
    for (Oeuf* x : listOeuf)
    {
        cout << x << endl ;
    }
    
    
    Reine* maReine;
    maReine = new Reine();
    listOeuf = maReine->ponteOeuf(listOeuf);
    for (Oeuf* x : listOeuf)
    {
        cout << x->getAge() << endl ;
    }
    listOeuf = maReine->ponteOeuf(listOeuf);
    for (Oeuf* x : listOeuf)
    {
        cout << x->getAge() << endl ;
        x->Vieillir();
    }
    cout << "======Test====" << endl;
    for (Oeuf* x: listOeuf)
    {
        cout << x->getAge() << endl ;
    }
    

    /*
    int nbrObstacle, nbrNourriture, nbTour, largeur, hauteur;
    bool partieEnCours;
    std::vector<std::vector<Cellule> > terrain;
    char start;
    cout << "----------------------------------------" << std::endl;
    cout << " Menu      FOURMILIERE      PROJET LP73 " << std::endl;
    cout<<"Nombre Obstacle ="<<endl;
    cin>>nbrObstacle;
    cout<<"Nombre Nourriture ="<<endl;
    cin>>nbrNourriture;
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
        Environnement* monEnv=new Environnement(nbrObstacle,nbrNourriture,largeur,hauteur,0.95);
        terrain=monEnv->getTerrain();
        FourmisGuerriere* fourmi=new FourmisGuerriere(0,0);
        int x=fourmi->getX();
        int y=fourmi->getY();
        monEnv->affiche(x,y);
        for (size_t i = 0; i < nbTour; i++)
        {
            cout <<"TOUR "<<i<<endl;     
            vector<char> domaine=fourmi->etudeEnvironnement(terrain,hauteur,largeur);
            char dir =fourmi->direction(domaine,terrain);
            cout<<"Direction = "<<dir<<endl;
            fourmi->seDeplacer(terrain,dir,domaine);
            int newX=fourmi->getX();
            int newY=fourmi->getY();
            monEnv->affiche(newX,newY);
        }
        cout<<"Fin de la partie\n";
    }
    else{
        cout<<"A+\n";
    }
    */
/*
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
    */
    return 0;
}
