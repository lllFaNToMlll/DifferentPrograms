#include <iostream>
#include <cmath>
#include "conio.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 14;
	int a[n] = { 10, 49, 14, 25, 8, 5, 35, 7, 13, 9,17,23,21,43 };
	int c[n] = { 10, 49, 14, 25, 8, 5, 35, 7, 13, 9,17,23,21,43 };
	int d[n] = { 10, 49, 14, 25, 8, 5, 35, 7, 13, 9,17,23,21,43 };
	int i, j;
	int k5 = 0, k7 = 0, ko = 0;
	int* b5 = new int[k5];
	int* b7 = new int[k7];
	int* bo = new int[ko];
	/////Вывод массива
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=" << a[i] << endl;
	}

	//Подсчёт сколько элементов кратно 5, кратно 7 и подсчёт остальных элементов
	for (i = 0; i < n; i++)
		if (a[i] % 5 == 0) k5++;

	for (i = 0; i < n; i++)
		if (a[i] % 7 == 0) k7++;

	for (i = 0; i < n; i++)
		if (a[i] % 5 != 0 && a[i] % 7 != 0) ko++;

	cout << "Элементов в первом массиве= " << k5 << endl;
	cout << "Элементов во втором массиве= " << k7 << endl;
	cout << "Элементов в третьем массиве= " << ko << endl;

	cout << endl;


	//Заполнение результирующего массива b5
	for (i = j = 0; i < n; i++)
		if (a[i] % 5 == 0)
		{
			b5[j] = a[i];// temp[i];
			j++;
		}
	cout << endl;

	cout << "Результирующий массив кратный 5:" << endl;
	for (i = 0; i < k5; i++)
		cout << b5[i] << ' ';
	cout << endl;



	//Заполнение массива элементами кратными 7
	for (i = j = 0; i < n; i++)
		if (a[i] % 7 == 0)
		{
			b7[j] = a[i];// temp[i];
			j++;
		}
	//Результирующий массив b7
	cout << "Результирующий массив кратный 7:" << endl;
	for (i = 0; i < k7; i++)
		cout << b7[i] << ' ';
	cout << endl;
	cout << endl;

	//
	for (i = j = 0; i < n; i++)
		if (a[i] % 5 != 0 && a[i] % 7 != 0)
		{
			bo[j] = a[i];// temp[i];
			j++;
		}
	cout << endl;

	cout << "Результирующий массив для остальных элементов:" << endl;
	for (i = 0; i < ko; i++)
		cout << bo[i] << ' ';
	cout << endl;


	delete[]b5;
	delete[]b7;
	delete[]bo;

	_getch();
	return 0;
}