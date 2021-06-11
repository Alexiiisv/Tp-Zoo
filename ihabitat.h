#ifndef HABITAT_H
#define HABITAT_H
#include <string>

using namespace std;

class IHabitat
{
private:
    string m_type;
    int m_capacity;

public:
    IHabitat();
    IHabitat(string m_type);
    
    virtual ~IHabitat();
    virtual int getCapacity();
    virtual string getType();
    virtual void SetCapacity(int capacity);
};

#endif // HABITAT_H
