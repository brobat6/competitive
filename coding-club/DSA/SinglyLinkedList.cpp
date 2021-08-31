#include <iostream>
#include <cassert>
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
    void Initialize(const T& val) {
        head = new Node<T>(val);
        tail = head;
        count = 1;
    }
    void DestroyList() {
        count = 0;
        if(head==nullptr) return;
        while(head != tail) {
            auto temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
        head = tail = nullptr;
    }
    Node<T>* GotoIndex(int index) const {
        assert(index >=0 && index < count);
        auto temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    LinkedList() : head{nullptr}, tail{nullptr}, count{0} {}
    LinkedList(const T* arr, int len) : count{len} {
        assert(len > 0);
        head = new Node<T>(arr[0]);
        tail = head;
        for(int i=1; i<len; i++) {
            tail->next = new Node<T>(arr[i]);
            tail = tail->next;
        }
    }
    LinkedList(const LinkedList<T>& oldList) : count{oldList.count} {
        assert(count>0);
        auto temp = oldList.head;
        head = new Node<T>(temp->data);
        tail = head;
        for(int i=1; i<count; i++) {
            temp = temp->next;
            tail->next = new Node<T>(temp->data);
            tail = tail->next;
        }
    }
    ~LinkedList() {DestroyList();}
    Node<T>* First() const {return head;}
    Node<T>* Last() const {return tail;}
    int Length() {return count;}
    bool IsEmpty() const {return count==0;}
    LinkedList<T>* AddAtFirst(const T& val) {
        if(count==0) {
            count = 1;
            head = new Node<T>(val);
            tail = head;
            return this;
        }
        auto temp = new Node<T>(val);
        temp->next = head;
        head = temp;
        count += 1;
        return this;
    }
    LinkedList<T>* AddAfterIndex(const T& val, int index) {
        assert(index >=0 && index < count);
        if(index==count - 1) return AddAtLast(val);
        auto temp = GotoIndex(index);
        auto temp2 = temp->next;
        temp->next = new Node<T>(val);
        temp->next->next = temp2;
        count += 1;
        return this;
    }
    LinkedList<T>* AddBeforeIndex(const T& val, int index) {
        assert(index >=0 && index < count);
        if(index==0) return AddAtFirst(val);
        return AddAfterIndex(val, index - 1);
    }
    LinkedList<T>* AddAtLast(const T& val) {
        if(count==0) return AddAtFirst(val);
        auto temp = new Node<T>(val);
        tail->next = temp;
        tail = temp;
        count += 1;
        return this;
    }
    LinkedList<T>* DeleteAtFirst() {
        assert(!IsEmpty());
        count -= 1;
        if(head==tail) {
            DestroyList();
            return nullptr;
        }
        auto temp = head->next;
        delete head;
        head = temp;
        return this;
    }
    LinkedList<T>* DeleteAtIndex(int index) {
        assert(index>=0 && index<count);
        if(index==0) return DeleteAtFirst();
        if(index==count-1) return DeleteAtLast();
        auto temp1 = GotoIndex(index - 1);
        auto temp2 = temp1->next;
        auto temp3 = temp2->next;
        delete temp2;
        temp1->next = temp3;
        count -= 1;
        return this;
    }
    LinkedList<T>* DeleteAtLast() {
        assert(!IsEmpty());
        count -= 1;
        if(head==tail) {
            DestroyList();
            return this;
        }
        auto temp = GotoIndex(count - 1);
        delete temp->next;
        temp->next = nullptr;
        tail = temp;
        return this;
    }
    T* ToArray() const {
        assert(count>0);
        T* arr = new T[count];
        auto temp = head;
        arr[0] = temp->data;
        for(int i=1; i<count; i++) {
            temp = temp->next;
            arr[i] = temp->data;
        }
        return arr;
    }
    T* ToReverseArray() const {
        assert(count>0);
        T* a = ToArray();
        T* b = new T[count];
        for(int i=0; i<count; i++) b[i] = a[count - 1 - i];
        delete[] a;
        return b;
    }
    void Print() const{
        auto temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int* arr = new int[5]{10,20,30,40,50};
    int len = 5;
    auto l = new LinkedList<int>(arr, len);
    l->Print(); // 10 20 30 40 50
    l->AddAtFirst(5);
    l->Print(); // 5 10 20 30 40 50
    l->AddAtLast(60);
    l->Print(); // 5 10 20 30 40 50 60
    l->DeleteAtFirst();
    l->Print(); // 10 20 30 40 50 60
    l->DeleteAtLast();
    l->Print(); // 10 20 30 40 50
    l->DeleteAtIndex(2);
    l->Print(); // 10 20 40 50
    l->AddAfterIndex(6, 2);
    l->Print(); // 10 20 40 6 50
    l->AddBeforeIndex(9, 4);
    l->Print(); // 10 20 40 6 9 50
    auto m = new LinkedList<int>(*l); // 10 20 40 6 9 50
    l->AddAtLast(109)->AddAtFirst(22);
    l->Print(); // 22 10 20 40 6 9 50 109
    int* grr = l->ToArray(); // 10 20 40 6 9 50
    int* brr = l->ToReverseArray(); // 50 9 6 40 20 10
    auto n = new LinkedList<int>();
    n->AddAtFirst(20);
    n->AddAtFirst(10);
    n->Print(); // 10 20
    return 0;
}