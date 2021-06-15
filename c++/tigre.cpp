#include <iostream>
#include "../header/ianimal.h"
#include "../header/tigre.h"

using namespace std;

Tigre::Tigre(string name)
    :IAnimal(name)
{

}

void Tigre::fire()
{
    cout << "Je rugis" << endl;
}
