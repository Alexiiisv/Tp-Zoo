#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;
    string m_race;
    string m_gender;
    int m_age;

public:
    IAnimal();
    IAnimal(string m_name);
    virtual ~IAnimal();
    virtual void UpdateAge();

    //setter
    virtual void SetRace(string race);
    virtual void SetGender(string gender);
    virtual void SetAge(int Age);

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual int getAge();

};

#endif // IANIMAL_H
