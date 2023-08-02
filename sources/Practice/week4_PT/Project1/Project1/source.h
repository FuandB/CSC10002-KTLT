#pragma once

#include <iostream>
#include <math.h>

using namespace std;


struct fraction
{
	float num;
	float den;
};


fraction *inputFracArr(int);
void extracNevFrac(fraction*,int );
void displayNevFracArr(fraction*, int);
void findSumOfPosFrac(fraction*, int);