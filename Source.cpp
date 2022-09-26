#include<iostream>
using namespace std;
void print_happy()
{
	cout << "Ваш билет счастливый, может стоит его сьесть?.." << endl;
}
void print_unhappy()
{
	cout << "следующий обязательно будет счастливым)" << endl;
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
	//1. Пользователь вводит число.Программа говорит, является ли введенное число палиндромом.
	//Палиндром - это число, которое читается одинаково, как слева направо, так и справа налево.
	
	cout << "проверка числа на полиндром\nВведите число ->";
	cin >> poli;
	if (polindrom(poli))
		cout << "Введеное число полиндром." << endl;
	else
		cout << "Введеное число не полиндром" << endl;

//2. Ползователь вводит номер автобусного билета, и программа должна сказать,
//этот билет счастливый или обычный;
/*Счастливым считается полученный в общественном транспорте билет, в шестизначном номере
которого сумма первых трёх цифр совпадает с суммой трёх последних. 
Общее число шестизначных номеров, порождающих счастливые билеты, равно 55251
(55252, если учитывать билет с номером 000000), 
то есть в среднем примерно один билет из восемнадцати является счастливым. 
Также существует определение «счастливости», согласно которому совпадать должны не сами суммы, 
а их числовые корни (или, эквивалентно, остатки при делении на 9) — в таком случае счастливых 
билетов больше.*/
	cout << "программа определения счастливого билета\nВведите 6-ти значное число ->";
	cin >> bus_tiket;
	if (!bus_tiket)
	{
		cout << "билет с номером 0, считаем счатсливым)" << endl;
		system("pause");
		return 0;
	}
	else if (bus_tiket > 999999 || bus_tiket < 100000)
	{
		cout << "Введен не верный номер" << endl;
		system("pause");
		return 0;
	}
	cout << "Выберите каким способом определять счастье ->\n\
1.Сумма первых 3х совпадает с суммой последних.\n\
2.Совпадение корнями.\n\
3.остатки при делении на 9\n";
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
