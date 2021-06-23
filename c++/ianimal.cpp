#include "../header/ianimal.h"
#include <iostream>
#include <time.h>
#include <random>
using namespace std;

int randomnbr(int max)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{1, max};
    return distribution(generator);
}

IAnimal::IAnimal(string name)
    : m_name(name)
{
}

IAnimal::~IAnimal()
{
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

int IAnimal::getAlive()
{
    return m_alive;
}

int IAnimal::getId()
{
    return m_id;
}

int IAnimal::getIntMalade()
{
    return intmalade;
}

int IAnimal::getMat()
{
    return m_mat;
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

void IAnimal::SetAlive(int alive)
{
    m_alive = alive;
}

void IAnimal::SetId(int Id)
{
    m_id = Id;
}

void IAnimal::SetIntMalade(int IntMalade)
{
    intmalade = IntMalade;
}

void IAnimal::SetMat(int mat)
{
    m_mat = mat;
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

void IAnimal::UpdateAge()
{
    m_age += 1;
    if (m_race == "aigle")
    {
        if (m_age == 168 && m_fertile == 1)
        {
            m_fertile = 0;
        }
        if (m_alive == 1 && m_age < 168 && m_age >= 48)
        {
            m_fertile = 1;
        }
        if (getMalade() == 0 && randomnbr(5) == 1 && getMaladeOnce() == 0)
        {
            SetMalade(1, 0);
            SetMaladeOnce(1);
            SetIntMalade(getAge());
            cout << getName() << " est tombe malade" << endl;
        }
        if (getMalade() == 1 && getIntMalade() + 1 == getAge() && getMaladeOnce() == 1)
        {
            if (getFertile() == 1)
            {
                SetMalade(0, 1);
            }
            else
            {
                SetMalade(0, 0);
            }
            cout << getName() << " n'est plus malade" << endl;
        }
    }
    else if (m_race == "poule" || m_race == "coq")
    {
        //set la fertilité de la poule par rapport a son age
        if (m_age == 6 && m_fertile == 0)
        {
            m_fertile = 1;
        }
        if (m_age == 96 && m_fertile == 1)
        {
            m_fertile = 0;
        }

        //maladie poule
        if (getMalade() == 0 && randomnbr(10) == 1 && getMaladeOnce() == 0)
        {
            SetMalade(1, 0);
            SetMaladeOnce(1);
            SetIntMalade(getAge());
            cout << getName() << " est tombe malade" << endl;
        }
        if (getMalade() == 1 && getIntMalade() + 1 == getAge() && getMaladeOnce() == 1)
        {
            if (getFertile() == 1)
            {
                SetMalade(0, 1);
            }
            else
            {
                SetMalade(0, 0);
            }
            cout << getName() << " n'est plus malade" << endl;
        }
    }
    else if (m_race == "tigre")
    {
        if (m_age == 48 && m_fertile == 0 && m_gender == "Female")
        {
            m_fertile = 1;
        }
        if (m_age == 72 && m_fertile == 0 && m_gender == "Male")
        {
            m_fertile = 1;
        }
        if (m_age == 168 && m_fertile == 1)
        {
            m_fertile = 0;
        }
        //maladie tigre
        if (getMalade() == 0 && randomnbr(5) == 1 && getMaladeOnce() == 0)
        {
            SetMalade(1, 0);
            SetMaladeOnce(1);
            SetIntMalade(getAge());
            cout << getName() << " est tombe malade" << endl;
        }
        if (getMalade() == 1 && getIntMalade() + 1 == getAge() && getMaladeOnce() == 1)
        {
            if (getFertile() == 1)
            {
                SetMalade(0, 1);
            }
            else
            {
                SetMalade(0, 0);
            }
            cout << getName() << " n'est plus malade" << endl;
        }
    }
}
