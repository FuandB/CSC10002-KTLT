#include "source.h"


int main()
{
    node *List = nullptr;
    input(List);
    int a;

    //3.1
    // cout<<"Input value to remove!";
    // cin>>a;
    // removeX(List,a);

    //3.2
    // removeDup(List);
    // writeFile(List);

    //3.3
    //reverseList(List);

    //3.4
    // insertEven(List);

    //3.5
    //int n;
    //cout<<"Enter insert data:";
    //cin>>n;
    //node *tmp = new node(n);
    //insertSorted(List,tmp);
    
    //3.6
    //List = listOfSum(List);

    //3.7
    node *list2 = nullptr;
    splitList(List,list2);
    // printList(List);
    // cout<<endl;
    // printList(list2);

    //3.8
    //compileList(List,list2);

    //3.9
    // join2List(List,list2);

     printList(List);
   // writeFile(List);
}