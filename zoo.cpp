#include "zoo.h"

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

void Zoo::fire()
{
    AnimalIterator it = m_animals.begin();
    while(it != m_animals.end()){
        (*it)->fire();
        it++;
    }
}


