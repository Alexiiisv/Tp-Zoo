#ifndef IANIMAL_H
#define IANIMAL_H
#include <string>

using namespace std;

class IAnimal
{
    string m_name;
    string m_race;
    string m_gender;
    int m_malade;
    int m_alive;
    int m_id;
    int m_fertile;
    int m_mat;
    int m_Maladeonce = 0, intmalade = 0;
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
    virtual void SetAlive(int Alive);
    virtual void SetId(int Id);
    virtual void SetIntMalade(int IntMalade);
    virtual void SetMat(int Mat);
    virtual void SetMaladeOnce(int Monce);
    virtual void SetMalade(int malade, int fertile);
    virtual void SetFood(float food);

    //getter
    virtual string getName();
    virtual string getRace();
    virtual string getGender();
    virtual int getFertile();
    virtual int getMalade();
    virtual int getAlive();
    virtual int getId();
    virtual int getIntMalade();
    virtual int getMat();
    virtual int getMaladeOnce();
    virtual int getAge();
    virtual float getMeat();

};

#endif // IANIMAL_H
