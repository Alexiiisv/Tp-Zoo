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
    string getName();
    void addAnimal(IAnimal* animal);
    void fire();
};

#endif // ZOO_H
