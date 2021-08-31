#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Vector {
private:
    T* arr;
    int size;
    int capacity;
    void double_capacity() {
        capacity *= 2;
        T* grr = new T[capacity];
        for(int i=0; i<size; i++) grr[i] = arr[i];
        delete[] arr;
        arr = grr;
    }
public:
    Vector() : size{0}, capacity{1} {
        Initialize();
    }
    void Initialize() {
        T* grr = new T[1];
        delete[] arr;
        arr = grr;
    }
    void Push_Back(T val) {
        if(size==capacity) double_capacity();
        arr[size] = val;
        size += 1;
    }
    void Push_Back_Array(T grr[], int len) {
        for(int i=0; i<len; i++) Push_Back(grr[i]);
    }
    bool IsEmpty() const { return (size == 0);}
    void Pop_Back() {
        assert(size > 0);
        size -= 1;
    }
    void Clear() {
        size = 0;
        capacity = 1;
        Initialize();
    }
    T First() const {
        assert(size > 0);
        return arr[0];
    }
    T Last() const {
        assert(size > 0);
        return arr[size - 1];
    }
    int Capacity() const { return capacity;}
    int Size() const {return size;}
    T GetElementAtIndex(const int& index) {
        assert(index>=0 && index<size);
        return arr[index];
    }
    void EraseElementAtIndex(const int& index) {
        assert(index>=0 && index<size);
        for(int i = index+1; i<size; i++) {
            arr[i-1] = arr[i]; 
        }
        size -= 1;
    }
    ~Vector() { Clear();}
};

int main() {
    Vector <int> v;
    v.Push_Back(10);
    cout << v.First() << endl;
    int a[] = {10, 20, 30};
    v.Push_Back_Array(a, 3);
    cout << v.Last() << endl;
    cout << v.GetElementAtIndex(1) << endl;
    v.EraseElementAtIndex(1);
    cout << v.GetElementAtIndex(1) << endl;
    v.Push_Back_Array(a, 3);
    int s = v.Size();
    cout << "The elements of the vector are - ";
    for(int i=0; i<s; i++) {
        cout << v.GetElementAtIndex(i) << " ";
    }
}