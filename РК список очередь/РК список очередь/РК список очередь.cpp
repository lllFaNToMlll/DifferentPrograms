// РК список очередь.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// RK_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "stdafx.h" 
#include <conio.h>
#include <locale.h>
#include <ctime>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;

struct element // тип элемента
{
	char value[80]; // информационное поле 1
	element* next; // адресное поле ≪следующий≫
};


void deleteList(element** head)
{
	element* prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		delete (prev);
	}
	delete (*head);
}

void printlist(element* head)
{
	printf("Вывод:\n");
	while (head)
	{
		printf("     %s\n", head->value);
		head = head->next;
	}
}



int main(int argc, char* argv[])

{
	char b[80] = "k\0", * ptr;
	element* head, * tail, * prom, *newProm;
	setlocale(0, "russian");
	int counter = 0;
	while (strcmp(b, "end") != 0 || counter % 3 != 0) {
		printf("Введите %d число. Для завершения ввода введите end (также количество введенных чисел должно быть кратно 3): ",counter+1);
		gets_s(b);
		if (strcmp(b, "end") != 0 || counter % 3 != 0) {
			while (atoi(b) == 0 && b[0] != '0') {
				printf("Вы ввели не число, либо число введенных чисел не кратно 3. Введите число: ");
				gets_s(b);
			}
			if (counter == 0) {
				head = new element;
				tail = head;
				head->next = NULL;
				strcpy(head->value, b);
			}
			else {
				prom = new element;
				strcpy(prom->value, b);
				tail->next = prom;
				prom->next = NULL;
				tail = prom;
			}
			counter++;
		}
	}
	puts("\nИсходный список");
	printlist(head);
	prom = head;
	counter = 0;
	while (prom)
	{
		counter++;
		if (counter % 3 == 0) {
			newProm = new element;
			strcpy(newProm->value, "0\0");
			newProm->next = prom->next;
			prom->next = newProm;
			counter = 0;
			prom = prom->next;
		}
		prom = prom->next;
	}
	printf("\n\nИзмененный список после добавления 0 после каждого 3-его элемента\n");
	printlist(head);
	deleteList(&head);
	puts("\nнажмите любую клавишу для завершения...");
	_getch();
	return 0;
}