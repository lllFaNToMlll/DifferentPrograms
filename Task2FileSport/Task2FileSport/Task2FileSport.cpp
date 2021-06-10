// Task2FileSport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define SIZE 100
#define _CRT_SECURE_NO_WARNINGS_

/*
aaa 11 22 22 22
bbb 22 33 33 33
ccc 33 44 44 44
ddd 11 33 33 33
eee 22 11 11 11
fff 44 33 33 33
ggg 22 33 33 33
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
//#include <Windows.h>

using namespace std;

void cin_c(string line, string* sportsman, double* minutes, double* seconds, double* tenthsOfSeconds, double* hundredthsOfSeconds);
void line_sort(char* line, char** sportsman, string* temp, int k);
void sportsman_sort(char** sportsmen, string* temp, int n);

int main() {
    setlocale(LC_CTYPE, "ru");
    string path = "first_file.txt";
    int n = 0;
    fstream f, ff;

    f.open(path, fstream::in | fstream::out | fstream::app);
    if (!f.is_open()) {
        cout << "Файл не открылся";
    }
    else
    {
        do
        {
            string line;
            string sportsman;
            double minutes, seconds, tenthsOfSeconds, hundredthsOfSeconds;
            cout << "Введите фамилию спортсмена и его время в формате: Фамилия минуты секунды десятые сотые (введите end для выхода): " << endl;
            //SetConsoleCP(1251);
            getline(cin, line);
            if (line == "end") 
                break;
            cin_c(line, &sportsman, &minutes, &seconds, &tenthsOfSeconds, &hundredthsOfSeconds);
            f << sportsman << " " << minutes << " " << seconds << " " << tenthsOfSeconds << " " << hundredthsOfSeconds << "\n";
            //SetConsoleCP(866);
        } while (true);
    }
    f.close();

    f.open(path, fstream::in | fstream::out | fstream::app);

    if (!f.is_open()) {
        cout << "Файл не открылся";
    }
    else
    {
        char sportsman[SIZE];
        f >> sportsman;
        while (true)
        {
            char st[SIZE];
            f.getline(st, SIZE);
            if (f.eof())
                break;
            n++;
        }
    }
    f.close();


    f.open(path, fstream::in | fstream::out | fstream::app);

    string* temp = new string[n];
    char** sportsmen = new char* [n];
    for (int i = 0; i < n; i++) {
        sportsmen[i] = new char[SIZE];
    }

    if (!f.is_open()) {
        cout << "Файл не открылся";
    }
    else
    {
        for (int i = 0; i < n; i++) {
            char line[SIZE];
            f.getline(line, SIZE);
            line_sort(line, sportsmen, &temp[i], i);
        }
    }
    f.close();

    string path2 = "output.txt";
    ff.open(path2, ios::out);

    sportsman_sort(sportsmen, temp, n);
    if (n >= 7) {
        for (int i = 0; i < 7; i++) {
            ff << sportsmen[i] << " " << temp[i] << "\n";
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            ff << sportsmen[i] << " " << temp[i] << "\n";
        }
    }
    return 0;
}

void cin_c(string line, string* sportsman, double* minutes, double* seconds, double* tenthsOfSeconds, double* hundredthsOfSeconds) {
    int i = 0, e;
    string first, second, third, forth;
    while (!isdigit(line[i])) {
        sportsman->append(line, i, 1);
        i++;
    }
    sportsman->replace(i - 1, 1, "\0");
    e = i;
    while (line[i] != ' ') 
        i++;
    first.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i] != ' ')
        i++;
    second.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i] != ' ')
        i++;
    third.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i])
        i++;
    forth.append(line, e, i - e);
    first += "\0";
    second += "\0";
    third += "\0";
    forth += "\0";
    *minutes = stod(first);
    *seconds = stod(second);
    *tenthsOfSeconds = stod(third);
    *hundredthsOfSeconds = stod(forth);
}

void line_sort(char* line, char** sportsman, string* temp, int k)
{
    int i = 0, e;
    string first, second, third, forth, cc;
    while (!isdigit(line[i])) {
        cc.append(line, i, 1);
        i++;
    }
    cc[i - 1] = '\0';
    e = i;
    while (line[i] != ' ')
        i++;
    first.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i] != ' ')
        i++;
    second.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i] != ' ') 
        i++;
    third.append(line, e, i - e);
    e = i + 1;
    i++;
    while (line[i])
        i++;
    forth.append(line, e, i - e);

    first += "\0";
    second += "\0";
    third += "\0";
    forth += "\0";
    *temp = first + " "  + second + " " + third + " " + forth;
    for (i = 0; cc[i]; i++) {
        sportsman[k][i] = cc[i];
    }
    sportsman[k][i] = '\0';
}

void sportsman_sort(char** sportsmen, string* temp, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = (n - 1); j >= (i + 1); j--) {
            if (temp[j] < temp[j - 1]) {
                swap(temp[j], temp[j - 1]);
                swap(sportsmen[j], sportsmen[j - 1]);
            }
        }
    }
}