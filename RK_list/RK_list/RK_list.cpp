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
	char b[80], * ptr, * ptr2;
	element* head, * tail, * prom;
	int kolvo = 0, bkv = 0;
	setlocale(0, "russian");
	unsigned int i, kol, dlsl;
	puts("введите строку");
	gets_s(b);
	puts("исходная строка");
	puts(b);
	ptr = b;
	while ((ptr = strstr(ptr, "  ")) != NULL)
		strcpy(ptr, ptr + 1);
	ptr = b;
	if (b[0] == ' ')
		strcpy(ptr, ptr + 1);
	if (b[strlen(b) - 1] == ' ')
		b[strlen(b) - 1] = '\0';
	strcat(ptr, " ");
	puts("строка без лишних пробелов");
	puts(b);
	ptr = b;
	ptr2 = b;

	ptr = strtok(b, " ");
	head = new element;
	tail = head;
	head->next = NULL;
	strcpy(head->value, ptr);
	while (ptr = strtok(NULL, " \0"), ptr != NULL)
	{
		prom = new element;
		strcpy(prom->value, ptr);
		tail->next = prom;
		prom->next = NULL;
		tail = prom;
	}
	puts("\nисходный список");
	printlist(head);
	element* q, * p, * m;
	m = new element;

	printf("\n\nИзмененный список\n");
	printlist(head);
	deleteList(&head);
	puts("\nнажмите любую клавишу для завершения...");
	_getch();
	return 0;
}

