#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

struct element // тип элемента
{
	char surname[80]; // информационное поле 1
	int firstMark; // информационное поле 2
	int secondMark; // информационное поле 3
	int thirdMark; // информационное поле 4
	int sumOfMark; // информационное поле 5
	element* prev; // адресное поле ≪предыдущий≫
	element* next; // адресное поле ≪следующий≫
};

void removelist(element** head) // подпрограмма для удаления списка 
								// (очистка памяти, выделенной под него)
{
	element* cur;
	while ((*head))
	{
		cur = *head;
		*head = (*head)->next;
		delete cur;
	}
	cur = NULL;
}

void printlist(element* head, element* tail) // подпрограмма печати списка в двух направлениях
{
	printf("Вывод с начала:\n");
	while (head)
	{
		printf("\n      %s \n", head->surname);
		printf("\n      %d \n", head->firstMark);
		printf("\n      %d \n", head->secondMark);
		printf("\n      %d \n", head->thirdMark);
		printf("\n      %d \n", head->sumOfMark);
		head = head->next;
	}
	/*printf("Вывод с конца:\n");
	while (tail)
	{
		printf("\n      %d \n", tail->surname);
		printf("\n      %d \n", tail->firstMark);
		printf("\n      %d \n", tail->secondMark);
		printf("\n      %d \n", tail->thirdMark);
		printf("\n      %d \n", tail->sumOfMark);
		tail = tail->prev;
	}*/
}

