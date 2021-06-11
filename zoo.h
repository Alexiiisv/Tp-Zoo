#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"
#include "ihabitat.h"

#include <vector>
#include <string>

using namespace std;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;
typedef vector <IHabitat*> HabitatList;
typedef HabitatList::iterator HabitatIterator;
class Zoo
{
    string m_name;
    AnimalList m_animals;
    HabitatList m_habitats;
public:
    Zoo(string name = "");
    void addAnimal(IAnimal* animal);
    void addHabitat(IHabitat* habitat);
    void fire();
    void UpdateAge();


    //getter
    string getName();
    void getAName();
    void getARace();
    void getAGender();
    void GetHabitatSize();
};

#endif // ZOO_H
