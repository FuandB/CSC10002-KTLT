#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct book{
    char title[201];
    char id[11];
    char auth[41];
    char language[41];
    unsigned int year;
    unsigned long int price;
    unsigned int stock;
    book *bnext;
};


void insertBook(book*& bookstore);
void sellaBook(book*& bookstore);
void searchBook(book*& bookstore);
void removeAllBook(book*& bookstore);

