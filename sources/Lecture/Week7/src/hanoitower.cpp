#include <iostream>
using namespace std;

void move(int n, char src, char dest, char mid)
{
    if(n==1){
        cout<< "Move 1 from "<<src<<" to "<<dest<<endl;
        return;
    }

    move(n-1,src,mid,dest);
    cout<< " Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    move(n - 1, mid, dest, src);
}

int main()
{
    int n = 4;
    move(n,'A','B','C');
}