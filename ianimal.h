#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;
    string m_race;

public:
    IAnimal();
    IAnimal(string m_name);
    virtual ~IAnimal();

    //setter
    virtual void SetRace(string race);

    //getter
    virtual string getName();
    virtual string getRace();

};

#endif // IANIMAL_H
