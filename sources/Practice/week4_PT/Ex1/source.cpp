#include "source.h"

fraction *inputFracArr(int n)
{
	fraction *fracArr = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter numerator of fraction " << i+1 << " : ";
		cin >> fracArr[i].num;
		cout << "Enter denominator of fraction " << i + 1 << " : ";
		cin >> fracArr[i].den;
		if (fracArr[i].den == 0)
		{
			cout << "denominator can not be zero please enter denominator of fraction " << i + 1 << " again : ";
			cin >> fracArr[i].den;
		}
	}
	return fracArr;
}

void extracNevFrac(fraction* temp, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if ((temp[i].num < 0) ^ (temp[i].den < 0))
		{
			cnt++;
		}
	}
	int j = 0;
	fraction *nevFracArr = new fraction[cnt];
	for (int i = 0; i < size; i++)
	{
		if ((temp[i].num < 0) ^ (temp[i].den < 0))
		{
			nevFracArr[j] = temp[i];
			j++;
		}
	}
	displayNevFracArr(nevFracArr,cnt);

}
void displayNevFracArr(fraction* nevFracArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Fraction [" << i + 1 << "] : " << nevFracArr[i].num << "/" << nevFracArr[i].den << endl;
	}
}
void findSumOfPosFrac(fraction* fracArr, int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((fracArr[i].num >= 0 && fracArr[i].den > 0) or (fracArr[i].num < 0 && fracArr[i].den < 0))
		{
			sum += (fracArr[i].num / fracArr[i].den);
		}
	}
	cout << "Sum of all positive fractions : " << sum;
}
