#include "../header/zoo.h"
#include "../header./aigle.h"
#include "../header./tigre.h"
#include "../header./poule.h"
#include "../header./coq.h"
#include "../header/eagleHabitat.h"
#include "../header/chickenHabitat.h"
#include "../header/tigerHabitat.h"
#include "utils.h"

#include <random>
#include <iostream>
using namespace std;

void sellTigre(Zoo &zoo)
{
    int habitat = 0;
    int animal = 0;
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
}
void sellPoule(Zoo &zoo)
{
    int habitat = 0;
    int animal = 0;
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
        if (animal > zoo.GetAnimalNbrByRace(to_string(habitat), "poule"))
        {
            animal = 0;
        }
    }
    zoo.SellAnimal(animal, habitat, "poule");
}
void sellAigle(Zoo &zoo)
{
    int habitat = 0;
    int animal = 0;
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
}
void sellAnimal(Zoo &zoo)
{
    int whichRace = 0, habitat = 0, whatToBuy = 1, animal = 0, backupmone = 0;
    cout << "Vendre un :\n1 | Tigre\t\t 2 | Poule / Coq\t\t3 | Aigle" << endl;
    scanf("%d", &whichRace);
    switch (whichRace)
    {
    case 1: // vente tigre
        sellTigre(zoo);
        break;
    case 2: // vente poule/coq
        sellPoule(zoo);
        break;
    case 3: // vente aigle
        sellAigle(zoo);
        break;
    }
}

void sellHabitatT(Zoo &zoo)
{
    int backupmone = zoo.getBudget();
    zoo.SellHabitat("tigre");
    if (backupmone == zoo.getBudget())
        cout << "Aucun habitat de tigre n'as ete vendu" << endl;
    else
        cout << "Tu viens de vendre un habitat de tigre ; Il t'en reste " << zoo.GetHabitatNbrByRace("tigre") << endl;
}
void sellHabitatP(Zoo &zoo)
{
    int backupmone = zoo.getBudget();
    zoo.SellHabitat("poule");
    if (backupmone == zoo.getBudget())
        cout << "Aucun habitat de poule n'as ete vendu" << endl;
    else
        cout << "Tu viens de vendre un habitat de poule ; Il t'en reste " << zoo.GetHabitatNbrByRace("poule") << endl;
}
void sellHabitatA(Zoo &zoo)
{
    int backupmone = zoo.getBudget();
    zoo.SellHabitat("aigle");
    if (backupmone == zoo.getBudget())
        cout << "Aucun habitat d'aigle n'as ete vendu" << endl;
    else
        cout << "Tu viens de vendre un habitat d'aigle ; Il t'en reste " << zoo.GetHabitatNbrByRace("aigle") << endl;
}
void sellHabitat(Zoo &zoo)
{
    int whichRace = 0, backupmone = 0;
    cout << "Vendre un habitat de : /!\\ L'habitat vendu sera celui ou il y a le moins d'animaux. Tous les animaux de cet habitat disparaitront /!\\\n1 | Tigre\t\t 2 | Poule\t\t3| Aigle" << endl;
    scanf("%d", &whichRace);
    Clear();
    switch (whichRace)
    {
    case 1: // vente habitat tigre
        sellHabitatT(zoo);
        break;
    case 2: // vente habitat poule
        sellHabitatP(zoo);
        break;
    default: // vente habitat aigle
        sellHabitatA(zoo);
        break;
    }
}

