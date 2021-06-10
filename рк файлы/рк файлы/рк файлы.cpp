// рк файлы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double number;
	string flag;
	ofstream outfile("Numbers.bin", ios::binary);
	if (!outfile)
	{
		cerr << "Файл не открылся" << endl;
		exit(1);
	}
	while (flag != "end")
	{
		cout << "Введите число:" << endl;
		cin >> number;
		outfile.write(reinterpret_cast<char*>(&number), sizeof(number));
		cout << "Для продолжения ввода введите любое символ. Для завершения ввода введите end" << endl;
		cin >> flag;
	}
	outfile.close();
	ifstream infile("Numbers.bin", ios::binary);
	if (!infile)
	{
		cerr << "Файл не открылся" << endl;
		exit(1);
	}
	while (infile.read(reinterpret_cast<char*>(&number), sizeof(number)))
	{
		cout << "Вещественное число из файла: " << number << endl;
	}
	return 0;
}