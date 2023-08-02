#include "Source.h"
int main() {
	circle* CirArray = new circle;
	int size = 0;
	bool readable = readFile(CirArray, size);
	if(!readable)
	{
		cout<<"Radius much be positive or can not openfile or can not open file!!"<<endl;
		return 0;
	}
	WriteFile(CirArray, size);
	return 0;

}