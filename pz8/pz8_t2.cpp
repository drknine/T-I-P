#include <iostream>

// рекурсивный НОД по алгоритму Евклида
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;          // база рекурсии
    return gcd(b, a % b);  // рекурсивный шаг
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}