// task7Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"

// функция заполнения матрицы случайными числами от -50 до 50
void randomVvod(int** myMatrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            *(*(myMatrix + i) + j) = rand() % 100 - 50;// рандомное заполнение матрицы элементами от -50 до 50
}

// функция вывода исходной матрицы
void vivod(int** myMatrix, int n)
{
    std::cout << "Вывод исходной матрицы" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%6d", *(*(myMatrix + i) + j));
        printf("\n");
    }
}

// функция нахождение последнего минимального элемента и его индексов выше главной диагонали и на ней
int findMin(int** myMatrix, int n, int& str, int& col)
{
    int min = 100000;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (min >= *(*(myMatrix + i) + j))
            {
                min = *(*(myMatrix + i) + j);
                str = i;
                col = j;
            }
    }
    return min;
}

// фунция нахождения произведения элементов выбранной строки
int findMulti(int** myMatrix, int n, int index)
{
    int i = index;
    int multi = 1;
    for (int j = 0; j < n; j++)
    {
        multi *= *(*(myMatrix + i) + j);
    }
    return multi;
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int** myMatrix; // матрица
    int n, str, col; // размер матрицы
    //определяем переменную, которая будет показывать выбор пользователя:
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - Найти значение минимального элемента и его индексы на главной диагонали и выше\n "
                "2 - Найти произведение элементов в указанной пользователем строке\n "
                "0 - выйти из программы\n ");
            scanf("%d", &userChoice);
        }
        if (userChoice == 1) {
            //инициализируем переменные
            n = -1;
            // выполняем проверку размера
            while (n <= 0) {
                printf("Введите размер матрицы n: ");
                scanf("%d", &n);//задаем размер
            }
            // выделяем память под исходную матрицу
            myMatrix = new int* [n]; // выделяем память под первый элемент каждого массива (строки матрицы)
            for (int i = 0; i < n; i++)
            {
                myMatrix[i] = new int[n]; //выделяем память под каждый массив (строку матрицы)
            }
            randomVvod(myMatrix, n);
            vivod(myMatrix, n);
            int minElem;
            minElem = findMin(myMatrix, n, str, col);
            printf("Минимальный элемент выше главной диагонали и на ней: %d, его индексы: [%d][%d] \n", minElem, str, col);
            for (int i = 0; i < n; i++) // отчистка памяти, выделенной под каждый массив (строку матрицы)
                delete[] myMatrix[i];
            delete[] myMatrix; // отчистка памяти, выделенной под первый элемент каждого массива (строки матрицы)
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            //инициализируем переменные
            n = -1;
            // выполняем проверку размера
            while (n <= 0) {
                printf("Введите размер матрицы n: ");
                scanf("%d", &n);//задаем размер
            }
            // выделяем память под исходную матрицу
            myMatrix = new int* [n]; // выделяем память под первый элемент каждого массива (строки матрицы)
            for (int i = 0; i < n; i++)
            {
                myMatrix[i] = new int[n]; //выделяем память под каждый массив (строку матрицы)
            }
            randomVvod(myMatrix, n);
            vivod(myMatrix, n);
            int multi;
            str = -1;
            while (str <= 0 || str >= n) {
                printf("Введите строку матрицы, для которой хотите найти произведение: ");
                scanf("%d", &str);
            }
            multi = findMulti(myMatrix, n, str);
            printf("Произведение элементов [%d]-ой строки: %d \n", str, multi);
            for (int i = 0; i < n; i++) // отчистка памяти, выделенной под каждый массив (строку матрицы)
                delete[] myMatrix[i];
            delete[] myMatrix; // отчистка памяти, выделенной под первый элемент каждого массива (строки матрицы)
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
    system("pause");
}