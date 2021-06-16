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
    int random = rand()%2;
    if (m_capacity < nbr_animals && state == "Plein" && random == 1)
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
    if (state == "Vol")
    {
        cout << "un animal a ete vole : " << m_animals[qtt]->getName() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "Vente")
    {
        cout << "un animal a ete vendu : " << m_animals[qtt]->getName() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "Creve")
    {
        cout << "un animal a canner de vieillesse : " << m_animals[qtt]->getName() << endl;
        cout << getnbrAnimals() << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals -= 1;
        cout << nbr_animals << endl;
    }
    
    
}

string IHabitat::UpdateAge(int id)
{
        m_animals[id]->UpdateAge();
        if (m_animals[id]->getAge() == 300)
        {
            return "A Kill";
        }
        return "Alive";
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

int IHabitat::getAnimalValue(int IdAni)
{
    int id = 1;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if (IdAni == id)
        {
            if ((*it)->getAge() < 48) //inferieur a 4ans
            {
                return 500;
            }
            if ((*it)->getAge() >= 48 && (*it)->getAge() < 168) //entre 4ans et 14ans
            {
                return 2000;
            }
            if ((*it)->getAge() >= 168 && (*it)->getAge() < 300) //entre 14ans et 25ans
            {
                return 400;
            }
            
        }
        it++;
        id++;
    }
    return 0;
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