#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

struct element // тип элемента
{
	char value[80]; // информационное поле 1
	element* next; // адресное поле ≪следующий≫
};


void deleteList(element** head) // подпрограмма для удаления списка 
                                //(очистка памяти, выделенной под него)
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

void printlist(element* head) // подпрограмма печати списка
{
	printf("Вывод:\n");
	while (head)
	{
		printf("     %s\n", head->value);
		head = head->next;
	}
}

int main()

{
	char buff[80]; // буфер промежуточного хранения считываемого из файла текста
	element* head, * tail, * prom; // указатели на первый, последний и промежуточный элементы списка
	setlocale(0, "russian");
	ifstream fin("FILE.txt"); // открыли файл для чтения
	head = NULL;
	while (fin) { // пока в файле есть слова
		fin >> buff; // считали слово из файла
		if (head == NULL) { // первый элемент списка обрабатывается отдельно
			head = new element;
			tail = head;
			head->next = NULL;
			strcpy(head->value, buff);
		}
		else { // обрабатываем остальные элементы списка
			prom = new element;
			strcpy(prom->value, buff);
			tail->next = prom;
			prom->next = NULL;
			tail = prom;
		}
	}
	fin.close(); // закрываем файл
	puts("\nИсходный список, созданный после чтения файла");
	printlist(head);
	prom = head;
	element* temp = new element; // временная переменная для хранения элемента массива
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован
	while (!exit) // пока массив не отсортирован
	{
		exit = true;
		for (prom = head; prom->next; prom = prom->next) // внутренний цикл
		  //сортировка пузырьком по возрастанию - знак >
		  //сортировка пузырьком по убыванию - знак <
			if (strcmp(prom->value, prom->next->value) > 0) // сравниваем два соседних элемента
			{
				// выполняем перестановку элементов списка (точнее значений информационного поля элементов списка)
				strcpy(temp->value, prom->value);
				strcpy(prom->value, prom->next->value);
				strcpy(prom->next->value, temp->value);
				exit = false; // на очередной итерации была произведена перестановка элементов
			}
	}
	printf("\n\nИзмененный список после сортировки\n");
	printlist(head);
	deleteList(&head);
	puts("\nнажмите любую клавишу для завершения...");
	system("pause");
	return 0;
}