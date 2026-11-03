#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    char symbol;
    cin >> symbol;
    
    if (symbol == 'N') {
        cout << "Lyakuev Fedor" << endl;
    }
    else if (symbol == 'g') {
        // ax^2 + bx + c = 0
        if (a == 0 && b == 0 && c == 0) {
            cout << "x - любое действительное число" << endl;
        }
        else if (a == 0 && b == 0) {
            cout << "Корней нет" << endl;
        }
        else if (a == 0) {
            // bx + c = 0
            double x = -c / b;
            cout << "x = " << x << endl;
        }
        else {
            double D = b*b - 4*a*c;
            if (D < 0) {
                cout << "Корней нет" << endl;
            }
            else if (D == 0) {
                double x = -b / (2*a);
                cout << "x = " << x << endl;
            }
            else {
                double x1 = (-b - sqrt(D)) / (2*a);
                double x2 = (-b + sqrt(D)) / (2*a);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
        }
    }
    else if (symbol == 'z') {
        double celsius;
        cout << "Введите температуру в градусах Цельсия: ";
        cin >> celsius;
        double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
        cout << "Температура в градусах Фаренгейта: " << fahrenheit << endl;
    }
    
    return 0;
}