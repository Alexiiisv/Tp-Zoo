#ifndef TIGRE_H
#define TIGRE_H
#include <string>
#include "ianimal.h"

using namespace std;


class Tigre:public IAnimal
{
public:
    Tigre(string name, string race, string gender, float food, int age);
    ~Tigre();
    virtual void UpdateAge();

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual float getMeat();
    virtual int getAge();
};

#endif // TIGRE_H
