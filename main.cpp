#include <iostream>
#include <cmath>
#include "zoo.h"
#include "aigle.h"
#include "poule.h"
#include "tigre.h"

using namespace std;

double Visitor(int tiger, int eagle, int chicken, int month)
{
    double variation = (rand() % 41)-20;
    cout << variation << endl;
    if (month >=5 && month <= 9)
    {
        return  round((30 * tiger + 15 * eagle + 2 * chicken)*(1+variation/100));
    }
    return  round((5 * tiger + 7 * eagle + 0.5 * chicken)*(1+variation/100));
}

int subvention(int tiger, int eagle)
{
    return tiger * 43800 + eagle * 2190;
}

int main()
{
    double visitor = 0, budget = 80000;
    int month = 0, year = 0, nextMonth = 0;
    int tiger = 4, eagle = 4, chicken = 10, coq = 1;

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
