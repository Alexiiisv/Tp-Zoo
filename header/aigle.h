#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle:public IAnimal
{
public:
    Aigle(string name, string race, string gender, float food, int age);
    ~Aigle();
    virtual void UpdateAge();

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual float getFood();
    virtual int getAge();
};

#endif // AIGLE_H