void buyAigle(Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1, choix_age = 0, age = 0, genre = 10, habitat = 0;
    float food;
    bool nomoni = true;
    string gender[2] = {"Female", "Male"};

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
void buyTigre(Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1, choix_age = 0, age = 0, genre = 10, habitat = 0;
    float food;
    bool nomoni = true;
    string gender[2] = {"Female", "Male"};
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
void buyPoule(Zoo &zoo)
{
    int habitat = 0;
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
void buyCoq(Zoo &zoo)
{
    int habitat = 0;
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
        buyAigle(zoo);
    }
    else if (whatToBuy == 4)
    {
        buyTigre(zoo);
    }
    else if (whatToBuy == 5)
    {
        buyPoule(zoo);
    }
    else if (whatToBuy == 6)
    {
        buyCoq(zoo);
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

void buyViandes(Zoo &zoo, bool &VG)
{
    int food = 0;
    cout << "Quelle quantite de viande voulez-vous acheter ? " << endl;
    scanf("%f", &food);
    Clear();
    if (zoo.getBudget() - (food * 5) >= 0)
    {
        zoo.getInfo();
        VG = false;
        cout << "\nTu viens d'acheter " << food << "kg de viandes" << endl;
        zoo.setMeat(zoo.getMeat() + food);
        zoo.UpdateBudget(-food * 5);
        cout << "Maintenant tu as " << zoo.getMeat() << "kg de viandes" << endl;
    }
    else
    {
        cout << "Vous n'avez pas assez d'argent pour acheter " << food << " de viande" << endl;
    }
}
void buyGraines(Zoo &zoo, bool &VG)
{
    int seed = 0;
    cout << "Quelle quantite de graine voulez-vous acheter ? " << endl;
    scanf("%f", &seed);
    Clear();
    if (zoo.getBudget() - (seed * 2.5) >= 0)
    {
        zoo.getInfo();
        VG = false;
        cout << "\nTu viens d'acheter " << seed << "kg de graines" << endl;
        zoo.setSeed(zoo.getSeed() + seed);
        zoo.UpdateBudget(-seed * 2.5);
        cout << "Maintenant tu as " << zoo.getSeed() << "kg de graines" << endl;
    }
    else
    {
        cout << "Vous n'avez pas assez d'argent pour acheter " << seed << " de graines" << endl;
    }
}

// Actions d'acheter animaux
void actionMonth(Zoo &zoo)
{
    int whatToBuy = 1;
    bool VG = true;
    while (whatToBuy != 0)
    {
        if (VG) zoo.getInfo();
        VG = true;
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
            buyViandes(zoo, VG);
            break;
        case 4: // achat de graine
            buyGraines(zoo, VG);
            break;
        case 5: // vente d'habitat
            sellHabitat(zoo);
            break;
        case 6: // vente d'animaux
            sellAnimal(zoo);
            break;
        default:
            break;
        }
    }
}

void switchAigle(Zoo &zoo)
{
    int initialHabitat = 0, animal = 0, destination = 0, skip = 2;
    bool confirmation = false;
    while (skip != 0 && skip != 1)
    {
        Clear();
        // choix de l'habitat de départ
        cout << "Depuis l'habitat numero __ , vous deplacez l'aigle numero __ , vers l'habitat numero __" << endl;
        cout << "De quel habitat voulez-vous deplacer l'animal ?\nVous avez "
                << zoo.GetHabitatNbrByRace("aigle") << " habitat pour les aigles" << endl;
        scanf("%d", &initialHabitat);
        Clear();

        // choix de l'animal a déplacer
        zoo.GetHabitatAnimal(to_string(initialHabitat), "aigle");
        cout << "\nDepuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero __ , vers l'habitat numero __" << endl;
        cout << "Quel animal de cet habitat voulez-vous deplacer ?"
                << endl;
        scanf("%d", &animal);
        Clear();

        // choix de l'habitat de destination
        zoo.GetHabitatAnimal("aigle");
        cout << "\nDepuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero __" << endl;
        cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
        scanf("%d", &destination);
        Clear();

        cout << "\nDepuis l'habitat numero " << initialHabitat << ", vous deplacez l'aigle numero " << animal << " vers l'habitat numero " << destination << endl;
        cout << "Appuyez sur 0 pour annuler ou 1 pour confirmer" << endl;
        scanf("%d", &skip);
        if (skip == 1)
        {
            confirmation = true;
        }
        Clear();
    }
    cout << confirmation << endl;
    if (confirmation)
    {
        zoo.SwitchHabitat(initialHabitat, animal, destination, "aigle");
    }
}
void switchTigre(Zoo &zoo)
{
    int initialHabitat = 0, animal = 0, destination = 0, skip = 2;
    bool confirmation = false;
    while (skip != 0 && skip != 1)
    {
        Clear();
        // choix de l'habitat de départ
        cout << "Depuis l'habitat numero __ , vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
        cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("tigre") << " habitat pour les tigres" << endl;
        scanf("%d", &initialHabitat);
        Clear();

        // choix de l'animal a déplacer
        zoo.GetHabitatAnimal(to_string(initialHabitat), "tigre");
        cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
        scanf("%d", &animal);
        Clear();

        // choix de l'habitat de destination
        zoo.GetHabitatAnimal("tigre");
        cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero __" << endl;
        scanf("%d", &destination);
        Clear();

        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero " << destination << endl;
        cout << "Appuyez sur 0 pour annuler ou 1 pour confirmer" << endl;
        scanf("%d", &skip);
        if (skip == 1)
        {
            confirmation = true;
        }
        Clear();
    }
    if (confirmation)
    {
        zoo.SwitchHabitat(initialHabitat, animal, destination, "tigre");
    }while (skip != 0 && skip != 1)
    {
        Clear();
        // choix de l'habitat de départ
        cout << "Depuis l'habitat numero __ , vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
        cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("tigre") << " habitat pour les tigres" << endl;
        scanf("%d", &initialHabitat);
        Clear();

        // choix de l'animal a déplacer
        zoo.GetHabitatAnimal(to_string(initialHabitat), "tigre");
        cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero __ , vers l'habitat numero __" << endl;
        scanf("%d", &animal);
        Clear();

        // choix de l'habitat de destination
        zoo.GetHabitatAnimal("tigre");
        cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero __" << endl;
        scanf("%d", &destination);
        Clear();

        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez le tigre numero " << animal << " vers l'habitat numero " << destination << endl;
        cout << "Appuyez sur 0 pour annuler ou 1 pour confirmer" << endl;
        scanf("%d", &skip);
        if (skip == 1)
        {
            confirmation = true;
        }
        Clear();
    }
    if (confirmation)
    {
        zoo.SwitchHabitat(initialHabitat, animal, destination, "tigre");
    }
}
void switchPoule(Zoo &zoo)
{
    int initialHabitat = 0, animal = 0, destination = 0, skip = 2;
    bool confirmation = false;
    while (skip != 0 && skip != 1)
    {
        Clear();
        // choix de l'habitat de départ
        cout << "Depuis l'habitat numero __, vous deplacez la/le poule/coq numero __ vers l'habitat numero __" << endl;
        cout << "De quel habitat voulez-vous deplacer l'animal\nVous avez " << zoo.GetHabitatNbrByRace("poule") << " habitats pour les poules/coqs" << endl;
        scanf("%d", &initialHabitat);
        Clear();

        // choix de l'animal a déplacer
        zoo.GetHabitatAnimal(to_string(initialHabitat), "poule");
        cout << "Quel animal de cet habitat voulez-vous deplacer ?\n"
                << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez la poule numero __ vers l'habitat numero __" << endl;
        scanf("%d", &animal);
        Clear();

        // choix de l'habitat de destination
        zoo.GetHabitatAnimal("poule");
        cout << "Dans quel habitat voulez-vous placer l'animal choisi" << endl;
        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez la/le poule/coq numero " << animal << " vers l'habitat numero __" << endl;
        scanf("%d", &destination);
        Clear();

        cout << "Depuis l'habitat numero " << initialHabitat << ", vous deplacez la/le poule/coq numero " << animal << " vers l'habitat numero " << destination << endl;
        cout << "Appuyez sur 0 pour annuler ou 1 pour confirmer" << endl;
        scanf("%d", &skip);
        if (skip == 1)
        {
            confirmation = true;
        }
    }
    if (confirmation)
    {
        zoo.SwitchHabitat(initialHabitat, animal, destination, "poule");
    }
}
// Changer un animal d'habitat
void switchHabitat(Zoo &zoo)
{
    int whichAnimal = 5;
    while (whichAnimal != 1 && whichAnimal != 2 && whichAnimal != 3 && whichAnimal != 4 && whichAnimal != 0)
    {
        cout << "Quel animal voulez-vous deplacer ?\n1 | aigle\t\t2 | tigre\t\t3 | poule / coq\t\t0 | quitter le menu" << endl;
        scanf("%d", &whichAnimal);
        switch (whichAnimal)
        {
        case 1: // Déplacer un aigle
            switchAigle(zoo);
            break;
        case 2: // Déplacer un tigre
            switchTigre(zoo);
            break;
        case 3: // Déplacer poule/coq
            switchPoule(zoo);
            break;
        default:
            break;
        }
    }
}

// Exceptional events per month
void specialEvent(Zoo &zoo)
{
    int fireEvent = 0, stealingEvent = 0, nuisiblesEvent = 0, rottenEvent = 0;
    
    fireEvent = randomnbr(1, 100);
    if (fireEvent == 69) // nice random number
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
    if (stealingEvent == 69) // nice random number
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
