#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <random>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "./header/zoo.h"
#include "./header/aigle.h"
#include "./header/eagleHabitat.h"
#include "./header/chickenHabitat.h"
#include "./header/poule.h"
// #include "tigre.h"

using namespace std;

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
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
            cout << std::boolalpha << nbEagleSuccess << "\t| Ami des aigles\tAvoir plus de 12 aigles" << endl;
            cout << std::boolalpha << moneySuccess << "\t| Riche as fuck\t\tAtteindre plus de 100000$" << endl;
            cout << std::boolalpha << nbTotalVisitorSucess << "\t| Parc d'attraction\tAtteindre plus de 1000 visiteurs" << endl;
            cout << std::boolalpha << nbTotalVisitorSucess << "\t| Plus apprecie que les maisons closes\tAtteindre 150 en un seul mois\n"
                 << endl;
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
            message = "Succes deverouiller : Plus apprecie que les maisons closes (vous avez eu plus de 150 visiteurs dans un seul mois)";
        }
        else if (nbEagleSuccess == false && (zoo.getAGender("Female", "aigle") + zoo.getAGender("Male", "aigle")) >= 12)
        {
            nbEagleSuccess = true;
            message = "Succes deverouiller : Ami des aigles (vous possedez 12 aigles ou plus)";
        }
        else if (moneySuccess == false && zoo.getBudget() >= 100000)
        {
            moneySuccess = true;
            message = "Succes deverouiller : Riche as fuck (Vous avec atteint un budget de 100000$)";
        }
        else if (all_visitors >= 1000)
        {
            nbTotalVisitorSuccess = true;
            message = "Succes deverouiller : Parc d'attraction (Vous avez atteint 1000 visiteurs au cumule)";
        }

        for (int i = 6; i > 0; i--)
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
    int initialHabitat = 0, animal = 0, destination = 0, skip = 1;

    while (skip != 0)
    {
        cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("aigle") << " habitat pour les aigles" << endl;
        scanf("%d", &initialHabitat);
        cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
             << endl;
        zoo.GetHabitatAnimal(to_string(initialHabitat));
        scanf("%d", &animal);
        cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
        zoo.GetHabitatAnimal("aigle");
        scanf("%d", &destination);

        cout << "Appuyez sur 0 pour confirmer" << endl;
        scanf("%d", &skip);
    }
    zoo.SwitchHabitat(initialHabitat, animal, destination);
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
    cout << "Revenus pour " << visitor << " visiteurs : " << result << endl;
    return result;
}
// Get number of visitors
int Visitor(int tiger, int eagle, int chicken, int month)
{
    srand(time(0));
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
float subvention(int tiger, int eagle, int month, int year)
{
    float subvention = eagle * 2190; // Calcul de la subvention en fonction de l'animal
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
    cout << "que voulez-vous acheter ?\n3 | aigles\t\t4 | tigres\t\t0 | pour quitter le menu\n5 | poules\t\t6 | coq\nentrez un des numeros pour acheter un animal" << endl;
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
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez " << zoo.GetHabitatNbrByRace("aigle") << " d'habitat pour les aigles" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("aigle"))
                    {
                        habitat = 0;
                    }
                }
                zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age), habitat - 1);
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
    else if (whatToBuy == 5)
    {
        if (zoo.getBudget() - 20 >= 0)
        {
            if (zoo.GetHabitatNbrByRace("poule") > 0)
            {
                while (habitat == 0)
                {
                    cout << "Dans quelle habitat voulez-vous l'introduire ?\nVous avez " << zoo.GetHabitatNbrByRace("poule") << " d'habitat pour les poules" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("poule"))
                    {
                        habitat = 0;
                    }
                }
                zoo.UpdateBudget(-20);
                zoo.addAnimal(new Poule(randomStr(6), "poule", 0.15, 6), habitat - 1);
                habitat = 0;
            }
        }
        else
        {
        }
    }
}
// Menu to buy Habitat
void buyHabitats(Zoo &zoo)
{
    int whatToBuy = 1;
    while (whatToBuy != 0)
    {
        cout << "que voulez-vous acheter ?\n3 | Habitat aigles\t\t4 | Habitat tigres\t\t0 | pour quitter le menu\n5 | Habitat poules\nentrez un des numeros pour acheter un habitat" << endl;
        scanf("%d", &whatToBuy);
        switch (whatToBuy)
        {
        case 3: // achat habitat d'aigle
            zoo.addHabitat(new EagleHabitat("aigle"));
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
    int whichRace = 0, habitat = 0, whatToBuy = 1, animal = 0;
    float food, seed;
    while (whatToBuy != 0)
    {
        cout << "Que voulez-vous faire :\nAcheter :\t1 | Habitats\t\t2 | Animaux\t\t3 | viandes\t\t4 | Graines\t\t0 pour quitter le menu\nVendre :\t5 | Habitat\t\t6 | Animaux" << endl;
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
            if (zoo.getBudget() - (food * 5) >= 0)
            {
                zoo.setMeat(zoo.getMeat() + food);
                zoo.UpdateBudget(-food * 5);
                cout << zoo.getMeat() << endl;
            }
            else
            {
                cout << "Vous n'avez pas assez d'argent pour acheter " << food << " de viande" << endl;
            }
            break;
        case 4: // achat de graine
            cout << "Quelle quantite de graine voulez-vous acheter ? " << endl;
            scanf("%f", &seed);
            if (zoo.getBudget() - (seed * 2.5) >= 0)
            {
                zoo.setSeed(zoo.getSeed() + seed);
                zoo.UpdateBudget(-seed * 2.5);
                cout << zoo.getSeed() << endl;
            }
            else
            {
                cout << "Vous n'avez pas assez d'argent pour acheter " << seed << " de graines" << endl;
            }

            break;
        case 5: // vente d'habitat
            cout << "Vendre un habitat de :\t1 | Tigre\t\t 2 | Poule\t\t3| Aigle" << endl;
            scanf("%d", &whichRace);
            switch (whichRace)
            {
            case 1: // vente habitat tigre
                cout << "vente d'un habitat de tigre" << endl;
                break;
            case 2: // vente habitat poule
                cout << "vente d'un habitat de poule" << endl;
                break;
            default: // vente habitat aigle
                cout << "vente d'un habitat d'aigle" << endl;
                zoo.SellHabitat("aigle");
                break;
            }
            break;
        case 6: // vente d'animaux
            cout << "Vendre un :\t1 | Tigre\t\t 2 | Poule\t\t3| Aigle\t\t4 | Coq" << endl;
            scanf("%d", &whichRace);
            switch (whichRace)
            {
            case 1: // vente tigre
                cout << "vente d'un tigre" << endl;
                break;
            case 2: // vente poule
                cout << "vente d'une poule" << endl;
                break;
            case 3: // vente aigle
                habitat = 0;
                animal = 0;
                while (habitat == 0)
                {
                    zoo.GetHabitatAnimal("aigle"); // affiche tout les habitats d'aigles
                    cout << "Dans quel habitat se situe l'aigle que vous voulez vendre ?" << endl;
                    scanf("%d", &habitat);
                    if (habitat > zoo.GetHabitatNbrByRace("aigle"))
                    {
                        habitat = 0; // reinitialise la variable si elle ne correspond pas au nb d'habitat
                    }
                }
                cout << "L'habitat d'aigle numero " << habitat << endl;
                zoo.GetHabitatAnimal(to_string(habitat)); // affiche l'habitat selectionné
                while (animal == 0)
                {
                    cout << "Quel aigle de l'habitat choisi voulez vous vendre ?" << endl;
                    scanf("%d", &animal);
                    if (animal > zoo.GetAnimalNbrByRace(to_string(habitat)))
                    {
                        animal = 0;
                    }
                }
                zoo.SellAnimal(animal, habitat);
                break;
            default: // vente coq
                cout << "vente d'un coq" << endl;
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
    srand(time(0));
    fireEvent = rand() % 100;
    if (fireEvent == 69) // nice random number
    {
        cout << "FEU !!!!" << endl;
        int randhab = rand() % 3;
        // Détruit un habitat d'une race en aléatoire
        switch (randhab)
        {
        case 0:
            // zoo.FireHabitat("tigre");
            cout << "Un habitat de tigre a cramer" << endl;
            break;
        case 1:
            zoo.FireHabitat("aigle");
            break;
        default:
            // zoo.FireHabitat("poule");
            cout << "Un habitat de poulet a cramer" << endl;
            break;
        }
    }
    stealingEvent = rand() % 100;
    if (stealingEvent == 69) // nice random number
    {
        cout << "VOL !!!!" << endl;
        switch (rand() % 4)
        {
        case 0:
            cout << "Une poule a ete vole" << endl;
            break;
        case 1:
            cout << "Un coq a ete vole" << endl;
            break;
        case 2:
            zoo.VolDanimal("aigle");
            break;
        default:
            cout << "Un tigre a ete vole" << endl;
            break;
        }
    }
    nuisiblesEvent = rand() % 100;
    if (nuisiblesEvent < 20)
    {
        cout << "NUISIBLE !!!!" << endl;
        zoo.setSeed(zoo.getSeed() * 0.9);
        cout << "tu n'as plus que " << zoo.getSeed() << "Kg de graines." << endl;
    }
    rottenEvent = rand() % 100;
    if (rottenEvent < 10)
    {
        cout << "VIANDE AVARIEE !!!!" << endl;
        zoo.setMeat(zoo.getMeat() * 0.8);
        cout << "tu n'as plus que " << zoo.getMeat() << "Kg de viandes." << endl;
    }
}
int main()
{
    Zoo zoo(randomStr(60)); //nom du zoo
    zoo.setBudget(80000);
    string test = "";
    int visitor = 0, all_visitors = 0, nextMonth = 0;
    int tiger = 0, chicken = 0, coq = 0;
    bool enoughMeat, enoughSeed = false;
    bool nbEagleSuccess = false, moneySuccess = false, nbTotalVisitorSuccess = false, nbMonthVisitorsSuccess = false;

    while (zoo.getYear() < 10)
    // Tous les mois
    {
        if (zoo.getMonth() != 0) // tous les mois sauf celui quand le code se lance
        {
            visitor = Visitor(tiger, zoo.GetAnimalNbrByRace("aigle"), zoo.GetAnimalNbrByRace("poule"), zoo.getMonth()); // calcul le nb de visiteur
            all_visitors += visitor;                                                                                    // calcul le nb de visiteurs total
            zoo.UpdateBudget(VisitorRevenue(visitor));                                                                  // calcul le revenue lié aux visiteurs
            specialEvent(zoo);                                                                                          // créé les événements spéciaux
        }
        zoo.NextMonth(); // incrémente la variable tout les mois

        if (zoo.getMonth() == 13) // Nouvelle année
        {
            zoo.setMonth(1);
            zoo.setYear(1);
            zoo.UpdateMalade();
            zoo.UpdateBudget(subvention(tiger, zoo.GetAnimalNbrByRace("aigle"), zoo.getMonth(), zoo.getYear()));
        }
        zoo.getInfo(); // affiche l'année, le mois et le budget, chaque mois

        // PONTES D'OEUFS DES AIGLES
        if (enoughMeat)
        {
            zoo.reproduction(zoo.getMonth() % 12);
            //reproduction des tigres
        }
        if (enoughSeed)
        {
            // repoduction poules
            cout << "les poules pondent des oeufs" << endl;
        }

        nextMonth = 0;
        while (zoo.getYear() < 10 && nextMonth != 1) // Action pour le mois
        {
            cout << "\n1 | Passer le mois\t\t2 | Achat / Vente\t\t3 | Avoir des information sur le zoo\n4 | Changer un animal d'habitat\t0 | Quitter" << endl;
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
            case 2: //  Actions pour le mois actuel
                actionMonth(zoo);
                cout << "aigle " << zoo.GetAnimalNbrByRace("aigle") << " tigre " << tiger << " poulet " << chicken << " money " << zoo.getBudget() << endl;
                cout << zoo.getHAigle() << " habitats d'aigles pour " << zoo.GetAnimalNbrByRace("aigle") << " aigles" << endl;
                break;
            case 1: // Lorsque le mois est passé, met a jour la nourriture et l'age des animaux
                zoo.UpdateAge();
                zoo.UpdateMeat();
                zoo.UpdateSeed();
                zoo.UpdateHabitat();
                break;
            default:
                return 0;
                break;
            }

            cout << "consommation de viande par mois : " << (((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5))) << endl;
            cout << "Quantite de viande actuel : " << zoo.getMeat() << endl;
            cout << "consommation de graines par mois : " << zoo.GetAnimalNbrByRace("poule") * 4.5 << endl;
            cout << "Quantite de graine actuel : " << zoo.getSeed() << endl;

            zoo.getInfo(); // Affiche la quantité de nourritre

            checkSuccess(zoo, nbEagleSuccess, moneySuccess, all_visitors, nbTotalVisitorSuccess, nbMonthVisitorsSuccess, visitor); // Verifie si un succes a été débloqué

            if (zoo.getMeat() == 0) // CHECKING MEAT STORAGE
            {
                cout << "Attention !! Plus de viandes" << endl; // Affiche un message lorsqu'il n'y a plus de viande
                enoughMeat = false;
            }
            else if (zoo.getMeat() < ((((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5)) * 3)))
            {
                cout << "3 mois ou moins de viande restant" << endl; // Affiche un message lorsqu'il reste moins de 3 mois de viandes
                enoughMeat = true;
            }
            else
            {
                enoughMeat = true;
            }
            if (zoo.getSeed() == 0) // CHECKING SEED STORAGE
            {
                cout << "Attention !! Plus de graines" << endl; // Affiche un message lorsqu'il n'y a plus de graine
                enoughSeed = false;
            }
            else if (zoo.getMeat() < (zoo.GetAnimalNbrByRace("poule") * 4.5 * 3))
            {
                cout << "3 mois ou moins de graines restant" << endl; // Affiche un message lorsqu'il reste moins de 3 mois de graines
                enoughSeed = true;
            }
            else
            {
                enoughSeed = true;
            }
        }
    }
    // fin de la partie
    Clear();
    cout << "La Partie est finie\nA la fin tu avais " << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors << " visiteurs sur " << zoo.getYear() << " ans" << endl;
    return 0;
}