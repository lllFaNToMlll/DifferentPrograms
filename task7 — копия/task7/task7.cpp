// task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale.h>

double Factorial(int N)//подпрограмма для нахождения факториала
{
    double F = 1;
    for (int i = 1; i <= N; ++i)
    {
        F *= i; 
    }
    return F; 
}

double FirstTask(double x, double N) {
    double sum = 1;
    for (int i = 1; i < N+1; i++){
        sum += pow(-1, i) * pow(x, i * 2) / Factorial(i * 2 + 1);//вычисляем знак элемента, затем числитель и знаменатель
    }
    return sum;
}

double SecondTask(double x, double E1, double &counter) {
    double sumBiggerThanE = 1, elem = pow(-1, 1) * pow(x, 1 * 2) / Factorial(1 * 2 + 1);
    for (int i = 1; abs(elem) > E1; i++) {
        elem = pow(-1, i) * pow(x, i * 2) / Factorial(i * 2 + 1);
        if (abs(elem) > E1) {
            sumBiggerThanE += elem;//вычисляем знак элемента, затем числитель и знаменатель
            counter++;//считаем количество элементов
        }
    }
    return sumBiggerThanE;
}

void ThirdTask(double x, double E1,double E2) {
    double sumBiggerThanE1 = 1, counter1 = 0, counter2 = 0, sumBiggerThanE2 = 1, elem = pow(-1, 1) * pow(x, 1 * 2) / Factorial(1 * 2 + 1);
    for (int i = 1; abs(elem) > E1; i++) {
        elem = pow(-1, i) * pow(x, i * 2) / Factorial(i * 2 + 1);
        if (abs(elem) > E1) {
            sumBiggerThanE1 += elem;//вычисляем знак элемента, затем числитель и знаменатель
            counter1++;//считаем количество элементов
        }
        if (abs(elem) > E2) {
            sumBiggerThanE2 += elem;//вычисляем знак элемента, затем числитель и знаменатель
            counter2++;//считаем количество элементов
        }
    }
    printf("Cумма методом элементов > E1 = %2.5lf, количетсво таких элементов = %2.1lf.\n"
        "Cумма методом элементов > E2 = %2.5lf, количетсво таких элементов = %2.1lf\n ", sumBiggerThanE1, counter1, sumBiggerThanE2, counter2);
}

double FourthTask(double X) {
    if (X == 0)
        return 1;
    if (X > 100000)
        return 0;
    return (sin(X) / X);
}

int main()
{
    //делаем так, чтобы можно было печатать на русском языке
    setlocale(LC_ALL, "Russian");
    //определяем переменные
    double x = 0, N = 0, E = 0, sum = 1, sumBiggerThanE1 = 0, counter1 = 0, result = 0;
    //определяем переменную, которая будет показывать выбор пользователя:
    //1 - вычислить функцию методом суммы для N чисел
    //2 - вычислить функцию методом суммы чисел, которые по абсолютной величине больше E
    //3 - нахождение функции методом суммы и количества для двух Е, которые отличаются на порядок
    //4 - сравнение полученного приближенного результата с точным значением функции
    //0 - выйти из программы
    int userChoice = -1;
    while (userChoice != 0) {
        while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 0) {
            printf("Выберите нужную функцию:\n "
                "1 - вычислить функцию методом суммы для N чисел\n "
                "2 - вычислить функцию методом суммы чисел, которые по абсолютной величине больше E\n "
                "3 - нахождение функции методом суммы и количества элементов между двумя Е, которые отличаются на порядок\n "
                "4 - точное значение функции\n "
                "0 - выйти из программы\n ");
            scanf("%d",&userChoice);
        }
        if (userChoice == 1) {
            //инициализируем переменные
            printf("Введите значение Х:");
            scanf("%lf", &x);
            printf("Введите значение N:");
            scanf("%lf", &N);
            //осуществляем выполнение приближенного нахождения значения нашей функции
            sum = FirstTask(x, N);
            printf("Сумма методом N элементов = %2.5lf\n ", sum);
            system("pause");
            system("cls");
        }
        if (userChoice == 2) {
            counter1 = 0;
            //инициализируем переменные
            printf("Введите значение Х:");
            scanf("%lf", &x);
            printf("Введите значение E:");
            scanf("%lf", &E);
            //осуществляем выполнение приближенного нахождения значения нашей функции
            sumBiggerThanE1 = SecondTask(x, E, counter1);
            printf("Cумма методом элементов > E = %2.5lf, количетсво таких элементов = %2.1lf\n ", sumBiggerThanE1, counter1);
            system("pause");
            system("cls");
        }
        if (userChoice == 3) {
            //инициализируем переменные
            printf("Введите значение Х:");
            scanf("%lf", &x);
            printf("Введите значение E1 (значение Е2 будет на 1 порядок больше):");
            scanf("%lf", &E);
            //осуществляем выполнение приближенного нахождения значения нашей функции
            ThirdTask(x, E, E*10);
            system("pause");
            system("cls");
        }
        if (userChoice == 4) {
            //инициализируем переменные
            printf("Введите значение Х:");
            scanf("%lf", &x);
            //осуществляем выполнение приближенного нахождения значения нашей функции
            result = FourthTask(x);
            printf("Точное значение функции = %2.5lf\n ", result);
            system("pause");
            system("cls");
        }
        if (userChoice != 0)
            userChoice = -1;
    }
    printf("Спасибо, что воспользовались моей программой! Удачного Вам дня!\n");
    system("pause");
}