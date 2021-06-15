#include <iostream>
#include <cmath>
#include "./header/zoo.h"
#include "./header/aigle.h"
#include "./header/eagleHabitat.h"
// #include "poule.h"
// #include "tigre.h"

using namespace std;

// Avoir toutes les infos à propos du zoo
void infoZoo(Zoo zoo)
{
    int Gender = 2;
    int info = 1;
    float food;
    while (info != 0)
    {
        cout << "Que voulez-vous afficher ?\n1 | Infos sur les animaux\t\t2 | Nombre d'habitats\t\t0 pour quitter le menu\n3 | Quantite de nourriture" << endl;
        scanf("%d", &info);
        // cout << "\x1B[2J\x1B[H" << endl;

        if (info == 1)
        // infos sur les animaux
        {
            cout << "\x1B[2J\x1B[HSur quel race vous-voulez des informations ?\n3 | Aigles\t\t4 | Tigres\t\t0 | pour quitter le menu\n5 | Poules\n"
                 << endl;
            scanf("%d", &info);
            if (info == 3)
            // infos sur les aigles
            {
                cout << "Nombre d'aigle actuel : " << zoo.GetAnimalNbrByRace("aigle") << endl;                                                                            //nb d'aigle
                cout << "Vous avez " << zoo.getAGender("Male", "aigle") << " male(s) et " << zoo.getAGender("Female", "aigle") << " femelle(s)" << endl; // nb de male et de femelle
                cout << "Vous-voulez plus d'informations sur vos aigles ?\n1 | Oui\t\t0 | Non\t\t" << endl;                                              // demande d'info supplémentaire
                scanf("%d", &info);
                if (info == 1)
                {
                    zoo.getAllInfo("aigle");
                }
            }
            else if (info == 4)
            // infos sur les tigres
            {
                cout << "tigres" << endl;
            }
            else if (info == 5)
            // infos sur les poules
            {
                cout << "poules" << endl;
            }
        }
        else if (info == 2)
        // infos sur les habitats
        {
        }
        else if (info == 3)
        // infos sur la nourriture
        {
            cout << "Quantite de viande : " << zoo.getFood() << endl;
        }
    }
}
// Eagles eggs
void EagleEggs(int month, Zoo zoo, int &eagleEggs)
{
    int randDeath = 0, mort = 0;

    // Reproduction des aigles en Mars
    if (month == 3)
    {
        // Calcule le ratio de femelle/male
        if (zoo.getAGender("Female", "aigle") >= zoo.getAGender("Male", "aigle"))
        {
            int ratio = zoo.getAGender("Female", "aigle") - zoo.getAGender("Male", "aigle");
            int nbFemellePonte = zoo.getAGender("Female", "aigle") - ratio;
            eagleEggs = nbFemellePonte * 2; // chaque aigle femelle pond 2 oeufs
            cout << "nombre d'oeufs d'aigle : " << eagleEggs << endl;
        }
        cout << "FAITES L'AMOUR" << endl;
    }
    // Eclosion des oeufs en mai
    else if (month == 5)
    {
        // range over each eggs to see if they die
        for (int i = 0; i < eagleEggs; i++)
        {
            randDeath = rand() % 2; // Generate 0 or 1
            // Lorsqu'un aigle est mort né
            if (randDeath == 1)
            {
                eagleEggs--;
                mort++;
            }
        }
        cout << "nb de bb aigles : " << eagleEggs << endl;
        cout << "nb de bb aigles MORT : " << mort << endl;
    }
}
// When there is no more meat or seeds
void noMoreFood(int daysWhitoutFood, string state)
{
    if (state == "meat")
    {
        if (daysWhitoutFood >= 2)
        {
            cout << "les lions ne se reproduisent plus" << endl;
        }
        if (daysWhitoutFood >= 10)
        {
            cout << "les aigles ne se reproduisent plus" << endl;
        }
    }
    else if (state == "seed" && daysWhitoutFood >= 2)
    {
        cout << "les poules ne se repoduisent plus" << endl;
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
float subvention(int tiger, int eagle, int month, int year)
{
    float subvention = eagle * 2190; // Calcul de la subvention en fonction de l'animal
    cout << "New Year ! subvention : " << subvention << endl;
    return subvention;
}
// Menu to buy an Animal
void buyAnimal(int &aigle, Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1, choix_age = 0, age = 0, genre = 10;
    float food;
    string gender[2] = {"Female", "Male"};
    cout << "que voulez-vous acheter ?\n3 | aigles\t\t4 | tigres\t\t0 | pour quitter le menu\n5 | poules\t\t6 | coq\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {
        while (genre != 0 && genre != 1)
        {
            cout << "Voulez-vous un male une femelle ?\n0 | Femelle\t1 | Male" << endl;
            scanf("%d", &genre);
        }
        cout << "Donnez un nom a votre aigle" << endl;
        scanf("%15s", &nom);
        aigle += 1;
        while (choix_age == 0)
        {
            cout << "Voulez-vous l'acheter enfant, adulte ou vieux ?\n1 | Enfant (1000$)\t\t2 | Adulte (4000$)\t\t3| Vieux (2000$)" << endl;
            scanf("%d", &choix_age);
            switch (choix_age)
            {
            case 1:
                cout << "Enfant" << endl;
                zoo.UpdateBudget(-1000);
                age = 120 / 10 / 1 / 2;
                break;
            case 2:
                cout << "Adulte" << endl;
                zoo.UpdateBudget(-4000);
                age = 12 * 4;
                break;
            case 3:
                cout << "Vieux" << endl;
                zoo.UpdateBudget(-2000);
                age = 12 * 14;
                break;
            default:
                break;
            }
            if (choix_age > 3 || choix_age < 1)
            {
                choix_age = 0;
            }
        }

        if (genre == 0)
        {
            food = 0.3;
        }
        else
        {
            food = 0.25;
        }
        zoo.addAnimal(new Aigle(nom, "aigle", gender[genre], food, age));
    }
}
// Menu to buy Habitat
void buyHabitats(int &eaglehabitat, Zoo &zoo)
{
    int whatToBuy = 1;
    string gender[2] = {"Female", "Male"};
    cout << "que voulez-vous acheter ?\n3 | Habitat aigles\t\t4 | Habitat tigres\t\t0 | pour quitter le menu\n5 | Habitat poules\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {
        eaglehabitat += 1;
        zoo.addHabitat(new EagleHabitat("aigle"));
        zoo.UpdateBudget(-2000);
    }
}
// Actions d'acheter animaux
void actionMonth(Zoo &zoo, int &tigre, int &poules, int aigle, int eagleHabitat)
{
    int whatToBuy = 1;
    float food;
    while (whatToBuy != 0)
    {
        cout << "que voulez-vous acheter ?\n1 | Habitats\t\t2 | Animaux\t\t0 pour quitter le menu\n3 | viandes"
             << endl;
        scanf("%d", &whatToBuy);

        if (whatToBuy == 1)
        {
            buyHabitats(eagleHabitat, zoo);
        }
        else if (whatToBuy == 2)
        {
            buyAnimal(aigle, zoo);
        }
        else if (whatToBuy == 3)
        {
            cout << "Quelle quantite de viande voulez-vous acheter ? " << endl;
            scanf("%f", &food);
            zoo.setFood(zoo.getFood() + food);
            zoo.UpdateBudget(-food * 5);
            cout << zoo.getFood() << endl;
        }
    }
}
// Exceptional events per month
void specialEvent(Zoo &zoo)
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
        cout << zoo.getFood() << endl;
        zoo.setFood(zoo.getFood() * 0.8);
        cout << zoo.getFood() << endl;
        cout << "ROTTEN MEAT !!!!" << endl;
    }
}

