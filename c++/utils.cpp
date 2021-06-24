#include <random>
#include <iostream>
using namespace std;

int randomnbr(int min, int max)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}
// Génère un string random
string randomStr(int len)
{
    mt19937 generator{random_device{}()};
    uniform_int_distribution<int> distribution{'a', 'z'};
    string rand_str(len, '\0');
    for (auto &dis : rand_str)
        dis = distribution(generator);
    return rand_str;
}

void Clear()
{
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined(__APPLE__)
        system("clear");
    #endif
}
