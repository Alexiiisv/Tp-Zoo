#include "../header/ihabitat.h"
#include <iostream>
#include <random>
// #include<bits/stdc++.h>
using namespace std;

int randomnbre(int max)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{1, max};
    return distribution(generator);
}

IHabitat::IHabitat()
    : m_type("habitat sans nom")
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
    if (m_capacity < nbr_animals && state == "Plein" && random == 1 && child && m_type == "aigle")
    {
        cout << "un animal est mort due a la surpopulation" << endl;
        SetFertilite(qtt);
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (m_capacity < nbr_animals && state == "Plein" && random == 1 && child && m_type == "tigre")
    {
        cout << "un animal est mort due a la surpopulation" << endl;
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    else if (m_capacity < nbr_animals && state == "Plein" && random == 1 && child && m_type == "poule")
    {
        cout << "plusieur poules/coq sont mort" << endl;
        for (int i = 0; i < 4; i++)
        {
            m_animals.erase(m_animals.begin());
            nbr_animals--;
        }
        
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
        SetFertilite(qtt);
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "Vente")
    {
        cout << "un animal a ete vendu : " << m_animals[qtt]->getName() << endl;
        SetFertilite(qtt);
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals--;
    }
    if (state == "Creve")
    {
        cout << "un animal est mort de vieillesse" << endl;
        SetFertilite(qtt);
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals -= 1;
    }
    if (state == "Malade")
    {
        cout << "un animal est mort de maladie"<< endl;
        SetFertilite(qtt);
        m_animals.erase(m_animals.begin()+qtt);
        nbr_animals -= 1;
    }
    
    
}

void IHabitat::SetFertilite(int qtt)
{
    if (m_type == "aigle")
    {
        int id = m_animals[qtt]->getMat();
        if (id != 0)
        {
            AnimalIterator it = m_animals.begin();
            while (it != m_animals.end())
            {
                if (id == (*it)->getId())
                {
                    cout << "un aigle est mort, son compagnon est devenu veuf " << (*it)->getFertile() << endl;
                    (*it)->SetFertile(0);
                    (*it)->SetAlive(0);
                }
                it++;
            }
        }
    }
}
string IHabitat::UpdateAge(int id)
{
        m_animals[id]->UpdateAge();
        if (m_animals[id]->getAge() == 300 && m_type == "aigle")
        {
            return "A Kill 1";
        }
        if (m_animals[id]->getAge() == 180 && m_type == "poule")
        {
            return "A Kill 1";
        }
        if (m_animals[id]->getMalade() == 1 && randomnbre(10) == 6)
        {
            return "A Kill 2";
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
                    (*an1)->SetAlive(1);
                    (*an2)->SetAlive(1);
                    break;
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
    int id= 1;
    string mal = "non", fer = "non", dejmal = "non", mat = "celib";
    if (nbr_animals == 0) cout << "-------------------------------------------------------------------------" << endl;
    else cout << "-------------------------------------------------------------------------\n" << endl;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it)->getMaladeOnce() == 1) dejmal = "oui";
        else dejmal = "non";
        if ((*it)->getFertile() == 1) fer = "oui";
        else fer = "non";
        if ((*it)->getMalade() == 1) mal = "oui";
        else mal = "non";
        cout << "\t\t\t" << (*it)->getRace() << "\t" << id << endl;
        cout << "\n\t\tNom\t\t\t" << (*it)->getName() << endl;
        if ((*it)->getRace() == "aigle")
        {
            if ((*it)->getMat() != 0) mat = to_string((*it)->getMat());
            else mat = "celib";
            cout << "\t\tId\t\t\t" << (*it)->getId() << endl;
            cout << "\t\tmate\t\t\t" << mat << endl;
        }
        cout << "\t\tSexe\t\t\t" << (*it)->getGender() << endl;
        cout << "\t\tAge\t\t\t" << (*it)->getAge()/12 << " ans " << (*it)->getAge()%12 << " mois" << endl;
        cout << "\t\tfood\t\t\t" << (*it)->getMeat() << endl;
        cout << "\t\tfertilite\t\t" << fer << endl;
        cout << "\t\tmalade\t\t\t" << mal << endl;
        cout << "\t\tdeja tombe malade\t" << dejmal << endl;
        if (it+1 == m_animals.end()) cout << "\n-------------------------------------------------------------------------" << endl;
        else cout << "\n-------------------------------------------------------------------------\n" << endl;
        
        it++;
        id++;
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
    if (m_type == "aigle")
    {
        fmenseinte = getEagleEggs()/2;
        food += (0.3*fmenseinte)*30;
    }
    else if (m_type == "tigre")
    {
        fmenseinte = getEagleEggs()/3;
        food += (10*fmenseinte)*30;
    }
    
    return food;
}
bool IHabitat::getAccouche()
{
    return accouche;
}
int IHabitat::getAnimalValue(int IdAni)
{
    int id = 1;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if (IdAni == id && (*it)->getRace() == "aigle")
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
        else if (IdAni == id && (*it)->getRace() == "poule")
        {
            return 10;
        }
        else if (IdAni == id && (*it)->getRace() == "coq")
        {
            return 20;
        }
        else if (IdAni == id && (*it)->getRace() == "tigre")
        {
            if ((*it)->getAge() < 48) //inferieur a 4ans
            {
                return 1500;
            }
            if ((*it)->getAge() >= 48 && (*it)->getAge() < 168) //entre 4ans et 14ans
            {
                return 60000;
            }
            if ((*it)->getAge() >= 168 && (*it)->getAge() < 300) //entre 14ans et 25ans
            {
                return 10000;
            }
            
        }
        else 
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

int IHabitat::getTbb()
{
    return tbb;
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
            }else if (info == "fertilite")
            {
                return (*it)->getFertile();
            }else if (info == "mat")
            {
                return (*it)->getMat();
            }else if (info == "malade")
            {
                return (*it)->getMalade();
            }else if (info == "id")
            {
                return (*it)->getId();
            }else if (info == "maladeonce")
            {
                return (*it)->getMaladeOnce();
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

int IHabitat::getARace(string race, int age) {
    int result = 0;
    AnimalIterator it = m_animals.begin();
    while (it != m_animals.end())
    {
        if ((*it)->getRace() == race)
        {
            if (age == 4)
            {
                result +=1;
            }
            else if (age == 1 && ((*it)->getAge() >= 0 && (*it)->getAge() < 6 )) //enfant
            {
                result +=1;
            }
            else if (age == 2 && ((*it)->getAge() >= 6 && (*it)->getAge() < 64 )) //adulte
            {
                result +=1;
            }
            else if (age == 3 && ((*it)->getAge() > 64 && (*it)->getAge() <= 180 )) //vieux
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
void IHabitat::SetTbb(int Tbb)
{
    tbb = Tbb;
}
void IHabitat::setAccouche(bool Accouche)
{
    accouche = Accouche;
}