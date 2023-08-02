#include "source.h"
//6.1
int calA(int n){
    if(n==1)
    return 1;

    return calA(n-1)+n;
}
int calB(int n , int x)
{
    if(n==1)
    return x;

    return calB(n-1,x)*x;
}
float calC(int n){
    if(n==1)
    return 1;

    if(n%2==0)
        return calC(n-1)-(1.0/n);
     else
        return calC(n-1)+(1.0/n);
}


//6.2
int sumEven(int arr[],int index)
{
    if(index < 0)
        return 0;
    
    if(arr[index]%2==0)
        return sumEven(arr,index-1)+arr[index];
    else 
        return sumEven(arr,index-1);
}

int findMax(int arr[],int size, int index)
{
    if(size==0)
    return arr[0];
    else{
        int max = findMax(arr,size-1,index+1);
        if(arr[index]>max)
        return arr[index];
        else
        return max;
    }

}

void reverseString(char arr[],int index)
{
    if(index<0)
        return;
    cout<<arr[index];
    reverseString(arr,index-1);
}


void printCurrency(int n){
    if(n<1000)
        cout<<n;
    else{
        printCurrency(n/1000);
        cout<<",";
        if(n/100!=0)
            cout<<(n%1000)/100;
        else 
            cout<<"0";
        if(n/10!=0)
            cout<<(n%100)/10;
        else 
            cout<<"0";
        cout<<n%10;

    }
}
//6,3
void swapchar(char&a,char&b){
    char temp = a;
    a = b;
    b = temp;
}
char* toString(int n)
{
    char *temp = new char[n+1];
    for(int i = 0; i<n;i++)
    {
        temp[i]= '0'+i+1;
    }
    temp[n] ='\0';
    return temp;
}
void printPermutation(char*a ,int l , int r)
{
    if (l == r)
        cout << a << endl;
    else {
        for (int i = l; i <= r; i++)
         {
            swapchar(a[l], a[i]);
            printPermutation(a, l + 1, r);
            swapchar(a[l], a[i]);
        }
        }
}

void printKpermutation(char*a,int l,int r, int k){
    if (l == r)
        {
            for(int i = 0;i<k;i++)
            {
                cout<<a[i];
            }
            cout<<endl;
        }
    else {
            for (int i = l; i <= r; i++)
            {
                swapchar(a[l], a[i]);
                printKpermutation(a, l + 1, r ,k);
                swapchar(a[l], a[i]);
            }
        }
}
