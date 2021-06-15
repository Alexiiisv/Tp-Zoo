#include "../header/ihabitat.h"
#include <iostream>
// #include<bits/stdc++.h>
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
    nbr_animals++;
}

void IHabitat::delAnimal(int qtt, string state)
{
    if (m_capacity < nbr_animals && state == "plein")
    {
        cout << "un animal va canner : " << m_animals[qtt]->getName() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "Deplacement")
    {
        cout << "un animal a ete deplace : " << m_animals[qtt]->getName() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "vol")
    {
        cout << "un animal a ete deplace : " << m_animals[qtt]->getName() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    
    
}

void IHabitat::UpdateAge()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        (*it)->UpdateAge();
        cout << (*it)->getAge() << endl;
        it++;
    }
}

IHabitat::~IHabitat()
{
    
}

void IHabitat::getAnimal()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        cout << "Nom\t" << (*it)->getName() << endl;
        cout << "Sexe\t" << (*it)->getGender() << endl;
        cout << "Age\t" << (*it)->getAge()/12 << " ans " << (*it)->getAge()%12 << " mois" << endl;
        cout << "race\t" << (*it)->getRace() << endl;
        cout << "food\t" << (*it)->getFood() << endl;
        cout << "-------------------" << endl;
        it++;
    }
}

float IHabitat::getFood()
{
    float food = 0; 
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        food += (*it)->getFood()*30;
        it++;
    }
    return food;
}
int IHabitat::getnbrAnimals() 
{
    return nbr_animals;
}
void IHabitat::SetCapacity(int capacity)
{
    m_capacity = capacity;
}

int IHabitat::getCapacity()
{
    return m_capacity;
}

string IHabitat::getSingleAnimalInfoS(string info, int id)
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it) == m_animals[id])
        {
            if (info == "Name")
            {
                return (*it)->getName();
            }else if (info == "Gender")
            {
                return (*it)->getGender();
            }else if (info == "Race")
            {
                return (*it)->getRace();
            }
        }
        it++;
    }
    return "";
}

float IHabitat::getSingleAnimalInfoI(string info, int id)
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it) == m_animals[id])
        {
            if (info == "Age")
            {
                return (*it)->getAge();
            }else if (info == "Food")
            {
                return (*it)->getFood();
            }
        }
        it++;
    }
    return 0;
}

string IHabitat::getType()
{
    return m_type;
}

int IHabitat::getAGender(string gender, string race) {
    int result = 0;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it)->getGender() == gender && (*it)->getRace() == race)
        {
            result +=1;
        }
        it++;
    }
    return result;
}