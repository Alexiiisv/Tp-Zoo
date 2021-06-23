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
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

int randomnbr(int min, int max)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

// Génère un string random
string randomStr(int len)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{'a', 'z'};
    string rand_str(len, '\0');
    for (auto &dis : rand_str)
        dis = distribution(generator);
    return rand_str;
}
// Affiche les succes deverouillé et non deverouillé
void AffichageSuccess(bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSucess, bool nbMonthVisitorSuccess)
{
    cout << boolalpha << nbEagleSuccess << "\t| Ami des aigles\t\t\tAvoir plus de 12 aigles" << endl;
    cout << boolalpha << moneySuccess << "\t| Riche as fuck\t\t\t\tAtteindre plus de 100000$" << endl;
    cout << boolalpha << nbTotalVisitorSucess << "\t| Parc d'attraction\t\t\tAtteindre plus de 1000 visiteurs" << endl;
    cout << boolalpha << nbTotalVisitorSucess << "\t| Plus apprecie que les maisons closes\tAtteindre 150 en un seul mois\n"
         << endl;
}
// Menu de début de jeu
void StartGame(Zoo &zoo, int &nbYearZoo)
{
    char zooName[15];
    int choice = 0, nbyear = 0, budg = 0, choix = 0;
    Clear();
    cout << "Bienvenue dans ZooPtycon, la simulation de zoo la plus realiste de 2021\n\nVoulez-vous donner un nom a votre zoo ?\n1 | Oui\t\t 0 | Non" << endl;
    scanf("%d", &choix);
    if (choix == 1)
    {
        cout << "Comment s'appel votre Zoo ?" << endl;
        scanf("%15s", &zooName);
        zoo.setName(zooName);
    }

    Clear();
    cout << "Que voulez-vous faire ?\n"
         << endl;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "1 | Partie rapide : 80000$, 2 couples d'aigle, 2 couples de tigre, 2 coqs, 8 poules sur 10 ans\n2 | Partie personnalise\n3 | SandBox" << endl;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
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
                zoo.addAnimal(new Poule("Poulette", "poule", 0.15, 6), 0);
            }
            // Règle la durée à 10 ans
            nbYearZoo = 10;
            break;
        case 2:
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
            break;
        case 3:
            // set le budget
            zoo.setBudget(999999999);
            // set la nourriture
            zoo.setMeat(999999999);
            zoo.setSeed(999999999);
            // Règle la durée à 10 ans
            nbYearZoo = 100;
        default:
            break;
        }
    }
    Clear();
}
// Affichage de fin de jeu
void printEndGame(Zoo zoo, int all_visitors, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSuccess, bool nbMonthVisitorsSuccess)
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
// Avoir toutes les infos à propos du zoo
void infoZoo(Zoo zoo, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSucess, bool nbMonthVisitorSuccess)
{
    int Gender = 2;
    int info = 1;
    float food;
    while (info != 0)
    {
        cout << "Que voulez-vous afficher ?\n1 | Infos sur les animaux\t\t2 | Nombre d'habitats\t\t0 pour quitter le menu\n3 | Quantite de nourriture\t\t4 | Les succes" << endl;
        scanf("%d", &info);

        switch (info)
        {
        case 1: // Affiche les infos des animaux
            cout << "\x1B[2J\x1B[HSur quel race vous-voulez des informations ?\n3 | Aigles\t\t4 | Tigres\t\t0 | pour quitter le menu\n5 | Poules"
                 << endl;
            scanf("%d", &info);
            switch (info)
            {
            case 3: // infos sur les aigles
                cout << "\n          ///,        ////\n          \\  /,      /  >.\n           \\  /,   _/  /.\n            \\_  /_/   /.\n             \\__/_   <\n             /<<< \\_\\_\n            /,)^>>_._ \\\n            (/   \\\\ /\\\\\\\n                 // ````\n                ((`\n"
                     << endl;

                cout << "Nombre d'aigle actuel : " << zoo.GetAnimalNbrByRace("aigle") << endl;                                                           //nb d'aigle
                cout << "Vous avez " << zoo.getAGender("Male", "aigle") << " male(s) et " << zoo.getAGender("Female", "aigle") << " femelle(s)" << endl; // nb de male et de femelle
                cout << "Vous-voulez plus d'informations sur vos aigles ?\n1 | Oui\t\t0 | Non\t\t" << endl;                                              // demande d'info supplémentaire
                scanf("%d", &info);
                if (info == 1)
                {
                    zoo.getAllInfo("aigle");
                }
                break;
            case 4: // infos sur les tigres
                cout << "tigres" << endl;
                break;
            case 5:
                cout << "poules" << endl;
                break;
            default: // infos sur les poules
                break;
            }
            break;
        case 2: // Affiche les infos des habitats
            zoo.GetHabitatAnimal("All Habitat");
            break;
        case 3: // Affiche la quantité de nourriture
            cout << "Quantite de viande : " << zoo.getMeat() << endl;
            cout << "Quantite de graine : " << zoo.getSeed() << endl;
            break;
        case 4: // Affiche les succès
            AffichageSuccess(nbEagleSuccess, moneySuccess, nbTotalVisitorSucess, nbMonthVisitorSuccess);
            break;
        default:
            break;
        }
    }
}
// Check les succès
void checkSuccess(Zoo zoo, bool &nbEagleSuccess, bool &moneySuccess, int all_visitors, bool &nbTotalVisitorSuccess, bool &nbMonthVisitorsSuccess, int visitor)
{
    string message;
    if ((nbEagleSuccess == false && (zoo.getAGender("Female", "aigle") + zoo.getAGender("Male", "aigle")) >= 12) || (moneySuccess == false && zoo.getBudget() >= 100000) || (nbTotalVisitorSuccess == false && all_visitors >= 1000) || (nbMonthVisitorsSuccess == false && visitor >= 150))
    {
        if (nbMonthVisitorsSuccess == false && visitor >= 150)
        {
            nbMonthVisitorsSuccess = true;
            message = "Succes deverouiller : Plus apprecie que les maisons closes (vous avez eu plus de 150 visiteurs dans un seul mois) + 2500$";
            zoo.UpdateBudget(2500);
        }
        else if (nbEagleSuccess == false && (zoo.getAGender("Female", "aigle") + zoo.getAGender("Male", "aigle")) >= 12)
        {
            nbEagleSuccess = true;
            message = "Succes deverouiller : Ami des aigles (vous possedez 12 aigles ou plus) + 3000$";
            zoo.UpdateBudget(3000);
        }
        else if (moneySuccess == false && zoo.getBudget() >= 100000)
        {
            moneySuccess = true;
            message = "Succes deverouiller : Riche as fuck (Vous avec atteint un budget de 100000$) + 2000$";
            zoo.UpdateBudget(2000);
        }
        else if (all_visitors >= 1000)
        {
            nbTotalVisitorSuccess = true;
            message = "Succes deverouiller : Parc d'attraction (Vous avez atteint 1000 visiteurs au cumule) + 3000$";
            zoo.UpdateBudget(3000);
        }

        for (int i = 1; i > 0; i--)
        {
            cout << "\n\n\n\n\n\n\n         .* *.               `o`o`\n         *. .*              o`o`o`o      ^,^,^\n           * \\               `o`o`     ^,^,^,^,^\n              \\     ***        |       ^,^,^,^,^\t" << message << "\n               \\   *****       |        /^,^,^\n                \\   ***        |       /\n    ~@~*~@~      \\   \\         |      /\n  ~*~@~*~@~*~     \\   \\        |     /\n  ~*~@smd@~*~      \\   \\       |    /     #$#$#        .`'.;.\n  ~*~@~*~@~*~       \\   \\      |   /     #$#$#$#   00  .`,.',\n    ~@~*~@~ \\        \\   \\     |  /      /#$#$#   /|||  `.,'\n_____________\\________\\___\\____|_/______/_________|\\/\\___||______" << endl;
            cout << i << endl;
            Sleep(1000);
            Clear();
        }
    }
}
// Changer un animal d'habitat
void switchHabitat(Zoo zoo)
{
    int initialHabitat = 0, animal = 0, destination = 0, skip = 1, whichAnimal = 0;

    while (whichAnimal != 1 && whichAnimal != 2 && whichAnimal != 3 && whichAnimal != 4)
    {
        cout << "Quel animal voulez-vous deplacer ?\n1 | aigle\t\t2 | tigre\t\t3 | poule\t\t4 | coq\t\t0 | quitter le menu" << endl;
        scanf("%d", &whichAnimal);

        switch (whichAnimal)
        {
        case 1: // Déplacer un aigle
            while (skip != 0)
            {
                // choix de l'habitat de départ
                cout << "Depuis l'habitat numero __ , vous deplacez l'aigle numero __ , vers l'habitat numero __" << endl;
                cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez "
                     << zoo.GetHabitatNbrByRace("aigle") << " habitat pour les aigles" << endl;
                scanf("%d", &initialHabitat);

                // choix de l'animal a déplacer
                cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                     << endl;
                zoo.GetHabitatAnimal(to_string(initialHabitat), "aigle");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero __ , vers l'habitat numero __" << endl;
                scanf("%d", &animal);

                // choix de l'habitat de destination
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero __" << endl;
                cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
                zoo.GetHabitatAnimal("aigle");
                scanf("%d", &destination);

                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero " << destination << endl;
                cout << "Appuyez sur 0 pour confirmer" << endl;
                scanf("%d", &skip);
            }
            zoo.SwitchHabitat(initialHabitat, animal, destination, "aigle");
            break;
        case 2: // Déplacer un tigre
            while (skip != 0)
            {
                // choix de l'habitat de départ
                cout << "Depuis l'habitat numero __ , vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
                cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("tigre") << " habitat pour les tigres" << endl;
                scanf("%d", &initialHabitat);

                // choix de l'animal a déplacer
                cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                     << endl;
                zoo.GetHabitatAnimal(to_string(initialHabitat), "tigre");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
                scanf("%d", &animal);

                // choix de l'habitat de destination
                cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
                zoo.GetHabitatAnimal("tigre");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero __" << endl;
                scanf("%d", &destination);

                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero " << destination << endl;
                cout << "Appuyez sur 0 pour confirmer" << endl;
                scanf("%d", &skip);
            }
            zoo.SwitchHabitat(initialHabitat, animal, destination, "tigre");
            break;
        case 3: // Déplacer poule
            while (skip != 0)
            {
                // choix de l'habitat de départ
                cout << "Depuis l'habitat numero __, vous deplacez le la poule numero __ vers l'habitat numero __" << endl;
                cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("poule") << " habitats pour les poules" << endl;
                scanf("%d", &initialHabitat);

                // choix de l'animal a déplacer
                cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                     << endl;
                zoo.GetHabitatAnimal(to_string(initialHabitat), "poule");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero __ vers l'habitat numero __" << endl;
                scanf("%d", &animal);

                // choix de l'habitat de destination
                cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
                zoo.GetHabitatAnimal("poule");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero __" << endl;
                scanf("%d", &destination);

                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero " << destination << endl;
                cout << "Appuyez sur 0 pour confirmer" << endl;
                scanf("%d", &skip);
            }
            zoo.SwitchHabitat(initialHabitat, animal, destination, "poule");
            break;
        case 4: // Déplacer coq
            while (skip != 0)
            {
                // choix de l'habitat de départ
                cout << "Depuis l'habitat numero __, vous deplacez l'aigle numero __ vers l'habitat numero __" << endl;
                cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez "
                     << zoo.GetHabitatNbrByRace("poule") << " habitats pour les poules" << endl;
                scanf("%d", &initialHabitat);

                // choix de l'animal a déplacer
                cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                     << endl;
                zoo.GetHabitatAnimal(to_string(initialHabitat), "poule");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero __ vers l'habitat numero __" << endl;
                scanf("%d", &animal);

                // choix de l'habitat de destination
                cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
                zoo.GetHabitatAnimal("poule");
                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero __" << endl;
                scanf("%d", &destination);

                cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero " << destination << endl;
                cout << "Appuyez sur 0 pour confirmer" << endl;
                scanf("%d", &skip);
            }
            zoo.SwitchHabitat(initialHabitat, animal, destination, "coq");
            break;
        default:
            break;
        }
    }
}
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
    cout << "\nRevenus pour " << visitor << " visiteurs : " << result << endl;
    return result;
}
// Get number of visitors
int Visitor(int tiger, int eagle, int chicken, int month)
{
    double variation = randomnbr(0, 40) - 20; // generate random number (-20 / 20)
    if (month >= 5 && month <= 9)
    {
        // Saison haute
        return round((30 * tiger + 15 * eagle + 2 * chicken) * (1 + variation / 100));
    }
    // Saison basse
    return round((5 * tiger + 7 * eagle + 0.5 * chicken) * (1 + variation / 100));
}
// Add money each year
float subvention(int tiger, int eagle, int month, int year)
{
    float subvention = tiger * 43800 + eagle * 2190; // Calcul de la subvention en fonction de l'animal
    cout << "New Year ! subvention : " << subvention << endl;
    return subvention;
}
// Menu to buy an Animal
void buyAnimal(Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1, choix_age = 0, age = 0, genre = 10, habitat = 0;
    float food;
    bool nomoni = true;
    string gender[2] = {"Female", "Male"};
    cout << "\nQue voulez-vous acheter ?\n3 | aigles\t\t4 | tigres\t\t0 | pour quitter le menu\n5 | poules\t\t6 | coq\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {

        if (zoo.GetHabitatNbrByRace("aigle") > 0 && zoo.getBudget() >= 1000)
        {
            while (genre != 0 && genre != 1)
            {
                cout << "Voulez-vous un male une femelle ?\n0 | Femelle\t1 | Male" << endl;
                scanf("%d", &genre);
            }
            cout << "Donnez un nom a votre aigle" << endl;
            scanf("%15s", &nom);
            while (choix_age == 0)
            {
                cout << "Voulez-vous l'acheter enfant, adulte ou vieux ?\n1 | Enfant (1000$)\t\t2 | Adulte (4000$)\t\t3| Vieux (2000$)" << endl;
                scanf("%d", &choix_age);
                switch (choix_age)
                {
                case 1:
                    cout << "Enfant" << endl;
                    if (zoo.getBudget() - 1000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas la tune pour acheter un aigle" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 1000 >= 0)
                    {
                        zoo.UpdateBudget(-1000);
                        age = 120 / 10 / 1 / 2;
                    }
                    break;
                case 2:
                    cout << "Adulte" << endl;
                    if (zoo.getBudget() - 4000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas la tune pour acheter un aigle" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 4000 >= 0)
                    {
                        zoo.UpdateBudget(-4000);
                        age = 12 * 4;
                    }
                    break;
                case 3:
                    cout << "Vieux" << endl;

                    if (zoo.getBudget() - 2000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas la tune pour acheter un aigle" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 2000 >= 0)
                    {
                        zoo.UpdateBudget(-2000);
                        age = 12 * 14;
                    }
                    break;
                default:
                    break;
                }
                if (choix_age > 3 || choix_age < 1)
                {
                    choix_age = 0;
                }
            }
            if (nomoni)
            {
                switch (genre)
                {
                case 0: // consommation de viande aigle femelle
                    food = 0.3;
                    break;

                default: // consommation de viande aigle male
                    food = 0.25;
                    break;
                }
                cout << habitat << endl;

                while (habitat == 0)
                {
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez "
                         << zoo.GetHabitatNbrByRace("aigle") << " d'habitat pour les aigles" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("aigle"))
                    {
                        habitat = 0;
                    }
                }
                zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age), habitat - 1);
                Clear();
                cout << "Tu viens d'acheter un aigle ; tu en as maintenant " << zoo.GetAnimalNbrByRace("aigle") << endl;
            }

            habitat = 0;
        }
        else if (zoo.GetHabitatNbrByRace("aigle") == 0)
        {
            cout << "Vous n'avez pas d'habitat d'aigle ! Veuillez en acheter un" << endl;
        }
        else if (zoo.getBudget() < 1000)
        {
            cout << "Vous n'avez pas assez d'argent pour acheter un aigle" << endl;
        }
    }
    else if (whatToBuy == 4)
    {
        if (zoo.GetHabitatNbrByRace("tigre") > 0 && zoo.getBudget() >= 3000)
        {
            while (genre != 0 && genre != 1)
            {
                cout << "Voulez-vous un male une femelle ?\n0 | Femelle\t1 | Male" << endl;
                scanf("%d", &genre);
            }
            cout << "Donnez un nom a votre aigle" << endl;
            scanf("%15s", &nom);
            while (choix_age == 0)
            {
                cout << "Voulez-vous l'acheter enfant, adulte ou vieux ?\n1 | Enfant (3000$)\t\t2 | Adulte (120000$)\t\t3| Vieux (60000$)" << endl;
                scanf("%d", &choix_age);
                switch (choix_age)
                {
                case 1:
                    cout << "Enfant" << endl;
                    if (zoo.getBudget() - 3000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas l'argent pour acheter un tigre" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 3000 >= 0)
                    {
                        zoo.UpdateBudget(-3000);
                        age = 120 / 10 / 1 / 2;
                    }
                    break;
                case 2:
                    cout << "Adulte" << endl;
                    if (zoo.getBudget() - 120000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas l'argent pour acheter un tigre" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 120000 >= 0)
                    {
                        zoo.UpdateBudget(-120000);
                        age = 12 * 4;
                    }
                    break;
                case 3:
                    cout << "Vieux" << endl;

                    if (zoo.getBudget() - 60000 < 0)
                    {
                        nomoni = false;
                        cout << "t'as pas l'argent pour acheter un tigre" << endl;
                        break;
                    }
                    else if (zoo.getBudget() - 60000 >= 0)
                    {
                        zoo.UpdateBudget(-60000);
                        age = 12 * 14;
                    }
                    break;
                default:
                    break;
                }
                if (choix_age > 3 || choix_age < 1)
                {
                    choix_age = 0;
                }
            }
            if (nomoni)
            {
                switch (genre)
                {
                case 0: // consommation de viande tigre femelle
                    food = 10;
                    break;

                default: // consommation de viande tigre male
                    food = 12;
                    break;
                }
                cout << habitat << endl;

                while (habitat == 0)
                {
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez "
                         << zoo.GetHabitatNbrByRace("tigre") << " d'habitat pour les tigres" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("tigre"))
                    {
                        habitat = 0;
                    }
                }
                zoo.addAnimal(new Tigre(nom, "tigre", gender[genre], food, age), habitat - 1);
                Clear();
                cout << "Tu viens d'acheter un tigre ; tu en as maintenant " << zoo.GetAnimalNbrByRace("tigre") << endl;
            }

            habitat = 0;
        }
        else if (zoo.GetHabitatNbrByRace("tigre") == 0)
        {
            cout << "Vous n'avez pas d'habitat pour les tigres ! Veuillez en acheter un" << endl;
        }
        else if (zoo.getBudget() < 3)
        {
            cout << "Vous n'avez pas assez d'argent pour acheter un tigre" << endl;
        }
    }
    else if (whatToBuy == 5)
    {
        if (zoo.getBudget() - 20 >= 0)
        {
            if (zoo.GetHabitatNbrByRace("poule") > 0)
            {
                while (habitat == 0)
                {
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez "
                         << zoo.GetHabitatNbrByRace("poule") << " d'habitat pour les poules" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("poule"))
                    {
                        habitat = 0;
                    }
                }
                zoo.UpdateBudget(-20);
                zoo.addAnimal(new Poule(randomStr(6), "poule", 0.15, 6), habitat - 1);
                habitat = 0;
                Clear();
                cout << "Tu viens d'acheter une poule ; tu as maintenant " << zoo.GetAnimalNbrByRace("poule") << " poules et coqs" << endl;
            }
        }
        else
        {
            cout << "Vous n'avez pas assez d'argent pour acheter une poule" << endl;
        }
    }
    else if (whatToBuy == 6)
    {
        if (zoo.getBudget() - 100 >= 0)
        {
            if (zoo.GetHabitatNbrByRace("poule") > 0)
            {
                while (habitat == 0)
                {
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez "
                         << zoo.GetHabitatNbrByRace("poule") << " d'habitat pour les poules / coq" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("poule"))
                    {
                        habitat = 0;
                    }
                }
                zoo.UpdateBudget(-20);
                zoo.addAnimal(new Coq(randomStr(6), "coq", 0.18, 6), habitat - 1);
                habitat = 0;
                Clear();
                cout << "Tu viens d'acheter un coq ; tu as maintenant " << zoo.GetAnimalNbrByRace("poule") << " poules et coqs" << endl;
            }
        }
        else
        {
            cout << "Vous n'avez pas assez d'argent pour acheter un coq" << endl;
        }
    }
}
// Menu to buy Habitat
void buyHabitats(Zoo &zoo)
{
    int whatToBuy = 1;
    while (whatToBuy != 0 && whatToBuy != 3 && whatToBuy != 4 && whatToBuy != 5)
    {
        Clear();
        cout << "que voulez-vous acheter ?\n3 | Habitat aigles\t\t4 | Habitat tigres\t\t0 | pour quitter le menu\n5 | Habitat poules\nentrez un des numeros pour acheter un habitat" << endl;
        scanf("%d", &whatToBuy);
        Clear();
        switch (whatToBuy)
        {
        case 3: // achat habitat d'aigle
            zoo.addHabitat(new EagleHabitat("aigle"));
            break;
        case 4: // achat habitat d'aigle
            zoo.addHabitat(new TigerHabitat("tigre"));
            break;
        case 5: // achat habitat de poule
            zoo.addHabitat(new ChickenHabitat("poule"));
            break;
        default:
            break;
        }
    }
}
// Actions d'acheter animaux
void actionMonth(Zoo &zoo)
{
    int whichRace = 0, habitat = 0, whatToBuy = 1, animal = 0, backupmone = 0;
    float food = 0, seed = 0;
    while (whatToBuy != 0)
    {
        cout << "\nQue voulez-vous faire :\nAcheter :\t1 | Habitats\t\t2 | Animaux\t\t3 | viandes\t\t4 | Graines\t\t0 pour quitter le menu\nVendre :\t5 | Habitat\t\t6 | Animaux" << endl;
        scanf("%d", &whatToBuy);

        switch (whatToBuy)
        {
        case 1: // achat d'habitat
            buyHabitats(zoo);
            break;
        case 2: // achat d'animaux
            buyAnimal(zoo);
            break;
        case 3: // achat de viande
            cout << "Quelle quantite de viande voulez-vous acheter ? " << endl;
            scanf("%f", &food);
            Clear();
            if (zoo.getBudget() - (food * 5) >= 0)
            {
                cout << "Tu viens d'acheter " << food << "kg de viandes" << endl;
                zoo.setMeat(zoo.getMeat() + food);
                zoo.UpdateBudget(-food * 5);
                cout << "Maintenant tu as " << zoo.getMeat() << "kg de viandes" << endl;
            }
            else
            {
                cout << "Vous n'avez pas assez d'argent pour acheter " << food << " de viande" << endl;
            }
            break;
        case 4: // achat de graine
            cout << "Quelle quantite de graine voulez-vous acheter ? " << endl;
            scanf("%f", &seed);
            Clear();
            if (zoo.getBudget() - (seed * 2.5) >= 0)
            {
                cout << "Tu viens d'acheter " << seed << "kg de graines" << endl;
                zoo.setSeed(zoo.getSeed() + seed);
                zoo.UpdateBudget(-seed * 2.5);
                cout << "Maintenant tu as " << zoo.getSeed() << "kg de graines" << endl;
            }
            else
            {
                cout << "Vous n'avez pas assez d'argent pour acheter " << seed << " de graines" << endl;
            }

            break;
        case 5: // vente d'habitat
            cout << "Vendre un habitat de : !! La vente d'un habitat supprime tout les animaux qu'il possede. La vente se fait sur celui qui possede le moins d'animaux !!\n1 | Tigre\t\t 2 | Poule\t\t3| Aigle" << endl;
            scanf("%d", &whichRace);
            Clear();
            switch (whichRace)
            {
            case 1: // vente habitat tigre
                backupmone = zoo.getBudget();
                zoo.SellHabitat("tigre");
                if (backupmone == zoo.getBudget())
                    cout << "Aucun habitat de tigre n'as ete vendu" << endl;
                else
                    cout << "Tu viens de vendre un habitat de tigre ; Il t'en reste " << zoo.GetHabitatNbrByRace("tigre") << endl;
                break;
            case 2: // vente habitat poule
                backupmone = zoo.getBudget();
                zoo.SellHabitat("poule");
                if (backupmone == zoo.getBudget())
                    cout << "Aucun habitat de poule n'as ete vendu" << endl;
                else
                    cout << "Tu viens de vendre un habitat de poule ; Il t'en reste " << zoo.GetHabitatNbrByRace("poule") << endl;
                break;
            default: // vente habitat aigle
                backupmone = zoo.getBudget();
                zoo.SellHabitat("aigle");
                if (backupmone == zoo.getBudget())
                    cout << "Aucun habitat d'aigle n'as ete vendu" << endl;
                else
                    cout << "Tu viens de vendre un habitat d'aigle ; Il t'en reste " << zoo.GetHabitatNbrByRace("aigle") << endl;
                break;
            }
            break;
        case 6: // vente d'animaux
            cout << "Vendre un :\n1 | Tigre\t\t 2 | Poule\t\t3 | Aigle\t\t4 | Coq" << endl;
            scanf("%d", &whichRace);
            switch (whichRace)
            {
            case 1: // vente tigre
                habitat = 0;
                animal = 0;
                while (habitat == 0)
                {
                    zoo.GetHabitatAnimal("tigre"); // affiche tout les habitats des tigres
                    cout << "Dans quel habitat se situe le tigre que vous voulez vendre ?" << endl;
                    scanf("%d", &habitat);
                    Clear();
                    if (habitat > zoo.GetHabitatNbrByRace("tigre"))
                    {
                        habitat = 0; // reinitialise la variable si elle ne correspond pas au nb d'habitat
                    }
                }
                cout << "L'habitat de tigre numero " << habitat << endl;
                zoo.GetHabitatAnimal(to_string(habitat), "tigre"); // affiche l'habitat selectionné
                while (animal == 0)
                {
                    cout << "Quel tigre de l'habitat choisi voulez-vous vendre ?" << endl;
                    scanf("%d", &animal);
                    Clear();
                    if (animal > zoo.GetAnimalNbrByRace(to_string(habitat)))
                    {
                        animal = 0;
                    }
                }
                zoo.SellAnimal(animal, habitat, "tigre");
                break;
            case 2: // vente poule
                habitat = 0;
                animal = 0;
                while (habitat == 0)
                {
                    zoo.GetHabitatAnimal("poule"); // affiche tout les habitats des poules
                    cout << "Dans quel habitat se situe la poule que vous voulez vendre ?" << endl;
                    scanf("%d", &habitat);
                    Clear();
                    if (habitat > zoo.GetHabitatNbrByRace("poule"))
                    {
                        habitat = 0; // reinitialise la variable si elle ne correspond pas au nb d'habitat
                    }
                }
                cout << "L'habitat de poule numero " << habitat << endl;
                zoo.GetHabitatAnimal(to_string(habitat), "poule"); // affiche l'habitat selectionné
                while (animal == 0)
                {
                    cout << "Quelle poule de l'habitat choisi voulez-vous vendre ?" << endl;
                    scanf("%d", &animal);
                    Clear();
                    if (animal > zoo.GetAnimalNbrByRace(to_string(habitat)))
                    {
                        animal = 0;
                    }
                }
                zoo.SellAnimal(animal, habitat, "poule");
                break;
            case 3: // vente aigle
                habitat = 0;
                animal = 0;
                while (habitat == 0)
                {
                    zoo.GetHabitatAnimal("aigle"); // affiche tout les habitats d'aigles
                    cout << "Dans quel habitat se situe l'aigle que vous-voulez vendre ?" << endl;
                    scanf("%d", &habitat);
                    Clear();
                    if (habitat > zoo.GetHabitatNbrByRace("aigle"))
                    {
                        habitat = 0; // reinitialise la variable si elle ne correspond pas au nb d'habitat
                    }
                }
                cout << "L'habitat d'aigle numero " << habitat << endl;
                zoo.GetHabitatAnimal(to_string(habitat), "aigle"); // affiche l'habitat selectionné
                while (animal == 0)
                {
                    cout << "Quel aigle de l'habitat choisi voulez-vous vendre ?" << endl;
                    scanf("%d", &animal);
                    Clear();
                    if (animal > zoo.GetAnimalNbrByRace(to_string(habitat)))
                    {
                        animal = 0;
                    }
                }
                zoo.SellAnimal(animal, habitat, "aigle");
                break;
            default: // vente coq
                habitat = 0;
                animal = 0;
                while (habitat == 0)
                {
                    zoo.GetHabitatAnimal("poule"); // affiche tout les habitats des coqs
                    cout << "Dans quel habitat se situe le coq que vous voulez vendre ?" << endl;
                    scanf("%d", &habitat);
                    Clear();
                    if (habitat > zoo.GetHabitatNbrByRace("poule"))
                    {
                        habitat = 0; // reinitialise la variable si elle ne correspond pas au nb d'habitat
                    }
                }
                cout << "L'habitat numero " << habitat << endl;
                zoo.GetHabitatAnimal(to_string(habitat), "poule"); // affiche l'habitat selectionné
                while (animal == 0)
                {
                    cout << "Quel coq de l'habitat choisi voulez-vous vendre ?" << endl;
                    scanf("%d", &animal);
                    Clear();
                    if (animal > zoo.GetAnimalNbrByRace(to_string(habitat)))
                    {
                        animal = 0;
                    }
                }
                zoo.SellAnimal(animal, habitat, "poule");
                break;
            }
            break;
        }
    }
}
// Exceptional events per month
void specialEvent(Zoo &zoo)
{
    int fireEvent = 0, stealingEvent = 0, nuisiblesEvent = 0, rottenEvent = 0;
    fireEvent = randomnbr(1, 100);
    if (fireEvent == 1) // nice random number
    {
        int randhab = randomnbr(0, 2);
        cout << "\nFEU !!!!  " << randhab << endl;
        // Détruit un habitat d'une race en aléatoire
        switch (randhab)
        {
        case 0:
            zoo.FireHabitat("tigre");
            break;
        case 1:
            zoo.FireHabitat("aigle");
            break;
        default:
            zoo.FireHabitat("poule");
            break;
        }
    }
    stealingEvent = randomnbr(1, 100);
    if (stealingEvent == 1) // nice random number
    {
        cout << "\nVOL !!!!" << endl;
        switch (randomnbr(0, 3))
        {
        case 0:
            zoo.VolDanimal("poule");
            break;
        case 2:
            zoo.VolDanimal("aigle");
            break;
        default:
            zoo.VolDanimal("tigre");
            break;
        }
    }
    nuisiblesEvent = randomnbr(1, 100);
    if (nuisiblesEvent < 20)
    {
        cout << "\nNUISIBLE !!!!" << endl;
        zoo.setSeed(zoo.getSeed() * 0.9);
        cout << "tu n'as plus que " << zoo.getSeed() << "Kg de graines." << endl;
    }
    rottenEvent = randomnbr(1, 100);
    if (rottenEvent < 10)
    {
        cout << "\nVIANDE AVARIEE !!!!" << endl;
        zoo.setMeat(zoo.getMeat() * 0.8);
        cout << "tu n'as plus que " << zoo.getMeat() << "Kg de viandes." << endl;
    }
}
// Verifie la quantité de nourriture et empeche les animaux d'être fertile quand ils ont faim
void checkingFoodStorage(Zoo zoo, bool &enoughMeat, bool &enoughSeed)
{
    // Affiche la quantité de viande
    cout << "\n-------------------------\nconsommation de viande par mois : " << zoo.getConsobyRace("aigle") + zoo.getConsobyRace("tigre") << endl;
    cout << "Quantite de viande actuel : " << zoo.getMeat() << endl;
    // Verifie la quantité de viande
    if (zoo.getMeat() == 0)
    {
        cout << "Attention !! Plus de viandes" << endl; // Affiche un message lorsqu'il n'y a plus de viande
        enoughMeat = false;
    }
    else if (zoo.getMeat() < (((zoo.getConsobyRace("aigle") + zoo.getConsobyRace("tigre")) * 3)))
    {
        cout << "3 mois ou moins de viande restant" << endl; // Affiche un message lorsqu'il reste moins de 3 mois de viandes
        enoughMeat = true;
    }
    else
    {
        enoughMeat = true;
    }

    // Affiche la quantité de graines
    cout << "\nconsommation de graines par mois : " << zoo.getConsobyRace("poule") << endl;
    cout << "Quantite de graine actuel : " << zoo.getSeed() << endl;
    // Verifie la quantité de graines
    if (zoo.getSeed() == 0)
    {
        cout << "Attention !! Plus de graines" << endl; // Affiche un message lorsqu'il n'y a plus de graine
        enoughSeed = false;
    }
    else if (zoo.getSeed() < (zoo.getConsobyRace("poule") * 3))
    {
        cout << "3 mois ou moins de graines restant" << endl; // Affiche un message lorsqu'il reste moins de 3 mois de graines
        enoughSeed = true;
    }
    else
    {
        enoughSeed = true;
    }
    cout << "-------------------------" << endl;
}
// Permet aux animaux de se reproduire quand ils ont de la nourriture
void animalsReproduction(Zoo zoo, bool enoughMeat, bool enoughSeed)
{
    if (enoughMeat || zoo.getMonth() % 12 == 5) // PONTES D'OEUFS DES AIGLES (lorsqu'il y a assez de viande ou en avril lorsque les oeufs éclosent)
    {
        zoo.ReproductionAigle(zoo.getMonth() % 12);
    }
    if (enoughMeat) // Reproduction des tigres lorsqu'il y a assez de viande
    {
        zoo.ReproductionTigre();
    }
    else
    {
        zoo.ReproductionTigre("ded");
    }
    if (enoughSeed || zoo.getMonth() % 2 == 1) // Reproduction des poules lorsqu'il y a assez de graines (mois pairs) et éclosions des oeufs (mois impairs)
    {
        zoo.ReproductionPoule(zoo.getMonth() % 12);
    }
}

