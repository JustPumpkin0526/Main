#include "call_nas.h"

struct Student
{
	string name;
	int age;
	int number;
};

void Array(int numb)
{

	cout << endl;
	cout << numb << "���� ������ ����" << endl;
	cout << endl;

	int** arr = new int* [numb];

	for (int i = 0; i < numb; i++)
	{
		arr[i] = new int[numb];
	}

	int n = numb;

	int num = 1;
	int x, y;

	for (x = 0; x < (n / 2) + 1; x++)
	{
		for (y = x; y < n - x; y++)
		{
			arr[x][y] = num++;
		}
		for (y = x + 1; y < n - x; y++)
		{
			arr[y][n - x - 1] = num++;
		}
		for (y = n - x - 2; y >= x; y--)
		{
			arr[n - x - 1][y] = num++;
		}
		for (y = n - x - 2; y >= x + 1; y--)
		{
			arr[y][x] = num++;
		}
	}

	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			cout << arr[x][y] << " ";
		}
		cout << endl;
	}
}

int tuto0324()
{
	//�����Ҵ�
	int sn;
	cout << "�迭 ������ �Է��Ͻÿ�. ";
	cin >> sn;
	cout << endl;
	Student* stuArr = new Student[sn];
	for (int i = 0; i < sn;i++)
	{
		string name;
		int age;
		int num;

		cout << "�̸��� �Է��Ͻÿ�. ";
		cin >> name;
		cout << "���̸� �Է��Ͻÿ�. ";
		cin >> age;
		cout << "��ȣ�� �Է��Ͻÿ�. ";
		cin >> num;

		stuArr[i].name = name;
		stuArr[i].age = age;
		stuArr[i].number = num;

		cout << stuArr[i].name << endl;
		cout << stuArr[i].age << endl;
		cout << stuArr[i].number << endl;
	}
	delete[] stuArr;

	//������ �迭
	int number;
	while (true)
	{
		cout << "1���� 30���� �� �� �Է�" << endl;
		cin >> number;

		if ((number < 1) | (number > 30))
		{
			cout << "Error" << endl;
		}
		else
		{
			break;
		}

	}
	Array(number);

	//����Ž��
	int arr[5] = { 3, 6, 2, 9, 8 };
	int sm;
	cin >> sm;
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		if (sm == arr[i])
		{
			cout << "��ǥ Ž�� �Ϸ� : " << arr[i] << endl;
		}
	}

	//����Ž��
	int num;
	cin >> num;


	int bnarr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int low = 0;
	int high = sizeof(arr) / sizeof(*arr) - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (bnarr[mid] == num)
		{
			cout << "��ǥ Ž�� �Ϸ� : " << bnarr[mid] << endl;
			break;
		}
		else if (bnarr[mid] < num)
		{
			low = mid + 1;
		}
		else if (bnarr[mid] > num)
		{
			high = mid - 1;
		}
	}
	return 0;
}