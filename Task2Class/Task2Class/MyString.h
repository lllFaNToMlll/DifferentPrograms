#pragma once
#include <iostream>
using namespace std;

class MyString {
    char* myStr;
public:
    static int countOfStrings;
    //����������� �� ���������
    MyString();
    //�����������
    MyString(const char* str);
    //����������� �����������
    MyString(const MyString& myString);
    //����� ������������ ���� �����
    void koncat(const MyString& str2);
    //����� ������� ������ ������ �� ������������ ����� � ������ (����� n �������)
    void koncatAtPos(const MyString& str2, int n);
    //����� �������� ����� ������
    int sizeOfMyString();
    //����� ������� ������
    void clearMyString();
    //����� ��������� ���� �����
    //���������� ������ s1 �� ������� s2 � ���������� ��������� ���� int: 
    //0 ����� ������ ������������, >0 � ���� s1<s2,  <0  � ���� s1>s2 � ������ ��������
    int compareMyStrings(const MyString& str2);
    //������ 
    void SetMyStr(const char* str);
    //������
    char* GetMyStr();
    //����� ��������� ������
    void reverseMyString();
    MyString& operator=(const MyString& s);
    MyString& operator=(const char* s);
    //����������
    ~MyString();
    //����� ��������� ���������� ��������� ��������
    static int getCountStrings() {
        return countOfStrings;
    }
    //��������� �����/������
    friend std::ostream& operator<<(std::ostream&, const MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};