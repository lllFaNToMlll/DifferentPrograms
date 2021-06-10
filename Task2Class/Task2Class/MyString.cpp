#include <iostream>
#include "MyString.h"
using namespace std;

//����������� �� ���������
MyString::MyString(){
	myStr = nullptr;
	countOfStrings++;
}

//�����������
MyString::MyString(const char* str) {
	myStr = new char[strlen(str) + 1];
	strcpy(myStr, str);
	countOfStrings++;
}

//����������� �����������
MyString::MyString(const MyString& myString) : myStr(myString.myStr) { countOfStrings++; }

//����� ������������ ���� �����
void MyString::koncat(const MyString& str2) {
	strcat(this->myStr, str2.myStr);
}

//����� ������� ������ ������ �� ������������ ����� � ������ (����� n �������)
void MyString::koncatAtPos(const MyString& str2, int n) {
	//�������� �� ��, ��� n ������ ���� ����� ������ ������ 1
	if (n > strlen(this->myStr) || n < 0 ) {
		cout << "�� ����� ������������ ������� �������. ������� � ������ �� ���������" << endl;
		return ;
	}
	//������� �����
	MyString bufMyStr(this->myStr);
	countOfStrings--;
	delete[] this->myStr;
	this->myStr = new char[strlen(bufMyStr.myStr) + strlen(str2.myStr) + 1];
	//������� �������, ����� ��������� ���������� ������ ������ ������
	int counter = 0;
	//��������� ���� �� ������ ������ ������, ����� ����� ������ ����� �������
	for (int i = 0; i < strlen(this->myStr); i++)
	{
		//���� ������� ������ �����, �� ��������� ���� ������� ������ ������, ����� �������� ��� � ������ ������
		if (i == n) {
			for (int j = 0; j < strlen(str2.myStr); j++)
			{
				this->myStr[j + i] = str2.myStr[j];
				//����������� �������, ����� ��������� ���������� ������ ������ ������
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

//����� �������� ����� ������
int MyString::sizeOfMyString() {
	return strlen(this->myStr);
}

//����� ������� ������
void MyString::clearMyString() {
	delete this->myStr;
	this->myStr = new char[1];
	this->myStr[0] = '\0';
}

//����� ��������� ���� �����
//���������� ������ s1 �� ������� s2 � ���������� ��������� ���� int: 
//0 ����� ������ ������������, >0 � ���� s1<s2,  <0  � ���� s1>s2 � ������ ��������
int MyString::compareMyStrings(const MyString& str2) {
	return strcmp(this->myStr, str2.myStr);
}

//������ 
void MyString::SetMyStr(const char* str) {
	this->myStr = new char[strlen(str) + 1];
	strcpy(this->myStr, str);
}

int MyString::countOfStrings = 0;

//������
char* MyString::GetMyStr() {
	return this->myStr;
}

//����� ��������� ������
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
	if (this != &s) // �������� �� ������������ ������ ����
	{
		this->myStr = nullptr;
		this->myStr = new char[strlen(s.myStr) + 1];
		strcpy(this->myStr, s.myStr);
	}
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	if (this->myStr != s) // �������� �� ������������ ������ ����
	{
		this->myStr = nullptr;
		this->myStr = new char[strlen(s) + 1];
		strcpy(this->myStr, s);
	}
	return *this;
}

//����������
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