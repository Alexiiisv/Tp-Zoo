#include "../header/zoo.h"
#include <iostream>
using namespace std;

Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
    year = 0;
}

void Zoo::addAnimal(IAnimal *animal)
{
    if (animal->getRace() == "aigle")
    {
        cout << "tu a acheter un " << animal->getRace() << endl;
        setAnimalHabitat(animal, 0);
    }
    
}

void Zoo::addHabitat(IHabitat *habitat)
{
    m_habitats.push_back(habitat);
    if (habitat->getType() == "aigle")
    {
        aigle_Habitat += 1;
    }
}

void Zoo::NextMonth()
{
    month += 1;
}

void Zoo::UpdateAge()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        (*it)->UpdateAge();
        it++;
    }
}

void Zoo::UpdateFood()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {        
        viande -= (*it)->getFood()*30;
        if (viande <= 0)
        {
            viande = 0;
            break;
        }
        
        it++;
    }
}

void Zoo::UpdateHabitat()
{
    int i = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == "aigle")
        {
            (*it)->delAnimal(rand()%5);
        }
        
        it++;
        i++;
    }
}

void Zoo::UpdateBudget(float Budget)
{
    budget += Budget;
}


/*
GETTER
*/

string Zoo::getName()
{
    return m_name;
}

float Zoo::getFood()
{
    return viande;
}

float Zoo::getBudget()
{
    return budget;
}

int Zoo::getMonth()
{
    return month;
}

int Zoo::getYear()
{
    return year;
}

int Zoo::getHAigle()
{
    return aigle_Habitat;
}

int Zoo::getHTigre()
{
    return tigre_Habitat;
}

int Zoo::getHPoules()
{
    return poules_Habitat;
}

int Zoo::getAGender(string gender, string race)
{
    int result = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        result += (*it)->getAGender(gender, race);
        it++;
    }
    return result;
}

void Zoo::getInfo()
{
    cout << getName() <<  "\nYear : " << getYear() << "\nMonth : " << getMonth() << "\nBudget : " << getBudget() << endl;
}

void Zoo::getAllInfo(string race)
{
    int i;
    HabitatIterator it = m_habitats.begin();
    cout << "-------------------" << endl;
    while (it != m_habitats.end())
    {
        (*it)->getAnimal();
        it++;
    }
}

void Zoo::GetHabitatSize()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        cout << (*it)->getCapacity() << endl;
        it++;
    }
}

void Zoo::GetHabitatType(string type)
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == type)
        {
            cout << (*it)->getType() << "zergfojuin" << endl;
        }
        it++;
    }
}

void Zoo::GetHabitatAnimal()
{
    int i = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        cout << "habitat numero " << i << endl;
        (*it)->getAnimal();
        it++;
        i++;
    }
}

int Zoo::GetAnimalNbrByRace(string race)
{
    int result = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == race)
        {
            result += (*it)->getnbrAnimals();
        }
        it++;
    }
    return result;
}


/*
SETTER
*/

void Zoo::setFood(float food) 
{
    viande = food;
}

void Zoo::setYear(float Year) 
{
    year += Year;
}

void Zoo::setMonth(float Month) 
{
    month = Month;
}

void Zoo::setBudget(float Budget) 
{
    budget = Budget;
}
void Zoo::setAnimalHabitat(IAnimal* animal, int HAnimal)
{
    int i;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (i == HAnimal)
        {
            (*it)->addAnimal(animal);
        }
        it++;
        i++;
    }
}