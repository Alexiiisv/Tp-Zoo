#include <iostream>
#include "zoo.h"
#include "aigle.h"
#include "poule.h"
#include "tigre.h"

using namespace std;

int main()
{
    Zoo zoo("Zoo de la Montagne");

    zoo.addAnimal(new Tigre("bob"));
    zoo.addAnimal(new Tigre("larry"));
    zoo.addAnimal(new Poule("poule 1"));
    zoo.addAnimal(new Poule("poule 2"));
    zoo.addAnimal(new Aigle("aigle 1"));
    zoo.addAnimal(new Aigle("aigle 2"));

    zoo.fire();
    return 0;
}
