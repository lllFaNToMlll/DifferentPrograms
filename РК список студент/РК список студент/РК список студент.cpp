#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

struct element // тип элемента
{
	char name[80]; // информационное поле 1
	char surname[80]; // информационное поле 2
	char dadname[80]; // информационное поле 3
	char group[80]; // информационное поле 4
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
		printf("     %s\n", head->surname);
		printf("     %s\n", head->name);
		printf("     %s\n", head->dadname);
		printf("     %s\n", head->group);
		head = head->next;
	}
}

int main()
{
	char buff[80] = ""; // буфер промежуточного хранения считываемого из файла текста
	element* head, * tail, * prom; // указатели на первый, последний и промежуточный элементы списка
	setlocale(0, "russian");
	head = NULL;
	while (strcmp(buff, "end") != 0) { // пока не написали end
		if (head == NULL) { // первый элемент списка обрабатывается отдельно
			head = new element;
			tail = head;
			head->next = NULL;
			cout << "Введите фамилию" << endl;
			cin >> buff; // считали слово 
			strcpy(head->surname, buff);
			cout << "Введите имя" << endl;
			cin >> buff; // считали слово 
			strcpy(head->name, buff);
			cout << "Введите отчество" << endl;
			cin >> buff; // считали слово 
			strcpy(head->dadname, buff);
			cout << "Введите группу" << endl;
			cin >> buff; // считали слово 
			strcpy(head->group, buff);
			cout << "Введите end, если хотите завершить программу. Введите любое слово для продолжения" << endl;
			cin >> buff; // считали слово 
		}
		else { // обрабатываем остальные элементы списка
			prom = new element;
			cout << "Введите фамилию" << endl;
			cin >> buff; // считали слово 
			strcpy(prom->surname, buff);
			cout << "Введите имя" << endl;
			cin >> buff; // считали слово 
			strcpy(prom->name, buff);
			cout << "Введите отчество" << endl;
			cin >> buff; // считали слово 
			strcpy(prom->dadname, buff);
			cout << "Введите группу" << endl;
			cin >> buff; // считали слово 
			strcpy(prom->group, buff);
			tail->next = prom;
			prom->next = NULL;
			tail = prom;
			cout << "Введите end, если хотите завершить программу. Введите любое слово для продолжения" << endl;
			cin >> buff; // считали слово 
		}
	}
	puts("\nИсходный список");
	printlist(head);
	deleteList(&head);
	puts("\nнажмите любую клавишу для завершения...");
	system("pause");
	return 0;
}