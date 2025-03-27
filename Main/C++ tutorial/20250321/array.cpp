#include "call_array.h"

//포인트 스왑
void pswap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	return;
}

void addarray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
		cout << arr[i] << endl;
	}
}

int tuto0321()
{
	//배열 포인터
	int gradeArr[2][5] =
	{
		{ 1,3,5,7,9 },
		{ 2,4,6,8,10 }
	};

	cout << *(gradeArr[0]) << endl;

	//포인터 스왑
	int x = 10;
	int y = 20;
	cout << "x의 값은 " << x << endl;
	cout << "y의 값은 " << y << endl;
	int* xp = &x;
	int* yp = &y;
	pswap(xp, yp);
	cout << "바뀐 x의 값은 " << x << endl;
	cout << "바뀐 y의 값은 " << y << endl;


	//배열값추가
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	addarray(arr, 10);

	return 0;
}