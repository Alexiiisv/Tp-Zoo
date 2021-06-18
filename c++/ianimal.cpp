#include "../header/ianimal.h"
#include <iostream>
#include <time.h>
using namespace std;

IAnimal::IAnimal(string name)
    : m_name(name)
{
}

IAnimal::~IAnimal()
{
    cout << "tamer" << endl;
}

string IAnimal::getName()
{
    return m_name;
}

string IAnimal::getRace()
{
    return m_race;
}

int IAnimal::getAge()
{
    return m_age;
}

float IAnimal::getMeat()
{
    return m_food;
}

string IAnimal::getGender()
{
    return m_gender;
}

int IAnimal::getFertile()
{
    return m_fertile;
}

int IAnimal::getMalade()
{
    return m_malade;
}

int IAnimal::getMaladeOnce()
{
    return m_Maladeonce;
}

void IAnimal::SetFood(float food)
{
    m_food = food;
}
void IAnimal::SetRace(string race)
{
    m_race = race;
}

void IAnimal::SetAge(int Age)
{
    m_age = Age;
}

void IAnimal::SetMaladeOnce(int Monce)
{
    m_Maladeonce = Monce;
}

void IAnimal::SetMalade(int malade, int fertile)
{
    m_malade = malade;
    SetFertile(fertile);
}

void IAnimal::SetGender(string gender)
{
    m_gender = gender;
}

void IAnimal::SetFertile(int fertile)
{
    m_fertile = fertile;
}

int age;
void IAnimal::UpdateAge()
{
    srand(time(0));
    m_age += 1;
    if (m_race == "aigle")
    {
    if (m_age == 48 && m_fertile == 0)
    {
        m_fertile = 1;
        cout << "fertile" << endl;
    }
    if (m_age == 168 && m_fertile == 1)
    {
        m_fertile = 0;
        cout << "plus fertile" << endl;
    }
    cout << "lel1" << endl;
    if (getMalade() == 0 && rand()%10 == 1 && getMaladeOnce() == 0)
    {
        SetMalade(1, 0);
        SetMaladeOnce(1);
        age = getAge();
        cout << getName() << " est tombe malade" << endl;
    }
    cout << getAge() << " lel2 " << age+1 << endl;
    if (getMalade() == 1 && age+1 == getAge() && getMaladeOnce() == 1)
    {
        if (getFertile() == 1)
        {
            SetMalade(0, 1);
        }else {
            SetMalade(0, 0);
        }
        cout << getName() << " n'est plus malade" << endl;
    }
    }
    else if (m_race == "poule")
    {
        if (m_age == 48 && m_fertile == 0)
        {
            m_fertile = 1;
            cout << "fertile" << endl;
        }
        if (m_age == 168 && m_fertile == 1)
        {
            m_fertile = 0;
            cout << "plus fertile" << endl;
        }
    }
    
    
}
