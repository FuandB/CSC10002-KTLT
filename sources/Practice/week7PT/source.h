#pragma once
#include <fstream>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *pnext = nullptr;

    node(int val) : data(val),pnext(nullptr) {};
};


void input(node *&);
void writeFile(node *&);
void removeX(node*&,int);
void printList(node*&);
void removeDup(node*&);
void addTail(node*&,node*);
void reverseList(node *&);
void insertEven(node*&);
void insertNode(node*&,node*&);
void insertSorted(node*&, node*& );
node* listOfSum(node *&);
void splitList(node*&,node *&);
void compileList(node*& , node*& );
void join2List(node*&,node*&);