int main()
{
	char buff[80]; // буфер промежуточного хранения считываемого текста из файла 
	element* head, * tail, * prom, * ptr, * ptr2; // указатели на первый, последний и промежуточный элементы списка
	int flag = 0;
	setlocale(0, "russian");
	ifstream fin("FILE1.txt"); // открыли файл для чтения
	head = NULL;
	while (fin) { // пока в файле есть слова
		fin >> buff; // считали слово из файла
		if (strcmp(buff,"") == 0)
			break;
		if (head == NULL) { // первый элемент списка обрабатывается отдельно
			head = new element;
			tail = head;
			head->prev = NULL;
			head->next = NULL;
			strcpy(head->surname, buff);
			fin >> buff; // считали слово из файла
			head->firstMark = atoi(buff);
			fin >> buff; // считали слово из файла
			head->secondMark = atoi(buff);
			fin >> buff; // считали слово из файла
			head->thirdMark = atoi(buff);
			head->sumOfMark = head->firstMark + head->secondMark + head->thirdMark;
		}
		else { // обрабатываем остальные элементы списка
			prom = new element;
			strcpy(prom->surname, buff);
			fin >> buff; // считали слово из файла
			prom->firstMark = atoi(buff);
			fin >> buff; // считали слово из файла
			prom->secondMark = atoi(buff);
			fin >> buff; // считали слово из файла
			prom->thirdMark = atoi(buff);
			prom->sumOfMark = prom->firstMark + prom->secondMark + prom->thirdMark;
			flag = 0;
			if (prom->sumOfMark > head->sumOfMark) // проверяем на вставку вместо головы списка
			{
				head->prev = prom;
				prom->prev = NULL;
				prom->next = head;
				head = prom;
				flag = 1;
			}
			else if (head == tail) // проверяем на вставку вместо головы списка, если список состоит из одного элемента
			{
				prom->prev = head;
				prom->next = NULL;
				tail = prom;
				head->next = prom;
				flag = 1;
			}
			else if (prom->sumOfMark == head->sumOfMark) // проверяем на вставку вместо головы списка, если суммы оценок равны
			{
				flag = 0;
				ptr2 = head;
				if (strcmp(prom->surname, ptr2->surname) < 0) // проверяем на вставку вместо головы списка сравнивая фамилии
				{
					head->prev = prom;
					prom->prev = NULL;
					prom->next = head;
					head = prom;
					flag = 1;
				}
				while (ptr2->next && flag == 0 && prom->sumOfMark == ptr2->sumOfMark) // ищем место вставки в середину списка по алфавиту
				{
					if (strcmp(prom->surname, ptr2->surname) < 0)
					{
						prom->prev = ptr2->prev;
						prom->next = ptr2;
						ptr2->prev->next = prom;
						ptr2->prev = prom;
						flag = 1;
					}
					ptr2 = ptr2->next;
				}
				if (flag == 0) // не нашли в середине фамилий, ставим после всех фамилий
				{
					prom->prev = ptr2->prev;
					prom->next = ptr2;
					ptr2->prev->next = prom;
					ptr2->prev = prom;
					flag = 1;
				}
			}
			else if (prom->sumOfMark > tail->sumOfMark) // обрабатываем хвост списка
			{
				prom->next = tail;
				prom->prev = tail->prev;
				tail->prev->next = prom;
				tail->prev = prom;
				flag = 1;
			}
			else if (prom->sumOfMark == tail->sumOfMark) // если суммы равны, то проверяем по фамилиям
			{
				if (strcmp(prom->surname, tail->surname) < 0)
				{
					prom->prev = tail->prev;
					prom->next = tail;
					tail->prev->next = prom;
					tail->prev = prom;
					flag = 1;
				}
				else // по фамилии ставим новый элмемент в конец списка
				{
					prom->next = NULL;
					prom->prev = tail;
					tail->next = prom;
					tail = prom;
					flag = 1;
				}
			}
			else // обрабатываем вставки в середине списка
			{
				ptr = head;
				flag = 0;
				while (ptr->next && flag == 0)
				{
					if (prom->sumOfMark > ptr->sumOfMark) // смотрим по суммам оценок
					{
						prom->prev = ptr->prev;
						prom->next = ptr;
						ptr->prev->next = prom;
						ptr->prev = prom;
						flag = 1;
					}
					else if (prom->sumOfMark == ptr->sumOfMark) // смотрим по фамилиям
					{
						ptr2 = ptr;
						while (ptr2->next && flag == 0 && prom->sumOfMark == ptr2->sumOfMark)
						{
							if (strcmp(prom->surname, ptr2->surname) < 0)
							{
								prom->prev = ptr2->prev;
								prom->next = ptr2;
								ptr2->prev->next = prom;
								ptr2->prev = prom;
								flag = 1;
							}
							ptr2 = ptr2->next;
						}
					}
					ptr = ptr->next;
				}
			}
			if (flag == 0) // если сумма оценок меньше всех + фамилия в конце по алфавиту
			{
				prom->next = NULL;
				prom->prev = tail;
				tail->next = prom;
				tail = prom;
			}
		}
	}
	fin.close(); // закрываем файл
	puts("\nИсходный список, созданный после чтения файла\n");
	printlist(head, tail);
    FILE *f;
    if ((f=fopen("FILE.bin","rb+"))==NULL){
        perror ("\nОшибка открытия файла\n");   // выводом ошибки в случае наличия
		return 1;
    }
	ptr = head;
    while (ptr !=NULL) {
		fwrite(ptr, sizeof(*ptr), 1, f);
        ptr = ptr->next;
    }
	cout << "Enter surname of student: ";
	cin >> buff;
	cout << endl;
	ptr = head;
	flag = 0;
	while (ptr) {
		if (strcmp(ptr->surname, buff) == 0) {
			cout << ptr->surname << " " << ptr->firstMark << " " << ptr->secondMark << " " << ptr->thirdMark << " " << ptr->sumOfMark << endl;
			flag = 1;
		}
		ptr = ptr->next;
	}
	if (flag == 0) {
		cout << "No student with this surname" << endl;
	}
    fclose(f);
	puts("\nСозданный список записан в бинарный файл\n");
	removelist(&head);
	puts("\nНажмите любую клавишу для завершения...");
	system("pause");
	return 0;
}