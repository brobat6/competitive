#include <iostream>
using namespace std;

template <class T>
class Node {
    T data;
    Node<T>* next;
public:
    Node() : next{nullptr} {}
    Node(const T& value) : data{value}, next{nullptr} {}
    template <class X> friend class LinkedList;
};

template <class T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int count;
    LinkedList() : head{nullptr}, tail{nullptr}, count{0} {}
    void AddAtLast(const T& val) {
        if(count==0) {
            head = new Node<T>(val);
            tail = head;
        }
        else {
            auto temp = new Node<T>(val);
            tail->next = temp;
            tail = temp;
        }
        count += 1;
    }
    void PrintForward(){
        auto temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Reverse() {
        auto current = head;
        auto next = head->next;
        current->next = nullptr;
        auto previous = current;
        current = next;
        while(current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    void PrintBackWard(){
        Reverse();
        PrintForward();
        Reverse();
    }
};

int main() {
    auto l = new LinkedList<int>();
    l->AddAtLast(20);
    l->AddAtLast(30);
    l->AddAtLast(50);
    l->PrintForward();
    l->PrintBackWard();
    l->AddAtLast(100);
    l->PrintBackWard();
    l->PrintForward();
}