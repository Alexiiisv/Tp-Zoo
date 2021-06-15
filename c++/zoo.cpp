#include "../header/zoo.h"
#include "../header./aigle.h"
#include <iostream>
using namespace std;

Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
    year = 0;
}

void Zoo::addAnimal(IAnimal *animal, int habitat)
{
    if (animal->getRace() == "aigle")
    {
        cout << "tu a acheter un " << animal->getRace() << endl;
        setAnimalHabitat(animal, habitat);
    }
    
}

void Zoo::addHabitat(IHabitat *habitat)
{
    m_habitats.push_back(habitat);
    if (habitat->getType() == "aigle")
    {
        aigle_Habitat += 1;
        budget -= 2000;
    }
}

void Zoo::SellHabitat(string Race)
{
    int less = 0, id = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getnbrAnimals() < m_habitats[less]->getnbrAnimals() && (*it)->getType() == Race)
        {
            less = id;
        }
        id++;
        it++;
    }
    cout << less << endl;
    m_habitats.erase(m_habitats.begin()+less);
    if (Race == "Poule")
    {
        budget += 50;
    } else {
        budget += 500;
    }
    
}

void Zoo::FireHabitat(string Race)
{
    if (GetHabitatNbrByRace(Race) != 0)
    {
        int randHab = rand() % GetHabitatNbrByRace(Race);
        m_habitats.erase(m_habitats.begin()+randHab);
        if (Race == "aigle")
        {
            cout << "un feu s'est declare dans ton habitat d'" << Race << "\nTout tes Animaux dans cet habitat sont morts. Chaud" << endl;
        }else {
            cout << "un feu s'est declare dans ton habitat de " << Race << "\nTout tes Animaux dans cet habitat sont morts. Chaud" << endl;
        }
        
    }else {
        cout << "Un feu s'est declare dans ton zoo fort heureusement les pompiers l'ont maitrise avant d'atteindre un habitat." << endl;
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
            (*it)->delAnimal(rand()%5, "plein");
        }
        
        it++;
        i++;
    }
}

void Zoo::VolDanimal(string state)
{
    if (GetHabitatNbrByRace(state) != 0)
    {
        int randhab = rand() % GetHabitatNbrByRace(state);
        if (m_habitats[randhab]->getnbrAnimals() != 0)
        {
            int randani = rand() % m_habitats[randhab]->getnbrAnimals();
            m_habitats[randhab]->delAnimal(randani, "vol");
            if (state == "poule")
            {
                cout << "Une " << state << " a ete vole" << endl;
            }else {
                cout << "Un " << state << " a ete vole" << endl;
            }
            
        }else {
            cout << "Il y a eu une tentative de vol dans un de tes habitats,\nHeureusement il etait vide." << endl;
        }
        
    } else {
        cout << "tu n'as pas d'habitat qui accueille les " << state << endl;
    }
    
}

void Zoo::UpdateBudget(float Budget)
{
    budget += Budget;
}

void Zoo::SwitchHabitat(int hab1, int IdAni, int hab2)
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it) == m_habitats[hab1-1])
        {
            m_habitats[hab2-1]->addAnimal( new Aigle((*it)->getSingleAnimalInfoS("Name", IdAni-1), (*it)->getSingleAnimalInfoS("Race", IdAni-1), (*it)->getSingleAnimalInfoS("Gender", IdAni-1), (*it)->getSingleAnimalInfoI("Food", IdAni-1), (*it)->getSingleAnimalInfoI("Age", IdAni-1))); //zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age), habitat - 1);
            m_habitats[hab2-1]->getAnimal();
            m_habitats[hab1-1]->delAnimal(IdAni-1, "Deplacement");
            break;
        }
    it++;
    }
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
            cout << (*it)->getType() << endl;
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

int Zoo::GetHabitatNbrByRace(string race)
{
    int result = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == race)
        {
            result += 1;
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
            break;
        }
        it++;
        i++;
    }
}