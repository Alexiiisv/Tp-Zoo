#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "./header/zoo.h"
#include "./header/aigle.h"
#include "./header/eagleHabitat.h"
#include "./header/chickenHabitat.h"
#include "./header/tigerHabitat.h"
#include "./header/poule.h"
#include "./header/tigre.h"
#include "./header/coq.h"
#include "./Sources/utils.h"
#include "./Sources/actionMonth.h"
#include "./Sources/success.h"
#include "./Sources/visitor.h"
#include "./Sources/infoZoo.h"
#include "./Sources/foodStorage.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int main()
{
    Zoo zoo("ZooPtycon"); // déclaration du nom par défaut
    int visitor = 0, all_visitors = 0, nextMonth = 0, nbYearZoo = 0, revenue = 0, mois = 1;
    float Subvention = 0;
    bool enoughMeat, enoughSeed = false;
    bool nbEagleSuccess = false, moneySuccess = false, nbTotalVisitorSuccess = false, nbMonthVisitorsSuccess = false;
    StartGame(zoo, nbYearZoo);

    while (zoo.getYear() < nbYearZoo) // Tous les mois
    {
        if (zoo.getMonth() == 0) // tous les mois sauf celui quand le code se lance
        {
            zoo.NextMonth(); // incrémente la variable tout les mois
            zoo.getInfo();   // affiche l'année, le mois et le budget, chaque mois
        }

        nextMonth = 0; // Action pour le mois
        while (zoo.getYear() < 10 && nextMonth != 1)
        {
            cout << "\n--------------------------------\n1 | Passer le mois\t\t\t 2 | Achat / Vente\t\t3 | Avoir des information sur le zoo" << endl;
            cout << "4 | Changer un animal d'habitat\t\t-1 | Quitter le jeu" << endl;
            scanf("%d", &nextMonth);
            Clear();
            switch (nextMonth)
            {
            case 4: // changement d'habitat pour un animal
                switchHabitat(zoo);
                Clear();
                zoo.getInfo();
                break;
            case 3: // Affichage des infos du zoo
                infoZoo(zoo, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess);
                break;
            case 2: // Actions pour le mois actuel
                actionMonth(zoo);
                Clear();
                zoo.getInfo();
                break;
            case 1:              // Lorsque le mois est passé, met a jour la nourriture et l'age des animaux
                zoo.NextMonth(); // incrémente la variable tout les mois
                
                visitor = Visitor(zoo);            // calcul le nb de visiteur
                all_visitors += visitor;           // calcul le nb de visiteurs total
                revenue = VisitorRevenue(visitor); // calcul du revenue par rapport aux visiteurs
                zoo.UpdateBudget(revenue);         // calcul le revenue lié aux visiteurs
                if (zoo.getMonth() == 13)          // Nouvelle année
                {
                    zoo.setMonth(1);    // reset le mois à 1 pour janvier
                    zoo.setYear(1);     // ajoute 1 aux années
                    zoo.UpdateMalade(); // Reset la possibilité qu'un animal soit malade
                    Subvention = subvention(zoo); // calcul les subventions
                    zoo.UpdateBudget(Subvention); // ajoute les subventions
                }
                zoo.getInfo();                                    // Affiche la date du nouveau mois + le budget
                zoo.UpdateAge();                                  // ajoute un mois à l'age de chaque animaux
                zoo.UpdateMeat();                                 // Réduit la quantité de viande en fonction des tigres et aigles
                zoo.UpdateSeed();                                 // Réduit la quantité de graines en fonction des poules et coqs
                zoo.UpdateHabitat();                              // Verifie s'il y a une surpop dans un habitat (risque de mort d'un animal)
                animalsReproduction(zoo, enoughMeat, enoughSeed); // Reproduction des animaux
                break;
            case -1:
                printEndGame(zoo, all_visitors, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess); // affiche la fin de la partie
                return 0;
            }

            checkSuccess(zoo, nbEagleSuccess, moneySuccess, all_visitors, nbTotalVisitorSuccess, nbMonthVisitorsSuccess, visitor); // Verifie si un succes a été débloqué
            if (mois+1 = zoo.getMonth())
            {
                specialEvent(zoo);                                                                                                     // créé les événements spéciaux
                mois = zoo.getMonth();
            }
            checkingFoodStorage(zoo, enoughMeat, enoughSeed);                                                                      // Affiche et verifie la quantité de nourriture
            cout << "\nRevenus pour " << visitor << " visiteurs : " << revenue << endl;
            if (zoo.getMonth() == 1)
            {
                cout << "New Year ! subvention : " << Subvention << endl;
                mois = 1;
            }
        }
    }
    printEndGame(zoo, all_visitors, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess); // affiche la fin de la partie
    return 0;
}
