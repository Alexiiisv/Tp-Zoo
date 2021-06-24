#include "../header/zoo.h"
#include <iostream>
using namespace std;

// Vérifie le nombre de viandes restant
void infoViandes(Zoo &zoo, bool &enoughMeat)
{
    // Affiche la quantité de viande
    cout << "\n-------------------------\n\nConsommation de viande par mois : " << zoo.getConsobyRace("aigle") + zoo.getConsobyRace("tigre") << endl;
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
}
// Vérifie le nombre de graines restant
void infoGraines(Zoo &zoo, bool &enoughSeed)
{
    // Affiche la quantité de graines
    cout << "\nConsommation de graines par mois : " << zoo.getConsobyRace("poule") << endl;
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
    cout << "\n-------------------------" << endl;
}

// Verifie la quantité de nourriture et empeche les animaux d'être fertile quand ils ont faim
void checkingFoodStorage(Zoo &zoo, bool &enoughMeat, bool &enoughSeed)
{
    infoViandes(zoo, enoughMeat);
    infoGraines(zoo, enoughSeed);
}