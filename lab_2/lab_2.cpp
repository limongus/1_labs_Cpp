#include <iostream>
#include <string>

// вар 5
// 
// Прямоугольник(сторона1, сторона2) --
// Конструктор копирования.
// Конструктор полного заполнения.
// Геттер минимальной стороны. --
// Найти площадь прямоугольника. --
// Геттер всей информации(стороны, площадь)


class Rect {
	// поля
	float m_a, m_b;

	// методы
public:
	// конструктор по умолчанию
	Rect() {
		std::cout << "Конструируем... " << std::endl;
		m_a = 1;
		m_b = 2;
	}

	// конструктор копирования
	Rect(const Rect& copy) {
		m_a = copy.m_a;
		m_b = copy.m_b;
	}

	Rect(float a, float b) {
		setAB(a,b);
	}

	// конструктор полного заполнения с проверкой корректности
	void setAB(float a, float b) {
		if (a < 0) {
			std::cout << "Отрицательный a. Теперь a = 1." << std::endl;
			a = 1;
		}
		if (b < 0) {
			std::cout << "Отрицательный b. Теперь b = 1." << std::endl;
			b = 2;
		}
		m_a = a;
		m_b = b;
	}
	
	// площадь
	float area() {
		return (m_a * m_b);
	}
	
	// деструктор 
	~Rect() {
		std::cout << "Class deleted" << std::endl;
	}

	// геттер минимальной стороны
	float min_ab() const {
		return std::min(m_a, m_b);
	}

	// геттер всей информации
	std::string all() {

		std::string string_a = std::to_string(m_a);
		std::string string_b = std::to_string(m_b);
		std::string string_area = std::to_string(area());

		std::string all = "Сторона a: " + string_a + "\nСторона b: " + string_b + "\nПлощадь: " + string_area;

		return all;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	Rect r;
	//Rect copy_r{ r };
	r.setAB(10.5,8);
	
	std::cout << "Минимальная сторона: " << r.min_ab() << std::endl;
	
	std::cout << "Информация:\n " << std::endl;
	std::cout << r.all() << std::endl;
	

	return 0;
}