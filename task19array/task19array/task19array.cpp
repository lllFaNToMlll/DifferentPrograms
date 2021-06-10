// task19array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"
using namespace std;
void randomVvod(int* a, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        a[i] = rand() % 100 - 50;
}

void rucnoiVvod(int* a, int arraySize)
{
    int buf;
    for (int i = 0; i < arraySize; i++) {
        printf("\nВведите элемент массива: ");
        scanf("%d", &buf);//вводим вручную элемент массива
        a[i] = buf;
    }
}

void vivod(int* a, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

int findZeroAndMax(int* a, int arraySize)
{
    int indexZero = -1;
    for (int i = 0; i < arraySize; i++)
    {
        if (a[i] == 0) 
        {
            indexZero = i;
        }
    }
    return indexZero;
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int* myArray, arraySize, indexZero;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Создать случайный массив, состоящий из элементов от -50 до 50, и найти в нем последний нулевой элемент
    //2 - Создать и заполнить вручную массив и найти в нем последний нулевой элемент
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - Создать случайный массив, состоящий из элементов от -50 до 50, и найти в нем последний нулевой элемент\n "
                "2 - Создать и заполнить вручную массив и найти в нем последний нулевой элемент\n "
                "0 - выйти из программы\n ");
            scanf("%d", &userChoice);
        }
        if (userChoice == 1) {
            //инициализируем переменные
            arraySize  = -1;
            while (arraySize <= 0) {
                printf("Введите размер массива n: ");
                scanf("%d", &arraySize);//задаем размер
            }
            myArray = new int[arraySize];
            randomVvod(myArray, arraySize);
            vivod(myArray, arraySize);
            indexZero = findZeroAndMax(myArray, arraySize);
            if (indexZero == -1)
            {
                printf(" В массиве нет нулевых элементов!\n ");
            }
            else
            {
                printf(" Индекс последнего нулевого элемента = %d;\n ", indexZero);
            }
            delete[] myArray; //отчистка памяти, которую мы выделили под массив
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            //инициализируем переменные
            arraySize = -1;
            while (arraySize <= 0) {
                printf("Введите размер массива n: ");
                scanf("%d", &arraySize);//задаем размер
            }
            myArray = new int[arraySize];
            rucnoiVvod(myArray, arraySize);
            vivod(myArray, arraySize);
            indexZero = findZeroAndMax(myArray, arraySize);
            if (indexZero == -1)
            {
                printf(" В массиве нет нулевых элементов!\n ");
            }
            else
            {
                printf(" Индекс последнего нулевого элемента = %d;\n ", indexZero);
            }
            delete[] myArray; //отчистка памяти, которую мы выделили под массив
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
    system("pause");
}