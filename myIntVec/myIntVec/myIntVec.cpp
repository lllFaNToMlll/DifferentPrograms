#include <iostream>
using namespace std;

template <class Type>
class MyVector {
public:
	MyVector() {  // конструктор по умолчанию
		length = 0;
		capacity = 5;  // делаем 5, чтобы точно было 5 элементов в векторе
		dataPointer = new Type[capacity];
	}
	MyVector(const MyVector& rhs) {  // конструктор копирования
		length = rhs.length; // присваиваем сначала все свойства rhs вектора
		capacity = rhs.capacity;
		dataPointer = new Type[rhs.capacity];
		for (int i = 0; i < rhs.length; i++) // теперь присваиваем его элементы
		{
			dataPointer[i] = rhs[i];  // здесь используем дополнительное переопределение оператора []
		}
	}
	~MyVector() {  // деструктор
		delete[] dataPointer;
	}
	void PushBack(Type newElement);
	Type& operator[] (int index);
	const Type& operator[](int index) const;
	MyVector& operator= (const MyVector& rhs);
	bool IsEmpty() const;
	int Length() const;
	int Capacity() const;
	void Swap(MyVector& element2);
	void InputMyIntVector(int N);
	void OutputMyIntVector();

private:
	void UpCapacity();
	int length;
	int capacity;
	Type* dataPointer;
};

template <class Type>
void MyVector<Type>::UpCapacity() {  // увеличиваем вместимость вектора
	capacity = 2 * capacity;  // увеличиваем вместимость вектора в 2 раза
	Type* result = new Type[capacity];  // выделяем объем памяти под новую вместимость
	for (int i = 0; i < length; ++i)  // инициализируем элементы вектора
	{
		result[i] = dataPointer[i];
	}
	delete[] dataPointer;  // очищаем старую память
	dataPointer = result;  // присваиваем новую
}

template <class Type>
void MyVector<Type>::Swap(MyVector& element2) {  // наш метод Swap this-это vec1
	MyVector element3(*this);  // используем конструктор копирования
	*this = element2;  // используем оператор присваивания
	element2 = element3;  // используем оператор присваивания
}

template <class Type>
void MyVector<Type>::PushBack(Type newElement) {  // метод добавления нового элемента в конец вектора
	if (++length >= capacity) {
		UpCapacity();
	}
	dataPointer[length - 1] = newElement;
}

template <class Type>
bool MyVector<Type>::IsEmpty() const {  // метод проверки на пустой вектор 
	if (length == 0)
		return true;
	else
		return false;
}

template <class Type>
Type& MyVector<Type>::operator[] (int index) {  // переопределения оператора []
	return dataPointer[index];
}

template <class Type>
MyVector<Type>& MyVector<Type>::operator= (const MyVector& rhs) {  // оператор присваивания
	if (this == &rhs) // делаем проверку на присваивания элемента самому себе (в случае: х=х)
		//если ее не сделать, то будет бросаться исключение
		return *this;
	delete[] dataPointer;
	length = rhs.length;
	capacity = rhs.capacity;
	dataPointer = new Type[length];
	for (int i = 0; i < length; i++)
		dataPointer[i] = rhs.dataPointer[i];
	return *this;
}

template <class Type>
const Type& MyVector<Type>::operator[](int index) const {  // переопределения оператора [] для конструктора копирования
	return dataPointer[index];
}

template <class Type>
int MyVector<Type>::Length() const {  // метод возвращения длины вектора
	return length;
}

template <class Type>
int MyVector<Type>::Capacity() const {  // метод возвращения вместимости вектора
	return capacity;
}

template <class Type>
void MyVector<Type>::InputMyIntVector(int N) {  // заполнение нашего вектора
	Type el;
	for (int i = 0; i < N; i++) {
		cout << "Введите [" << i + 1 << "] элемент массива" << endl;
		cin >> el;
		this->PushBack(el);
	}
}

template <class Type>
void MyVector<Type>::OutputMyIntVector() {  // печать нашего вектора
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
	MyVector<char[3]> vec1, vec2;
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
	cout << "\n*Применяем функцию Swap метод класса MyVector*" << endl;
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