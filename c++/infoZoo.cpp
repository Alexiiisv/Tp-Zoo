#include "../header/zoo.h"
#include <stdlib.h>
#include "../header/utils.h"
#include "../header/aigle.h"
#include "../header/tigre.h"
#include "../header/poule.h"
#include "../header/coq.h"
#include "../header/eagleHabitat.h"
#include "../header/chickenHabitat.h"
#include "../header/tigerHabitat.h"
#include "../header/success.h"
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
using namespace std;

void partiePerso(Zoo &zoo, int &nbYearZoo)
{
    int nbyear = 0, budg = 0;
    while (nbyear != 1 && nbyear != 2 && nbyear != 3 && nbyear != 4 && nbyear != 5)
    {
        Clear();
        cout << "Combien d'annee voulez-voulez jouer ?\n1 | 2 ans\t\t2 | 5 ans\t\t3 | 10 ans\t\t4 | 20 ans\t\t5 | 50 ans" << endl;
        scanf("%d", &nbyear);
        switch (nbyear)
        {
        case 1:
            nbYearZoo = 2;
            break;
        case 2:
            nbYearZoo = 5;
            break;
        case 3:
            nbYearZoo = 10;
            break;
        case 4:
            nbYearZoo = 20;
            break;
        case 5:
            nbYearZoo = 50;
            break;
        default:
            break;
        }
        Clear();
        cout << "Quel budget vous-voulez avoir ?\n1 | 20000$\t\t2 | 50000$\t\t3 | 100000$\t\t4 | 150000$\t\t5 | 500000$" << endl;
        scanf("%d", &budg);
        switch (budg)
        {
        case 1:
            zoo.setBudget(20000);
            break;
        case 2:
            zoo.setBudget(50000);
            break;
        case 3:
            zoo.setBudget(100000);
            break;
        case 4:
            zoo.setBudget(150000);
            break;
        case 5:
            zoo.setBudget(500000);
            break;
        default:
            break;
        }
    }
}

// Créé les éléments nécessaire pour la partie rapide
void partieRapide(Zoo &zoo, int &nbYearZoo)
{
    // set le budget
    zoo.setBudget(86300);
    // achete un habitat d'aigle et 2 couples d'aigle
    zoo.addHabitat(new EagleHabitat("aigle"));
    zoo.addAnimal(new Aigle("AigleMale1", "aigle", "Male", 0.25, 12 * 4), 0);
    zoo.addAnimal(new Aigle("AigleMale2", "aigle", "Male", 0.25, 12 * 4), 0);
    zoo.addAnimal(new Aigle("AigleFemelle1", "aigle", "Female", 0.3, 12 * 4), 0);
    zoo.addAnimal(new Aigle("AigleFemelle2", "aigle", "Female", 0.3, 12 * 4), 0);
    // achete deux habitats de tigre et 2 couples de tigre
    zoo.addHabitat(new TigerHabitat("tigre"));
    zoo.addHabitat(new TigerHabitat("tigre"));
    zoo.addAnimal(new Tigre("TigreMale1", "tigre", "Male", 12, 12 * 6), 0);
    zoo.addAnimal(new Tigre("TigreMale2", "tigre", "Male", 12, 12 * 6), 1);
    zoo.addAnimal(new Tigre("TigreFemelle1", "tigre", "Female", 10, 12 * 4), 1);
    zoo.addAnimal(new Tigre("TigreFemelle2", "tigre", "Female", 10, 12 * 4), 0);
    // achete un habitat de poule, 2 coqs et 8 poules
    zoo.addHabitat(new ChickenHabitat("poule"));
    zoo.addAnimal(new Coq("Coq1", "coq", 0.18, 6), 0);
    zoo.addAnimal(new Coq("Coq2", "coq", 0.18, 6), 0);
    for (int i = 0; i < 8; i++)
    {
        string name = "poulette" + to_string(i+1);
        zoo.addAnimal(new Poule(name, "poule", 0.15, 6), 0);
    }
    // Règle la durée à 10 ans
    nbYearZoo = 10;
}

