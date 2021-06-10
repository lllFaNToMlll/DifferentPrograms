// task7array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"
using namespace std;
void vvod(int* a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100 - 50;
}
void vivod(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

void shiftLeft(int* a, int n, int k)
{
    while (k != 0) {
        const int buf = a[0];
        for (int i = 1; i < n; i++)
            a[i - 1] = a[i];
        a[n - 1] = buf;
        k--;
    }
}

void shiftRight(int* a, int n, int k)
{
    while (k != 0) {
        const int buf = a[n - 1];
        for (int i = n - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = buf;
        k--;
    }
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int* myArray, n, k;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Ввести новое значение k n и сдвиг влево
    //2 - Ввести новое значение k n и сдвиг вправо
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - Ввести новое значение k n и сдвиг влево\n "
                "2 - Ввести новое значение k n и сдвиг вправо\n "
                "0 - выйти из программы\n ");
            scanf("%d", &userChoice);
        }
        if (userChoice == 1) {
            //инициализируем переменные
            n = -1;
            k = -1;
            while (n <= 0) {
                printf("Введите размер массива n: ");
                scanf("%d", &n);//задаем размер
            }
            myArray = new int[n];
            vvod(myArray, n);
            vivod(myArray, n);
            while (k <=0 || k >=5 || k > n) {
                printf("Введите количество, на которое нужно сдвинуть элементы массива влево (0<k<5 && k<n): ");
                scanf("%d", &k);//задаем размер
            }
            shiftLeft(myArray, n, k);
            printf("Измененный массив: \n");
            vivod(myArray, n);
            delete[] myArray; //отчистка памяти, которую мы выделили под массив
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            //инициализируем переменные
            n = -1;
            k = -1;
            while (n <= 0) {
                printf("Введите размер массива n: ");
                scanf("%d", &n);//задаем размер
            }
            myArray = new int[n];
            vvod(myArray, n);
            vivod(myArray, n);
            while (k <= 0 || k >= 5 || k > n) {
                printf("Введите количество, на которое нужно сдвинуть элементы массива вправо (0<k<5 && k<n): ");
                scanf("%d", &k);//задаем размер
            }
            shiftRight(myArray, n, k);
            printf("Измененный массив: \n");
            vivod(myArray, n);
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