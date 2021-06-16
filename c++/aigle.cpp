#include "../header/ianimal.h"
#include "../header/aigle.h"
#include <iostream>
using namespace std;
Aigle::Aigle(string name, string race, string gender, float food, int age)
    :IAnimal(name)
{
    IAnimal::SetRace(race);
    IAnimal::SetAge(age);
    IAnimal::SetGender(gender);
    IAnimal::SetFood(food);
    cout << age << endl;
    if (age < 48 || age > 168)
    {
        cout << "pas fertile" << endl;
        IAnimal::SetFertile(0);
    } else {
        cout << "fertile" << endl;
        IAnimal::SetFertile(1);
    }
    
}
Aigle::~Aigle()
{
    cout << " la pute " << endl;
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

float Aigle::getFood()
{
    return IAnimal::getFood();
}