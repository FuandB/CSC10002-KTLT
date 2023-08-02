#include "Source.h"

bool readFile(circle*& cirArray, int &size)
{
	ifstream inF("input.txt");
	inF >> size;
	for (int i = 0; i < size; i++) {
		inF >> cirArray[i].center.x;
		inF >> cirArray[i].center.y;
		inF >> cirArray[i].radius;
		if(cirArray[i].radius<=0)
		return false;
	}
	inF.close();
	return true;
}
double calSumArea(circle* cirArray, int size)
{
	double sumofArea = 0;
	for (int i = 0; i < size; i++)
	{
		sumofArea += pow(cirArray[i].radius, 2) * pi;
	}
	return sumofArea;

}

bool WriteFile(circle* cirArray, int size)
{
	double sumofArea = calSumArea(cirArray,size);
	
	ofstream outF("output.txt");
	ofstream outF("output.txt");
	if (!outF.is_open()) {
		cout << "Can not open file to write!!" << endl;
		return false;
	}
	outF << sumofArea;
	outF.close();
	return true;
}
