#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

struct Movie {
    std::string title;
    int year;
};

// разбор одной строки формата "название;год".
// используем rfind, чтобы корректно работать с пробелами в названии.
bool parseLine(const std::string& line, Movie& movie) {
    std::size_t pos = line.rfind(';');
    if (pos == std::string::npos) return false;

    std::string title = line.substr(0, pos);
    std::string yearStr = line.substr(pos + 1);

    // обрезаем возможные \r
    if (!yearStr.empty() && yearStr.back() == '\r')
        yearStr.pop_back();

    // обрезаем пробелы вокруг названия
    std::size_t first = title.find_first_not_of(" \t");
    std::size_t last  = title.find_last_not_of(" \t");
    if (first == std::string::npos) return false;  // пустое название
    movie.title = title.substr(first, last - first + 1);

    // парсим год с проверкой
    try {
        std::size_t processed = 0;
        movie.year = std::stoi(yearStr, &processed);
        return processed == yearStr.size();
    } catch (...) {
        return false;
    }
}

int main() {
    std::string inputFile  = "movies.txt";
    std::string outputFile = "filtered_movies.txt";

    int threshold;
    std::cout << "Введите год, после которого оставлять фильмы: ";
    if (!(std::cin >> threshold)) {
        std::cerr << "Некорректный год.\n";
        return 1;
    }

    std::ifstream in(inputFile);
    if (!in.is_open()) {
        std::cerr << "Не удалось открыть файл \"" << inputFile << "\"\n";
        return 1;
    }

    std::ofstream out(outputFile);
    if (!out.is_open()) {
        std::cerr << "Не удалось создать файл \"" << outputFile << "\"\n";
        return 1;
    }

    std::vector<Movie> kept;
    std::string line;
    int lineNo = 0, skipped = 0;

    while (std::getline(in, line)) {
        ++lineNo;
        if (line.empty()) continue;

        Movie m;
        if (!parseLine(line, m)) {
            std::cerr << "  строка " << lineNo
                      << " пропущена (некорректный формат): \"" << line << "\"\n";
            ++skipped;
            continue;
        }
        if (m.year > threshold) {
            kept.push_back(m);
            out << m.title << ';' << m.year << '\n';
        }
    }

    in.close();
    out.close();

    std::cout << "\nНайдено фильмов: " << kept.size()
              << " (пропущено строк: " << skipped << ")\n";
    std::cout << "Результат записан в \"" << outputFile << "\":\n\n";
    for (const auto& m : kept) {
        std::cout << "  " << m.title << " (" << m.year << ")\n";
    }

    return 0;
}