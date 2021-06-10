#include <iostream>
#include "MyString.h"
using namespace std;

//конструктор по умолчанию
MyString::MyString(){
	myStr = nullptr;
	countOfStrings++;
}

//конструктор
MyString::MyString(const char* str) {
	myStr = new char[strlen(str) + 1];
	strcpy(myStr, str);
	countOfStrings++;
}

//конструктор копирования
MyString::MyString(const MyString& myString) : myStr(myString.myStr) { countOfStrings++; }

//метод конкатенации двух строк
void MyString::koncat(const MyString& str2) {
	strcat(this->myStr, str2.myStr);
}

//метод вставки второй строки на определенное место в первой (после n символа)
void MyString::koncatAtPos(const MyString& str2, int n) {
	//проверка на то, что n меньше либо равен длинне строки 1
	if (n > strlen(this->myStr) || n < 0 ) {
		cout << "Вы ввели недопустимую позицию вставки. Вставка в строку не произошла" << endl;
		return ;
	}
	//создаем буфер
	MyString bufMyStr(this->myStr);
	countOfStrings--;
	delete[] this->myStr;
	this->myStr = new char[strlen(bufMyStr.myStr) + strlen(str2.myStr) + 1];
	//создаем счетчик, чтобы правильно продолжить запись первой строки
	int counter = 0;
	//запускаем цикл по длинне первой строки, чтобы найти нужное место вставки
	for (int i = 0; i < strlen(this->myStr); i++)
	{
		//если находим нужное место, то запускаем цикл длинной второй строки, чтобы вставить его в первую строку
		if (i == n) {
			for (int j = 0; j < strlen(str2.myStr); j++)
			{
				this->myStr[j + i] = str2.myStr[j];
				//увеличиваем счетчик, чтобы правильно продолжить запись первой строки
				counter++;
			}
			counter--;
		}
		else {
			if (counter != 0)
				this->myStr[i + counter] = bufMyStr.myStr[i - 1];
			else
				this->myStr[i] = bufMyStr.myStr[i];
		}
	}
}

//метод подсчета длины строки
int MyString::sizeOfMyString() {
	return strlen(this->myStr);
}

//метод очистки строки
void MyString::clearMyString() {
	delete this->myStr;
	this->myStr = new char[1];
	this->myStr[0] = '\0';
}

//метод сравнения двух строк
//сравнивает строку s1 со строкой s2 и возвращает результат типа int: 
//0 –если строки эквивалентны, >0 – если s1<s2,  <0  — если s1>s2 С учётом регистра
int MyString::compareMyStrings(const MyString& str2) {
	return strcmp(this->myStr, str2.myStr);
}

//сеттер 
void MyString::SetMyStr(const char* str) {
	this->myStr = new char[strlen(str) + 1];
	strcpy(this->myStr, str);
}

int MyString::countOfStrings = 0;

//геттер
char* MyString::GetMyStr() {
	return this->myStr;
}

//метод обращения строки
void MyString::reverseMyString() {
	MyString bufMyStr(this->myStr);
	countOfStrings--;
	for (int i = strlen(this->myStr) - 1, b = 0; i >= 0; i--, b++)
	{
		bufMyStr.myStr[b] = this->myStr[i];
	}
	strcpy(this->myStr, bufMyStr.myStr);
}

MyString& MyString::operator=(const MyString& s)
{
	if (this != &s) // проверка на присваивание самому себе
	{
		this->myStr = nullptr;
		this->myStr = new char[strlen(s.myStr) + 1];
		strcpy(this->myStr, s.myStr);
	}
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	if (this->myStr != s) // проверка на присваивание самому себе
	{
		this->myStr = nullptr;
		this->myStr = new char[strlen(s) + 1];
		strcpy(this->myStr, s);
	}
	return *this;
}

//деструктор
MyString::~MyString() {
	delete[] myStr;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.myStr;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
	char BUFF[2048];
	is >> BUFF;
	obj = BUFF;
	return is;
}