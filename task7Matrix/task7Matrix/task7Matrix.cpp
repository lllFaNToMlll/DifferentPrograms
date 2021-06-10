// task7Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*7) В квадратной матрице А(nХn) определить количество строк
a) упорядоченных по возрастанию;
b) упорядоченных по убыванию;
c) состоящих из равных элементов;
d) неупорядоченных.
*/
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

// функция заполнения матрицы вручную
void handVvod(int** myMatrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Введите значение [%d][%d] элемента матрицы: ", i, j);
            scanf("%d", &*(*(myMatrix + i) + j));// ручное заполнение матрицы элементами
        }
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

// функция, которая определяет, является ли строка матрицы упорядоченной по возрастанию или нет
bool isLowToHigh(int** myMatrix, int n, int index) {
    int i = index;
    bool flag = true;
    for (int j = 0; j < n - 1; j++)
        if (*(*(myMatrix + i) + j) >= * (*(myMatrix + i) + j+1)) {
            flag = false;
            break;
        }
    return flag;
}

// функция, которая определяет, является ли строка матрицы упорядоченной по убыванию или нет
bool isHighToLow(int** myMatrix, int n, int index) {
    int i = index;
    bool flag = true;
    for (int j = 0; j < n - 1; j++)
        if (*(*(myMatrix + i) + j) <= * (*(myMatrix + i) + j + 1)) {
            flag = false;
            break;
        }
    return flag;
}

// функция, которая определяет, состоит ли строка матрицы из одинаковых элементов
bool isEqual(int** myMatrix, int n, int index) {
    int i = index;
    bool flag = true;
    for (int j = 0; j < n - 1; j++)
        if (*(*(myMatrix + i) + j) != *(*(myMatrix + i) + j + 1)) {
            flag = false;
            break;
        }
    return flag;
}
/*7) В квадратной матрице А(nХn) определить количество строк
a) упорядоченных по возрастанию;
b) упорядоченных по убыванию;
c) состоящих из равных элементов;
d) неупорядоченных.
*/
// функция вывода информации о матрице (см. задание выше)
void mantrixInfo(int** myMatrix, int n)
{
    // инициализируем переменные-счетчики
    int lowToHighCounter = 0; //  счетчик строк упорядоченных по возрастанию;
    int highToLowCounter = 0; //  счетчик строк упорядоченных по убыванию;
    int equalCounter = 0; //  счетчик строк состоящих из равных элементов;
    int disorderedCounter = 0; //  счетчик неупорядоченных строк.

    // инициализируем переменные-флажки упорядоченности и равности
    bool lowToHighFlag = true; // флаг упорядоченности по возрастанию
    bool highToLowFlag = true; // флаг упорядоченности по убыванию
    bool equalFlag = true; // флаг равных элементов

    // запускаем цикл по всем строкам матрицы
    for (int i = 0; i < n; i++)
    {
        lowToHighFlag = isLowToHigh(myMatrix, n, i); // проверяем строку на упорядоченность по возрастанию
        highToLowFlag = isHighToLow(myMatrix, n, i); // проверяем строку на упорядоченность по убыванию
        equalFlag = isEqual(myMatrix, n, i); // состоит ли строка только из одинаковых элементов

        if (lowToHighFlag == true) // если упорядоченна по возрастанию 
            lowToHighCounter++; // то увеличиваем соответствующий счетчик 

        if (highToLowFlag == true) // если упорядоченна по убыванию 
            highToLowCounter++; // то увеличиваем соответствующий счетчик

        if (equalFlag == true) // если состоит только из одинаковых элементов
            equalCounter++; // то увеличиваем соответствующий счетчик

        if (lowToHighFlag == false && highToLowFlag == false || equalFlag == true) // если неупорядоченна
            disorderedCounter++; // то увеличиваем соответствующий счетчик
    }
    printf(" Количество упорядоченных строк по возрастанию: %d\n ", lowToHighCounter);
    printf("Количество упорядоченных строк по убыванию: %d\n ", highToLowCounter);
    printf("Количество строк, состоящих только из одинаковых элементов: %d\n ", equalCounter);
    printf("Количество неупорядоченных строк: %d\n ", disorderedCounter);
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int** myMatrix; // матрица
    int n; // размер матрицы
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Создать новую случайную матрицу, состоящую из элементов от -50 до 50 
    //2 - Создать новую матрицу и заполнить вручную
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - Создать новую случайную матрицу, состоящую из элементов от -50 до 50\n "
                "2 - Создать новую матрицу и заполнить вручную\n "
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
            mantrixInfo(myMatrix, n);
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
            handVvod(myMatrix, n);
            vivod(myMatrix, n);
            mantrixInfo(myMatrix, n);
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