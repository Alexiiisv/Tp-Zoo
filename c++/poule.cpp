#include <iostream>
#include "../header/ianimal.h"
#include "../header/poule.h"

using namespace std;

Poule::Poule(string name)
    :IAnimal(name)
{

}

void Poule::fire()
{
    cout << "Je caquette" << endl;
}
