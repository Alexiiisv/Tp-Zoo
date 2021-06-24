#include "../header/zoo.h"
#include "../header/utils.h"
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
using namespace std;

// Check les succès
void checkSuccess(Zoo zoo, bool &nbEagleSuccess, bool &moneySuccess, int all_visitors, bool &nbTotalVisitorSuccess, bool &nbMonthVisitorsSuccess, int visitor)
{
    string message;
    if ((nbEagleSuccess == false && (zoo.getAGender("Female", "aigle") + zoo.getAGender("Male", "aigle")) >= 12) || (moneySuccess == false && zoo.getBudget() >= 300000) || (nbTotalVisitorSuccess == false && all_visitors >= 20000) || (nbMonthVisitorsSuccess == false && visitor >= 500))
    {
        if (nbMonthVisitorsSuccess == false && visitor >= 150)
        {
            nbMonthVisitorsSuccess = true;
            message = "Succes deverouiller : Plus apprecie que les maisons closes (vous avez eu plus de 500 visiteurs dans un seul mois) + 2500$";
            zoo.UpdateBudget(2500);
        }
        else if (nbEagleSuccess == false && (zoo.getAGender("Female", "aigle") + zoo.getAGender("Male", "aigle")) >= 12)
        {
            nbEagleSuccess = true;
            message = "Succes deverouiller : Ami des aigles (vous possedez 12 aigles ou plus) + 3000$";
            zoo.UpdateBudget(3000);
        }
        else if (moneySuccess == false && zoo.getBudget() >= 300000)
        {
            moneySuccess = true;
            message = "Succes deverouiller : Riche as fuck (Vous avec atteint un budget de 300000$) + 5000$";
            zoo.UpdateBudget(5000);
        }
        else if (all_visitors >= 20000)
        {
            nbTotalVisitorSuccess = true;
            message = "Succes deverouiller : Parc d'attraction (Vous avez atteint 20000 visiteurs au cumule) + 3000$";
            zoo.UpdateBudget(3000);
        }

        for (int i = 7; i > 0; i--)
        {
            cout << "\n\n\n\n\n\n\n         .* *.               `o`o`\n         *. .*              o`o`o`o      ^,^,^\n           * \\               `o`o`     ^,^,^,^,^\n              \\     ***        |       ^,^,^,^,^\t" << message << "\n               \\   *****       |        /^,^,^\n                \\   ***        |       /\n    ~@~*~@~      \\   \\         |      /\n  ~*~@~*~@~*~     \\   \\        |     /\n  ~*~@smd@~*~      \\   \\       |    /     #$#$#        .`'.;.\n  ~*~@~*~@~*~       \\   \\      |   /     #$#$#$#   00  .`,.',\n    ~@~*~@~ \\        \\   \\     |  /      /#$#$#   /|||  `.,'\n_____________\\________\\___\\____|_/______/_________|\\/\\___||______" << endl;
            cout << i << endl;
            Sleep(1000);
            Clear();
            zoo.getInfo();
        }
    }
}

// Affiche les succes deverouillé et non deverouillé
void AffichageSuccess(bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSucess, bool nbMonthVisitorSuccess)
{
    cout << "\n\t" << boolalpha << nbEagleSuccess << "\t| Ami des aigles\t\t\tAvoir plus de 12 aigles" << endl;
    cout << "\t" << boolalpha << moneySuccess << "\t| Riche as fuck\t\t\t\tAtteindre plus de 300000$" << endl;
    cout << "\t" << boolalpha << nbTotalVisitorSucess << "\t| Parc d'attraction\t\t\tAtteindre plus de 20000 visiteurs" << endl;
    cout << "\t" << boolalpha << nbTotalVisitorSucess << "\t| Plus apprecie que les maisons closes\tAtteindre 500 en un seul mois\n"
         << endl;
}
