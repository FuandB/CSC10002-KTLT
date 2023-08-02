#include "Source.h"

void sortFracArray(fraction* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if ((a[j].num / a[j].den) < (a[min].num / a[min].den))
			{
				min = j;
			}
			
		}
		fraction temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}



}

bool readFile(fraction *&temp,int &size)
{
	ifstream inf("input.txt");
	
	if (!inF.is_open()) {
		cout << "Can not open file to read!!";
		return false;
	}
	inf >> size;
	temp = new fraction[size];
	for (int i = 0; i < size; i++)
	{
		inf >> temp[i].num;
		inf >> temp[i].den;
		if (temp[i].den == 0)
			return 0;
	}
	inf.close();
	return 1;
}

bool writeFile(fraction *FracArray,int n)
{
	ofstream outF("output.txt");
	if (!outF.is_open()) {
		cout << "Can not open file to write!!" << endl;
		return false;
	}
	outF << n;
	for (int i = 0; i < n; i++)
	{
		outF <<endl<< FracArray[i].num<<" ";
		outF << FracArray[i].den;
	}
		outF.close();
		return true;
}

