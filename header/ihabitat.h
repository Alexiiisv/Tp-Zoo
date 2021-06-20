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
    int m_capacity, nbr_animals = 0, bb = 0, EagleEggs = 0;
    AnimalList m_animals;

public:
    IHabitat();
    IHabitat(string m_type);
    void addAnimal(IAnimal* animal);
    void delAnimal(int qtt, string state);
    string UpdateAge(int id);
    virtual void UpdateMalade(int year, int month);
    virtual void UpdMating();
    
    virtual ~IHabitat();
    virtual void getAnimal();
    virtual float getMeat();
    virtual int getAnimalValue(int IdAni);
    virtual int getnbrAnimals();
    virtual int getCapacity();
    virtual int getEagleEggs();
    virtual float getSingleAnimalInfoI(string info, int id);
    virtual string getSingleAnimalInfoS(string info, int id);
    virtual string getType();
    int getAGender(string gender, string race, int age);
    virtual void SetCapacity(int capacity);
    virtual void SetEagleEggs(int eagleEggs);
};

#endif // HABITAT_H
