#pragma once
#include <iostream>
using namespace std;

class MyString {
    char* myStr;
public:
    static int countOfStrings;
    //конструктор по умолчанию
    MyString();
    //конструктор
    MyString(const char* str);
    //конструктор копировани€
    MyString(const MyString& myString);
    //метод конкатенации двух строк
    void koncat(const MyString& str2);
    //метод вставки второй строки на определенное место в первой (после n символа)
    void koncatAtPos(const MyString& str2, int n);
    //метод подсчета длины строки
    int sizeOfMyString();
    //метод очистки строки
    void clearMyString();
    //метод сравнени€ двух строк
    //сравнивает строку s1 со строкой s2 и возвращает результат типа int: 
    //0 Цесли строки эквивалентны, >0 Ц если s1<s2,  <0  Ч если s1>s2 — учЄтом регистра
    int compareMyStrings(const MyString& str2);
    //сеттер 
    void SetMyStr(const char* str);
    //геттер
    char* GetMyStr();
    //метод обращени€ строки
    void reverseMyString();
    MyString& operator=(const MyString& s);
    MyString& operator=(const char* s);
    //деструктор
    ~MyString();
    //метод получени€ количества созданных объектов
    static int getCountStrings() {
        return countOfStrings;
    }
    //операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream&, const MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};