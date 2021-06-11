#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"
#include "ihabitat.h"

#include <vector>
#include <string>

using namespace std;
typedef vector <IAnimal*> AnimalList;
typedef AnimalList::iterator AnimalIterator;
typedef vector <IHabitat*> HabitatList;
typedef HabitatList::iterator HabitatIterator;
class Zoo
{
    string m_name;
    AnimalList m_animals;
    HabitatList m_habitats;
    float viande, budget;
    int tigre = 0, aigle = 0, poules = 0, coq = 0, month = 0, year = 0;
    int tigre_Habitat, aigle_Habitat, poules_Habitat;
public:
    Zoo(string name = "");
    void addAnimal(IAnimal* animal);
    void addHabitat(IHabitat* habitat);
    void fire();
    void NextMonth();
    void UpdateAge();
    void UpdateFood();
    void UpdateBudget(float budget);


    //getter
    string getName();
    float getFood();
    float getBudget();
    int getMonth();
    int getYear();
    int getAigle();
    int getGAigle();
    int getTigre();
    int getPoules();
    int getCoq();
    int getHAigle();
    int getHTigre();
    int getHPoules();
    int getAGender();
    int getAGender(string gender, string race);
    void getAName();
    void getARace();
    void getAllInfo(string race);
    void GetHabitatSize();

    //setter
    void setFood(float food);
    void setMonth(float month);
    void setYear(float year);
    void setBudget(float budget);
};

#endif // ZOO_H
