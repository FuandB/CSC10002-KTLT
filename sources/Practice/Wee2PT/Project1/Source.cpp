#include "Source.h"



bool readFile(Phone* &shop, int &size)
{
	ifstream inF("input.txt");
	if (!inF.is_open()) {
		cout << "Can not open file to read!!";
		return false;
	}
	inF >> size;
	shop = new Phone[size];
	
	for (int i = 0; i < size; i++)
	{
		shop[i].model = new char[10];
		inF >> shop[i].id;
		inF.getline(shop[i].model, 10, '\n');
		inF >> shop[i].stock;
		inF >> shop[i].price;

		if (shop[i].price <= 0)
			return false;
	}
	inF.close();
	return true;
}

unsigned int calcTotal(Phone* shop, int size)
{
	unsigned  int total = 0;
	for (int i = 0; i < size; i++)
	{
		total = total + (shop[i].price * shop[i].stock);
	}
	return total;
}
bool writeFile(Phone *shop,int size)
{
	ofstream outF("output.txt");
	if (!outF.is_open()) {
		cout << "Can not open file to write!!" << endl;
		return false;
	}
	outF << calcTotal(shop, size);
	outF.close();
	return true;
}
