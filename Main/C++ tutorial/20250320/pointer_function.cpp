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
		cout << "팩토리얼은 " << n << endl;
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
		cout << "피보나치 수는 " << x << endl;
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
	//스왑
	int x = 10;
	int y = 20;
	swap(x, y);

	cout << x << endl;
	cout << y << endl;

	countNum(5);

	//팩토리얼
	factorial(5);

	int fanum = 1;

	for (int fa = 5; fa >= 1; fa--)
	{
		fanum *= fa;
	}
	cout << "for문 팩토리얼은 " << fanum << endl;

	int fa = 1;
	fanum = 1;
	while (fa <= 5)
	{
		fanum *= fa;
		fa++;
	}
	cout << "while문 팩토리얼은 " << fanum << endl;

	//피보나치
	fibonacci(1, 1);

	int finum = 1;
	int fi = 1;
	for (fi; fi < 10;)
	{
		int temp = finum;
		finum += fi;
		fi = temp;
		cout << "for문 피보나치는 " << finum << endl;
	}
	finum = 1;
	fi = 1;
	while (fi < 10)
	{
		int temp = finum;
		finum += fi;
		fi = temp;
		cout << "while문 피보나치는 " << finum << endl;
	}

	//스태틱
	cout << "staticTest 함수 1번째호출 " << endl;
	staticTest();
	cout << "staticTest 함수 2번째호출 " << endl;
	staticTest();
	cout << "staticTest 함수 3번째호출 " << endl;
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

	//구조체 정의
	Student stu;
	stu.age = 20;
	stu.name = "박정호";
	stu.number = 20060526;

	cout << stu.age << endl;
	cout << stu.name << endl;
	cout << stu.number << endl;

	//구조체 for문
	Student fstu[100];

	for (int i = 0; i < (sizeof(fstu) / sizeof(*fstu));i++)
	{
		fstu[i].name = "박정호";
		fstu[i].age = 20;
		fstu[i].number = i + 20200100;

		cout << fstu[i].name << endl;
		cout << fstu[i].age << endl;
		cout << fstu[i].number << endl;
		cout << endl;
	}

	//다중배열 합, 곱
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
			cout << i << "번 배열의 " << j << "번째 수는 " << board[i][j] << endl;
			sum += board[i][j];
			mul *= board[i][j];

		}
		cout << "덧셈 결과는 " << sum << endl;
		cout << "곱셈 결과는 " << mul << endl;
	}

	//포인터
	int arr[3] = { 1,2,3 };
	int* x_ptr;
	x_ptr = &arr[0];
	x_ptr++;

	cout << *x_ptr << endl;

	//더블 포인터
	int dx = 10;
	int* dx_ptr = &dx;
	int** dx_ptr_ptr = &dx_ptr;

	cout << dx << endl;
	cout << *dx_ptr << endl;
	cout << **dx_ptr_ptr << endl;

	//포인터로 값 수정
	int px = 10;
	int temp = 20;
	int* px_ptr = &x;

	*px_ptr += temp;

	cout << px << endl;
	cout << *px_ptr << endl;
	
	return 0;
}