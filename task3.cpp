#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Circle {
private:
    double x;
    double y;
    double radius;

public:
    // Конструктор по умолчанию с параметрами
    Circle(double xVal = 0.0, double yVal = 0.0, double rVal = 0.0)
        : x(xVal), y(yVal), radius(abs(rVal)) {}

    // Метод для удобного вывода объекта
    void print(const string& name) const {
        cout << name << ": Центр(" << x << ", " << y 
                  << "), Радиус = " << radius << "\n";
    }

    bool operator>(const Circle& other) const { return radius > other.radius; }
    bool operator<(const Circle& other) const { return radius < other.radius; }
    bool operator>=(const Circle& other) const { return radius >= other.radius; }
    bool operator<=(const Circle& other) const { return radius <= other.radius; }
    bool operator==(const Circle& other) const { return radius == other.radius; }
    bool operator!=(const Circle& other) const { return radius != other.radius; }
};

int main() {
    cout << "Программа выполняет операции сравнения объектов класса по значению выбранного параметра" << endl;

    cout << "\nИсполнитель: Новиков Д. А." << endl;
    cout << "Вариант: №14\n" << endl;

    // Создание трех исходных объектов с произвольными параметрами
    Circle T1(1.0, 1.0, 5.0);
    Circle T2(2.0, -2.0, 3.0);
    Circle T3(0.0, 0.0, 10.0);

    cout << "--- Исходные объекты ---\n";
    T1.print("T1");
    T2.print("T2");
    T3.print("T3");
    cout << "\n";

    // Результаты операций сравнения
    cout << "--- Результаты сравнения по радиусу (Задача 3) ---\n";
    cout << "T1 > T2  : " << (T1 > T2 ? "Истина" : "Ложь") << "\n";
    cout << "T2 == T3 : " << (T2 == T3 ? "Истина" : "Ложь") << "\n";
    cout << "T3 >= T1 : " << (T3 >= T1 ? "Истина" : "Ложь") << "\n";
    cout << "T1 != T2 : " << (T1 != T2 ? "Истина" : "Ложь") << "\n";

    return 0;
}