#include "call_array.h"

//����Ʈ ����
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
	//�迭 ������
	int gradeArr[2][5] =
	{
		{ 1,3,5,7,9 },
		{ 2,4,6,8,10 }
	};

	cout << *(gradeArr[0]) << endl;

	//������ ����
	int x = 10;
	int y = 20;
	cout << "x�� ���� " << x << endl;
	cout << "y�� ���� " << y << endl;
	int* xp = &x;
	int* yp = &y;
	pswap(xp, yp);
	cout << "�ٲ� x�� ���� " << x << endl;
	cout << "�ٲ� y�� ���� " << y << endl;


	//�迭���߰�
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	addarray(arr, 10);

	return 0;
}