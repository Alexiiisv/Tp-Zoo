#include <iostream>
#include <cmath>
#include "zoo.h"
#include "aigle.h"
#include "eagleHabitat.h"
// #include "poule.h"
// #include "tigre.h"

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
    case 1: // famille de 4 + un mec tout seul
        visitor -= 1;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17;
        visitor += 1;
        break;
    case 2: // famille de 4 + deux gays
        visitor -= 2;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17 * 2;
        visitor += 2;
        break;
    default: // famille de 4 + deux gays et un enfant adopté
        visitor -= 3;
        result = (visitor / 2 * 17) + (visitor / 2 * 13);
        result += 17 * 2 + 13;
        visitor += 3;
        break;
    }
    cout << "Revenus pour " << visitor << " visiteurs : " << result << endl;
    return result;
}
// Get number of visitors
int Visitor(int tiger, int eagle, int chicken, int month)
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
    int subvention = eagle * 2190; // Rajouter les autres animaux une fois fait
    cout << "New Year ! subvention : " << subvention << endl;
    return subvention;
}
// Menu to buy an Animal
void buyAnimal(int &Gender, int &aigle, double &budget, Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1;
    string gender[2] = {"Female", "Male"};
    cout << "que voulez-vous acheter ?\n3 | aigles\t\t4 | tigres\t\t0 | pour quitter le menu\n5 | poules\t\t6 | coq\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {
        cout << "give a name to your eagle" << endl;
        scanf("%15s", &nom);
        cout << "Do you want a male or a female ?\n0 | Female\t1 | Male" << endl;
        scanf("%d", &Gender);
        aigle += 1;
        zoo.addAnimal(new Aigle(nom, "aigle", gender[Gender]));
        budget -= 1000;
    }
}
// Menu to buy Habitat
void buyHabitats(int &eaglehabitat, double &budget, Zoo &zoo)
{
    int whatToBuy = 1;
    string gender[2] = {"Female", "Male"};
    cout << "que voulez-vous acheter ?\n3 | Habitat aigles\t\t4 | Habitat tigres\t\t0 | pour quitter le menu\n5 | Habitat poules\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {
        eaglehabitat += 1;
        zoo.addHabitat(new EagleHabitat("aigle", 5));
        budget -= 2000;
    }
}

// Actions d'acheter animaux
void actionMonth(Zoo &zoo, int &tigre, int &poules, double &budget, int &aigle, int &eagleHabitat)
{
    int Gender = 2;
    int whatToBuy = 1;
    while (whatToBuy != 0)
    {
        cout << "que voulez-vous acheter ?\n1 | Habitats\t\t2 | Animaux\t\t0 pour quitter le menu\n"
             << endl;
        scanf("%d", &whatToBuy);

        if (whatToBuy == 1)
        {
            buyHabitats(eagleHabitat, budget, zoo);
        }
        else if (whatToBuy == 2)
        {
            buyAnimal(Gender, aigle, budget, zoo);
        }
    }
}
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
    Zoo zoo("Zoo de la Montagne");
    double budget = 80000;
    int month = 0, year = 0, nextMonth = 0;
    int visitor = 0;
    int tiger = 0, eagle = 4, chicken = 0, coq = 0;
    int tigerHabitat = tiger / 2, eagleHabitat = eagle / 4, chickenHabitat = chicken / 10;

    // Tous les mois
    while (year < 10)
    {
        cout << "a" << endl;
        cout << zoo.getName() << endl;
        if (month != 0)
        {
            visitor = Visitor(tiger, eagle, chicken, month); // calcul le nb de visiteur
            budget += VisitorRevenue(visitor);               // calcul le revenue lié aux visiteurs
            specialEvent();                                  // créé les événements spéciaux
        }
        month++;

        if (month == 13)
        {
            month = 1;
            year++;
            budget += subvention(tiger, eagle);
        }

        cout << "Year : " << year << "\nMonth : " << month << "\nBudget : " << budget << endl;

        // PERTE D'UN ANIMAL LORSQU'ILS SONT TROP NOMBREUX DANS UN HABITAT
        cout << eagle << endl;
        if (eagle/eagleHabitat > 4 && rand()% 2 == 1) {
            cout << "Vous avez perdu un aigle" << endl;
            eagle -= 1;
        }
        
        nextMonth = 0;
        // Action pour le mois
        while (year < 10 && nextMonth != 1)
        {
            cout << "Press 1 to pass the month / 2 to buy" << endl;
            scanf("%d", &nextMonth);
            cout << "\x1B[2J\x1B[H"; // clear le terminal

            if (nextMonth == 2)
            {
                actionMonth(zoo, tiger, chicken, budget, eagle, eagleHabitat);
                cout << "aigle " << eagle << " tigre " << tiger << " poulet " << chicken << " money " << budget << endl;
                cout << eagleHabitat << " habitats d'aigles pour " << eagle << " aigles" << endl;
            }
            else if (nextMonth == 1)
            {
                zoo.UpdateAge();
                zoo.GetHabitatRace();
            }
        }
    }

    return 0;
}
