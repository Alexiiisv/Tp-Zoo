#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"

#include <vector>
#include <string>

using namespace std;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;
class Zoo
{
    string m_name;
    AnimalList m_animals;
public:
    Zoo(string name = "");
    void addAnimal(IAnimal* animal);
    void fire();
    void UpdateAge();


    //getter
    string getName();
    void getAName();
    void getARace();
    void getAGender();
};

#endif // ZOO_H
