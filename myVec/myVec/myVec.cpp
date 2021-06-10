// myVec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

class MyIntVector {

public:
	MyIntVector() {  // конструктор по умолчанию
		length = 0;
		capacity = 5;  // делаем 5, чтобы точно было 5 элементов в векторе
		dataPointer = new int[capacity];
	}
	MyIntVector(const MyIntVector& rhs) {  // конструктор копирования
		length = rhs.length; // присваиваем сначала все свойства rhs вектора
		capacity = rhs.capacity;
		dataPointer = new int[rhs.capacity];
		for (int i = 0; i < rhs.length; i++) // теперь присваиваем его элементы
		{
			dataPointer[i] = rhs[i];  // здесь используем дополнительное переопределение оператора []
		}
	}
	~MyIntVector() {  // деструктор
		delete[] dataPointer;
	}
	void PushBack(int newElement);
	int& operator[] (int index);
	const int& operator[](int index) const;
	MyIntVector& operator= (const MyIntVector& rhs);
	bool IsEmpty() const;
	int Length() const;
	int Capacity() const;
	void Swap(MyIntVector& element2);
	void InputMyIntVector(int N);
	void OutputMyIntVector();

private:
	void UpCapacity();
	int length;
	int capacity;
	int* dataPointer;
};

void MyIntVector::UpCapacity() {  // увеличиваем вместимость вектора
	capacity = 2 * capacity;  // увеличиваем вместимость вектора в 2 раза
	int* result = new int[capacity];  // выделяем объем памяти под новую вместимость
	for (int i = 0; i < length; ++i)  // инициализируем элементы вектора
	{
		result[i] = dataPointer[i];
	}
	delete[] dataPointer;  // очищаем старую память
	dataPointer = result;  // присваиваем новую
}

void MyIntVector::Swap( MyIntVector& element2) {  // наш метод Swap this-это vec1
	MyIntVector element3(*this);  // используем конструктор копирования
	*this = element2;  // используем оператор присваивания
	element2 = element3;  // используем оператор присваивания
}

void MyIntVector::PushBack(int newElement) {  // метод добавления нового элемента в конец вектора
	if (++length >= capacity) {
		UpCapacity();
	}
	dataPointer[length-1] = newElement;
}

bool MyIntVector::IsEmpty() const {  // метод проверки на пустой вектор 
	if (length == 0) 
		return true;
	else 
		return false;
}

int& MyIntVector::operator[] (int index) {  // переопределения оператора []
	return dataPointer[index];
}

MyIntVector& MyIntVector::operator= (const MyIntVector& rhs) {  // оператор присваивания
	if (this == &rhs) // делаем проверку на присваивания элемента самому себе (в случае: х=х)
		//если ее не сделать, то будет бросаться исключение
		return *this;
	delete[] dataPointer;
	length = rhs.length;
	capacity = rhs.capacity;
	dataPointer = new int[length];
	for (int i = 0; i < length; i++)
		dataPointer[i] = rhs.dataPointer[i];
	return *this;
}

const int& MyIntVector::operator[](int index) const {  // переопределения оператора [] для конструктора копирования
	return dataPointer[index];
}

int MyIntVector::Length() const {  // метод возвращения длины вектора
	return length;
}

int MyIntVector::Capacity() const {  // метод возвращения вместимости вектора
	return capacity;
}

void MyIntVector::InputMyIntVector(int N) {  // заполнение нашего вектора
	int el;
	for (int i = 0; i < N; i++) {
		cout << "Введите [" << i+1 << "] элемент массива" << endl;
		cin >> el;
		this->PushBack(el);
	}
}
void MyIntVector::OutputMyIntVector() {  // печать нашего вектора
	for (int i = 0; i < this->Length(); ++i) {
		cout << this->dataPointer[i] << " ";
	}
}

template <class MyType>
void MySwap(MyType& element1, MyType& element2) {
	MyType element3 = element1;
	element1 = element2;
	element2 = element3;
}

int main()
{
	setlocale(0, "Rus");
	MyIntVector vec1, vec2;
	int n;
	cout << "\nВведите количество элементов первого вектора: ";
	cin >> n;
	cout << "\nВведите элементы первого вектора: ";
	vec1.InputMyIntVector(n);
	cout << "\nПервый вектор: ";
	vec1.OutputMyIntVector();
	cout << "\nВведите количество элементов второго вектора: ";
	cin >> n;
	cout << "\nВведите элементы второго вектора: ";
	vec2.InputMyIntVector(n);
	cout << "\nВторой вектор: ";
	vec2.OutputMyIntVector();
	cout << "\n*Применяем функцию Swap метод класса MyIntVector*" << endl;
	vec1.Swap(vec2);
	cout << "\nПервый вектор: ";
	vec1.OutputMyIntVector();
	cout << "\nВторой вектор: ";
	vec2.OutputMyIntVector();
	cout << "\n*Применяем функцию Swap шаблонную*" << endl;
	MySwap(vec1, vec2);
	cout << "\nПервый вектор: ";
	vec1.OutputMyIntVector();
	cout << "\nВторой вектор: ";
	vec2.OutputMyIntVector();
	return 0;
}
