#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // std::set хранит только уникальные значения
    set<int> uniqueElements(arr.begin(), arr.end());

    cout << "Количество уникальных элементов: "
         << uniqueElements.size() << endl;

    return 0;
}