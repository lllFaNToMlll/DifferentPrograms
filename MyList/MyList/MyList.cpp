// MyList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
using namespace std;

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct MyList {
    int size;
    Node* head;
    Node* tail;
};

MyList* createMyList() {
    MyList* tmp = (MyList*)malloc(sizeof(MyList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void deleteMyList(MyList** list) {
    Node* tmp = (*list)->head;
    Node* next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushBack(MyList* list, int value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void pushFront(MyList* list, int data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}


Node* getNth(MyList* list, int index) {
    Node* tmp = list->head;
    int i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void initMyList(MyList* list) {
    cout << "Введите количество элеметнов, которые вы хотите вставить в список: " << endl;
    int counter = NULL;
    cin >> counter;
    for (int i = 0; i < counter; i++)
    {
        cout << "Введите элемент списка" << endl;
        int value = NULL;
        cin >> value;
        pushBack(list, value);
    }
}

void printMyList(MyList* list) {
    Node* elm = NULL;
    elm = list->head;
    cout << "Вывод списка: " << endl;
    while (elm)
    {
        cout << elm->value << endl;
        elm = elm->next;
    }
}

void insert(MyList* list, int index, int value) {
    Node* elm = NULL;
    Node* ins = NULL;
    elm = getNth(list, index-1);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*)malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

void deleteNth(MyList* list, int index) {
    Node* elm = NULL;
    int tmp = NULL;
    elm = getNth(list, index-1);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;
}
////////////////////////////////////////////////
MyList* createReverseList(MyList* list) {
    MyList* returnedList = createMyList();
    Node* elm = NULL;
    elm = list->head;
    while (elm)
    {
        pushFront(returnedList, elm->value);
        elm = elm->next;
    }
    return returnedList;
}

int main() {
    setlocale(0, "russian");
    MyList* myList = createMyList();
    initMyList(myList);
    printMyList(myList);
    cout << "Вставка нового элемента после N позиции. Введите N" << endl;
    int N = NULL, number = NULL;
    cin >> N;
    cout << "Введите элемент" << endl;
    cin >> number;
    if (N < 0 || N > myList->size)
        cout << "Вы ввели недопустимый индекс" << endl;
    else 
        insert(myList, N, number);
    cout << "Результат вставки" << endl;
    printMyList(myList);
    cout << "Удаление элемента на N позиции. Введите N" << endl;
    cin >> N;
    deleteNth(myList, N);
    cout << "Результат удаления" << endl;
    printMyList(myList);
    cout << "Создание и вывод обратного списка" << endl;
    MyList* myList2 = createMyList();
    myList2 = createReverseList(myList);
    printMyList(myList2);
    deleteMyList(&myList);
    deleteMyList(&myList2);
    system("pause");
}