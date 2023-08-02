#include "Source.h"
int main() {
	Phone* shop = nullptr;
	int size = 0;
	bool check = readFile(shop, size);
	writeFile(shop, size);
	int i = 0;
	for(int i = 0 ; shop[0].model[i]!='\n';i++)
	cout << shop[0].model[i];

	delete[] shop;
	return 1;


}