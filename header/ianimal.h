#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;
    string m_race;
    string m_gender;
    int m_fertile;
    int m_age;
    float m_food;

public:
    IAnimal(string m_name);
    virtual ~IAnimal();
    virtual void UpdateAge();

    //setter
    virtual void SetRace(string race);
    virtual void SetGender(string gender);
    virtual void SetFertile(int fertile);
    virtual void SetAge(int Age);
    virtual void SetFood(float food);

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual int getFertile();
    virtual int getAge();
    virtual float getFood();

};

#endif // IANIMAL_H
