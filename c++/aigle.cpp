#include "../header/ianimal.h"
#include "../header/aigle.h"
#include <iostream>
using namespace std;
int id = 1;
Aigle::Aigle(string name, string race, string gender, float food, int age)
    :IAnimal(name)
{
    IAnimal::SetRace(race);
    IAnimal::SetAge(age);
    IAnimal::SetGender(gender);
    IAnimal::SetFood(food);
    IAnimal::SetId(id);
    id++;
    IAnimal::SetMat(0);
    IAnimal::SetMaladeOnce(0);
    cout << age << endl;
    if (age < 48 || age >= 168)
    {
        cout << "pas fertile" << endl;
        IAnimal::SetFertile(0);
        IAnimal::SetMalade(0, 0);
    } else {
        cout << "fertile" << endl;
        IAnimal::SetFertile(1);
        IAnimal::SetMalade(0, 1);
    }
    
}
Aigle::~Aigle()
{

}

string Aigle::getName()
{
    return IAnimal::getName();
}

string Aigle::getRace()
{
    return IAnimal::getRace();
}

int Aigle::getAge()
{
    return IAnimal::getAge();
}

string Aigle::getGender()
{
    return IAnimal::getGender();
}

void Aigle::UpdateAge()
{
    IAnimal::UpdateAge();
}

float Aigle::getMeat()
{
    return IAnimal::getMeat();
}