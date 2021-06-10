#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <conio.h>
#include <clocale>
#include <string.h>


struct TREE {
	char symbol;
	TREE* left_des;
	TREE* right_des;

};

bool check_vowel(char symbol)
{
	char vowels[13] = "aAiIoOuUyYeE";
	bool res = false;
	for (int i = 0; i < 13; i++)
	{
		if (vowels[i] == symbol)
		{
			res = true;
		}
	}
	return res;
}
void AddNode(TREE** MyTree, TREE* TreeElem)
{
	TREE* current = *MyTree;
	if (current == NULL)
	{
		*MyTree = TreeElem;
	}
	else
	{
		if (TreeElem->symbol > current->symbol)
		{
			AddNode(&current->left_des, TreeElem);
		}
		else
		{
			AddNode(&current->right_des, TreeElem);
		}
	}

}
void PrintTREE(TREE* MyTree)
{
	if (MyTree != NULL)
	{
		std::cout << MyTree->symbol << " ";
		PrintTREE(MyTree->left_des);
		PrintTREE(MyTree->right_des);
	}
}
void Del1(TREE** r, TREE** q)
{
	TREE* s = new TREE;

	if ((*r)->right_des == NULL)
	{
		(*q)->symbol = (*r)->symbol;
		*q = *r;
		s = *r;
		*r = (*r)->left_des;
		delete s;
	}
	else
	{
		Del1(&((*r)->right_des), q);
	}
}

TREE* DeleteNode(TREE* node, char symbol)
{


	if (node == NULL)
		return node;

	if (symbol == node->symbol) {

		TREE* tmp;
		if (node->right_des == NULL)
			tmp = node->left_des;
		else {

			TREE* ptr = node->right_des;
			if (ptr->left_des == NULL) {
				ptr->left_des = node->left_des;
				tmp = ptr;
			}
			else {

				TREE* pmin = ptr->left_des;
				while (pmin->left_des != NULL) {
					ptr = pmin;
					pmin = ptr->left_des;
				}
				ptr->left_des = pmin->right_des;
				pmin->left_des = node->left_des;
				pmin->right_des = node->right_des;
				tmp = pmin;
			}
		}

		delete node;
		return tmp;
	}
	else if (symbol < node->symbol)
		node->left_des = DeleteNode(node->left_des, symbol);
	else
		node->right_des = DeleteNode(node->right_des, symbol);
	return node;

}
void Del_Node(TREE** MyTree, char k)
{
	TREE* current;
	TREE* q;
	current = *MyTree;
	if (*MyTree == NULL)
	{
		current = *MyTree;
	}
	else if (k < (current)->symbol)
	{
		Del_Node(&current->left_des, k);
	}
	else if (k > (current)->symbol)
	{
		Del_Node(&current->right_des, k);
	}
	else
	{
		q = *MyTree;
		if (q->right_des == NULL)
		{
			*MyTree = q->left_des;
			delete q;
		}
		else if (q->left_des == NULL)
		{
			*MyTree = q->right_des;
			delete q;
		}
		else
		{
			Del1(&q->left_des, &q);
		}

	}
}
void vowels(TREE** MyTree, int* counter)
{
	TREE* current;
	current = *MyTree;
	if (*MyTree != NULL)
	{
		vowels(&(*MyTree)->left_des, counter);
		vowels(&(*MyTree)->right_des, counter);
		if (check_vowel((*MyTree)->symbol))
		{
			(*counter)++;
			Del_Node(MyTree, (*MyTree)->symbol);
		}

	}
}
void basic_delete(char* string, int* counter)
{

	char* ptr = string;
	while (ptr != NULL)
	{
		if (check_vowel(*ptr))
		{
			(*counter)++;
			strcpy(ptr, ptr++);
		}
		else
		{
			ptr++;
		}

	}

}


int main()
{
	setlocale(LC_ALL, "rus");
	TREE* MyTree = NULL;
	TREE* TreeElem = NULL;
	// std::cout << std::endl << "Введите размер строки с символами, из которых хотите сделать бинарное дерево" << std::endl;
	// int size; 
	// std::cin >> size;
	// std::cout << std::endl; 
	char* buffer = new char[40];
	std::cout << std::endl << "Введите символьную строку" << std::endl;
	gets_s(buffer, 40);
	char* ptr = buffer;
	while (*ptr != '\0')
	{
		TreeElem = new TREE;
		TreeElem->symbol = *ptr;
		TreeElem->left_des = NULL;
		TreeElem->right_des = NULL;
		AddNode(&MyTree, TreeElem);
		ptr++;
	}
	int counter = 0;
	PrintTREE(MyTree);
	clock_t start_binary = clock();
	TREE* tmp = NULL;
	vowels(&MyTree, &counter);
	clock_t end_binary = clock();
	std::cout << std::endl << "В бинарном дереве " << counter << "гласных букв" << std::endl;
	std::cout << std::endl << "Удаление гласных с помощью бинарного дерева поиска длилось " << (double)(end_binary - start_binary)
		/ CLOCKS_PER_SEC << " секунд" << std::endl;
	std::cout << std::endl << "После удаления гласных бинарное дерево имеет вид:" << std::endl;
	PrintTREE(MyTree);
	clock_t start_basic = clock();
	basic_delete(buffer, &counter);
	clock_t end_basic = clock();
	std::cout << std::endl << "Удаление гласных с помощью функций библиотеки string.h длилось " << (double)(end_basic - start_basic)
		/ CLOCKS_PER_SEC << " секунд" << std::endl;
	return 0;



}
