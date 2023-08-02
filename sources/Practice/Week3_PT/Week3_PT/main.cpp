#include"source.h"


int main()
{
    int a = 1, b = 2;
    cout << doSomething(&a, &b) << endl;

    int k = 1;
    addOne(&k);
    cout << k;

}