int main()
{
    Zoo zoo("ZooPtycon"); // déclaration du nom par défaut
    int visitor = 0, all_visitors = 0, nextMonth = 0, nbYearZoo = 0;
    bool enoughMeat, enoughSeed = false;
    bool nbEagleSuccess = false, moneySuccess = false, nbTotalVisitorSuccess = false, nbMonthVisitorsSuccess = false;
    StartGame(zoo, nbYearZoo);

    while (zoo.getYear() < nbYearZoo) // Tous les mois
    {
        if (zoo.getMonth() != 0) // tous les mois sauf celui quand le code se lance
        {
            visitor = Visitor(zoo.GetAnimalNbrByRace("tigre"), zoo.GetAnimalNbrByRace("aigle"), zoo.GetAnimalNbrByRace("poule"), zoo.getMonth()); // calcul le nb de visiteur
            all_visitors += visitor;                                                                                                              // calcul le nb de visiteurs total
            zoo.UpdateBudget(VisitorRevenue(visitor));                                                                                            // calcul le revenue lié aux visiteurs
            specialEvent(zoo);                                                                                                                    // créé les événements spéciaux
        }
        else
        {
            zoo.getInfo(); // affiche l'année, le mois et le budget, chaque mois
        }
        zoo.NextMonth(); // incrémente la variable tout les mois

        if (zoo.getMonth() == 13) // Nouvelle année
        {
            zoo.setMonth(1);                                                                                                               // reset le mois à 1 pour janvier
            zoo.setYear(1);                                                                                                                // ajoute 1 aux années
            zoo.UpdateMalade();                                                                                                            // Reset la possibilité qu'un animal soit malade
            zoo.UpdateBudget(subvention(zoo.GetAnimalNbrByRace("tigre"), zoo.GetAnimalNbrByRace("aigle"), zoo.getMonth(), zoo.getYear())); // ajoute les subventions
        }

        nextMonth = 0; // Action pour le mois
        while (zoo.getYear() < 10 && nextMonth != 1)
        {
            cout << "\n--------------------------------\n1 | Passer le mois\t\t2 | Achat / Vente\t\t3 | Avoir des information sur le zoo\n4 | Changer un animal d'habitat\t0 | Quitter" << endl;
            scanf("%d", &nextMonth);
            Clear();
            switch (nextMonth)
            {
            case 4: // changement d'habitat pour un animal
                switchHabitat(zoo);
                break;
            case 3: // Affichage des infos du zoo
                infoZoo(zoo, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess);
                break;
            case 2: // Actions pour le mois actuel
                actionMonth(zoo);
                Clear();
                zoo.getInfo();
                break;
            case 1:                                               // Lorsque le mois est passé, met a jour la nourriture et l'age des animaux
                zoo.getInfo();                                    // Affiche la date du nouveau mois + le budget
                zoo.UpdateAge();                                  // ajoute un mois à l'age de chaque animaux
                zoo.UpdateMeat();                                 // Réduit la quantité de viande en fonction des tigres et aigles
                zoo.UpdateSeed();                                 // Réduit la quantité de graines en fonction des poules et coqs
                zoo.UpdateHabitat();                              // Verifie s'il y a une surpop dans un habitat (risque de mort d'un animal)
                animalsReproduction(zoo, enoughMeat, enoughSeed); // Reproduction des animaux
                break;
            case 0:
                printEndGame(zoo, all_visitors, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess); // affiche la fin de la partie
                return 0;
            }

            checkSuccess(zoo, nbEagleSuccess, moneySuccess, all_visitors, nbTotalVisitorSuccess, nbMonthVisitorsSuccess, visitor); // Verifie si un succes a été débloqué
            checkingFoodStorage(zoo, enoughMeat, enoughSeed);                                                                      // Affiche et verifie la quantité de nourriture
        }
    }
    printEndGame(zoo, all_visitors, nbEagleSuccess, moneySuccess, nbTotalVisitorSuccess, nbMonthVisitorsSuccess); // affiche la fin de la partie
    return 0;
}