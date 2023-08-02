#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define pi  3.14159265359;
struct point {
	double x;
	double y;
};
struct circle
{
	double radius;
	point center;
};

bool readFile(circle*&, int&);
bool WriteFile(circle*, int);
