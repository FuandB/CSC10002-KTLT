#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct fraction
{
	double num;
	double den;
};

bool readFile(fraction*&,int&);
bool writeFile(fraction*,int);
void sortFracArray(fraction* , int );