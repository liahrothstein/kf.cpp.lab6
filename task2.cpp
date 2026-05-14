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

    // Сложение объектов (складываются координаты и радиусы)
    Circle operator+(const Circle& other) const {
        return Circle(x + other.x, y + other.y, radius + other.radius);
    }

    // Вычитание объектов (координаты вычитаются, радиус берется по модулю, чтобы не был < 0)
    Circle operator-(const Circle& other) const {
        return Circle(x - other.x, y - other.y, abs(radius - other.radius));
    }

    // Умножение на вещественное число СПРАВА (Circle * double)
    Circle operator*(double scalar) const {
        return Circle(x * scalar, y * scalar, radius * abs(scalar));
    }

    // Умножение на вещественное число СЛЕВА (double * Circle)
    // Реализуется через дружественную функцию, так как левый операнд не является объектом класса
    friend Circle operator*(double scalar, const Circle& c) {
        return c * scalar; // используем уже написанный оператор "справа"
    }
};

int main() {
    cout << "Программа выполняет: сложения объектов, вычитания объектов и умножения объектов на вещественное число справа и слева" << endl;

    cout << "\nИсполнитель: Новиков Д. А." << endl;
    cout << "Вариант: №14\n" << endl;

    // Создание трех исходных объекова с произвольными параметрами
    Circle T1(1.0, 1.0, 5.0);
    Circle T2(2.0, -2.0, 3.0);
    Circle T3(0.0, 0.0, 10.0);

    cout << "--- Исходные объекты ---\n";
    T1.print("T1");
    T2.print("T2");
    T3.print("T3");
    cout << "\n";

    // Вычисления новых объектов
    Circle T4 = T1 + T2;
    Circle T5 = T1 - T2;
    Circle T6 = 2.0 * T1 + T2 * 3.0;
    Circle T7 = 2.0 * T1 - 3.0 * T2 + T3;

    cout << "--- Результаты вычислений ---\n";
    T4.print("T4 (T1 + T2)");
    T5.print("T5 (T1 - T2)");
    T6.print("T6 (2*T1 + T2*3)");
    T7.print("T7 (2*T1 - 3*T2 + T3)");
    cout << "\n";

    return 0;
}