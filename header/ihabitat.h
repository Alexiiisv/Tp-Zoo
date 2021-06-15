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
    int m_capacity, nbr_animals = 0;
    AnimalLis m_animals;

public:
    IHabitat();
    IHabitat(string m_type);
    void addAnimal(IAnimal* animal);
    void delAnimal(int qtt, string state);
    void UpdateAge();
    
    virtual ~IHabitat();
    virtual void getAnimal();
    virtual float getFood();
    virtual int getnbrAnimals();
    virtual int getCapacity();
    virtual float getSingleAnimalInfoI(string info, int id);
    virtual string getSingleAnimalInfoS(string info, int id);
    virtual string getType();
    int getAGender(string gender, string race);
    virtual void SetCapacity(int capacity);
};

#endif // HABITAT_H
