#ifndef CHICKENHABITAT_H
#define CHICKENHABITAT_H
#include <string>
#include "ihabitat.h"

using namespace std;

class ChickenHabitat:public IHabitat
{
public:
    ChickenHabitat();
    ChickenHabitat(string type);
    void addAnimal(IAnimal* animal);
    void UpdateAge(int Id);
    
    // getter
    void getAnimal();
    virtual int getCapacity();
    virtual string getType();
    virtual float getMeat();
};

#endif // CHICKENHABITAT_H
