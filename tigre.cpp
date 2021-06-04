#include <iostream>
#include "ianimal.h"
#include "tigre.h"

using namespace std;

Tigre::Tigre()
{

}

Tigre::Tigre(string name)
    :IAnimal(name)
{

}

void Tigre::fire()
{
    cout << "Je rugis" << endl;
}
