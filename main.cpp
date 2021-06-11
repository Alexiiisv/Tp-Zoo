#include <iostream>
#include <cmath>
#include "zoo.h"
#include "aigle.h"
#include "eagleHabitat.h"
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
                cout << "Nombre d'aigle actuel : " << zoo.getAigle() << endl;                                                                            //nb d'aigle
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
void buyAnimal(int &Gender, int &aigle, Zoo &zoo)
{
    char nom[16];
    int whatToBuy = 1, choix_age = 0, age = 0;
    float food;
    string gender[2] = {"Female", "Male"};
    cout << "que voulez-vous acheter ?\n3 | aigles\t\t4 | tigres\t\t0 | pour quitter le menu\n5 | poules\t\t6 | coq\nentrez un des numeros pour acheter un animal" << endl;
    scanf("%d", &whatToBuy);
    if (whatToBuy == 3)
    {
        cout << "Voulez-vous un male une femelle ?\n0 | Femelle\t1 | Male" << endl;
        scanf("%d", &Gender);
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

        if (Gender == 0)
        {
            food = 0.3;
        }
        else
        {
            food = 0.25;
        }
        zoo.addAnimal(new Aigle(nom, "aigle", gender[Gender], food, age));
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
    int Gender = 2;
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
            buyAnimal(Gender, aigle, zoo);
        }
        else if (whatToBuy == 3)
        {
            cout << "Quelle quantite de viande voulez-vous acheter ? " << endl;
            scanf("%f", &food);
            zoo.setFood(zoo.getFood()+food);
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
    if (rottenEvent < 100)
    {
        cout << zoo.getFood() << endl;
        zoo.setFood(zoo.getFood()*0.8);
        cout << zoo.getFood() << endl;
        cout << "ROTTEN MEAT !!!!" << endl;
    }
}

int main()
{
    Zoo zoo("Zoo de la Montagne");
    zoo.setBudget(80000);
    int month = 0, year = 0, nextMonth = 0;
    int visitor = 0;
    int tiger = 0, chicken = 0, coq = 0;
    int tigerHabitat = tiger / 2, chickenHabitat = chicken / 10;
    int all_visitors = 0;

    while (zoo.getYear() < 10)
    // Tous les mois
    {

        if (zoo.getMonth() != 0)
        // tous les mois sauf celui quand le code se lance
        {
            visitor = Visitor(tiger, zoo.getAigle(), chicken, month); // calcul le nb de visiteur
            all_visitors += visitor;                                  // calcul le nb de visiteurs total
            zoo.UpdateBudget(VisitorRevenue(visitor));                // calcul le revenue lié aux visiteurs
            specialEvent(zoo);                                           // créé les événements spéciaux
        }
        zoo.NextMonth(); // incrémente la variable tout les mois

        if (zoo.getMonth() == 13)
        // Nouvelle année
        {
            zoo.setMonth(1);
            zoo.setYear(1);
            zoo.UpdateBudget(subvention(tiger, zoo.getAigle(), zoo.getMonth(), zoo.getYear()));
        }
        zoo.getInfo(); // affiche l'année, le mois et le budget, chaque mois

        // PERTE D'UN ANIMAL LORSQU'ILS SONT TROP NOMBREUX DANS UN HABITAT
        float ratio = (float)zoo.getAigle() / (float)zoo.getHAigle();
        if (ratio > 4 && rand() % 2 == 1)
        {
            cout << "Vous avez perdu un aigle" << endl;
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
                actionMonth(zoo, tiger, chicken, zoo.getAigle(), zoo.getHAigle());
                cout << "aigle " << zoo.getAigle() << " tigre " << tiger << " poulet " << chicken << " money " << zoo.getBudget() << endl;
                cout << zoo.getHAigle() << " habitats d'aigles pour " << zoo.getAigle() << " aigles" << endl;
            }
            else if (nextMonth == 1)
            // Lorsque le mois est passé, met a jour la nourriture et l'age des animaux
            {
                zoo.UpdateAge();
                zoo.UpdateFood();
                zoo.GetHabitatAnimal();
            }
            cout << "consommation de viande des animaux : " << ((((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5)) * 3)) << endl;
            // Affiche la quantité de nourritre
            cout << "Quantite de nourriture : " << zoo.getFood() << endl;
            cout << "\x1B[2J\x1B[H" << endl;
            zoo.getInfo();
            if (zoo.getFood() == 0)
            {
                // Affiche un message lorsqu'il n'y a plus de nourriture
                cout << "Attention : Plus de viande !!!" << endl;
            }
            else if (zoo.getFood() < ((((zoo.getAGender("Female", "aigle") * 9) + (zoo.getAGender("Male", "aigle") * 7.5)) * 3)))
            {
                // Affiche un message lorsqu'il reste moins de 3 mois de viandes
                cout << "3 mois ou moins de viande restant" << endl;
            }
        }
    }
    // fin de la partie
    cout << "\x1B[2J\x1B[HLa Partie est finie\nA la fin tu avais " << zoo.getBudget() << " dollars\nTon zoo a acceuilli " << all_visitors << " visiteurs sur " << year << " ans" << endl;
    return 0;
}