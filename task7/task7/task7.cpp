// task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>


void main()
{
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    double result = 0, lastElem = 0, result2 = 0, element = M_PI / 2, E = 0, resultOfpow = 0;
    int x = 0, one = -1, counter = 0, counter2 = 0, N = 0;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - Ввести новое значение E
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - Ввести новое значение x и Е\n "
                "2 - Ввести новое значение х и Е (будет выполнено для 2-х Е, одно из которых на порядок больше)\n "
                "3 - Ввести новое значение x и N (Задание 1)\n "
                "0 - выйти из программы\n ");
            scanf("%d",&userChoice);
        }
        if (userChoice == 1) {
            //инициализируем переменные
            x = 0;
            while (x <= 1) {
                printf("Введите значение x > 1:");
                scanf("%d", &x);
            }
            printf("Введите значение E:"); 
            scanf("%lf", &E);
            //осуществляем вычисления
            element = M_PI/2;
            result = M_PI / 2;
            counter = 0;
            resultOfpow = x;
            for (int n = 1; abs(element) > E; n++)
            {
                //вычисляем 
                //вычисляем степень единицы(находим знак элемента)
                if (n % 2 == 0)// степень четная?
                    one = 1;//да = знак +
                else
                    one = -1;//нет = знак
                int i = 0;
                if (n != 1)
                    while (i < 2) {
                        resultOfpow *= x;
                        i++;
                    }
                element = one / ((2 * n - 1) * resultOfpow);
                result += element;
                counter++;
            }
            printf("Сумма = %4.5lf. Количество слагаемых N = %d\n ", result, counter);
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            //инициализируем переменные
            x = 0;
            while (x <= 1) {
                printf("Введите значение x > 1:");
                scanf("%d", &x);
            }
            printf("Введите значение E1 (E2 будет на порядок больше):");
            scanf("%lf", &E);
            //осуществляем вычисления
            element = M_PI / 2;
            result = M_PI / 2;
            result2 = M_PI / 2;
            counter = 0;
            resultOfpow = x;
            counter2 = 0;
            for (int n = 1; abs(element) > E; n++)
            {
                //вычисляем 
                //вычисляем степень единицы(находим знак элемента)
                if (n % 2 == 0)// степень четная?
                    one = 1;//да = знак +
                else
                    one = -1;//нет = знак -
                double buf = element; 
                int i = 0;
                if (n != 1)
                    while (i < 2) {
                        resultOfpow *= x;
                        i++;
                    }
                element = one / ((2 * n - 1) * resultOfpow);
                result += element;
                counter++;
                if (abs(buf) > E*10) {
                    result2 += element;
                    counter2++;
                }
            }
            printf("Сумма при Е1 : %4.5lf. Количество слагаемых N = %d\n", result, counter);
            printf("Сумма при E2 : %4.5lf. Количество слагаемых N = %d\n", result2, counter2);
            system("pause");
            system("cls");
        }
        if (userChoice == 3) {
            //инициализируем переменные
            x = 0;
            while (x <= 1) {
                printf("Введите значение x > 1:");
                scanf("%d", &x);
            }
            printf("Введите значение N:");
            scanf("%d", &N);
            //осуществляем вычисления
            element = M_PI / 2;
            result = M_PI / 2;
            counter = 0;
            resultOfpow = x;
            for (int n = 1; n <= N; n++)
            {
                //вычисляем 
                //вычисляем степень единицы(находим знак элемента)
                if (n % 2 == 0)// степень четная?
                    one = 1;//да = знак +
                else
                    one = -1;//нет = знак
                int i = 0;
                if (n != 1)
                    while (i < 2) {
                        resultOfpow *= x;
                        i++;
                    }
                element = one / ((2 * n - 1) * resultOfpow);
                result += element;
                lastElem = element;
            }
            printf("Сумма N элементов = %4.5lf.\n ", result);
            printf("Истинный результат функции = %4.5lf.\n ", atan(x));
            printf("Абсолютная погрешность полученного результата = %4.5lf.\n ", abs(atan(x) - result));
            if (abs(atan(x) - result) > lastElem){
                printf("Абсолютная погрешность полученного результата > абсолютной величины последнего элемента.\n ");
                printf("%4.5lf > %4.5lf.\n ", abs(atan(x) - result), abs(lastElem));
            }
            if (abs(atan(x) - result) == lastElem) {
                printf("Абсолютная погрешность полученного результата = абсолютной величины последнего элемента.\n ");
                printf("%4.5lf = %4.5lf.\n ", abs(atan(x) - result), abs(lastElem));
            }
            if (abs(atan(x) - result) < lastElem) {
                printf("Абсолютная погрешность полученного результата < абсолютной величины последнего элемента.\n ");
                printf("%4.5lf < %4.5lf.\n ", abs(atan(x) - result), abs(lastElem));
            }
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
    system("pause");
}