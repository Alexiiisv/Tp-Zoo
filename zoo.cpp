#include "zoo.h"
#include <iostream>
using namespace std;

Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
}

void Zoo::addAnimal(IAnimal *animal)
{
    m_animals.push_back(animal);
    if (animal->getRace() == "aigle")
    {
        cout << "tu a acheter un " << animal->getRace() << endl;
        aigle += 1;
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

void Zoo::UpdateFood()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        viande -= (*it)->getFood()*30;
        if (viande <= 0)
        {
            viande = 0;
        }
        
        it++;
    }
}

void Zoo::UpdateAge()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        (*it)->UpdateAge();
        cout << (*it)->getAge() << endl;
        it++;
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

int Zoo::getAigle()
{
    return aigle;
}

int Zoo::getGAigle()
{
    return aigle;
}

int Zoo::getTigre()
{
    return tigre;
}

int Zoo::getPoules()
{
    return poules;
}

int Zoo::getCoq()
{
    return coq;
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

int Zoo::getAGender()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        cout << (*it)->getGender() << endl;
        it++;
    }
    return 0;
}

int Zoo::getAGender(string gender, string race)
{
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

void Zoo::getInfo()
{
    cout << getName() <<  "\nYear : " << getYear() << "\nMonth : " << getMonth() << "\nBudget : " << getBudget() << endl;
}

void Zoo::getAName()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        cout << (*it)->getName() << endl;
        it++;
    }
}

void Zoo::getARace()
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        cout << (*it)->getRace() << endl;
        it++;
    }
}

void Zoo::getAllInfo(string race)
{
    int i;
    AnimalIterator it = m_animals.begin();
    cout << "---------------" << endl;
    while (it != m_animals.end())
    {
        if ((*it)->getRace() == race)
        {
            i++;
            cout << race << " " << i << endl;
            cout << "Nom\t" << (*it)->getName() << endl;
            cout << "Sexe\t" << (*it)->getGender() << endl;
            cout << "Age\t" << (*it)->getAge()/12 << " ans " << (*it)->getAge()%12 << " mois" << endl;
            cout << "race\t" << (*it)->getRace() << endl;
            cout << "food\t" << (*it)->getFood() << endl;
            cout << "---------------" << endl;
        }
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