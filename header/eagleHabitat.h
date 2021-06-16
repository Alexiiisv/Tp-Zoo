#ifndef EAGLEHABITAT_H
#define EAGLEHABITAT_H
#include <string>
#include "ihabitat.h"

using namespace std;

class EagleHabitat:public IHabitat
{
public:
    EagleHabitat();
    EagleHabitat(string type);
    void addAnimal(IAnimal* animal);
    void UpdateAge(int Id);
    
    // getter
    void getAnimal();
    virtual int getCapacity();
    virtual string getType();
    virtual float getFood();
};

#endif // EAGLEHABITAT_H
