#ifndef CARS_ON_CAMPUS_H_INCLUDED
#define CARS_ON_CAMPUS_H_INCLUDED
#include "utils_includes.h"
#define MAXSIZE 104*8
struct RecInfo{
    char id[8];
    int time;
    bool status;
    RecInfo(){}
};
void CarsOnCampus();
#endif // CARS_ON_CAMPUS_H_INCLUDED
