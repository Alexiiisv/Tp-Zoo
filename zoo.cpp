#include "zoo.h"
#include <iostream>
using namespace std;

Zoo::Zoo(string name)
    :m_name(name)
{

}

string Zoo::getName()
{
    return m_name;
}

void Zoo::addAnimal(IAnimal *animal)
{
    m_animals.push_back(animal);
}

void Zoo::getAName()
{
    AnimalIterator it = m_animals.begin();
    while(it != m_animals.end()){
        (*it)->getName();
        it++;
    }
}
void Zoo::UpdateAge()
{
    AnimalIterator it = m_age.begin();
    while(it != m_animals.end()){
        (*it)->setAge();
        it++;
    }
}

void Zoo::getARace()
{
    AnimalIterator it = m_animals.begin();
    while(it != m_animals.end()){
        (*it)->getRace();
        it++;
    }
}
