#include <iostream>
#include <cmath>
#include "zoo.h"
#include "aigle.h"
#include "poule.h"
#include "tigre.h"

using namespace std;

// Get number of visitors
double Visitor(int tiger, int eagle, int chicken, int month)
{
    double variation = (rand() % 41) - 20; // generate random number (-20 / 20)
    if (month >= 5 && month <= 9)
    {
        // Saison haute
        return round((30 * tiger + 15 * eagle + 2 * chicken) * (1 + variation / 100));
    }
    // Saison basse
    return round((5 * tiger + 7 * eagle + 0.5 * chicken) * (1 + variation / 100));
}

// Add money each year
int subvention(int tiger, int eagle)
{
    return tiger * 43800 + eagle * 2190;
}

// double actionMonth(int &tiger)
// {
//     int whatToBuy = 1;
//     while (whatToBuy != 0)
//     {
//         scanf()
//     }
//     return 2;
// }

// Exceptional events per month
void specialEvent()
{
    int fireEvent = rand() % 100, stealingEvent = rand() % 100, nuisiblesEvent = rand() % 100, rottenEvent = rand() % 100;

    if (fireEvent == 0)
    {
        cout << "FIRE !!!!" << endl;
    }
    if (stealingEvent == 0)
    {
        cout << "STEALING !!!!" << endl;
    }
    if (nuisiblesEvent < 20)
    {
        cout << "NUISIBLE !!!!" << endl;
    }
    if (rottenEvent < 10)
    {
        cout << "ROTTEN MEAT !!!!" << endl;
    }
}

int main()
{
    double visitor = 0, budget = 80000;
    int month = 0, year = 0, nextMonth = 0;
    int tiger = 4, eagle = 4, chicken = 10, coq = 1;
    int tigerHabitat = tiger / 2, eagleHabitat = eagle / 4, chickenHabitat = chicken / 10;
    cout << tigerHabitat << eagleHabitat << chickenHabitat << endl;

    // Tous les mois
    while (year < 10)
    {
        month++;
        visitor = Visitor(tiger, eagle, chicken, month);
        if (month == 13)
        {
            month = 1;
            year++;
            budget += subvention(tiger, eagle);
        }

        cout << "Year : " << year << endl;
        cout << "Month : " << month << endl;
        cout << "il y a " << visitor << " visiteurs dans le zoo" << endl;
        cout << "Budget : " << budget << endl;

        specialEvent();

        nextMonth = 0;
        // Action pour le mois
        while (year < 10 && nextMonth != 1)
        {

            // if (nextMonth == 2)
            // {
            // actionMonth(tiger);
            // cout < < < < endl;
            // }

            cout << "passer le tour" << endl;
            cout << "Press 1 to pass the month / 2 to buy" << endl;
            scanf("%d", &nextMonth);
            cout << "\x1B[2J\x1B[H"; // clear le terminal
        }
    }

    return 0;
}
