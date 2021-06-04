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
