#ifndef ZOO_H
#define ZOO_H
#include "ianimal.h"
#include "ihabitat.h"

#include <vector>
#include <string>

using namespace std;
typedef vector <IHabitat*> HabitatList;
typedef HabitatList::iterator HabitatIterator;
class Zoo
{
    string m_name;
    HabitatList m_habitats;
    float viande, graines, budget;
    int month, year;
    int tigre_Habitat, aigle_Habitat, poules_Habitat;
public:
    Zoo(string name = "");
    void addAnimal(IAnimal* animal, int habitat);
    void addHabitat(IHabitat* habitat);
    void SellHabitat(string Race);
    void SellAnimal(int IdAni, int IdHab, string race);
    void FireHabitat(string Race);
    void NextMonth();
    void UpdateAge();
    void UpdateMalade();
    void ReproductionAigle(int state);
    void ReproductionTigre();
    void ReproductionTigre(string state);
    void ReproductionPoule(int date);
    void UpdateMeat();
    void UpdateSeed();
    void UpdateHabitat();
    void VolDanimal(string state);
    void UpdateBudget(float budget);
    void SwitchHabitat(int hab1, int IdAni, int hab2, string race);


    //getter
    string getName();
    float getMeat();
    float getSeed();
    float getBudget();
    int getMonth();
    int getYear();
    int getHAigle();
    int getHTigre();
    int getHPoules();
    int getintHab(int id, string race);
    float getConsobyRace(string race);
    int getAGender(string gender, string race);
    void getInfo();
    void getAllInfo(string race);
    void GetHabitatSize();
    void GetHabitatType(string type);
    int GetAnimalNbrByRace(string State);
    int GetHabitatNbrByRace(string type);
    void GetHabitatAnimal(string State);
    void GetHabitatAnimal(string State, string race);

    //setter
    void setMeat(float food);
    void setSeed(float Seed);
    void setName(string name);
    void setMonth(float month);
    void setYear(float year);
    void setBudget(float budget);
    void setAnimalHabitat(IAnimal* animal, int HAnimal);
};

#endif // ZOO_H
