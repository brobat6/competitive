#include <iostream>
using namespace std;

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[low];
    int i = low;
    int j = high + 1;
    while(true) {
        while(arr[++i] < pivot) {
            if(i == high) break;
        }
        while(pivot < arr[--j]) {
            if(j == low) break;
        }
        if(i>=j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
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