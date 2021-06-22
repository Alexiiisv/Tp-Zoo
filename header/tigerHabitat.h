#ifndef TIGERHABITAT_H
#define TIGERHABITAT_H
#include <string>
#include "ihabitat.h"

using namespace std;

class TigerHabitat:public IHabitat
{
public:
    TigerHabitat();
    TigerHabitat(string type);
    void addAnimal(IAnimal* animal);
    void UpdateAge(int Id);
    
    // getter
    void getAnimal();
    virtual int getCapacity();
    virtual string getType();
    virtual float getMeat();
};

#endif // TIGERHABITAT_H
