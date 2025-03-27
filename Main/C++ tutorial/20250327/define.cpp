#include "define.h"

int define_test() {
	double radius = 5.0;
	double area = PI * SQUARE(radius);
	cout << "Area: " << area << endl;

	int value = 5;
#ifdef DEBUG
	cout << "Debug: value °ª = " << value << endl;
#endif
	return 0;
}