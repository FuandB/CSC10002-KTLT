#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct date
{
	int day;
	int month;
	int year;

};
bool checkValiddate(date date);
bool isLeapYear(int year);
bool equalAny(int, int*,int);
bool readFile(date*& dates, int& size);
void sortDates(date*& dates, int size);
bool writeFile(date* dates, int size);
