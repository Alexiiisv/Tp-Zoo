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
    // AnimalList m_animals;
    HabitatList m_habitats;
    float viande, budget;
    int month, year;
    int tigre_Habitat, aigle_Habitat, poules_Habitat;
public:
    Zoo(string name = "");
    void addAnimal(IAnimal* animal, int habitat);
    void addAnimal(IAnimal* animal);
    void addHabitat(IHabitat* habitat);
    void SellHabitat(string Race);
    void FireHabitat(string Race);
    void NextMonth();
    void UpdateAge();
    void UpdateFood();
    void UpdateHabitat();
    void VolDanimal(string state);
    void UpdateBudget(float budget);
    void SwitchHabitat(int hab1, int IdAni, int hab2);


    //getter
    string getName();
    float getFood();
    float getBudget();
    int getMonth();
    int getYear();
    int getHAigle();
    int getHTigre();
    int getHPoules();
    int getAGender(string gender, string race);
    void getInfo();
    void getAllInfo(string race);
    void GetHabitatSize();
    void GetHabitatType(string type);
    int GetAnimalNbrByRace(string type);
    int GetHabitatNbrByRace(string type);
    void GetHabitatAnimal();

    //setter
    void setFood(float food);
    void setMonth(float month);
    void setYear(float year);
    void setBudget(float budget);
    void setAnimalHabitat(IAnimal* animal, int HAnimal);
};

#endif // ZOO_H
