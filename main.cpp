#include <iostream>
#include "zoo.h"
#include "aigle.h"
#include "poule.h"
#include "tigre.h"

using namespace std;

int main()
{
    // Zoo zoo("Zoo de la Montagne");

    // zoo.addAnimal(new Tigre("bob"));
    // zoo.addAnimal(new Tigre("larry"));
    // zoo.addAnimal(new Poule("poule 1"));
    // zoo.addAnimal(new Poule("poule 2"));
    // zoo.addAnimal(new Aigle("aigle 1"));
    // zoo.addAnimal(new Aigle("aigle 2"));

    // zoo.fire();

    int month = 0, year = 8, nextMonth = 0;

    // Tous les mois
    while (year < 10)
    {
        month++;
        if (month == 13)
        {
            month = 1;
            year++;
        }

        cout << "annee : " << year << endl;
        cout << "mois : " << month << endl;

        nextMonth = 0;
        // Action pour le mois
        while (nextMonth != 1 && year < 10)
        {
            cout << "Press 1 to pass the month" << endl;
            scanf("%d", &nextMonth);
        }
    }

    return 0;
}
