#ifndef POULE_H
#define POULE_H
#include <string>
#include "ianimal.h"

using namespace std;


class Poule:public IAnimal
{
public:
    Poule(string name, string race, float food, int age);
    ~Poule();
    virtual void UpdateAge();

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual float getMeat();
    virtual int getAge();
};

#endif // POULE_H
