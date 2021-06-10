// HW_task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"

// функция заполнения массива случайными числами от -50 до 50
void vvod(int* myArray, int N)
{
    for (int i = 0; i < N; i++)
        myArray[i] = rand() % 100 - 50; // рандомное заполнение массива элементами от -50 до 50
}

// функция вывода исходного массива
void vivod(int* myArray, int N)
{
    std::cout << "Вывод исходного массива" << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << myArray[i] << "\t";
    std::cout << std::endl;
}

// функция нахождения пары элементов с максимальной разностью
void findPair(int* myArray, int N)
{
    int maxDiff = -10000, pairIndex;
    for (int i = 0; i < N - 1; i++)
    {
        // находим модуль разности между элементами
        if (abs(myArray[i] - myArray[i + 1]) > maxDiff)
        {
            maxDiff = abs(myArray[i] - myArray[i + 1]);
            pairIndex = i;
        }
    }
    std::cout << "Индексы пары элементов с максимальной разностью: " << pairIndex << ", " << pairIndex + 1 << std::endl;
    std::cout << "Их разность равна (по модулю): " << maxDiff << std::endl;
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int* myArray, N;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Создать случайный массив, состоящий из элементов от -50 до 50, и найти в нем пару с максимальной разностью
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 0) {
            std::cout << "Выберите нужную функцию:\n "
                "1 - Создать случайный массив, состоящий из элементов от -50 до 50, и найти в нем пару с максимальной разностью\n "
                "0 - выйти из программы " << std::endl;
            std::cin >> userChoice;
            std::cout << std::endl;
        }
        if (userChoice == 1) {
            //инициализируем переменные
            N = -1;
            while (N <= 0) {
                std::cout << "Введите размер массива n: ";
                std::cin >> N;//задаем размер
                std::cout << std::endl;
            }
            myArray = new int[N];
            vvod(myArray, N);
            vivod(myArray, N);
            findPair(myArray, N);
            delete[] myArray; //отчистка памяти, которую мы выделили под массив
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    std::cout << "Спасибо, что воспользовались моей программой! Удачного Вам дня!" << std::endl;
    system("pause");
}