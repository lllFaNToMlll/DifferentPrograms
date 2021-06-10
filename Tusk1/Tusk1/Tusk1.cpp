// Tusk1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream> 
#include <ctime>
#include "sort.h"
using namespace std;


int main()
{
	srand(time(NULL));
	setlocale(0, "russian");
	int length = -1;
	while (length < 0)
	{
		cout << "Введите размер массива" << endl;
		cin >> length;
	}
	int numberOfItemsSorted = -1;
	while (numberOfItemsSorted < 0 || numberOfItemsSorted > 12 || numberOfItemsSorted > length) 
	{
		cout << "Введите количество отсортированных элементов массива (N<=12 и N<=sizeOfMassiv)" << endl;
		cin >> numberOfItemsSorted;
	}
	int *massiv = new int[length];
	cout << "Исходный массив" << endl;
	vvod(massiv, length);
	vivod(massiv, length);
	puts(" ");
	// Делаем проверку на размерность массива и количество проверяемых элементов, ибо при сортировке всех
	// элементов нужно задавать цикл for на N-1
	if (numberOfItemsSorted == length)
		sort(massiv, length, numberOfItemsSorted-1);
	else
		sort(massiv, length, numberOfItemsSorted);
	cout << "Измененный массив" << endl;
	// Теперь, когда весь массив отсортирован - выводим его на экран
	vivod(massiv, length);
	puts("");
	system("pause");
	return 0;
}