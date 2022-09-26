#include<iostream>
using namespace std;
void print_happy()
{
	cout << "��� ����� ����������, ����� ����� ��� ������?.." << endl;
}
void print_unhappy()
{
	cout << "��������� ����������� ����� ����������)" << endl;
}
int double_num(int *num)
{
	int result = *num % 1000;
	int num1 = 0, num2 = 0;
	*num /= 1000;
	while (*num)
	{
		num1 += *num % 10;
		num2 += result % 10;
		*num /= 10;
		result /= 10;
	}
	*num = num1;
	return num2;

}
void summ(int n)
{
	int num=double_num(&n);
	
	if (num == n)
		print_happy();
	else
		print_unhappy();
}
void sqert_bus(int n)
{
	int result = n % 1000;
	n /= 1000;
	int num1 = 0, num2 = 0;
	while (n )
	{
		num1 += n % 10;
		num2 += result % 10;
		n /= 10;
		result /= 10;
	}
	while (true)
	{
		if ((num1 < 10) & (num2 < 10))
			break;
		else
		{
			while (num1 > 10)
			{
				num1 = (num1 / 10) + (num1 % 10);
			}
			while (num2 > 10)
			{
				num2 = (num2 / 10) + (num2 % 10);
			}
		}
	}
	if (num1 == num2)
		print_happy();
	else
		print_unhappy();
}
void div(int n)
{
	int result = n % 1000;
	n /= 1000;
	if ((result % 9) == (n % 9))
		print_happy();
	else
		print_unhappy();
	cout << n % 9 << endl << result % 9 << endl;

}
bool polindrom(int n) 
{
	//bool result;
	int revers_num = 0, num = n;
	while (n)
	{
		revers_num *= 10;
		revers_num += n % 10;
		n /= 10;
	}
	if (num == revers_num)
		return true;
	else
		return false;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int poli,bus_tiket,select_happy;
	//1. ������������ ������ �����.��������� �������, �������� �� ��������� ����� �����������.
	//��������� - ��� �����, ������� �������� ���������, ��� ����� �������, ��� � ������ ������.
	
	cout << "�������� ����� �� ���������\n������� ����� ->";
	cin >> poli;
	if (polindrom(poli))
		cout << "�������� ����� ���������." << endl;
	else
		cout << "�������� ����� �� ���������" << endl;

//2. ����������� ������ ����� ����������� ������, � ��������� ������ �������,
//���� ����� ���������� ��� �������;
/*���������� ��������� ���������� � ������������ ���������� �����, � ������������ ������
�������� ����� ������ ��� ���� ��������� � ������ ��� ���������. 
����� ����� ������������ �������, ����������� ���������� ������, ����� 55251
(55252, ���� ��������� ����� � ������� 000000), 
�� ���� � ������� �������� ���� ����� �� ������������ �������� ����������. 
����� ���������� ����������� �������������, �������� �������� ��������� ������ �� ���� �����, 
� �� �������� ����� (���, ������������, ������� ��� ������� �� 9) � � ����� ������ ���������� 
������� ������.*/
	cout << "��������� ����������� ����������� ������\n������� 6-�� ������� ����� ->";
	cin >> bus_tiket;
	if (!bus_tiket)
	{
		cout << "����� � ������� 0, ������� ����������)" << endl;
		system("pause");
		return 0;
	}
	else if (bus_tiket > 999999 || bus_tiket < 100000)
	{
		cout << "������ �� ������ �����" << endl;
		system("pause");
		return 0;
	}
	cout << "�������� ����� �������� ���������� ������� ->\n\
1.����� ������ 3� ��������� � ������ ���������.\n\
2.���������� �������.\n\
3.������� ��� ������� �� 9\n";
	cin >> select_happy;
	switch (select_happy)
	{
	case 1:
		summ(bus_tiket);
		break;
	case 2:
		sqert_bus(bus_tiket);
		break;
	case 3:
		div(bus_tiket);
	default:
		break;
	}
	


	system("pause");
	return 0;
}
