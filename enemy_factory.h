//Implementare de design pattern-ului factory
#include "weed.h"
#include "grass.h"

class EnemyFactory{
public:
    static Grass iarba() {return Grass();}
    static Weed buruiana() {return Weed();}
};