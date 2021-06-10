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
	// ���������� ������ ���������� ��������� �������
	// (����� ����������, �� ��� ����� ������������ � ���� �������, ����� �� �� ���� ��������)
	for (int startIndex = 0; startIndex < numberOfItemsSorted; ++startIndex)
	{
		// � ���������� biggestIndex �������� ������ ����������� ��������, ������� �� ����� � ���� ��������
		// �������� � ����, ��� ���������� ������� � ���� �������� - ��� ������ ������� (������ 0)
		int biggestIndex = startIndex;
		// ����� ���� ������� ���������� � ��������� ����� �������
		for (int currentIndex = startIndex + 1; currentIndex < N; ++currentIndex)
		{
			// ���� �� ����� �������, ������� ������ ������ ����������� ��������,
			if (massiv[currentIndex] > massiv[biggestIndex])
				// �� ���������� ���
				biggestIndex = currentIndex;
		}
		// biggestIndex ������ ���������� ������� 
				// ������ ������� ���� ��������� ���������� ����� � ���, ������� �� ����������
		swap(massiv[startIndex], massiv[biggestIndex]);
	}
}