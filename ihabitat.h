#ifndef HABITAT_H
#define HABITAT_H

#include <vector>
#include <string>

#include "ianimal.h"

using namespace std;

typedef vector <IAnimal*> AnimalLis;
typedef AnimalLis::iterator AnimalIterator;

class IHabitat
{
private:
    string m_type;
    int m_capacity;
    AnimalLis m_animals;

public:
    IHabitat();
    IHabitat(string m_type);
    void addAnimal(IAnimal* animal);
    
    virtual ~IHabitat();
    virtual void getAnimal();
    virtual int getCapacity();
    virtual string getType();
    virtual void SetCapacity(int capacity);
};

#endif // HABITAT_H
