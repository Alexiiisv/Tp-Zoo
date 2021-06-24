#include "../header/zoo.h"
#include "../header./aigle.h"
#include "../header./tigre.h"
#include "../header./poule.h"
#include "../header./coq.h"
// #include "../main.cpp"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;

// Génère un string random
string randomStre(int len)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{'a', 'z'};
    string rand_str(len, '\0');
    for (auto &dis : rand_str)
        dis = distribution(generator);

    return rand_str;
}
// Génère un string random
int randomNbr(int min, int max)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}
//Create the zoo
Zoo::Zoo(string name)
    : m_name(name)
{
    month = 0;
    viande = 0;
    graines = 0;
    year = 0;
    aigle_Habitat = 0;
    poules_Habitat = 0;
    tigre_Habitat = 0;
}
//Add an animal to a specific habitat
void Zoo::addAnimal(IAnimal *animal, int habitat)
{
    setAnimalHabitat(animal, habitat);
}
//Buy a habitat
void Zoo::addHabitat(IHabitat *habitat)
{
    if (habitat->getType() == "aigle" && budget - 2000 >= 0)
    {
        aigle_Habitat += 1;
        budget -= 2000;
        m_habitats.push_back(habitat);
        cout << "Tu viens d'acheter un habitat d'aigle ; tu en as maintenant " << GetHabitatNbrByRace("aigle") << endl;
    }
    else if (habitat->getType() == "poule" && budget - 300 >= 0)
    {
        poules_Habitat += 1;
        budget -= 300;
        m_habitats.push_back(habitat);
        cout << "Tu viens d'acheter un habitat de poule ; tu en as maintenant " << GetHabitatNbrByRace("poule") << endl;
    }
    else if (habitat->getType() == "tigre" && budget - 2000 >= 0)
    {
        tigre_Habitat += 1;
        budget -= 2000;
        m_habitats.push_back(habitat);
        cout << "Tu viens d'acheter un habitat de tigre ; tu en as maintenant " << GetHabitatNbrByRace("tigre") << endl;
    }
    else
        cout << "tu n'as pas assez d'argent pour acheter un habitat pour les " << habitat->getType() << endl;
    cout << endl;
}
//Sell a habitat
void Zoo::SellHabitat(string Race)
{
    int less = 0, id = 0;
    bool nohab = false;
    if (GetHabitatNbrByRace(Race) != 0)
    {
        while (m_habitats[less]->getType() != Race)
            less++;
    }

    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {

        if ((*it)->getnbrAnimals() <= m_habitats[less]->getnbrAnimals() && (*it)->getType() == Race)
        {
            less = id;
            nohab = true;
        }
        id++;
        it++;
    }
    if (nohab)
        m_habitats.erase(m_habitats.begin() + less);

    if (Race == "poule" && nohab)
        budget += 50;
    else if (nohab && Race != "poule")
        budget += 500;
}

void Zoo::SellAnimal(int IdAni, int IdHab, string race)
{
    int id = 1;
    IdHab = getintHab(IdHab, race);
            budget += m_habitats[IdHab]->getAnimalValue(IdAni);
            m_habitats[IdHab]->delAnimal(IdAni - 1, "Vente");
}

//Fire event
void Zoo::FireHabitat(string Race)
{
    if (GetHabitatNbrByRace(Race) != 0)
    {
        int randHab = randomNbr(0, GetHabitatNbrByRace(Race));
        int hab = getintHab(randHab + 1, Race);
        cout << "random habitat " << randHab << " int habitat random " << hab << endl;
        m_habitats.erase(m_habitats.begin() + hab);
        if (Race == "aigle")
            cout << "un feu s'est declare dans ton habitat d'" << Race << "\nTout tes Animaux dans cet habitat sont morts. Chaud" << endl;
        else
            cout << "un feu s'est declare dans ton habitat de " << Race << "\nTout tes Animaux dans cet habitat sont morts. Chaud" << endl;
    }
    else
        cout << "Un feu s'est declare dans ton zoo fort heureusement les pompiers l'ont maitrise avant d'atteindre un habitat." << endl;
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
            if (todo == "A Kill 1")
            {
                (*it)->delAnimal(Id, "Creve");
                Id--;
            }
            if (todo == "A Kill 2")
            {
                (*it)->delAnimal(Id, "Malade");
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
            (*it)->UpdateMalade(getYear(), getMonth());
        it++;
    }
}

