#include "source.h"


int main()
{
	int n = 3;
	fraction* temp = inputFracArr(n);
	extracNevFrac(temp, n);
	findSumOfPosFrac(temp,n);
}