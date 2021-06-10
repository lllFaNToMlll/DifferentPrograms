// HW_task6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#include "ctime"

/*
while (a > b)
{
    if (a % 2 == 0 && a / 2 >= b)
    {
        cout << ":2" << endl;
        a /= 2;
    }
    else
    {
        cout << -1 << endl;
        a--;
    }
}*/

void main()
{
    //для того, чтобы каждый раз была случайная матрица
    srand(time(NULL));
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    int A = -1, B = -1;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Преобразовать число А в В с помощью цикла While
    //2 - Преобразовать число А в В с помощью цикла For
    //3 - Преобразовать число А в В с помощью бесконечного цикла и оператора Break
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 0) {
            std::cout << "Выберите нужную функцию:\n "
                "1 - Преобразовать число А в В с помощью цикла While\n "
                "2 - Преобразовать число А в В с помощью цикла For\n "
                "3 - Преобразовать число А в В с помощью бесконечного цикла и оператора Break\n "
                "0 - выйти из программы " << std::endl;
            std::cin >> userChoice;
            std::cout << std::endl;
        }
        if (userChoice == 1) {
            // инициализируем переменные А и В 
            while (B < 1)
            {
                std::cout << "Введите значение числа В: ";
                std::cin >> B;
                std::cout << std::endl;
            }
            while (A < 1 || A < B)
            {
                std::cout << "Введите значение числа A (A > B): ";
                std::cin >> A;
                std::cout << std::endl;
            }
            // Цикл While
            while (A > B)
            {
                if (A % 2 == 0 && A / 2 >= B)
                {
                    std::cout << "Выполняем команду (2)" << std::endl;
                    A /= 2;
                }
                else
                {
                    std::cout << "Выполняем команду (-1)" << std::endl;
                    A--;
                }
                std::cout << "Значение А на текущий момент: " << A << std::endl;
            }
            std::cout << "Цикл While завершился" << std::endl;
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            // инициализируем переменные А и В 
            while (B < 1)
            {
                std::cout << "Введите значение числа В: ";
                std::cin >> B;
                std::cout << std::endl;
            }
            while (A < 1 || A < B)
            {
                std::cout << "Введите значение числа A (A > B): ";
                std::cin >> A;
                std::cout << std::endl;
            }
            // Цикл For
            for (size_t i = 1; A > B; i++)
            {
                if (A % 2 == 0 && A / 2 >= B)
                {
                    std::cout << "Выполняем команду (2)" << std::endl;
                    A /= 2;
                }
                else
                {
                    std::cout << "Выполняем команду (-1)" << std::endl;
                    A--;
                }
                std::cout << "Значение А на " << i << "-ом шаге" << ": " << A << std::endl;
            }
            std::cout << "Цикл For завершился" << std::endl;
            system("pause");
            system("cls");
        }
        if (userChoice == 3) {
            // инициализируем переменные А и В 
            while (B < 1)
            {
                std::cout << "Введите значение числа В: ";
                std::cin >> B;
                std::cout << std::endl;
            }
            while (A < 1 || A < B)
            {
                std::cout << "Введите значение числа A (A > B): ";
                std::cin >> A;
                std::cout << std::endl;
            }
            // бесконечный цикл
            while (1 > 0)
            {
                if (A % 2 == 0 && A / 2 >= B)
                {
                    std::cout << "Выполняем команду (2)" << std::endl;
                    A /= 2;
                }
                else
                {
                    std::cout << "Выполняем команду (-1)" << std::endl;
                    A--;
                }
                std::cout << "Значение А на текущий момент: " << A << std::endl;
                if (A == B)
                    break;
            }
            std::cout << "Бесконечный цикл завершился с помощью оператора Break" << std::endl;
            system("pause");
            system("cls");
        }
        // изменяем переменные А и В для нового ввода
        A = -1;
        B = -1;
        if (userChoice != 0)
            userChoice = -1;
    }
    std::cout << "Спасибо, что воспользовались моей программой! Удачного Вам дня!" << std::endl;
    system("pause");
}