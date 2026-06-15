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

    // --- СВОЙСТВА ---
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

    static string boolToString(bool result) {
        return result ? "истина" : "ложь";
    }

    /*
     --- ПЕРЕГРУЗКА ОПЕРАЦИЙ СРАВНЕНИЯ ---
     Сравнение объектов производится по значению радиуса
    */

    bool operator==(const Circle& other) const { return this->rVal == other.rVal; }
    bool operator!=(const Circle& other) const { return this->rVal != other.rVal; }
    bool operator<(const Circle& other) const { return this->rVal < other.rVal; }
    bool operator>(const Circle& other) const { return this->rVal > other.rVal; }
    bool operator<=(const Circle& other) const { return this->rVal <= other.rVal; }
    bool operator>=(const Circle& other) const { return this->rVal >= other.rVal; }
};

int main() {
    cout << "Программа выполняет операции сравнения объектов класса по значению выбранного параметра" << endl;

    cout << "Исполнитель: Новиков Д. А." << endl;
    cout << "Вариант: №14\n" << endl;

    // Создаем объекты для демонстрации сравнений
    Circle T1(0.0, 0.0, 5.0);
    Circle T2(3.0, 3.0, 3.0);
    Circle T3(5.0, -2.0, 5.0); // Окружность с таким же радиусом, как у T1, но другим центром

    cout << ">>> ИСХОДНЫЕ ОБЪЕКТЫ <<<" << endl;
    cout << "T1: "; T1.print(); cout << endl;
    cout << "T2: "; T2.print(); cout << endl;
    cout << "T3: "; T3.print(); cout << endl;

    cout << "\n>>> РЕЗУЛЬТАТЫ ОПЕРАЦИЙ СРАВНЕНИЯ <<<" << endl;
    cout << "T1 равен T2? => " << Circle::boolToString(T1 == T2) << endl;
    cout << "T1 не равен T2? => " << Circle::boolToString(T1 != T2) << endl;
    cout << "T1 равен T3? => " << Circle::boolToString(T1 == T3) << endl;
    cout << "T1 больше T2? => " << Circle::boolToString(T1 > T2)  << endl;
    cout << "T2 меньше T1? => " << Circle::boolToString(T2 < T1)  << endl;
    cout << "T1 больше либо равен T3? => " << Circle::boolToString(T1 >= T3) << endl;
    cout << "T1 меньше либо равен T3? => " << Circle::boolToString(T1 <= T3) << endl;

    return 0;
}