#include "callstarstamp.h"

int tuto0319()
{
	//짝홀수 구별
	int num1;
	cout << "짝홀수 구별 숫자 입력";
	cin >> num1;

	if (num1 % 2 == 0)
	{
		cout << "짝수" << endl;
	}
	else
	{
		cout << "홀수" << endl;
	}

	//숫자 크기 구별
	int num2;
	cout << "숫자 크기 구별 숫자 입력 ";
	cin >> num2;

	if (num2 < 10)
	{
		cout << "10보다 작음" << endl;
	}
	else if (num2 < 20)
	{
		cout << "20보다 작음" << endl;
	}
	else if (num2 < 30)
	{
		cout << "30보다 작음" << endl;
	}
	else
	{
		cout << "30이상" << endl;
	}

	//switch 조건문
	int num3;
	cout << "switch 조건문 숫자 입력 ";
	cin >> num3;

	switch (num3)
	{
	case 1:
		cout << "1입니다." << endl;
		break;
	case 2:
		cout << "2입니다." << endl;
		break;
	case 3:
		cout << "3입니다." << endl;
		break;
	case 4:
		cout << "4입니다." << endl;
		break;

	}

	//0부터 100까지 숫자 출력
	for (int num4 = 0; num4 <= 100; num4++)
	{
		cout << num4 << endl;
	}

	//배열 순서대로 출력
	int count[3] = { 2018, 2019, 2020 };

	for (int num5 = 0; num5 < sizeof(count) / sizeof(*count); num5++)
	{
		cout << num5 + 1 << "번째 번호는" << count[num5] << "입니다." << endl;
	}

	//for문 종료
	bool floop = true;
	char finput;
	for (; floop; )
	{
		cout << "for문 입력(나가기 위해 q를 입력하시오) ";
		cin >> finput;

		if (finput == 'q')
			floop = false;
	}

	//while 문
	bool wloop = true;
	char winput;
	while (wloop)
	{
		cout << "while문 입력(나가기 위해 q를 입력하시오) ";
		cin >> winput;

		if (winput == 'q')
			wloop = false;
	}

	//별찍기 프로그램
	cout << "별찍기" << endl;
	cout << "라인 수를 입력하시오 : ";
	int num;
	cin >> num;
	cout << "정사각형" << endl;
	for (int j = 0; j < num; j++)
	{
		for (int i = 0; i < num; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << "직각삼각형" << endl;
	for (int j = 1; j < num + 1; ++j)
	{
		for (int i = 0; i < j; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << "역직각삼각형" << endl;
	for (int j = num; j > 0; j--)
	{
		for (int k = 0; k < num - j; k++)
		{
			cout << ' ';
		}
		for (int i = 0; i < j; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << "이등변삼각형" << endl;
	for (int j = 1; j < num + 1; j++)
	{
		for (int k = 0; k < num - j; k++)
		{
			cout << ' ';
		}
		for (int i = 0; i < j; i++)
		{
			cout << '*';
		}
		for (int l = 0; l < j - 1;l++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}