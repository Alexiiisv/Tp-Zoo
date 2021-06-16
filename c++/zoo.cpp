#include "../header/zoo.h"
#include "../header./aigle.h"
#include <iostream>
using namespace std;
//Create the zoo
Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
    year = 0;
}
//Add an animal to a specific habitat
void Zoo::addAnimal(IAnimal *animal, int habitat)
{
    if (animal->getRace() == "aigle")
    {
        cout << "tu as acheter un " << animal->getRace() << endl;
        setAnimalHabitat(animal, habitat);
    }
    
}
//Buy a habitat
void Zoo::addHabitat(IHabitat *habitat)
{
    m_habitats.push_back(habitat);
    if (habitat->getType() == "aigle")
    {
        aigle_Habitat += 1;
        budget -= 2000;
    }
}
//Sell a habitat
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

void Zoo::SellAnimal(int IdAni, int IdHab)
{
    int id = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (IdHab == id)
        {
            budget += (*it)->getAnimalValue(IdAni);
            (*it)->delAnimal(IdAni-1, "Vente");
        }
        it++;
        id++;
    }
}

//Fire event
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
//increase the month value by one
void Zoo::NextMonth()
{
    month += 1;
}
//update the age of all animal by one
void Zoo::UpdateAge()
{
    int Id = 0, nbrani;
    string todo = "";
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        nbrani = (*it)->getnbrAnimals();
        while (Id != nbrani)
        {
            todo = (*it)->UpdateAge(Id);
            if (todo == "A Kill")
            {
                (*it)->delAnimal(Id, "Creve");
                Id--;
            }
            Id++;
            nbrani = (*it)->getnbrAnimals();
        }
        Id = 0;
        it++;
    }
}
//update the food situation about the animal consumption
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
//Check if the habitat don't overpopulate
void Zoo::UpdateHabitat()
{
    int i = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == "aigle")
        {
            (*it)->delAnimal(rand()%5, "Plein");
        }
        
        it++;
        i++;
    }
}
//Stealing event
void Zoo::VolDanimal(string state)
{
    if (GetHabitatNbrByRace(state) != 0)
    {
        int randhab = rand() % GetHabitatNbrByRace(state);
        if (m_habitats[randhab]->getnbrAnimals() != 0)
        {
            int randani = rand() % m_habitats[randhab]->getnbrAnimals();
            m_habitats[randhab]->delAnimal(randani, "Vol");
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
//Update the budget the zoo have
void Zoo::UpdateBudget(float Budget)
{
    budget += Budget;
}
//switch a animal from the habitat 1 to the habitat 2
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
//Get name of the zoo
string Zoo::getName()
{
    return m_name;
}
//Get value of the zoo
float Zoo::getFood()
{
    return viande;
}
//Get the budget of the zoo
float Zoo::getBudget()
{
    return budget;
}
//Get the current month
int Zoo::getMonth()
{
    return month;
}
//Get the current year
int Zoo::getYear()
{
    return year;
}
//Get the number of eagle habitat
int Zoo::getHAigle()
{
    return aigle_Habitat;
}
//Get the number of tiger habitat
int Zoo::getHTigre()
{
    return tigre_Habitat;
}
//Get the number of chicken habitat
int Zoo::getHPoules()
{
    return poules_Habitat;
}
//Get the number of animal by race
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
//Get the information about the zoo
void Zoo::getInfo()
{
    cout << getName() <<  "\nYear : " << getYear() << "\nMonth : " << getMonth() << "\nBudget : " << getBudget() << endl;
}
//Get all the information about all the animal per race
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
//Get the size of all habitat
void Zoo::GetHabitatSize()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        cout << (*it)->getCapacity() << endl;
        it++;
    }
}
//Inutile
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
//Get information about animal per habitat
void Zoo::GetHabitatAnimal(string State)
{
    int i = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (State == "All Habitat")
        {
            cout << "habitat " << (*it)->getType() << endl;
            (*it)->getAnimal();
        } else if (State == (*it)->getType()) 
        {
            cout << "habitat " << (*it)->getType() << " " << i << endl;
            (*it)->getAnimal();
        } else if (stoi(State) == i)
        {
            cout << "habitat " << (*it)->getType()  << " " << i <<  endl;
            (*it)->getAnimal();
            break;
        }
                
        it++;
        i++;
    }
}
//Get the amount of animal per race
int Zoo::GetAnimalNbrByRace(string State)
{
    int result = 0, id = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == State) //tigre/aigle/poules
        {
            result += (*it)->getnbrAnimals();
        }else if (id == stoi(State))
        {
            return (*it)->getnbrAnimals();
        }
        
        it++;
        id++;
    }
    return result;
}
//Get the amount of habitat per race
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
//Set the amount of food the user buy
void Zoo::setFood(float food) 
{
    viande = food;
}
//Set the year
void Zoo::setYear(float Year) 
{
    year += Year;
}
//Set the month
void Zoo::setMonth(float Month) 
{
    month = Month;
}
//Set the budget
void Zoo::setBudget(float Budget) 
{
    budget = Budget;
}
//Set a animal to a specific habitat
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