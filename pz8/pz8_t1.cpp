#include <iostream>

long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)          // если текущий бит степени равен 1
            result *= base;
        base *= base;          // возводим основание в квадрат
        exp >>= 1;             // сдвигаем степень на 1 бит вправо
    }
    return result;
}

int main() {
    long long a, n;
    std::cout << "Введите основание и степень: ";
    std::cin >> a >> n;

    std::cout << a << "^" << n << " = " << fastPow(a, n) << std::endl;
    return 0;
}