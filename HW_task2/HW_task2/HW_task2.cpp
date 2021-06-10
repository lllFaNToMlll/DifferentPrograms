// HW_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*2. Составить программу, которая в каждой строке матрицы B(m,n), m≤10, n≤12, находит модуль суммы отрицательных элементов 
и сумму положительных элементов. Из найденных элементов сформировать матрицу C(m,3), в каждой строке которой первые два элемента - найденные суммы, 
а третий элемент равен -1, если первая сумма больше второй, 0, если они равны, 1, если вторая сумма больше первой.
Вывести исходную и полученную матрицы так, чтобы в каждой строке сначала располагалась строка исходной матрицы, а затем строка полученной матрицы.*/

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"

// функция заполнения матрицы случайными числами от -50 до 50
void vvod(int** myMatrix, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            myMatrix[i][j] = rand() % 100 - 50; // рандомное заполнение матрицы элементами от -50 до 50
}

// функция вывода исходной матрицы
void vivod(int** myMatrix, int m, int n)
{
    std::cout << "Вывод исходной матрицы" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << myMatrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

// функция заполнения матрицы С (см задание)
void newMatrixC(int** myMatrix, int m, int n, int** matrixC)
{
    // Инициализируем переменные суммы модулей отрицательных элементов и положительных элементов строки
    int sumNeg = 0, sumPos = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // если элемент отрицательный, то прибавляем его к сумме модулей отрицательных элементов
            if (myMatrix[i][j] < 0)
                sumNeg += abs(myMatrix[i][j]);
            // иначе прибавляем его к сумме положительных элементов
            else
                sumPos += myMatrix[i][j];
        }
        // заполняем столбец матрица С, который состоит из суммы модулей отрицательных элементов
        matrixC[i][0] = sumNeg;
        // заполняем столбец матрица С, который состоит из суммы положительных элементов
        matrixC[i][1] = sumPos;
        // заполняем стол матрицы С, который состоит из чисел, показывающих, какая из из сумм больше (-1 sumNeg>, 0 равны, 1 sumPos>)
        if (sumNeg > sumPos)
            matrixC[i][2] = -1;
        else if (sumNeg == sumPos)
            matrixC[i][2] = 0;
        else if(sumNeg < sumPos)
            matrixC[i][2] = 1;
        // обнуляем наши суммы, чтобы найти их для следующей строки
        sumNeg = 0, sumPos = 0;
    }
}

void vivodResult(int** myMatrix, int m, int n, int** matrixC)
{
    std::cout << "Вывод исходной матрицы и матрицы результата (чередованием)" << std::endl;
    for (int i = 0; i < m; i++)
    {
        // выводим строку исходной матрицы
        for (int j = 0; j < n; j++)
            std::cout << myMatrix[i][j] << "\t";
        // спускаемся на строку ниже для вывода строки матрицы С
        std::cout << std::endl;
        // выводим строку матрицы С
        for (int k = 0; k < 3; k++)
        {
            std::cout << matrixC[i][k] << "\t";
        }
        // спускаемся на строку ниже для вывода строки исходной матрицы
        std::cout << std::endl;
    }
}

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int** myMatrix;
    int** matrixC;
    int m, n;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Создать новую случайную матрицу, состоящую из элементов от -50 до 50
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 0) {
            std::cout << "Выберите нужную функцию:\n "
                "1 - Создать новую случайную матрицу, состоящую из элементов от -50 до 50\n "
                "0 - выйти из программы" << std::endl;
            std::cin >> userChoice;
        }
        if (userChoice == 1) {
            //инициализируем переменные
            m = -1;
            // выполняем проверку размера
            while (m <= 0 || m > 10) {
                std::cout << "Введите размер массива m (m <= 10): " << std::endl;
                std::cin >> m; //задаем размер
            }
            n = -1;
            // выполняем проверку размера
            while (n <= 0 || n > 12) {
                std::cout << "Введите размер массива n (n <= 12): " << std::endl;
                std::cin >> n; //задаем размер
            }
            // выделяем память под исходную матрицу
            myMatrix = new int* [m];
            for (int i = 0; i < m; i++)
            {
                myMatrix[i] = new int[n];
            }
            // выделяем память под матрицу С
            matrixC = new int* [m];
            for (int i = 0; i < m; i++)
            {
                matrixC[i] = new int[3];
            }
            vvod(myMatrix, m, n);
            vivod(myMatrix, m, n);
            newMatrixC(myMatrix, m, n, matrixC);
            vivodResult(myMatrix, m, n, matrixC);
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    for (int i = 0; i < m; i++) // отчистка памяти, выделенной под строки исходной матрицы
        delete[] myMatrix[i];
    delete[] myMatrix; //удаление
    for (int i = 0; i < m; i++) // отчистка памяти, выделенной под строки матрицы C
        delete[] matrixC[i];
    delete[] matrixC; //удаление
    printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
    system("pause");
}