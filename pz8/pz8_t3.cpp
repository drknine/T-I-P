#include <iostream>
using namespace std;

// перекладываем n ингредиентов (нумерованы 1..n от маленького к большому)
// со стержня from на стержень to, используя aux как вспомогательный
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;                       // база рекурсии

    hanoi(n - 1, from, aux, to);              // 1) верхние n-1 → на aux
    cout << "Ingredient " << n
         << " move from " << from
         << " to " << to << "\n";             // 2) самый большой n → на to
    hanoi(n - 1, aux, to, from);              // 3) n-1 с aux → на to
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);                        // с 1-й на 3-ю через 2-ю
    return 0;
}