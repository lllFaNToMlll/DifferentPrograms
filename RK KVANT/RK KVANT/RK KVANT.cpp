// RK KVANT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>



//ОПИСАНИЕ КЛАССА

//описание класса - дробь

class fraction {
private:
    // числитель и знаменатель - компонентные данные объектов
    int numerator, denominator;
    //собственная функция для сокращения неправильной дроби
    void reduce();
    //счетчик количества объектов
    static int N;

public:

    //далее описываются доступные компоненты интерфейса

    /*конструктор класса с параметрами по умолчанию, который обеспечивает вызов конструктора без параметров, при этом дробь инициализируется 1; с одним параметром - числителем для создания дробного
    представления целого числа; наконец, с двумя параметрами - числителем и знаменателем для инициализации правильной дроби*/
    fraction(int numerator = 0, int denominator = 1);
    //конструктор копирования
    fraction(fraction& a);
    //деструктор
    ~fraction();

    /*открытые функции к закрытым объектам класса*/
    int getDenom();
    int getNumer();
    static int getN()
    { 
        return N; 
    }
    void setDenom(int d);
    void setNumer(int n);

    //перегрузка операции сложения
    fraction operator +(const fraction& a);
    fraction operator +(int a);

    // перегрузка операции присваивания
    fraction& operator =(const fraction& a);
    
    // метод печати дроби
    void PrintFraction();
    //объявление дружественной функции вывода
    friend  std::ostream& operator <<(std::ostream& out, fraction a);
    //объявление дружественной операции +
    friend  fraction operator +(int b, fraction a);
};

/*обязательное объявление статической компоненты класса с инициализацией, и единственной место в программе,
где к ней можно обратиться непосредственно по имени, так как она является собственной*/
int fraction::N = 0;

/*собственная функция сокращения дроби для приведения дроби к стандартному виду, используя алгоритм Евклида для нахождения НОД */
void fraction::reduce()

{
    if ((!numerator) || (!denominator))  return;

    int a = abs(numerator), b = abs(denominator);

    while (a != b)     if (a > b) a -= b;  else b -= a;

    numerator /= a;  denominator /= b;
}

/* в конструкторе инициализируются компоненты объекта по получаемым параметрам, дробь приводится к стандартному виду - сокращается,
и увеличивается счетчик экземпляров класса;*/
fraction::fraction(int n, int d)
{
    denominator = d;
    numerator = n;
    reduce();
    N++;
}

/* в конструкторе копирования компоненты объекта копируются из дроби-параметра, и увеличивается счетчик экземпляров класса;*/
fraction::fraction(fraction& a)
{
    numerator = a.numerator; 
    denominator = a.denominator;
    N++;
}

/*деструктор отвечает только за уменьшение количества объектов */
fraction::~fraction()
{
    N--;
}

/*функции get* возвращают значение соответсвующнго компонента*/
int fraction::getNumer()
{ 
    return numerator;
}

int fraction::getDenom()
{
    return denominator;
}
//функции set* устанавливает значение соответсвующнго компонента
void fraction::setDenom(int d)

{
    if (d)
    {
        denominator = d;
        reduce(); 
    }
}

void fraction::setNumer(int n)

{
    numerator = n;
    reduce();
}

/* перегрузка оператора сложения */
fraction fraction::operator +(int a)
{
    fraction sum = *this, buf(a);
    sum.numerator = sum.numerator * buf.denominator + buf.numerator * sum.denominator;
    sum.denominator *= buf.denominator;
    sum.reduce();
    return sum;
}

fraction fraction::operator +(const fraction& b)
{
    fraction sum(*this);
    sum.numerator = sum.numerator * b.denominator + b.numerator * sum.denominator;
    sum.denominator *= b.denominator;
    sum.reduce();
    return sum;
}

fraction operator +(int a, fraction b)

{
    fraction sum(a);
    sum.numerator = sum.numerator * b.denominator + b.numerator * sum.denominator;
    sum.denominator *= b.denominator;
    sum.reduce();
    return sum;
}

/* перегрузка операции присваивания*/
fraction& fraction::operator =(const fraction& a)

{
    if (&a == this)
        return *this;

    numerator = a.numerator;

    denominator = a.denominator;

    return *this;
}

//метод печати дроби 
void fraction::PrintFraction()
{
    std::cout << this->numerator << "/" << this->denominator << std::endl;
}

std::ostream& operator <<(std::ostream& out, fraction a)
{
    return out << a.numerator << "/" << a.denominator;
}


void main()

{
    setlocale(LC_ALL, "Russian");
    std::cout << "создаем три объекта класса Дробь разными способами" << std::endl;
    fraction first(10), second(5, 3), third;

    std::cout << "Проверка метода вывода дроби в консоль" << std::endl;
    std::cout << "first = " ;
    first.PrintFraction();
    std::cout << "second = ";
    second.PrintFraction();
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Проверка перегрузки оператора + (third = first + second) " << std::endl;
    third = (first + second);
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Проверка перегрузки оператора + (third = second + 5) " << std::endl;
    third = (second + 5);
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Проверка перегрузки оператора + (third = 5 + second) " << std::endl;
    third = (5 + second);
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Получим значение числителя элемента third" << std::endl;
    std::cout << "numerator = " << third.getNumer() << std::endl;

    std::cout << "Получим значение знаменателя элемента third" << std::endl;
    std::cout << "numerator = " << third.getDenom() << std::endl;

    std::cout << "Изменим значение числителя элемента third на 25" << std::endl;
    third.setNumer(25);
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Изменим значение знаменателя элемента third на 50" << std::endl;
    third.setDenom(50);
    std::cout << "third = ";
    third.PrintFraction();

    std::cout << "Получим значение счетчика объектов - статического данного класса, используя статическую функцию класса" << std::endl;
    std::cout << "N=" << fraction::getN() << std::endl;

    std::cout << "Cоздадим новый объект, чтобы проверить работу счетчика" << std::endl;
    fraction* NewElement = new fraction(15, 23);
    std::cout << "NewElement" << std::endl;
    std::cout << *NewElement << std::endl;
    std::cout << "N=" << fraction::getN() << std::endl;
    std::cout << "Удалим новый объект операцией delete, чтобы проверить работу счетчика и деструктора" << std::endl;
    delete NewElement;
    std::cout << "N=" << fraction::getN() << std::endl;
}

