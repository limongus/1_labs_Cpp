#pragma once

// 6 ���� ������������ �������  (��������� �� �����, ����. ���)
#include <iostream>
#include <cmath>

namespace sk {
    class D_Complex {
        float k_Re; // �������������� ����� ����� (�� ��� �X)
        float k_Im; // ������ ����� ����� (�� ��� �Y)
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
            std::cout << "����������� ����� " << k_Re << " + " << k_Im << "i" << " �������." << std::endl;
        }

        float Re() {
            return k_Re;
        }
        float Im() {
            return k_Im;
        }

        // ���������

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
        // ���������� �������� ++ (����� ����)
        D_Complex& operator++ () {
            ++k_Re;
            return *this;
        }
        // ����������� �������� ++ (����� ����)
        D_Complex operator++ (int) {
            D_Complex temp(*this);
            k_Re++;
            return temp;
        }
        // �������� �����
        friend std::istream& operator>>(std::istream& in, D_Complex& z) {
            in >> z.k_Re >> z.k_Im;
            return in;
        }
        // �������� ������
        friend std::ostream& operator<<(std::ostream& out, const D_Complex& z) {
            out << z.k_Re << " + " << z.k_Im << "i";
            return out;
        }
        // ������ ������������ �����
        double abs() {
            return sqrt(k_Re * k_Re + k_Im * k_Im);
        }
    };

    // ����� ���������� ������������ ���� ������-��������
    double scalar(D_Complex a, D_Complex b) {
        return a.Re() * b.Re() + a.Im()* b.Im();
    }

    // ����� ���������, � ������� ������������� ������-������
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

    // ������������ ������
    D_Complex max_abs(D_Complex a, D_Complex b) {
        if (a.abs() > b.abs()) {
            return a;
        }
        else if (a.abs() < b.abs()) {
            return b;
        }
        else {
            std::cout << "������ �����" << std::endl;
            return a;
        }
    }
}