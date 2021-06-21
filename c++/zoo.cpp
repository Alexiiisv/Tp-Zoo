#include "../header/zoo.h"
#include "../header./aigle.h"
#include "../header./poule.h"

#include <time.h>
#include <iostream>
using namespace std;
//Create the zoo
Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
    year = 0;
    aigle_Habitat = 0;
    poules_Habitat = 0;
    tigre_Habitat = 0;
}
//Add an animal to a specific habitat
void Zoo::addAnimal(IAnimal *animal, int habitat)
{
    cout << animal->getRace() << endl;
    if (animal->getRace() == "aigle")
    {
        cout << "tu as acheter un " << animal->getRace() << endl;
        setAnimalHabitat(animal, habitat);
    }
    if (animal->getRace() == "poule")
    {
        cout << "tu as acheter un " << animal->getRace() << endl;
        setAnimalHabitat(animal, habitat);
    }
    
}
//Buy a habitat
void Zoo::addHabitat(IHabitat *habitat)
{
    if (habitat->getType() == "aigle" && budget-2000 >= 0)
    {
        aigle_Habitat += 1;
        budget -= 2000;
        m_habitats.push_back(habitat);
        cout << "achat d'habitat d'aigles" << endl;
    }
    else if (habitat->getType() == "poule" && budget-300 >= 0)
    {
        poules_Habitat += 1;
        budget -= 300;
        m_habitats.push_back(habitat);
        cout << "achat d'habitat de poules" << endl;
    }
    else {
        cout << "tu n'as pas assez d'argent pour acheter un habitat pour les " << habitat->getType() << endl;
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

void Zoo::UpdateMalade()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (getYear() > 0 && getMonth() == 1)
        {
            (*it)->UpdateMalade(getYear(), getMonth());
        }
        it++;
    }
}

void Zoo::reproduction(int state)
{
    int F = 0, M = 0, randDeath = 0, mort = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {  
        if ((*it)->getType() == "aigle")
        {
            if (state == 3)
            {
            
                F = (*it)->getAGender("Female", "aigle", 2);
                M = (*it)->getAGender("Male", "aigle", 2);
                cout << "\tfemme " << F << "\n\thomme " << M << endl;
                if (F >= M)
                {
                    int ratio = F - M;
                    int nbFemellePonte = F - ratio;
                    (*it)->SetEagleEggs(nbFemellePonte * 2); // chaque aigle femelle pond 2 oeufs
                    cout << "nombre d'oeufs d'aigle : " << (*it)->getEagleEggs() << endl;
                }
            }
            else if (state == 5)
            {
                // range over each eggs to see if they die
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    randDeath = rand() % 2; // Generate 0 or 1
                    // Lorsqu'un aigle est mort né
                    if (randDeath == 1)
                    {
                        (*it)->SetEagleEggs((*it)->getEagleEggs()-1);
                        mort++;
                    }
                }
                cout << "nb de bb aigles : " << (*it)->getEagleEggs() << endl;
                cout << "nb de bb aigles MORT : " << mort << endl;
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    srand(time(0));
                    int randSex = rand() % 2;
                    float food;
                    string sex;
                    char name[16];

                    switch (randSex)
                    {
                    case 0:
                        sex = "Male";
                        food = 0.25;
                        break;
                    default:
                        sex = "Female";
                        food = 0.3;
                        break;
                    }
                    cout << "Donnez un nom au bebe aigle numero " << i << endl;
                    scanf("%15s", &name);
                    cout << name << endl;

                    (*it)->addAnimal(new Aigle(name, "aigle", sex, food, 0));
                }
                (*it)->SetEagleEggs(0);
            }
        }
        
        it++;
    }
}
//update the food situation about the animal consumption
void Zoo::UpdateMeat()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {        
        if ((*it)->getType() == "aigle")
        {
            viande -= (*it)->getMeat();
            if (viande <= 0)
            {
                viande = 0;
                break;
            }
        }
        it++;
    }
}

void Zoo::UpdateSeed()
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {        
        if ((*it)->getType() == "poule")
        {
            graines -= (*it)->getMeat();
            if (graines <= 0)
            {
                graines = 0;
                break;
            }
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
            (*it)->UpdMating();
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
void Zoo::SwitchHabitat(int hab1, int IdAni, int hab2, string race)
{
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it) == m_habitats[hab1-1] && race == "aigle")
        {
            m_habitats[hab2-1]->addAnimal( new Aigle((*it)->getSingleAnimalInfoS("Name", IdAni-1), (*it)->getSingleAnimalInfoS("Race", IdAni-1), (*it)->getSingleAnimalInfoS("Gender", IdAni-1), (*it)->getSingleAnimalInfoI("Food", IdAni-1), (*it)->getSingleAnimalInfoI("Age", IdAni-1))); //zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age), habitat - 1);
            m_habitats[hab2-1]->getAnimal();
            m_habitats[hab1-1]->delAnimal(IdAni-1, "Deplacement");
            break;
        }
        else if ((*it) == m_habitats[hab1-1] && race == "poule")
        {
            m_habitats[hab2-1]->addAnimal( new Poule((*it)->getSingleAnimalInfoS("Name", IdAni-1), (*it)->getSingleAnimalInfoS("Race", IdAni-1), (*it)->getSingleAnimalInfoI("Food", IdAni-1), (*it)->getSingleAnimalInfoI("Age", IdAni-1))); //zoo.addAnimal(new Poule(randomStr(6), "poule", 0.15, 6), habitat - 1);
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
float Zoo::getMeat()
{
    return viande;
}

float Zoo::getSeed()
{
    return graines;
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
        result += (*it)->getAGender(gender, race, 4);
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
        } else if (State != "poule" && State != "aigle" && State != "tigre" && stoi(State) == i)
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
            result -= (*it)->getEagleEggs()/2;
        }else if (State != "poule" && State != "aigle" && State != "tigre" && id == stoi(State))
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
void Zoo::setMeat(float food) 
{
    viande = food;
}

void Zoo::setSeed(float Seed) 
{
    graines = Seed;
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
        cout << "lelelelel" << endl;
        if (i == HAnimal && (*it)->getType() == animal->getRace())
        {
            (*it)->addAnimal(animal);
            break;
        } else if (i != HAnimal && (*it)->getType() == animal->getRace())
        {
            i++;
        }
        
        it++;
    }
}