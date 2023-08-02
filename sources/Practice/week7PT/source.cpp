#include "source.h"


void input(node *&root)
{
    ifstream in("input.txt");
    if(!in)
    {
        cout<<"Can not open file\n";
        return;
    }
    
    while(!in.eof()){
        int temp;
        in>>temp;
        if(temp == 0)
        {
            in.close();
            return;
        }
        else{
            node *tmp = new node(temp);
            addTail(root,tmp);
        }
        
    }
    in.close();
}
void addTail(node*& root, node* temp) {
    if (root == nullptr) {
        root = temp;
    } else {
        node* cur = root;
        while (cur->pnext != nullptr) {
            cur = cur->pnext;
        }
        cur->pnext = temp;
    }
}

void removeX(node *&root,int val)
{
    node *cur = root;
    
    while(cur->pnext != nullptr)
    {
        if(cur->pnext->data== val)
        {
            node *temp = cur->pnext;
            cur->pnext = cur->pnext ->pnext;
            delete(temp);
        }
        else{
            cur = cur->pnext;
        }
        
    }
}

void writeFile(node*& root)
{
    node *cur = root;
    ofstream out("output.txt");
    if(!out){
        cout<<"Can not open file!!";
        return;
    }
    while(cur!=nullptr)
    {
        out<<cur->data<<" ";
        cur=cur->pnext;
    }

    out.close();
}

void printList(node *&root)
{
    node *cur = root;
    while(cur!=nullptr)
    {
        cout<<cur->data<<" ";
        cur= cur->pnext;
    }
}

void removeDup(node *&root)
{
    node *cur = root;
    while(cur->pnext!=nullptr)
    {
        int val = cur->data;
        removeX(cur->pnext,val);
        cur=cur->pnext;

    }
}
void reverseList(node *&root)
{
    if(root == nullptr || root->pnext == nullptr)
    return;

    node *cur = root;
    node *prev = nullptr;
    node *next = nullptr;
    while(cur != nullptr)
    {
        next = cur->pnext;
        cur->pnext = prev;
        prev = cur;
        cur = next;
    }


    root = prev;

}

void insertEven(node*&root){
    node *cur = root;
    
    if(root==nullptr)
    {
        return;
    }
    int index = 2;
    node *temp = new node(index);
    temp->pnext = cur;
    root = temp;

    
    while(cur->pnext!=nullptr)
    {
        index+=2;
        node *tmp = new node(index);
        temp->pnext = cur->pnext;
        cur->pnext = temp;
        cur=tmp->pnext;
    }
}
void insertSorted(node *&root,node*& temp)
{
    

    if(root == nullptr){
        root = temp;
        return;
    }
    if(root->data>=temp->data)
    {
        temp->pnext = root;
        root = temp;
        return;
    }

    node *cur = root;
    
    while(cur->pnext!=nullptr )
    {
        if(cur->pnext->data>=temp->data)
        {
            temp->pnext = cur->pnext;
            cur->pnext = temp;
            return;
        }
        else
            cur=cur->pnext;
    }
    cur->pnext = temp;
}
node *listOfSum(node *&root)
{
    if(root== nullptr)
    return nullptr;

    node *cur = root;

    node *newList = new node(root->data);// head of newList = head of list
    int currendata = newList->data; // current data of new list
    while(cur->pnext!=nullptr){
       cur=cur->pnext;
       node *tmp = new node(currendata+cur->data);
       // new node tmp->data = curent node of newList->data + curent node of oldList->data
       addTail(newList,tmp);
       currendata = tmp->data;// cập nhật lại new cur
    }

    return newList;
}
void splitList(node*& root, node*& list2) {
    if (root == nullptr || root->pnext == nullptr) {
        return;
    }

    node* cur = root;
    list2 = root->pnext;
    node* cur2 = list2;

    while (cur != nullptr && cur->pnext != nullptr && cur2 != nullptr && cur2->pnext != nullptr) {
        cur->pnext = cur->pnext->pnext;
        cur = cur->pnext;
        
        cur2->pnext = cur2->pnext->pnext;
        cur2 = cur2->pnext;
    }

    if (cur != nullptr) {
        cur->pnext = nullptr;
    }

    if (cur2 != nullptr) {
        cur2->pnext = nullptr;
    }
}

void compileList(node*& list1, node*& list2)
{
    if(list1 == nullptr || list2== nullptr)
    {
        return;
    }
    node* cur = list2;
    while(cur != nullptr)
    {
       node *tmp = cur->pnext;
       insertSorted(list1,cur);
       cur= tmp;
    }
    
}
void join2List(node *&list1, node *&list2)
{
     if(list1 == nullptr || list2== nullptr)
    {
        return;
    }
    node *cur = list1;
    while(cur->pnext!= nullptr)
    {
        cur = cur->pnext;
    }
    cur->pnext = list2;

}