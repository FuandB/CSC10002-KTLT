#include "source.h"

int main() {
	student* students;
	int n = 4;
	students = inputStudents(4);
	findUnder5ScoreStudent(students, n);
	cout << endl;
	sortByID(students, n);
	cout << endl;
	sortByName(students, n);
	cout << endl;
	findTop3(students, n);

}