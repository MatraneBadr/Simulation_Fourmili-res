#include "cellule.h"
 
class Obstacle:public Cellule
{
public:
    Obstacle(int x,int y):Cellule(x,y,OBSTACLE){};
};