// Menu de début de jeu
void StartGame(Zoo &zoo, int &nbYearZoo)
{
    char zooName[20];
    int choice = 0, nbyear = 0, budg = 0, choix = 0;
    Clear();
    cout << "Bienvenue dans ZooPtycon, la simulation de zoo la plus realiste de 2021\n\nVoulez-vous donner un nom a votre zoo ?\n1 | Oui\t\t 0 | Non" << endl;
    scanf("%d", &choix);
    Clear();
    if (choix == 1)
    {
        cout << "Comment s'appel votre Zoo ? !! Ne pas depasser les 13 caracteres !!" << endl;
        scanf("%15s", &zooName);
        Clear();
        zoo.setName(zooName);
    }

    cout << "Que voulez-vous faire ?\n"
         << endl;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "1 | Partie rapide : 80000$, 2 couples d'aigle, 2 couples de tigre, 2 coqs, 8 poules sur 10 ans\n2 | Partie personnalise\n3 | SandBox" << endl;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // partie Rapide
            partieRapide(zoo, nbYearZoo);
            break;
        case 2: // partie Personnalisée
            partiePerso(zoo, nbYearZoo);
            break;
        case 3: // partie SandBox
            zoo.setBudget(999999999);
            zoo.setMeat(999999999);
            zoo.setSeed(999999999);
            nbYearZoo = 100;
        default:
            break;
        }
    }
    Clear();
}
// Affichage de fin de jeu
void printEndGame(Zoo &zoo, int all_visitors, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSuccess, bool nbMonthVisitorsSuccess)
{
    int yesSir;
    Clear();
    if (zoo.getYear() > 1)
    {
        cout << "La Partie est finie\nA la fin tu avais "
             << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors
             << " visiteurs sur " << zoo.getYear() << " ans et " << zoo.getMonth() << " mois." << endl;
    }
    else if (zoo.getYear() > 0)
    {
        cout << "La Partie est finie\nA la fin tu avais "
             << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors
             << " visiteurs sur " << zoo.getYear() << " an et " << zoo.getMonth() << " mois." << endl;
    }
    else
    {
        cout << "La Partie est finie\nA la fin tu avais "
             << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors
             << " visiteurs sur " << zoo.getMonth() << " mois." << endl;
    }

    //afficher sucess
    cout << "Voulez-vous voir les succes de la partie ?\n0 | Non\t\t1 | Oui" << endl;
    scanf("%d", &yesSir);
    if (yesSir == 1)
    {
        for (int i = 5; i > 0; i--)
        {
            AffichageSuccess(nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess);
            cout << i << endl;
            Sleep(1000);
            Clear();
        }
    }
}

