#include "Source.h"


bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
bool equalAny(int a, int *b,int size)
{
	int i = 0;
	while (i<size)
	{
		if (a == b[i])
			return true;
		i++;
	}
	return false;

}
bool checkValiddate(date dates)
{
	int a[] =  {1,3,5,7,8,10,12};
	int b[] = { 4,6,9,11 };
	if (dates.year <= 0 && dates.month <= 0 && dates.month > 12 && dates.day <= 0)
		return false;
	if (equalAny(dates.month,a,7) && dates.day > 31)
		return false;
	if (equalAny(dates.month, b,4) && dates.day > 30)
		return false;
	if (!isLeapYear(dates.year)) {
		if (dates.month > 29)
			return false;
	}
	else {
		if (dates.month > 28)
			return false;
	}
	return true;


}

bool readFile(date*& dates, int &size)
{
	ifstream inF("input.txt");
	if (!inF.is_open()) {
		cout << "Can not open file to read!!";
		return false;
	}
	inF >> size;
	dates = new date[size];
	for (int i = 0; i < size; i++)
	{
		inF >> dates[i].year;
		inF >> dates[i].month;
		inF >> dates[i].day;
		if (!checkValiddate(dates[i]))
			return false;

	}
	inF.close();
	return true;
}

void sortDates(date*& dates, int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		 min = i;
		 for (int j = i + 1; j < size; j++)
		 {
			 if (dates[j].year < dates[min].year)
				 min = j;
			 else if (dates[j].year == dates[min].year) {
				 if (dates[j].month < dates[min].month)
					 min = j;
				 else if (dates[j].month == dates[min].month)
				 {
					 if (dates[j].day < dates[min].day)
						 min = j;
				 }
			 }
		 }
		 date temp = dates[i];
		 dates[i] = dates[min];
		 dates[min] = temp;


	}
}

bool writeFile(date* dates, int size)
{
	ofstream outF("output.txt");
	ofstream outF("output.txt");
	if (!outF.is_open()) {
		cout << "Can not open file to write!!" << endl;
		return false;
	}
	outF << size ;
	for (int i = 0; i < size; i++)
	{
		outF << endl<< dates[i].year<<" ";
		outF  << dates[i].month << " ";
		outF  << dates[i].day;

	}
	outF.close();
	return true;
}