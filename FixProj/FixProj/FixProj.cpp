// FixProj.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

// создаем прототипы функций
void initMatrix(int** A, int n, int m); // функция инициализации матрицы случайными числами
void printMatrix(int** A, int n, int m); // функция вывода матрицы
void printSpiralMatrix(int** A, int n, int m); // функция вывода матрицы в строку,
                                               //читая по спирали от правого нижнего угла против часовой стрелки

int main()
{
	//для того, чтобы каждый раз была случайная матрица
	srand(time(NULL));
	//делаем так, чтобы можно было печатать на русском языке
	setlocale(LC_ALL, "Russian");
	int userChoice = -1; // инициализируем переменную, которая отвечает за выбор пользователя
	while (userChoice != 0) { // условие выхода из программы
		while (userChoice != 1 && userChoice != 0) { // проверка ввода
			printf("Выберите нужную функцию:\n "
				"1 - Создать новую случайную матрицу, состоящую из элементов от -50 до 50\n "
				"0 - выйти из программы\n ");
			scanf("%d", &userChoice);
		}
		if (userChoice == 1) {
			//инициализируем переменные
			int STROKES = -1, COLUMS = -1;
			// выполняем проверку размера
			while (STROKES <= 0) {
				printf("Введите количество строк матрицы: ");
				scanf("%d", &STROKES);//задаем размер
			}
			// выполняем проверку размера
			while (COLUMS <= 0) {
				printf("Введите количество столбцов матрицы: ");
				scanf("%d", &COLUMS);//задаем размер
			}
			// выделяем память под нашу матрицу
			int** A = (int**)malloc(STROKES * sizeof(int*));
			for (int i = 0; i < STROKES; i++) {
				A[i] = (int*)malloc(COLUMS * sizeof(int));
			}
			// инициализируем нашу матрицу
			initMatrix(A, STROKES, COLUMS);
			// выводим нашу матрицу
			printMatrix(A, STROKES, COLUMS);
			printf("\n Пишем элементы по спирали от правого нижнего угла против часовой стрелки: \n");
			// печатаем элементы нашей матрицы по спирали
			printSpiralMatrix(A, STROKES, COLUMS);
			// освобождаем память, выделенную под матрицу
			for (int i = 0; i < STROKES; i++) {
				free(A[i]);
			}
			free(A);
			printf("\n");
			system("pause");
			system("cls");
		}
		if (userChoice != 0) // открываем меню
			userChoice = -1;
	}
	printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
	system("pause");
}

void initMatrix(int** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % 100 - 50; // заполнение случайными числами от -50 до 50
		}
	}
}

void printMatrix(int** A, int n, int m) {
	printf("Матрица:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", A[i][j]); 
		}
		printf("\n");
	}
	return;
}

void printSpiralMatrix(int** A, int n, int m) {
	int elements = n * m; // количество элементов в матрице
	int lowStr = n-1, rightCol = m-1; // количество строк и столбцов для прохода по нижней и правой сторонах матрицы
	int highStr = 0, leftCol = 0; // количество строк и столбцов для прохода по верхней и левой сторонах матрицы
	while (elements != 0) // пока не прошлись по всем элементам
	{
		if (elements == 0) // если прошли по всем элементам, то выходим из цикла
			break;
		for (int j = rightCol; j >= leftCol; j--) // проходим по нижней стороне матрицы справа налево
		{
			printf("%4d", A[lowStr][j]);
			elements--; // уменьшаем количество оставшихся элементов
		}
		lowStr--; // уменьшаем количество оставшихся строк снизу
		if (elements == 0) // если прошли по всем элементам, то выходим из цикла
			break;
		for (int i = lowStr; i >= highStr; i--) // проходим по левой стороне матрицы снизу вверх
		{
			printf("%4d", A[i][leftCol]);
			elements--; // уменьшаем количество оставшихся элементов
		}
		leftCol++; // уменьшаем количество оставшихся строк слева
		if (elements == 0) // если прошли по всем элементам, то выходим из цикла
			break;
		for (int j = leftCol; j <= rightCol; j++) // проходим по верхней стороне матрицы слева направо
		{
			printf("%4d", A[highStr][j]);
			elements--; // уменьшаем количество оставшихся элементов
		}
		highStr++; // уменьшаем количество оставшихся строк сверху
		if (elements == 0) // если прошли по всем элементам, то выходим из цикла
			break;
		for (int i = highStr; i <= lowStr; i++) // проходим по правой стороне матрицы сверху вниз
		{
			printf("%4d", A[i][rightCol]);
			elements--; // уменьшаем количество оставшихся элементов
		}
		rightCol--; // уменьшаем количество оставшихся строк справа
	}
}