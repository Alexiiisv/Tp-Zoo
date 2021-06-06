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

    //getter
    virtual string getName();
    virtual string getRace();
};

#endif // AIGLE_H
