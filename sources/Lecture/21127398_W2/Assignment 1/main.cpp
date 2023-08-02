#include "Source.h"
int main() {
	fraction* FracArray = new fraction;
	int size = 0;
	bool readable = readFile(FracArray, size);
	if (!readable) {
		cout << "Fraction with zero denomitor can not exist !!" << endl;
		return 0 ;
	 }
	sortFracArray(FracArray,size);
	writeFile(FracArray,size);
	return 0;
}