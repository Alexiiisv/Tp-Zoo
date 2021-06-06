#include "ianimal.h"

IAnimal::IAnimal()
    :m_name("Animal sans Nom")
{

}

IAnimal::IAnimal(string name)
    :m_name(name)
{

}

IAnimal::~IAnimal()
{

}

string IAnimal::getName()
{
    return m_name;
}

string IAnimal::getRace()
{
    return m_race;
}

void IAnimal::SetRace(string race)
{
    m_race = race;
}