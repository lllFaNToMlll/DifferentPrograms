// Struct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "math.h"
#include <ctime>
#include <string>
#include <clocale>
#include <Windows.h> 
using namespace std;

unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;

struct Student // Структура Человек
{
	char surname[50]; // фамилия
	int firstEx; // день рождения
	int secondEx; // месяц рождения
	int thirdEx; // год рождения
};

void InputStudent(Student& student, int studentSize); // ввод структуры

void OutputArrayName(Student* structArray, int studentSize); // вывод массива структур 

void Exchange(Student& student1, Student& student2); // поменять местами элеменыт массива структур

void SortStructArray(Student* structArray, int studentSize); // сортировка массива структур по алфавиту сортировкой вставками

void finfStudent(Student* structArray, int studentSize, Student &newStructArray, int & newStudentSize); // составить массив структур студентов, средний балл которых < 3.5

void main()
{
	SetConsoleCP(1251); // устанавливаем русский язык
	SetConsoleOutputCP(1251); // устанавливаем русский язык
	int studentSize = -1; // количество людей
	while (studentSize <= 0) {
		printf("Введите кол-во людей, которые хотите записать (>0): ");
		scanf("%d", &studentSize);
	}
	Student* structArray = new Student[studentSize]; // создаем массив структур
	for (int i = 0; i < studentSize; i += 1)
		InputStudent(structArray[i], studentSize); // проходим по всему массиву структур и заполняем каждую из них
	printf("Исходный массив структур: \n");
	OutputArrayName(structArray, studentSize); // печатаем наш массив структур
	Student* newStructArray; // создаем указатель на новый массив структур студентов, у которых средний балл меньше 3.5
	int newStudentSize = 0;
	newStructArray = finfStudent(structArray, studentSize, *newStructArray, newStudentSize);
	if (newStudentSize != 0) {
		SortStructArray(newStructArray, studentSize); // сортируем людей, у которых средний балл меньше 3.5, по алфавиту сортировкой вставками
		printf("Отсортированный массив структур:");
		OutputArrayName(newStructArray, studentSize); // печатаем наш отстортированный массив структур
	}
	delete [] structArray;
	delete[] newStructArray;
	system("pause");
}

void InputStudent(Student& student, int studentSize)

{
	printf("Введите фамилию: ");
	scanf("%s", &student.surname);
	printf("\n");

	student.firstEx = 0;
	while (student.firstEx <= 0 || student.firstEx > 5)
	{
		printf("Введите оценку за первый экзамен: ");
		scanf("%d", &student.firstEx);
		printf("\n");
	}

	student.secondEx = 0;
	while (student.secondEx <= 0 || student.secondEx > 5)
	{
		printf("Введите оценку за второй экзамен: ");
		scanf("%d", &student.secondEx);
		printf("\n");
	}

	student.thirdEx = 0;
	while (student.thirdEx <= 0 || student.thirdEx > 5)
	{
		printf("Введите оценку за третий экзамен: ");
		scanf("%d", &student.thirdEx);
		printf("\n");
	}
}

void OutputArrayName(Student *structArray, int studentSize)
{
	for (int i = 0; i < studentSize; i += 1)
	{
		printf("%d: %s: %d, %d, %d \n", (i + 1), structArray[i].surname, structArray[i].firstEx, structArray[i].secondEx, structArray[i].thirdEx);
	}
}

void SortStructArray(Student *structArray, int studentSize)
{
	for (int i = 1; i < studentSize; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(structArray[j - 1].surname, structArray[j].surname) < 0)
			{
				Exchange(structArray[j - 1], structArray[j]);
			}
			else break;
		}
	}
}

void Exchange(Student& student1, Student& student2)
{
	Student buf;
	strcpy(buf.surname,student1.surname);
	buf.firstEx = student1.firstEx;
	buf.secondEx = student1.secondEx;
	buf.thirdEx = student1.thirdEx;
	strcpy(student1.surname, student2.surname);
	student1.firstEx = student2.firstEx;
	student1.secondEx = student2.secondEx;
	student1.thirdEx = student2.thirdEx;
	strcpy(student2.surname, buf.surname);
	student2.firstEx = buf.firstEx;
	student2.secondEx = buf.secondEx;
	student2.thirdEx = buf.thirdEx;
}

void finfStudent(Student* structArray, int studentSize, Student& newStructArray, int &newStudentSize) {
	newStudentSize = 0;
	for (int i = 0; i < studentSize; i++)
	{
		if ((structArray->firstEx + structArray->secondEx + structArray->thirdEx) / 3 < 3.5)
		{
			newStudentSize++;
		}
	}
	Student* newStructArray = new Student[newStudentSize];
	if (newStudentSize == 0)
	{
		printf("В массиве структур нет студентов со средним баллом меньше 3.5 \n");
	}
	else
	{
		for (int i = 0; i < studentSize; i++)
		{
			if ((structArray->firstEx + structArray->secondEx + structArray->thirdEx) / 3 < 3.5)
			{
				strcpy(newStructArray->surname, structArray->surname);
				newStructArray->firstEx = structArray->firstEx;
				newStructArray->secondEx = structArray->secondEx;
				newStructArray->thirdEx = structArray->thirdEx;
			}
		}
	}
	return newStructArray;
}