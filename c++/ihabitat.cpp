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
    bool child = true;
    if (state == "Plein")
    {
        AnimalIterator it = m_animals.begin();
        while (it != m_animals.end())
        {
            if ((*it)->getAge() == 0 || (*it)->getAge() == 1)
            {
                child = false;
                break;
            }
            it++;
        }
    }
    int random = rand()%2;
    if (m_capacity < nbr_animals && state == "Plein" && random == 1 && child)
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

void IHabitat::UpdateMalade(int year, int month)
{
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if (year > 0 && month == 1)
        {
            (*it)->SetMaladeOnce(0);
        }
        it++;
    }
    
}

void IHabitat::UpdMating()
{
    //"Female" "Male"
    AnimalIterator an1 = m_animals.begin();
    while (an1 != m_animals.end())
    {
        if ((*an1)->getMat() == 0)
        {
            AnimalIterator an2 = m_animals.begin();
            while (an2 != m_animals.end())
            {
                if ((*an2)->getGender() != (*an1)->getGender() && (*an2)->getId() != (*an1)->getId() && (*an2)->getMat() == 0)
                {
                    (*an1)->SetMat((*an2)->getId());
                    (*an2)->SetMat((*an1)->getId());
                }
                an2++;
            }
        }
        an1++;
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
        cout << "-------------------" << endl;
        cout << "Nom\t\t\t" << (*it)->getName() << endl;
        if ((*it)->getRace() == "aigle")
        {
        cout << "Id\t\t\t" << (*it)->getId() << endl;
        cout << "mate\t\t\t" << (*it)->getMat() << endl;
        }
        cout << "Sexe\t\t\t" << (*it)->getGender() << endl;
        cout << "Age\t\t\t" << (*it)->getAge()/12 << " ans " << (*it)->getAge()%12 << " mois" << endl;
        cout << "race\t\t\t" << (*it)->getRace() << endl;
        cout << "food\t\t\t" << (*it)->getMeat() << endl;
        cout << "fertilite\t\t" << (*it)->getFertile() << endl;
        cout << "malade\t\t\t" << (*it)->getMalade() << endl;
        cout << "deja tombe malade\t" << (*it)->getMaladeOnce() << endl;
        cout << "-------------------" << endl;
        it++;
    }
}

float IHabitat::getMeat()
{
    float food = 0;
    int fmenseinte = 0;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        food += (*it)->getMeat()*30;
        
        
        it++;
    }
    fmenseinte = getEagleEggs()/2;
    food += (0.3*fmenseinte)*30;
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

int IHabitat::getEagleEggs()
{
    return EagleEggs;
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
                return (*it)->getMeat();
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

int IHabitat::getAGender(string gender, string race, int age) {
    int result = 0;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it)->getGender() == gender && (*it)->getRace() == race)
        {
            if (age == 4)
            {
                result +=1;
            }
            else if (age == 1 && ((*it)->getAge() >= 0 && (*it)->getAge() < 48 )) //enfant
            {
                result +=1;
            }
            else if (age == 2 && ((*it)->getAge() >= 48 && (*it)->getAge() < 168 )) //adulte
            {
                result +=1;
            }
            else if (age == 3 && ((*it)->getAge() > 168 && (*it)->getAge() <= 300 )) //vieux
            {
                result +=1;
            }
        }
        it++;
    }
    
    
    return result;
}

void IHabitat::SetEagleEggs(int eagleEggs)
{
    EagleEggs = eagleEggs;
}