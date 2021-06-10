// LRstring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

int main() {
	//Русские буквы
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	wstring s;
	//Максмальная длинна слова
	int max_len = 1;
	//Длинна текущего слова
	int buf_len;
	//Буферный символ для копирования
	wchar_t buf_ch;
	//Позиции пробелов, для определения начала и конца слов
	vector<int> space_pos;
	wcout « "Введите строку:\n";
	//Считывание строки
	getline(wcin, s);
	// s="123 12 123 3 5 ";
	//s = "abc 123 йцу";
	// s="1 2 3 4 5 5 1 2 12";
	//Добавляем -1, то есть границу слов слева
	space_pos.push_back(-1);
	for (int i = 0; i < s.length(); ++i) {
		//Если найден пробел, добавляем его позицию как границу слова
		if (s[i] == ' ') {
			space_pos.push_back(i);
			//Если длина слова (разница между позицией новой границы и предыдущей) больше максимальной,
			// то это новая максмальная длина
			buf_len = space_pos[space_pos.size() - 1] - space_pos[space_pos.size() - 2] - 1;
			if (buf_len > max_len) {
				max_len = buf_len;
			}
		}
	}
	//Добавляем границу слов справа и опять проверяем на максимальную
	space_pos.push_back(s.size());
	buf_len = space_pos[space_pos.size() - 1] - space_pos[space_pos.size() - 2] - 1;
	if (buf_len > max_len) {
		max_len = buf_len;
	}

	//Для каждой границы слова
	for (int i = 1; i < space_pos.size(); ++i) {
		//Если длина слова равна максимальной длине
		if ((space_pos[i] - space_pos[i - 1] - 1) == max_len) {
			//Перестановка символов в слове
			for (int ch = 0; ch < max_len / 2; ++ch) {
				buf_ch = s[space_pos[i - 1] + 1 + ch];
				s[space_pos[i - 1] + 1 + ch] = s[space_pos[i] - ch - 1];
				s[space_pos[i] - ch - 1] = buf_ch;
			}
		}
	}
	wcout « endl « "Максмальная длина слова равна " « max_len « endl;
	//Вывод новой строки
	wcout « "Новая строка:\n" « s;
	return 0;
}