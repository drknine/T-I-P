#include <iostream>
#include <vector>

// слияние двух отсортированных половин массива [left..mid] и [mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // размер левой части
    int n2 = right - mid;     // размер правой части

    // временные массивы
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    // слияние обратно в arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    // дописываем остатки
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// рекурсивная сортировка слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;  // базовый случай: один элемент уже отсортирован

    int mid = left + (right - left) / 2;  // защита от переполнения

    mergeSort(arr, left, mid);        // сортируем левую половину
    mergeSort(arr, mid + 1, right);   // сортируем правую половину
    merge(arr, left, mid, right);     // сливаем
}

void mergeSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
}

// вспомогательная функция для вывода
void printArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "До сортировки: ";
    printArray(arr);

    mergeSort(arr);

    std::cout << "После сортировки: ";
    printArray(arr);
    return 0;
}