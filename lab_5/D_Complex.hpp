#pragma once

// 6 лаба наследование классов  (разбиение на файлы, насл. итд)
#include <iostream>
#include <cmath>

namespace sk {
    class D_Complex {
        float k_Re; // действительная часть числа (по оси оX)
        float k_Im; // мнимая часть числа (по оси оY)
    public:
        D_Complex() {
            k_Re = 1;
            k_Im = 0;
        };
        D_Complex(float Re, float Im) {
            k_Re = Re;
            k_Im = Im;
        }
        D_Complex(const D_Complex& copy) {
            k_Re = copy.k_Re;
            k_Im = copy.k_Im;
        }
        ~D_Complex() {
            std::cout << "комплексное число " << k_Re << " + " << k_Im << "i" << " удалено." << std::endl;
        }

        float Re() {
            return k_Re;
        }
        float Im() {
            return k_Im;
        }

        // Операторы

        D_Complex& operator = (const D_Complex& copy) {
            k_Re = copy.k_Re;
            k_Im = copy.k_Im;
            return *this;
        }
        D_Complex& operator+=(const D_Complex& copy) {
            k_Re += copy.k_Re;
            k_Im += copy.k_Im;
            return *this;
        }
        D_Complex operator+( D_Complex& other) {
            return D_Complex(k_Re + other.k_Re, k_Im + other.k_Im);
        }
        D_Complex& operator*= (D_Complex& other) {
            float new_Re = k_Re * other.k_Re - k_Im * other.k_Im;
            float new_Im = k_Re * other.k_Im + k_Im * other.k_Re;
            k_Re = new_Re;
            k_Im = new_Im;
            return *this;
        }
        D_Complex operator* (D_Complex& other) {
            return D_Complex(k_Re * other.k_Re - k_Im * other.k_Im, k_Re * other.k_Im + k_Im * other.k_Re);
        }
        // Префиксный оператор ++ (через цикл)
        D_Complex& operator++ () {
            ++k_Re;
            return *this;
        }
        // Постфиксный оператор ++ (через цикл)
        D_Complex operator++ (int) {
            D_Complex temp(*this);
            k_Re++;
            return temp;
        }
        // Оператор ввода
        friend std::istream& operator>>(std::istream& in, D_Complex& z) {
            in >> z.k_Re >> z.k_Im;
            return in;
        }
        // Оператор вывода
        friend std::ostream& operator<<(std::ostream& out, const D_Complex& z) {
            out << z.k_Re << " + " << z.k_Im << "i";
            return out;
        }
        // Модуль комплексного числа
        double abs() {
            return sqrt(k_Re * k_Re + k_Im * k_Im);
        }
    };

    // Поиск скалярного произведения двух радиус-векторов
    double scalar(D_Complex a, D_Complex b) {
        return a.Re() * b.Re() + a.Im()* b.Im();
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
        else if (a.Re() <= 0 and a.Im() < 0){
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
}