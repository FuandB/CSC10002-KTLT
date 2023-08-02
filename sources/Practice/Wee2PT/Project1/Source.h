#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

struct Phone {
	char* model = nullptr;
	int id;
	int stock;
	unsigned  int price;
};

bool readFile(Phone* &shop, int &size);
bool writeFile(Phone* shop, int size);
unsigned  int calcTotal(Phone* shop, int size);
