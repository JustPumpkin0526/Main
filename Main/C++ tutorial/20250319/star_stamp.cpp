#include "callstarstamp.h"

int tuto0319()
{
	//¦Ȧ�� ����
	int num1;
	cout << "¦Ȧ�� ���� ���� �Է�";
	cin >> num1;

	if (num1 % 2 == 0)
	{
		cout << "¦��" << endl;
	}
	else
	{
		cout << "Ȧ��" << endl;
	}

	//���� ũ�� ����
	int num2;
	cout << "���� ũ�� ���� ���� �Է� ";
	cin >> num2;

	if (num2 < 10)
	{
		cout << "10���� ����" << endl;
	}
	else if (num2 < 20)
	{
		cout << "20���� ����" << endl;
	}
	else if (num2 < 30)
	{
		cout << "30���� ����" << endl;
	}
	else
	{
		cout << "30�̻�" << endl;
	}

	//switch ���ǹ�
	int num3;
	cout << "switch ���ǹ� ���� �Է� ";
	cin >> num3;

	switch (num3)
	{
	case 1:
		cout << "1�Դϴ�." << endl;
		break;
	case 2:
		cout << "2�Դϴ�." << endl;
		break;
	case 3:
		cout << "3�Դϴ�." << endl;
		break;
	case 4:
		cout << "4�Դϴ�." << endl;
		break;

	}

	//0���� 100���� ���� ���
	for (int num4 = 0; num4 <= 100; num4++)
	{
		cout << num4 << endl;
	}

	//�迭 ������� ���
	int count[3] = { 2018, 2019, 2020 };

	for (int num5 = 0; num5 < sizeof(count) / sizeof(*count); num5++)
	{
		cout << num5 + 1 << "��° ��ȣ��" << count[num5] << "�Դϴ�." << endl;
	}

	//for�� ����
	bool floop = true;
	char finput;
	for (; floop; )
	{
		cout << "for�� �Է�(������ ���� q�� �Է��Ͻÿ�) ";
		cin >> finput;

		if (finput == 'q')
			floop = false;
	}

	//while ��
	bool wloop = true;
	char winput;
	while (wloop)
	{
		cout << "while�� �Է�(������ ���� q�� �Է��Ͻÿ�) ";
		cin >> winput;

		if (winput == 'q')
			wloop = false;
	}

	//����� ���α׷�
	cout << "�����" << endl;
	cout << "���� ���� �Է��Ͻÿ� : ";
	int num;
	cin >> num;
	cout << "���簢��" << endl;
	for (int j = 0; j < num; j++)
	{
		for (int i = 0; i < num; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << "�����ﰢ��" << endl;
	for (int j = 1; j < num + 1; ++j)
	{
		for (int i = 0; i < j; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << "�������ﰢ��" << endl;
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
	cout << "�̵�ﰢ��" << endl;
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