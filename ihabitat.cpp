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

IHabitat::~IHabitat()
{
    
}

void IHabitat::SetCapacity(int capacity)
{
    m_capacity = capacity;
}

int IHabitat::getCapacity()
{
    return m_capacity;
}