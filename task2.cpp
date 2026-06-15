#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double xVal;      // Координата центра X
    double yVal;      // Координата центра Y
    double rVal;      // Радиус окружности

public:
    // --- КОНСТРУКТОРЫ ---
    Circle() : xVal(0.0), yVal(0.0), rVal(1.0) {}

    Circle(double x, double y, double r) : xVal(x), yVal(y) {
        rVal = (r >= 0) ? r : 0;
    }

    // --- СВОЙСТВА (Getters / Setters) ---
    double X() const { return xVal; }
    void X(double value) { xVal = value; }

    double Y() const { return yVal; }
    void Y(double value) { yVal = value; }

    double Radius() const { return rVal; }
    void Radius(double value) {
        if (value >= 0) rVal = value;
    }

    // --- МЕТОДЫ ---
    void print() const {
        cout << "Центр(" << xVal << ", " << yVal << "), R = " << rVal;
    }

    // --- ПЕРЕГРУЗКА АРИФМЕТИЧЕСКИХ ОПЕРАЦИЙ ---

    // Сложение объектов: T1 + T2
    Circle operator+(const Circle& other) const {
        return Circle(this->xVal, this->yVal, this->rVal + other.rVal);
    }

    // Вычитание объектов: T1 - T2
    Circle operator-(const Circle& other) const {
        double newRadius = this->rVal - other.rVal;
        return Circle(this->xVal, this->yVal, newRadius);
    }

    // Умножение на число справа: T1 * number
    Circle operator*(double num) const {
        return Circle(this->xVal, this->yVal, this->rVal * num);
    }

    /*
     Умножение на число слева: number * T1
     Используется дружественная функция (friend), так как левый операнд типа double
    */
    friend Circle operator*(double num, const Circle& c) {
        return Circle(c.xVal, c.yVal, c.rVal * num);
    }
};

int main() {
    cout << "Программа выполняет: сложения объектов, вычитания объектов и умножения объектов на вещественное число справа и слева" << endl;

    cout << "Исполнитель: Новиков Д. А." << endl;
    cout << "Вариант: №14\n" << endl;

    // Создаем три исходных объекта T1, T2, T3 с произвольными параметрами
    Circle T1(0.0, 0.0, 5.0);
    Circle T2(1.0, 2.0, 3.0);
    Circle T3(-1.0, -1.0, 2.0);

    cout << ">>> ИСХОДНЫЕ ОБЪЕКТЫ <<<" << endl;
    cout << "T1: "; T1.print(); cout << endl;
    cout << "T2: "; T2.print(); cout << endl;
    cout << "T3: "; T3.print(); cout << endl;

    cout << "\n>>> ВЫЧИСЛЕНИЯ <<<" << endl;

    // Формула: T4 = T1 + T2
    Circle T4 = T1 + T2;
    cout << "T4 (T1 + T2)         = "; T4.print(); cout << endl;

    // Формула: T5 = T1 - T2
    Circle T5 = T1 - T2;
    cout << "T5 (T1 - T2)         = "; T5.print(); cout << endl;

    // Формула: T6 = 2 * T1 + T2 * 3
    Circle T6 = 2 * T1 + T2 * 3;
    cout << "T6 (2*T1 + T2*3)     = "; T6.print(); cout << endl;

    // Формула: T7 = 2 * T1 - 3 * T2 + T3
    Circle T7 = 2 * T1 - 3 * T2 + T3;
    cout << "T7 (2*T1 - 3*T2 + T3) = "; T7.print(); cout << endl;

    return 0;
}