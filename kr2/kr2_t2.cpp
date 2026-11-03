#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

int main() {
    int rows, cols;

    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Размеры массива должны быть положительными." << endl;
        return 1;
    }

    // исходный и целевой двумерные массивы
    vector<vector<int>> source(rows, vector<int>(cols));
    vector<vector<int>> destination(rows, vector<int>(cols));

    // генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100); // случайные числа от 1 до 100

    // заполняем исходный массив случайными числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            source[i][j] = dist(gen);
        }
    }

    // копируем элементы из source в destination
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            destination[i][j] = source[i][j];
        }
    }

    // выводим исходный массив
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << source[i][j];
        }
        cout << endl;
    }

    // выводим скопированный массив
    cout << "\nСкопированный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << destination[i][j];
        }
        cout << endl;
    }

    return 0;
}