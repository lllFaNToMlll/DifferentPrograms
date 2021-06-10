#include "sort.h"
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

void vvod(int* massiv, int N)
{
	for (int i = 0; i < N; i++)
		massiv[i] = rand() % 100 - 50;
}

void vivod(int* massiv, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << massiv[i] << " ";
	}
}

void sort(int* massiv, int N, int numberOfItemsSorted)
{
	// ѕеребираем нужное количество элементов массива
	// (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберЄмс€)
	for (int startIndex = 0; startIndex < numberOfItemsSorted; ++startIndex)
	{
		// ¬ переменной biggestIndex хранитс€ индекс наибольшего значени€, которое мы нашли в этой итерации
		// Ќачинаем с того, что наибольший элемент в этой итерации - это первый элемент (индекс 0)
		int biggestIndex = startIndex;
		// «атем ищем элемент наибольший в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < N; ++currentIndex)
		{
			// ≈сли мы нашли элемент, который больше нашего наибольшего элемента,
			if (massiv[currentIndex] > massiv[biggestIndex])
				// то запоминаем его
				biggestIndex = currentIndex;
		}
		// biggestIndex теперь наибольший элемент 
				// ћен€ем местами наше начальное наибольшее число с тем, которое мы обнаружили
		swap(massiv[startIndex], massiv[biggestIndex]);
	}
}