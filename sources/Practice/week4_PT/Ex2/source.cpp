#include "source.h"

student* inputStudents(int n)
{
	student* students = new student[n];
	for(int i = 0 ; i < n ; i++)
	{
		cout << "Enter student  " << i + 1 << " id : ";
		cin >> students[i].id;
		char temp[50];
		cout << "Enter student  " << i + 1 << " name : ";
		cin >> temp;
		students[i].name = new char[strlen(temp) + 1];
		strcpy_s(students[i].name, strlen(temp)+1, temp);
		cout << "Enter student  " << i + 1 << " score : ";
		cin >> students[i].score;
		char tmp[100];
		cout << "Enter student  " << i + 1 << " address : ";
		cin >> tmp;
		students[i].address = new char[strlen(tmp) + 1];
		strcpy_s(students[i].address,strlen(tmp)+1, tmp);
	}
	return students;

}

void findUnder5ScoreStudent(student* temp, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp[i].score < 5)
			cnt++;
	}
	student* students = new student[cnt];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp[i].score < 5)
		{
			students[j] = temp[i];
			j++;
		}
	}
	cout << "All false students:\n";
	displayStudents(students, j);
}
void displayStudents(student* temp, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Student [" << i + 1 << "]\n";
		cout << "ID: " << temp[i].id << endl;
		cout << "Name: " << temp[i].name << endl;
		cout << "Score: " << temp[i].score << endl;
		cout << "Address: " << temp[i].address << endl;
	}
}
void swap(student &a, student &b) {
	student temp = a;
	a = b;
	b = temp;
}

void sortByID(student* temp,int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (temp[j].id < temp[min].id)
				min = j;
			
		}
		swap(temp[i], temp[min]);	
	}
	displayStudents(temp, n);
}
void sortByName(student* temp, int n)
{
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(temp[j].name,temp[max].name)>0)
				max = j;
		}
		swap(temp[max], temp[i]);
	}
	displayStudents(temp, n);
}

void findTop3(student* temp, int n)
{
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (temp[j].score > temp[max].score)
				max = j;
		}
		swap(temp[max], temp[i]);
	}
	displayStudents(temp, 3);

}

