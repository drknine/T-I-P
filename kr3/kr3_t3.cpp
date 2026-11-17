#include <iostream>
#include <string>
#include <algorithm>  // для std::reverse

int main() {
    std::string s;
    std::cout << "Введите строку: ";
    std::getline(std::cin, s);  // читаем всю строку, включая пробелы

    std::reverse(s.begin(), s.end());

    std::cout << "Обратный порядок: " << s << '\n';
    return 0;
}