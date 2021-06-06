#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle:public IAnimal
{
public:
    Aigle();
    Aigle(string name, string race);
    virtual void UpdateAge();

    //getter
    virtual string getName();
    virtual string getRace();
    virtual int getAge();
};

#endif // AIGLE_H
