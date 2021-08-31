#include <iostream>
using namespace std;

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

template <typename T>
void quick_sort(T arr[], int low, int high) {
    if(low < high) {
        int x = partition(arr, low, high);
        quick_sort(arr, low, x - 1);
        quick_sort(arr, x + 1, high);
    }
}

int main() {
    double arr[10] {1, 2, 5.3, 4, 3, 10, 8, 6, 9, 7};
    quick_sort(arr, 0, 9);
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
}