#include "Source.h"
int main() {
	date* dates = new date;
	int size = 0;
	bool readable = readFile(dates, size);
	if (!readable)
	{
		cout << "Invalid input date!!" << endl;
		return 0;
	}
	sortDates(dates, size);
	writeFile(dates, size);
	return 0;
	

}