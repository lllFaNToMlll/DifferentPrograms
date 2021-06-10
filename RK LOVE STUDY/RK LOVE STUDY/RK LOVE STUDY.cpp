// RK LOVE STUDY.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "ctime"

using namespace std;
void vvod(int* arrayPtr, int length)// ввод массива
{
    for (int i = 0; i < length; i++)
        cin >>arrayPtr[i]; //arrayPtr[i] = rand() % 100 - 50;
}
void vivod(int* arrayPtr, int length)// вывод массива
{
    for (int i = 0; i < length; i++) {
        cout << arrayPtr[i] << " ";
    }
    cout << endl;
}

void choicesSort(int* arrayPtr, int length) // сортировка методом поиска мин/макс элемента
{
    for (int i = 0; i < length; i++)
    {
        // В переменной minIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
        // Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
        int minIndex = i;
        // Затем ищем элемент поменьше в остальной части массива
        for (int j = i + 1; j < length; j++)
        {
            // Если мы нашли элемент, который меньше нашего наименьшего элемента
            if (arrayPtr[minIndex] > arrayPtr[j])
                // то запоминаем его
                minIndex = j;
        }
        // minIndex теперь наименьший элемент. 
        // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
        int buf = arrayPtr[i];
        arrayPtr[i] = arrayPtr[minIndex];
        arrayPtr[minIndex] = buf;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int length = -1; // длинна массива 
    while (length <= 0) {
        cout << "Введите размер массива: ";
        cin >> length; //задаем размер
    }
    int* myArray = new int[length]; // одномерный динамический массив. Выделяем под него память

    vvod(myArray, length);// подпрограмма заполнения массива случайными числами

    vivod(myArray, length);// подпрограмма вывода массива

    choicesSort(myArray, length); // вызов функции сортировки вставками

    vivod(myArray, length);// подпрограмма вывода массива

    delete[] myArray; // высвобождаем память
    system("pause");
    return 0;
}