int main()
{
    Zoo zoo("Zoo de la Montagne");
    zoo.setBudget(80000);
    int month = 0, year = 0, nextMonth = 0;
    int visitor = 0, all_visitors = 0;
    int tiger = 0, chicken = 0, coq = 0;
    int daysWithoutMeat = 0;
    int eagleEggs = 0;

    while (zoo.getYear() < 10)
    // Tous les mois
    {

        if (zoo.getMonth() != 0)
        // tous les mois sauf celui quand le code se lance
        {
            visitor = Visitor(tiger, zoo.GetAnimalNbrByRace("aigle"), chicken, month); // calcul le nb de visiteur
            all_visitors += visitor;                                  // calcul le nb de visiteurs total
            zoo.UpdateBudget(VisitorRevenue(visitor));                // calcul le revenue lié aux visiteurs
            specialEvent(zoo);                                        // créé les événements spéciaux
        }
        zoo.NextMonth(); // incrémente la variable tout les mois

        if (zoo.getMonth() == 13)
        // Nouvelle année
        {
            zoo.setMonth(1);
            zoo.setYear(1);
            zoo.UpdateBudget(subvention(tiger, zoo.GetAnimalNbrByRace("aigle"), zoo.getMonth(), zoo.getYear()));
        }
        zoo.getInfo(); // affiche l'année, le mois et le budget, chaque mois

        // PONTES D'OEUFS DES AIGLES
        if (zoo.getMonth() % 12 == 3 || zoo.getMonth() % 12 == 5)
        {
            EagleEggs(zoo.getMonth() % 12, zoo, eagleEggs);
        }

        nextMonth = 0;
        while (zoo.getYear() < 10 && nextMonth != 1)
        // Action pour le mois
        {

            cout << "\n1 | Pass the month\t\t2 | Buy something\t\t3 | Get Information about the zoo" << endl;
            scanf("%d", &nextMonth);
            cout << "\x1B[2J\x1B[H"; // clear le terminal

            if (nextMonth == 3)
            {
                infoZoo(zoo);
            }
            else if (nextMonth == 2)
            //  Actions pour le mois actuel
            {
                actionMonth(zoo, tiger, chicken, zoo.GetAnimalNbrByRace("aigle"), zoo.getHAigle());
                cout << "aigle " << zoo.GetAnimalNbrByRace("aigle") << " tigre " << tiger << " poulet " << chicken << " money " << zoo.getBudget() << endl;
                cout << zoo.getHAigle() << " habitats d'aigles pour " << zoo.GetAnimalNbrByRace("aigle") << " aigles" << endl;
            }
            else if (nextMonth == 1)
            // Lorsque le mois est passé, met a jour la nourriture et l'age des animaux
            {
                zoo.UpdateAge();
                zoo.UpdateFood();
                zoo.UpdateHabitat();
            }
            cout << "consommation de viande des animaux : " << ((((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5)) * 3)) << endl;
            // Affiche la quantité de nourritre
            cout << "Quantite de nourriture : " << zoo.getFood() << endl;
            // cout << "\x1B[2J\x1B[H" << endl;
            zoo.getInfo();

            // CHECKING FOOD STORAGE
            if (zoo.getFood() == 0)
            {
                // Affiche un message lorsqu'il n'y a plus de nourriture
                cout << "Attention !! " << daysWithoutMeat << " jours sans viandes" << endl;
                daysWithoutMeat++;
                noMoreFood(daysWithoutMeat, "meat"); // appel la fonction lorsque qu'il n'y a plus de viande
            }
            else if (zoo.getFood() < ((((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5)) * 3)))
            {
                // Affiche un message lorsqu'il reste moins de 3 mois de viandes
                cout << "3 mois ou moins de viande restant" << endl;
                daysWithoutMeat = 0; // réinitialise le nb de jour sans viande
            }
            else
            {
                daysWithoutMeat = 0; // réinitialise le nb de jour sans viande
            }
        }
    }
    // fin de la partie
    cout << "\x1B[2J\x1B[HLa Partie est finie\nA la fin tu avais " << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors << " visiteurs sur " << year << " ans" << endl;
    return 0;
}