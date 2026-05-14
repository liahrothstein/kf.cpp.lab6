#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Complex {
private:
    double re; // вещественная часть
    double im; // мнимая часть

public:
    // Конструктор
    Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}

    // Вычисление модуля
    double Modul() const {
        return sqrt(re * re + im * im);
    }

    // Преобразование комплексного числа в строку для удобного вывода
    string Output() const {
        string s = to_string(re);
        if (im >= 0) {
            s += "+" + to_string(im) + "i";
        } else {
            s += "-" + to_string(abs(im)) + "i";
        }
        return s;
    }

    // Вывод информации
    void Info() const {
        cout << "Комплексное число: " << Output() 
                  << " | Модуль = " << Modul() << endl;
    }

    // --- Перегрузка операций ---

    // Сложение
    Complex operator+(const Complex& b) const {
        return Complex(re + b.re, im + b.im);
    }

    // Вычитание
    Complex operator-(const Complex& b) const {
        return Complex(re - b.re, im - b.im);
    }

    // Умножение
    Complex operator*(const Complex& b) const {
        return Complex(re * b.re - im * b.im, re * b.im + im * b.re);
    }

    // Деление
    Complex operator/(const Complex& b) const {
        double denominator = b.re * b.re + b.im * b.im;
        return Complex((re * b.re + im * b.im) / denominator,
                       (im * b.re - re * b.im) / denominator);
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(6, 7);

    cout << "--- Исходные числа ---\n";
    c1.Info();
    c2.Info();

    cout << "\n--- Результаты операций ---\n";
    
    Complex c3 = c1 + c2;
    cout << "Сложение (c1 + c2)  = " << c3.Output() << endl;

    Complex c4 = c1 - c2;
    cout << "Вычитание (c1 - c2) = " << c4.Output() << endl;

    Complex c5 = c1 * c2;
    cout << "Умножение (c1 * c2) = " << c5.Output() << endl;

    Complex c6 = c1 / c2;
    cout << "Деление (c1 / c2)   = " << c6.Output() << endl;

    return 0;
}