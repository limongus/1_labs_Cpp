#include <iostream>

// вар 5
// Реализуйте класс D_Complex для работы с комплексными числами в формате a + bi. Он должен включать:

// 1.	Базовые конструкторы(по умолчанию, полного заполнения)
// 2.	Конструктор копирования
// 3.	Оператор присваивания копированием
// 4.	Деструктор с соответствующей записью в консоли
// 5.	Операторы += и + , *= и *
// 6.	Оператор ++ префиксный и постфиксный(увеличение действительной части числа на 1)
// 7.	Операторы ввода и вывода

// Реализуйте след. функции для работы с классами по варианту*:

// – Поиск скалярного произведения двух радиус - векторов, соответствующих комплексным числам.
//	 (type scalarС(type a, type b))
// – Поиск максимального по модулю комплексного числа.
//	 (type absС(type a, type b))
// – Поиск квадранта в котором располагается радиус - вектор.
//	 (type qC(type a))

class D_Complex {

private:
	float a; // действительная часть
	float b; // комплексная часть

public:
	// конструктор по умолчанию
	D_Complex() {
		std::cout << "Конструируем... " << std::endl;
		a = 0;
		b = 0;
	}

	// конструктор полного заполнения
	D_Complex(float Re, float Im) {
		a = Re;
		b = Im;
	}

	// конструктор копирования
	D_Complex(const D_Complex& other) {
		a = other.a;
		b = other.b;
	}

	// оператор присваивания копированием
	D_Complex& operator=(const D_Complex& other) {
		a = other.a;
		b = other.b;

		return *this;
	}

	// деструктор
	~D_Complex() {
		std::cout << "комплексное число " << a << " + " << b << "i" << " удалено." << std::endl;
	}

	// операторы += и +
	D_Complex& operator+=(D_Complex& other) {
		a += other.a;
		b += other.b;

		return *this;
	}
	D_Complex operator+(D_Complex& other) {

		return D_Complex(a + other.a, b + other.b);
	}

	// операторы *= и *
	// (a + bi) · (c + di) = (ac – bd) + (ad + bc)i
	D_Complex& operator*=(D_Complex& other) {
		float new_A = a * other.a - b * other.b;
		float new_B = a * other.b + b * other.a;
		a = new_A;
		b = new_B;

		return *this;
	}
	D_Complex operator*(const D_Complex& other) {

		return D_Complex(a * other.a - b * other.b, a * other.b + b * other.a);
	}

	// оператор ++ префиксный(++a) и постфиксный(a++)
	D_Complex& operator++() {
		++a;
		return *this;
	}
	D_Complex& operator++(int value) {
		D_Complex temp(*this);
		//this->a++;
		++(*this);
		return temp;
	}

	// операторы ввода и вывода
	friend std::istream& operator>>(std::istream& in, D_Complex& z) {
		in >> z.a >> z.b;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const D_Complex& z) {
		out << z.a << " + " << z.b << "i";
		return out;
	}

	// модуль комплексного числа
	// |a + bi| = sqrt(a^2 + b^2)
	float abs() {
		return sqrt(a * a + b * b);
	}

	float Re() {
		return a;
	}
	float Im() {
		return b;
	}
};

// Поиск скалярного произведения двух радиус-векторов
float scalar(D_Complex a, D_Complex b) {
	return a.Re() * b.Re() + a.Im() * b.Im();
}

// Поиск квадранта, в котором располагается радиус-вектор
int qC(D_Complex a) {
	if (a.Re() > 0 and a.Im() >= 0) {
		return 1;
	}
	else if (a.Re() <= 0 and a.Im() > 0) {
		return 2;
	}
	else if (a.Re() < 0 and a.Im() <= 0) {
		return 3;
	}
	else if (a.Re() <= 0 and a.Im() < 0) {
		return 4;
	}
	else if (a.Re() == 0 and a.Im() == 0) {
		return 1;
	}
}

// максимальный модуль
D_Complex max_abs(D_Complex a, D_Complex b) {
	if (a.abs() > b.abs()) {
		return a;
	}
	else if (a.abs() < b.abs()) {
		return b;
	}
	else {
		std::cout << "модули равны" << std::endl;
		return a;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	std::cout << "// конструктор по умолчанию" << std::endl;
	D_Complex A;
	std::cout << "A = " << A << std::endl;
	std::cout << "\n";
	
	D_Complex B(2, 2);
	std::cout << "B = " << B << std::endl;
	std::cout << "\n";

	std::cout << "// конструктор копирования" << std::endl;
	D_Complex C = B;
	std::cout << "C = B = " << C << std::endl;
	std::cout << "\n";

	std::cout << "// операторы" << std::endl;
	B+=C;
	std::cout << "B = " << B << std::endl;

	D_Complex D = B + C;
	std::cout << "D = " << D << std::endl;

	D_Complex E(3,2);
	D_Complex F(2,1);

	std::cout << "E = " << E << std::endl;
	std::cout << "F = " << F << std::endl;
	E *= F;
	std::cout << "E*=F = " << E << std::endl;
	std::cout << "\n";

	D_Complex Q(3, 2);
	D_Complex W(7, 5);
	std::cout << "Q = " << Q << std::endl;
	std::cout << "W = " << W << std::endl;
	std::cout << "Q * W = " << Q*W << std::endl;
	std::cout << "\n";

	D_Complex T;
	std::cout << "число T: введите дейсвительную, затем мнимую часть" << std::endl;
	std::cin >> T;
	std::cout << "T = " << T << std::endl;
	std::cout << "\n";


	std::cout << "B = " << B << std::endl;

	for (int i = 0; i < 5; i++) {
		B++;
		//std::cout << "B = " << B << std::endl;
	}
	std::cout << "\n";
	
	for (int i = 0; i < 5; i++) {
		++A;
		//std::cout << "A = " << A << std::endl;
	}

	// модуль
	std::cout << "модуль числа D: " << D.abs() << std::endl;

	// cкалярное произведение
	std::cout << "скалярное произведение E и F: " << scalar(E, F) << std::endl;

	// rвадрант
	std::cout << "квадрант G: " << qC(Q) << std::endl;

	// максимальный модуль
	std::cout << "макс. модуль (W = " << W << "; Q = " << Q << "): " << max_abs(W, Q) << std::endl;
	

	return 0;
}