void infoAigle(Zoo &zoo)
{
    int info = 0;
    cout << "\n          ///,        ////\n          \\  /,      /  >.\n           \\  /,   _/  /.\n            \\_  /_/   /.\n             \\__/_   <\n             /<<< \\_\\_\n            /,)^>>_._ \\\n            (/   \\\\ /\\\\\\\n                 // ````\n                ((`\n\n"
         << endl;
    cout << "Nombre d'aigle actuel : " << zoo.GetAnimalNbrByRace("aigle") << endl;                                                           //nb d'aigle
    cout << "Vous avez " << zoo.getAGender("Male", "aigle") << " male(s) et " << zoo.getAGender("Female", "aigle") << " femelle(s)" << endl; // nb de male et de femelle
    cout << "Vous-voulez plus d'informations sur vos aigles ?\n1 | Oui\t\t0 | Non\t\t" << endl;                                              // demande d'info supplémentaire
    scanf("%d", &info);
    if (info == 1)
    {
        zoo.getAllInfo("aigle");
    }
}
void infoTigre(Zoo &zoo)
{
    int info = 0;
    cout << "\n   _\n  ( \\                ..-----..__\n   \\.'.        _.--'`  [   '  ' ```'-._\n    `. `'-..-'' `    '  ' '   .  ;   ; `-'''-.,__/|/_\n      `'-.;..-''`|'  `.  '.    ;     '  `    '   `'  `,\n                 \\ '   .    ' .     '   ;   .`   . ' 7 \\\n                  '.' . '- . \\    .`   .`  .   .\\     `Y\n                    '-.' .   ].  '   ,    '    /'`\"\"';:'\n                      /Y   '.] '-._ /    ' _.-'\n                      \\'\\_   ; (`'.'.'  .\"/\n                       ' )` /  `.'   .-'.'\n                        '\\  \\).'  .-'--\"\n                          `. `,_'`\n                            `.__)  \n\n"
         << endl;
    cout << "Nombre de tigre actuel : " << zoo.GetAnimalNbrByRace("tigre") << endl;                                                          //nb d'aigle
    cout << "Vous avez " << zoo.getAGender("Male", "tigre") << " male(s) et " << zoo.getAGender("Female", "tigre") << " femelle(s)" << endl; // nb de male et de femelle
    cout << "Vous-voulez plus d'informations sur vos tigres ?\n1 | Oui\t\t0 | Non\t\t" << endl;                                              // demande d'info supplémentaire
    scanf("%d", &info);
    if (info == 1)
    {
        zoo.getAllInfo("tigre");
    }
}
void infoPoule(Zoo &zoo)
{
    int info = 0;
    cout << "\n                                              _\n                                   .-.  .--''` )\n                                _ |  |/`   .-'`\n                               ( `\\      /`\n                               _)   _.  -'._\n                             /`  .'     .-.-;\n                             `).'      /  \\  \\\n                            (`,        \\_o/_o/__\n                             /           .-''`  ``'-.\n                             {         /` ,___.--''`\n                             {   ;     '-. \\ \\\n           _   _             {   |'-....-`'.\\_\\\n          / './ '.           \\   \\          `\"`\n       _  \\   \\  |            \\   \\\n      ( '-.J     \\_..----.._ __)   `\\--..__\n     .-`                    `        `\\    ''--...--.\n    (_,.--\"\"`/`         .-             `\\       .__ _)\n            |          (                 }    .__ _)\n            \\_,         '.               }_  - _.'\n               \\_,         '.            } `'--'\n                  '._.     ,_)          /\n                     |    /           .'\n                      \\   |    _   .-'\n                       \\__/;--.||-'\n                        _||   _||__   __\n                 _ __.-` \"`)(` `\"  ```._)\n                (_`,-   ,-'  `''-.   '-._)\n               (  (    /          '.__.'\n                `\"`'--'\n\n"
         << endl;
    cout << "Vous-voulez plus d'informations sur vos poules / coq ?\n1 | Oui\t\t0 | Non\t\t" << endl; // demande d'info supplémentaire
    scanf("%d", &info);
    if (info == 1)
    {
        zoo.getAllInfo("poule");
    }
}
// Avoir toutes les infos à propos du zoo
void infoZoo(Zoo &zoo, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSucess, bool nbMonthVisitorSuccess)
{
    int info = 1;
    while (info != 0)
    {
        cout << "Que voulez-vous afficher ?\n1 | Infos sur les animaux\t\t2 | Nombre d'habitats\t\t0 pour quitter le menu\n3 | Quantite de nourriture\t\t4 | Les succes" << endl;
        scanf("%d", &info);
        Clear();
        switch (info)
        {
        case 1: // Affiche les infos des animaux
            cout << "\x1B[2J\x1B[HSur quel race vous-voulez des informations ?\n3 | Aigles\t\t4 | Tigres\t\t0 | pour quitter le menu\n5 | Poules / Coq"
                 << endl;
            scanf("%d", &info);
            Clear();
            switch (info)
            {
            case 3: // infos sur les aigles
                infoAigle(zoo);
                break;
            case 4: // infos sur les tigres
                infoTigre(zoo);
                break;
            case 5: // infos sur les poules/coq
                infoPoule(zoo);
                break;
            default: // quitter
                break;
            }
            break;
        case 2: // Affiche les infos des habitats
            zoo.GetHabitatAnimal("All Habitat");
            break;
        case 3: // Affiche la quantité de nourriture
            cout << "Quantite de viande : " << zoo.getMeat() << endl;
            cout << "Quantite de graine : " << zoo.getSeed() << "\n"
                 << endl;
            break;
        case 4: // Affiche les succès
            AffichageSuccess(nbEagleSuccess, moneySuccess, nbTotalVisitorSucess, nbMonthVisitorSuccess);
            break;
        default:
            break;
        }
    }
    Clear();
    zoo.getInfo();
}