void Zoo::ReproductionAigle(int state)
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
                if (F >= M && (*it)->getnbrAnimals() > 1)
                {
                    int ratio = F - M;
                    int nbFemellePonte = F - ratio;
                    (*it)->SetEagleEggs(nbFemellePonte * 2); // chaque aigle femelle pond 2 oeufs
                    cout << "nombre d'oeufs d'aigle : " << (*it)->getEagleEggs() << endl;
                }
            }
            else if (state == 5 && (*it)->getEagleEggs() > 0)
            {
                // range over each eggs to see if they die
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    randDeath = randomNbr(0, 1); // Generate 0 or 1
                    // Lorsqu'un aigle est mort né
                    if (randDeath == 1)
                    {
                        (*it)->SetEagleEggs((*it)->getEagleEggs() - 1);
                        mort++;
                    }
                }
                cout << "nb de bb aigles : " << (*it)->getEagleEggs() << " ; nb de bb aigles MORT : " << mort << endl;
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    srand(time(0));
                    int randSex = randomNbr(0, 1);
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
void Zoo::ReproductionTigre()
{
    int F = 15, M = 51, randDeath = 0, mort = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == "tigre")
        {
            if ((*it)->getAccouche() && (*it)->getTbb() < 20)
                (*it)->SetTbb((*it)->getTbb() + 1);
            else if ((*it)->getAccouche() && (*it)->getTbb() == 20)
            {
                (*it)->SetTbb(0);
                (*it)->setAccouche(false);
            }
            else if ((*it)->getTbb() == 0)
            {
                F = (*it)->getAGender("Female", "tigre", 2);
                M = (*it)->getAGender("Male", "tigre", 2);
                cout << "\tfemme " << F << "\n\thomme " << M << endl;
                int ratio = F - M;
                if (ratio < 0)
                    ratio = 0;
                int nbFemellePonte = F - ratio;
                (*it)->SetEagleEggs(nbFemellePonte * 3); // chaque tigre femelle pond 3 enfants
                cout << "nombre de tigre enceinte : " << (*it)->getEagleEggs() / 3 << endl;
                (*it)->SetTbb((*it)->getTbb() + 1);
            }
            else if ((*it)->getTbb() > 0)
            {
                (*it)->SetTbb((*it)->getTbb() + 1);
                if ((*it)->getTbb() == 4)
                {
                    // range over each eggs to see if they die
                    for (int i = 0; i < (*it)->getEagleEggs(); i++)
                    {
                        randDeath = randomNbr(0, 2); // Generate 0 or 1 or 2
                        // Lorsqu'un tigre est mort né
                        if (randDeath == 1)
                        {
                            (*it)->SetEagleEggs((*it)->getEagleEggs() - 1);
                            mort++;
                        }
                    }
                    cout << "nb de bb tigres : " << (*it)->getEagleEggs() << "; nb de bb tigres MORT : " << mort << endl;
                    for (int i = 0; i < (*it)->getEagleEggs(); i++)
                    {
                        srand(time(0));
                        int randSex = randomNbr(0, 1);
                        float food;
                        string sex;
                        char name[16];

                        switch (randSex)
                        {
                        case 0:
                            sex = "Male";
                            food = 12;
                            break;
                        default:
                            sex = "Female";
                            food = 10;
                            break;
                        }
                        cout << "Donnez un nom au bebe tigre numero " << i << endl;
                        scanf("%15s", &name);
                        cout << name << endl;

                        (*it)->addAnimal(new Tigre(name, "tigre", sex, food, 0));
                    }
                    (*it)->SetEagleEggs(0);
                    (*it)->setAccouche(true);
                }
            }
        }

        it++;
    }
}
void Zoo::ReproductionTigre(string state)
{
    if (state == "ded")
    {
        HabitatIterator it = m_habitats.begin();
        while (it != m_habitats.end())
        {
            if ((*it)->getType() == "tigre" && (*it)->getEagleEggs() > 0)
                (*it)->SetEagleEggs(0);
            it++;
        }
    }
}
void Zoo::ReproductionPoule(int date)
{
    int P = 0, C = 0, randDeath = 0, mort = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == "poule")
        {
            if (date % 2 == 0)
            {
                P = (*it)->getARace("poule", 2);
                C = (*it)->getARace("coq", 2);
                cout << "\tpoule " << P << "\n\tcoq " << C << endl;
                int ratio = P - C * 4;
                if (ratio < 0)
                    ratio = 0;
                int nbFemellePonte = P - ratio;
                (*it)->SetEagleEggs(nbFemellePonte * 4); // chaque poule pond 4 oeufs tout les 2 mois
                cout << "nombre d'oeufs de poule : " << (*it)->getEagleEggs() << endl;
            }
            if (date % 2 == 1 && (*it)->getEagleEggs() > 0)
            {
                // // range over each eggs to see if they die
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    randDeath = randomNbr(0, 1); // Generate 0 or 1
                    // Lorsqu'un aigle est mort né
                    if (randDeath == 1)
                    {
                        (*it)->SetEagleEggs((*it)->getEagleEggs() - 1);
                        mort++;
                    }
                }
                cout << "\nnb de bb poule/coq : " << (*it)->getEagleEggs() << " ; nb de bb poule/coq MORT : " << mort << endl;
                for (int i = 0; i < (*it)->getEagleEggs(); i++)
                {
                    int random = randomNbr(0, 1);
                    switch (random)
                    {
                    case 0: //poule
                        (*it)->addAnimal(new Poule(randomStre(6), "poule", 0.15, 0));
                        break;
                    default: //coq
                        (*it)->addAnimal(new Coq(randomStre(6), "coq", 0.18, 0));
                        break;
                    }
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
        if ((*it)->getType() == "aigle" || (*it)->getType() == "tigre")
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
            (*it)->delAnimal(randomNbr(0, 4), "Plein");
            (*it)->UpdMating();
        }
        if ((*it)->getType() == "poule")
            (*it)->delAnimal(randomNbr(0, 10), "Plein");
        if ((*it)->getType() == "tigre")
            (*it)->delAnimal(randomNbr(0, 2), "Plein");

        it++;
        i++;
    }
}
//Stealing event
void Zoo::VolDanimal(string state)
{
    if (GetHabitatNbrByRace(state) != 0)
    {
        int randhab = randomNbr(0, GetHabitatNbrByRace(state));
        int hab = getintHab(randhab + 1, state);
        if (m_habitats[hab]->getnbrAnimals() != 0)
        {
            int randani = randomNbr(0, m_habitats[hab]->getnbrAnimals());
            m_habitats[hab]->delAnimal(randani, "Vol");
            if (state == "poule")
                cout << "Une poule a ete vole" << endl;
            else if (state != "poule")
                cout << "Un " << state << " a ete vole" << endl;
        }
        else
            cout << "Il y a eu une tentative de vol dans un de tes habitats,\nHeureusement il etait vide." << endl;
    }
    else
        cout << "Il y a eu une tentative de vol dans ton zoo,\nHeureusement la police a arreter les cambrioleurs a temps." << state << endl;
}
//Update the budget the zoo have
void Zoo::UpdateBudget(float Budget)
{
    budget += Budget;
}
//switch a animal from the habitat 1 to the habitat 2
void Zoo::SwitchHabitat(int hab1, int IdAni, int hab2, string race)
{
    hab1 = getintHab(hab1, race);
    hab2 = getintHab(hab2, race);
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it) == m_habitats[hab1] && race == "aigle")
        {
            m_habitats[hab2]->addAnimal(new Aigle((*it)->getSingleAnimalInfoS("Name", IdAni - 1), (*it)->getSingleAnimalInfoS("Race", IdAni - 1), (*it)->getSingleAnimalInfoS("Gender", IdAni - 1), (*it)->getSingleAnimalInfoI("Food", IdAni - 1), (*it)->getSingleAnimalInfoI("Age", IdAni - 1), (*it)->getSingleAnimalInfoI("fertilite", IdAni - 1), (*it)->getSingleAnimalInfoI("malade", IdAni - 1), (*it)->getSingleAnimalInfoI("id", IdAni - 1), (*it)->getSingleAnimalInfoI("mat", IdAni - 1), (*it)->getSingleAnimalInfoI("maladeonce", IdAni - 1)));
            m_habitats[hab1]->delAnimal(IdAni - 1, "Deplacement");
            m_habitats[hab2]->getAnimal();
            break;
        }
        if ((*it) == m_habitats[hab1] && race == "tigre")
        {
            m_habitats[hab2]->addAnimal(new Tigre((*it)->getSingleAnimalInfoS("Name", IdAni - 1), (*it)->getSingleAnimalInfoS("Race", IdAni - 1), (*it)->getSingleAnimalInfoS("Gender", IdAni - 1), (*it)->getSingleAnimalInfoI("Food", IdAni - 1), (*it)->getSingleAnimalInfoI("Age", IdAni - 1))); //zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age), habitat - 1);
            m_habitats[hab1]->delAnimal(IdAni - 1, "Deplacement");
            m_habitats[hab2]->getAnimal();
            break;
        }
        else if ((*it) == m_habitats[hab1] && race == "poule")
        {
            m_habitats[hab2]->addAnimal(new Poule((*it)->getSingleAnimalInfoS("Name", IdAni - 1), (*it)->getSingleAnimalInfoS("Race", IdAni - 1), (*it)->getSingleAnimalInfoI("Food", IdAni - 1), (*it)->getSingleAnimalInfoI("Age", IdAni - 1))); //zoo.addAnimal(new Poule(randomStr(6), "poule", 0.15, 6), habitat - 1);
            m_habitats[hab1]->delAnimal(IdAni - 1, "Deplacement");
            m_habitats[hab2]->getAnimal();
            break;
        }
        else if ((*it) == m_habitats[hab1] && race == "coq")
        {
            m_habitats[hab2]->addAnimal(new Coq((*it)->getSingleAnimalInfoS("Name", IdAni - 1), (*it)->getSingleAnimalInfoS("Race", IdAni - 1), (*it)->getSingleAnimalInfoI("Food", IdAni - 1), (*it)->getSingleAnimalInfoI("Age", IdAni - 1))); //zoo.addAnimal(new Poule(randomStr(6), "poule", 0.15, 6), habitat - 1);
            m_habitats[hab1]->delAnimal(IdAni - 1, "Deplacement");
            m_habitats[hab2]->getAnimal();
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
int Zoo::getintHab(int id, string race)
{
    int result = -1, i = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        result++;
        if ((*it)->getType() == race && id == i)
        {
            break;
        }
        else if ((*it)->getType() == race && id != i)
        {
            i++;
        }
        it++;
    }
    return result;
}
float Zoo::getConsobyRace(string race)
{
    float result = 0;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == race)
        {
            result += (*it)->getMeat();
        }
        it++;
    }
    return result;
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
    cout << "\t\t\t-------------------------" << endl;
    if (getBudget() < 10000)
    {
        cout << "\t\t\t| " << getName() << "\t\t|\n\t\t\t| Year : " << getYear() << "\t\t|\n\t\t\t| Month : " << getMonth() << "\t\t|\n\t\t\t| Budget : " << getBudget() << "\t\t|" << endl;
    }
    else
    {
        cout << "\t\t\t| " << getName() << "\t\t|\n\t\t\t| Year : " << getYear() << "\t\t|\n\t\t\t| Month : " << getMonth() << "\t\t|\n\t\t\t| Budget : " << getBudget() << "\t|" << endl;
    }
    cout << "\t\t\t-------------------------\n"
         << endl;
}
//Get all the information about all the animal per race
void Zoo::getAllInfo(string race)
{
    int i = 1;
    bool yes = true;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == race)
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\tDans l'habitat " << (*it)->getType() << " numero " << i << " il y a les animaux suivant\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            i++;
        }
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
    bool yes = true;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (State == "All Habitat")
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\t\tDans cet habitat il y a les animaux suivant\t\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            
        }
        else if (State == (*it)->getType())
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\tDans l'habitat " << (*it)->getType() << " numero " << i << " il y a les animaux suivant\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            i++;
        }
        else if (State != "poule" && State != "aigle" && State != "tigre" && stoi(State) == i)
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\tDans l'habitat " << (*it)->getType() << " numero " << i << " il y a les animaux suivant\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            break;
        }
        it++;
    }
}
//Get information about animal per habitat
void Zoo::GetHabitatAnimal(string State, string race)
{
    int i = 1;
    bool yes = true;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (State == "All Habitat")
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\t\tDans cet habitat il y a les animaux suivant\t\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
        }
        if (State == (*it)->getType())
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\tDans l'habitat " << (*it)->getType() << " numero " << i << " il y a les animaux suivant\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            i++;
        }
        if (State != "poule" && State != "aigle" && State != "tigre" && stoi(State) == i && (*it)->getType() == race)
        {
            if (yes)
            {
                cout << "\n-------------------------------------------------------------------------" << endl;
                yes = false;
            }
            cout << "|\t\t\t\t\t\t\t\t\t|\n|\tDans l'habitat " << (*it)->getType() << " numero " << i << " il y a les animaux suivant\t|\n|\t\t\t\t\t\t\t\t\t|" << endl;
            (*it)->getAnimal();
            i++;
            break;
        }
        else if (State != "poule" && State != "aigle" && State != "tigre" && stoi(State) != i && (*it)->getType() == race)
        {
            i++;
        }
        it++;
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
            if (State == "aigle")
            {
                result -= (*it)->getEagleEggs() / 2;
            }
            if (State == "tigre")
            {
                result -= (*it)->getEagleEggs() / 3;
            }
        }
        else if (State != "poule" && State != "aigle" && State != "tigre" && id == stoi(State))
        {
            return (*it)->getnbrAnimals();
        }

        it++;
        id++;
    }
    return result;
}
//Get the amount of animal per race
int Zoo::GetAnimalNbrByRace(string State, string race)
{
    int result = 0, id = 1;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if ((*it)->getType() == State) //tigre/aigle/poules
        {
            result += (*it)->getnbrAnimals();
            if (State == "aigle")
            {
                result -= (*it)->getEagleEggs() / 2;
            }
            if (State == "tigre")
            {
                result -= (*it)->getEagleEggs() / 3;
            }
        }
        else if (State != "poule" && State != "aigle" && State != "tigre" && id == stoi(State) && race == (*it)->getType())
        {
            return (*it)->getnbrAnimals();
        }
        else if (State != "poule" && State != "aigle" && State != "tigre" && id != stoi(State) && race == (*it)->getType())
        {
            id++;
        }

        it++;
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

void Zoo::setName(string name)
{
    m_name = name;
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
void Zoo::setAnimalHabitat(IAnimal *animal, int HAnimal)
{
    int i;
    HabitatIterator it = m_habitats.begin();
    while (it != m_habitats.end())
    {
        if (i == HAnimal && (((*it)->getType() == animal->getRace()) || ((*it)->getType() == "poule" && animal->getRace() == "coq")))
        {
            (*it)->addAnimal(animal);
            break;
        }
        else if (i != HAnimal && (((*it)->getType() == animal->getRace()) || ((*it)->getType() == "poule" && animal->getRace() == "coq")))
        {
            i++;
        }

        it++;
    }
}