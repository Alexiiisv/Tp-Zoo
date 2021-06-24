#include "../header/zoo.h"
#include "../header/utils.h"

#include <cmath>
#include <iostream>
using namespace std;

// Get visitors revenues
int VisitorRevenue(int visitor)
{
    int result;
    switch (visitor % 4)
    {
    case 0: // que des familles de 4
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        break;
    case 1: // famille de 4 + un adulte tout seul
        visitor -= 1;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17;
        visitor += 1;
        break;
    case 2: // famille de 4 + deux adultes
        visitor -= 2;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17 * 2;
        visitor += 2;
        break;
    default: // famille de 4 + deux adulte et un enfant
        visitor -= 3;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17 * 2 + 13;
        visitor += 3;
        break;
    }
    return result;
}
// Get number of visitors
int Visitor(Zoo &zoo)
{
    int tigre = zoo.GetAnimalNbrByRace("tigre"), aigle = zoo.GetAnimalNbrByRace("aigle"), poule = zoo.GetAnimalNbrByRace("poule"), mois = zoo.getMonth();
    double variation = randomnbr(0, 40) - 20; // generate random number (-20 / 20)
    if (mois >= 5 && mois <= 9)
    {
        // Saison haute
        return round((30 * tigre + 15 * aigle + 2 * poule) * (1 + variation / 100));
    }
    // Saison basse
    return round((5 * tigre + 7 * aigle + 0.5 * poule) * (1 + variation / 100));
}
// Add money each year
float subvention(Zoo &zoo)
{
    int tigre = zoo.GetAnimalNbrByRace("tigre"), aigle = zoo.GetAnimalNbrByRace("aigle"), mois = zoo.getMonth(), annee = zoo.getYear();
    float subvention = tigre * 43800 + aigle * 2190; // Calcul de la subvention en fonction de l'animal
    return subvention;
}