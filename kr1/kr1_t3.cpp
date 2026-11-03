#include <iostream>
using namespace std;

int main() {
    double c, x, y;

    cout << "Введите коэффициенты c, x, y: ";
    cin >> c >> x >> y;

    // упрощённое выражение: c(3x+5y) - y(5c-2x) = x(3c + 2y)
    double result = x * (3 * c + 2 * y);

    cout << "Значение выражения: " << result << endl;
    return 0;
}