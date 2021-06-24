#ifndef ACTIONMONTH_H
#define ACTIONMONTH_H

#include "zoo.h"

void actionMonth(Zoo &zoo);
void buyHabitats(Zoo &zoo);
void buyAnimal(Zoo &zoo);
void sellHabitat(Zoo &zoo);
void sellAnimal(Zoo &zoo);
void switchHabitat(Zoo &zoo);
void specialEvent(Zoo &zoo);
void animalsReproduction(Zoo zoo, bool enoughMeat, bool enoughSeed);

#endif