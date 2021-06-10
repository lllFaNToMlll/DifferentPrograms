// Task2Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include "MyString.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //конструктор
    MyString str1;
    //конструктор с параметрами
    MyString str2("hi");
    cout << "конструктор с параметрами" << endl << str2 << endl;
    //конструктор копирования
    MyString str3(str2);
    cout << "конструктор копирования" << endl << str3 << endl;
    //оператор ввода
    cout << "оператор ввода" << endl << "Введите строку" << endl;
    cin >> str1;
    //оператор вывода
    cout << "оператор вывода" << endl << "Строка:" << str1 << endl;
    //метод обращения строки
    cout << "метод обращения строки" << endl;
    cout << "Введите строку" << endl;
    cin >> str1;
    str1.reverseMyString();
    cout << str1 << endl;
    //конкатенация
    cout << "метод конкатенации" << endl;
    cout << "Введите строку 1" << endl;
    cin >> str1;
    cout << "Введите строку 2" << endl;
    cin >> str2;
    str1.koncat(str2);  
    cout << "Итоговая строка: " << str1 << endl;
    //метод конкатенации после n симовола в строке 1
    cout << "метод конкатенации после n симовола в строке 1" << endl;
    cout << "Введите строку 1" << endl;
    cin >> str1;
    cout << "Введите строку 2" << endl;
    cin >> str2;
    cout << "Введите номер символа в первой строке, после которого хотите вставить слово 2" << endl;
    int n;
    cin >> n;
    str1.koncatAtPos(str2, n);
    cout << "Итоговая строка: " << str1 << endl;
    //метод сравнения двух строк
    //сравнивает строку s1 со строкой s2 и возвращает результат типа int: 
    //0 –если строки эквивалентны, >0 – если s1<s2,  <0  — если s1>s2 С учётом регистра
    cout << "метод сравнения двух строк" << endl;
    cout << "Введите строку 1" << endl;
    cin >> str1;
    cout << "Введите строку 2" << endl;
    cin >> str2;
    int i = str1.compareMyStrings(str2);
    cout << "результат(0 – строки эквивалентны, >0 – s1<s2, <0 — s1>s2): " << i << endl;
    //метод размер строки
    cout << "Метод размер строки. Введите строку 1" << endl;
    cin >> str1;
    int size = str1.sizeOfMyString();
    cout << "Размер строки: " << size << endl;
    //метод очистки строки
    cout << "Метод очистки строки. Введите строку 1" << endl;
    cin >> str1;
    cout << "Ваша строка: " << str1 << endl;
    str1.clearMyString();
    cout << "Ваша строка после очистки: " << str1 << endl;
    //метод сеттер и геттер
    cout << "Метод сеттер. Введите слово, которое хотите присвоить" << endl;
    char* buf1 = new char[100];
    cin >> buf1;
    str1.SetMyStr(buf1);
    cout << "Метод геттер" << endl;
    char* buf2 = str1.GetMyStr();
    cout << "Ваша строка после метода сеттер(вывод через геттер): " << buf2 << endl;
    //оператор присваивания
    cout << "оператор присваивания" << endl;
    cout << "Введите строку 1" << endl;
    cin >> str1;
    cout << "Введите строку 2" << endl;
    cin >> str2;
    str1 = str2;
    cout << "*приравниваем строку 1 к строке 2 и выводим строку 1* Результат: " << str1 << endl;
    cout << "Количество созданных объектов: " << MyString::getCountStrings() << endl;
    system("pause");
}