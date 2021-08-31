#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node() : next{nullptr}, previous{nullptr} {}
    Node(const T& value) : data{value}, next{nullptr}, previous{nullptr} {}
};

template <class T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int count;
    LinkedList<T>* Initialize(const T& val) {
        assert(count==0);
        head = new Node<T>(val);
        tail = head;
        count = 1;
        return this;
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
        assert(index >= 0 && index < count);
        auto temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    inline void Join(Node<T>* lhs, Node<T>* rhs) {
        lhs->next = rhs;
        rhs->previous = lhs;
    }
    inline void Join(Node<T>* lhs, Node<T>* middle, Node<T>* rhs) {
        Join(lhs, middle);
        Join(middle, rhs);
    }
    LinkedList() : head{nullptr}, tail{nullptr}, count{0} {}
    LinkedList(const T* arr, int len) : count{len} {
        assert(count > 0);
        head = tail = new Node<T>(arr[0]);
        for(int i=1; i<len; i++) {
            auto temp = new Node<T>(arr[i]);
            Join(tail, temp);
            tail = temp;
        }
    }
    LinkedList(const LinkedList<T>& oldList) : count{oldList.count} {
        assert(count > 0);
        auto temp = oldList.head;
        head = tail = new Node<T>(temp->data);
        for(int i=1; i<count; i++) {
            temp = temp->next;
            auto temp2 = new Node<T>(temp->data);
            Join(tail, temp2);
            tail = temp2;
        }
    }
    Node<T>* First() const {return head;}
    Node<T>* Last() const {return tail;}
    int Length() const {return count;}
    bool IsEmpty() const {return count==0;}
    LinkedList<T>* AddAtFirst(const T& val) {
        if(head==nullptr) return Initialize(val);
        auto temp = new Node<T>(val);
        Join(temp, head);
        head = temp;
        count += 1;
        return this;
    }
    LinkedList<T>* AddAtLast(const T& val) {
        if(head==nullptr) return Initialize(val);
        auto temp = new Node<T>(val);
        Join(tail, temp);
        tail = temp;
        count += 1;
        return this;
    }
    LinkedList<T>* AddAfterIndex(const T& val, int index) {
        assert(index>=0 && index<count);
        if(index==count - 1) return AddAtLast(val);
        auto temp = new Node<T>(val);
        auto ptr = GotoIndex(index);
        Join(ptr, temp, ptr->next);
        return this;
    }
    LinkedList<T>* AddBeforeIndex(const T& val, int index) {
        assert(index>=0 && index<count);
        if(index==0) return AddAtFirst(val);
        return AddAfterIndex(val, index - 1);
    }
    void Print(const char* seperator = " ") const {
        auto temp = head;
        while(temp != nullptr) {
            cout << temp->data << seperator;
            temp = temp->next;
        }
        cout << endl;
    }
    LinkedList<T>* DeleteAtFirst() {
        assert(count > 0);
        if(count==1) {
            DestroyList();
            return nullptr;
        }
        auto temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
        count -= 1;
        return this;
    }
    LinkedList<T>* DeleteAtLast() {
        assert(count > 0);
        if(count==1) return DeleteAtFirst();
        auto temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
        count -= 1;
        return this;
    }
    LinkedList<T>* DeleteAtIndex(int index) {
        assert(count > 0);
        if(index==0) return DeleteAtFirst();
        if(index==count - 1) return DeleteAtLast();
        auto temp = GotoIndex(index);
        Join(temp->previous, temp->next);
        delete temp;
        return this;
    }
    T* ToArray() const {
        assert(count > 0);
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
        assert(count > 0);
        T* arr = new T[count];
        auto temp = tail;
        arr[0] = temp->data;
        for(int i=1; i<count; i++) {
            temp = temp->previous;
            arr[i] = temp->data;
        }
        return arr;
    }
    Node<T>* FindFirstOccurence(const T& value) const {
        assert(count > 0);
        auto temp = head;
        while(temp != nullptr) {
            if(temp->data == value) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    ~LinkedList() {DestroyList();}
};

int main() {
    auto l = new LinkedList<int>();
    l->AddAtFirst(10);
    l->Print(); // 10
    l->AddAtLast(20);
    l->Print(); // 10 20
    l->AddAfterIndex(30, 1);
    l->Print(); // 10 20 30
    l->AddBeforeIndex(40, 0);
    l->Print(); // 40 10 20 30
    l->DeleteAtFirst();
    l->Print(); // 10 20 30
    l->DeleteAtIndex(1);
    l->Print(); // 10 30
    l->AddBeforeIndex(50, 1);
    l->Print(); // 10 50 30
    cout << l->FindFirstOccurence(10)->data << endl;
    cout << (l->FindFirstOccurence(120)==nullptr) << endl;
}


