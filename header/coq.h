#ifndef COQ_H
#define COQ_H
#include <string>
#include "ianimal.h"

using namespace std;


class Coq:public IAnimal
{
public:
    Coq(string name, string race, float food, int age);
    ~Coq();
    virtual void UpdateAge();

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual float getMeat();
    virtual int getAge();
};

#endif // COQ_H
