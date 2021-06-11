#include "ihabitat.h"
#include <iostream>
using namespace std;

IHabitat::IHabitat()
    : m_type("habitat sans race")
{
}



IHabitat::IHabitat(string type)
    : m_type(type)
{

}

void IHabitat::addAnimal(IAnimal *animal)
{
    m_animals.push_back(animal);
}


IHabitat::~IHabitat()
{
    
}

void IHabitat::getAnimal()
{
    cout << "-------------------" << endl;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        cout << (*it)->getName() << endl;
        it++;
    }
    cout << "-------------------" << endl;
}

void IHabitat::SetCapacity(int capacity)
{
    m_capacity = capacity;
}

int IHabitat::getCapacity()
{
    return m_capacity;
}

string IHabitat::getType()
{
    return m_type;
}