#pragma once

#include <iostream>
#include <string>
using namespace std;

struct student
{
	int id;
	char* name;
	double score;
	char* address;
};

student* inputStudents(int);
void findUnder5ScoreStudent(student* ,int);
void displayStudents(student*, int);
void swap(student&, student& );
void sortByID(student*, int );
void sortByName(student*, int );
void findTop3(student*, int);
