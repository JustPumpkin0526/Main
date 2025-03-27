#include "call_pt_fc.h"

void countNum(int cnum)
{
	if (cnum == 1) {
		cout << "num is " << cnum << endl;
		return;
	}
	else {
		cout << "num is " << cnum << endl;
		countNum(cnum - 1);
	}
}

void factorial(int fnum, int n = 1)
{
	if (fnum == 1)
	{
		cout << "���丮���� " << n << endl;
		return;
	}
	else
	{
		n *= fnum;
		factorial(fnum - 1, n);
	}
}

void fibonacci(int x, int y)
{
	if (x < 10)
	{
		x += y;
		cout << "�Ǻ���ġ ���� " << x << endl;
		fibonacci(y, x);
		return;
	}
}

void staticTest()
{
	int local_count = 0;
	static int static_count = 0;
	local_count++;
	static_count++;

	cout << "local_count:" << local_count << endl;
	cout << "static_count" << static_count << endl;
}

struct Student
{
	string name;
	int age;
	int number;
};

int tuto0320() 
{
	//����
	int x = 10;
	int y = 20;
	swap(x, y);

	cout << x << endl;
	cout << y << endl;

	countNum(5);

	//���丮��
	factorial(5);

	int fanum = 1;

	for (int fa = 5; fa >= 1; fa--)
	{
		fanum *= fa;
	}
	cout << "for�� ���丮���� " << fanum << endl;

	int fa = 1;
	fanum = 1;
	while (fa <= 5)
	{
		fanum *= fa;
		fa++;
	}
	cout << "while�� ���丮���� " << fanum << endl;

	//�Ǻ���ġ
	fibonacci(1, 1);

	int finum = 1;
	int fi = 1;
	for (fi; fi < 10;)
	{
		int temp = finum;
		finum += fi;
		fi = temp;
		cout << "for�� �Ǻ���ġ�� " << finum << endl;
	}
	finum = 1;
	fi = 1;
	while (fi < 10)
	{
		int temp = finum;
		finum += fi;
		fi = temp;
		cout << "while�� �Ǻ���ġ�� " << finum << endl;
	}

	//����ƽ
	cout << "staticTest �Լ� 1��°ȣ�� " << endl;
	staticTest();
	cout << "staticTest �Լ� 2��°ȣ�� " << endl;
	staticTest();
	cout << "staticTest �Լ� 3��°ȣ�� " << endl;
	staticTest();

	//ofstream
	ofstream fout;
	fout.open("file.txt");
	fout << 1 << ' '
		 << 2 << '\t'
		 << 3 << '\n'
		 << 4;

	//ifstream
	ifstream fin;
	fin.open("file.txt");
	int number[4];
	fin >> number[0]
		>> number[1]
		>> number[2]
		>> number[3];

	for (int i = 0; i < 4; i++)
	{
		cout << number[i] << endl;
	}

	//����ü ����
	Student stu;
	stu.age = 20;
	stu.name = "����ȣ";
	stu.number = 20060526;

	cout << stu.age << endl;
	cout << stu.name << endl;
	cout << stu.number << endl;

	//����ü for��
	Student fstu[100];

	for (int i = 0; i < (sizeof(fstu) / sizeof(*fstu));i++)
	{
		fstu[i].name = "����ȣ";
		fstu[i].age = 20;
		fstu[i].number = i + 20200100;

		cout << fstu[i].name << endl;
		cout << fstu[i].age << endl;
		cout << fstu[i].number << endl;
		cout << endl;
	}

	//���߹迭 ��, ��
	srand(time(0));
	int board[2][2] =
	{
		{rand() % 10, rand() % 10},
		{rand() % 10, rand() % 10}
	};

	for (int i = 0; i < sizeof(board) / sizeof(*board); i++)
	{
		int sum = 0;
		int mul = 1;
		for (int j = 0; j < sizeof(board[i]) / sizeof(*board[i]); j++)
		{
			cout << i << "�� �迭�� " << j << "��° ���� " << board[i][j] << endl;
			sum += board[i][j];
			mul *= board[i][j];

		}
		cout << "���� ����� " << sum << endl;
		cout << "���� ����� " << mul << endl;
	}

	//������
	int arr[3] = { 1,2,3 };
	int* x_ptr;
	x_ptr = &arr[0];
	x_ptr++;

	cout << *x_ptr << endl;

	//���� ������
	int dx = 10;
	int* dx_ptr = &dx;
	int** dx_ptr_ptr = &dx_ptr;

	cout << dx << endl;
	cout << *dx_ptr << endl;
	cout << **dx_ptr_ptr << endl;

	//�����ͷ� �� ����
	int px = 10;
	int temp = 20;
	int* px_ptr = &x;

	*px_ptr += temp;

	cout << px << endl;
	cout << *px_ptr << endl;
	
	return 0;
}