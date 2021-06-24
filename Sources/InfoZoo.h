#ifndef INFOZOO_H
#define INFOZOO_H

#include "../header/zoo.h"

void StartGame(Zoo &zoo, int &nbYearZoo);
void infoZoo(Zoo zoo, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSucess, bool nbMonthVisitorSuccess);
void printEndGame(Zoo zoo, int all_visitors, bool nbEagleSuccess, bool moneySuccess, bool nbTotalVisitorSuccess, bool nbMonthVisitorsSuccess);

#endif