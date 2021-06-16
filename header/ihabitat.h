#ifndef HABITAT_H
#define HABITAT_H

#include <vector>
#include <string>

#include "ianimal.h"

using namespace std;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;

class IHabitat
{
private:
    string m_type;
    int m_capacity, nbr_animals = 0;
    AnimalList m_animals;

public:
    IHabitat();
    IHabitat(string m_type);
    void addAnimal(IAnimal* animal);
    void delAnimal(int qtt, string state);
    string UpdateAge(int id);
    
    virtual ~IHabitat();
    virtual void getAnimal();
    virtual float getFood();
    virtual int getAnimalValue(int IdAni);
    virtual int getnbrAnimals();
    virtual int getCapacity();
    virtual float getSingleAnimalInfoI(string info, int id);
    virtual string getSingleAnimalInfoS(string info, int id);
    virtual string getType();
    int getAGender(string gender, string race);
    virtual void SetCapacity(int capacity);
};

#endif // HABITAT_H
