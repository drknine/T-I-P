#include <iostream>
#include <string>

// Заменяет все пробелы в строке на символ '_' (строка изменяется на месте)
void replaceSpaces(std::string& str) {
    for (char& ch : str) {
        if (ch == ' ') {
            ch = '_';
        }
    }
}

int main() {
    std::string text;

    std::cout << "введите любое предложение:" << std::endl;
    std::cout << "> ";

    std::getline(std::cin, text);   // читаем всю строку, включая пробелы

    if (text.empty()) {
        std::cout << "Вы ничего не ввели. Завершение программы." << std::endl;
        return 1;
    }

    replaceSpaces(text);

    std::cout << "\nРезультат:" << std::endl;
    std::cout << "< " << text << std::endl;

    return 0;
}