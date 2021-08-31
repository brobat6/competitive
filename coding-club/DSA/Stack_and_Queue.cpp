#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Node {
public:
    T val;
    Node* next;
    Node() : next{nullptr} {}
    Node(const T& val, Node<T>* next = nullptr) : val{val}, next{next} {}
};

template <class T>
class Stack {
private:
    Node<T>* head;
    int count;
public:
    Stack() : count{0}, head{nullptr} {}
    bool IsEmpty() const { return (count==0);}
    Stack<T>* Push(const T& val) {
        auto temp = new Node<T>(val, head);
        temp->next = head;
        head = temp;
        count += 1;
        return this;
    }
    void Pop() {
        assert(count > 0);
        auto temp = head->next;
        delete head;
        head = temp;
        count -= 1;
    }
    const T& Top() const {
        assert(count > 0);
        return head->val;
    }
};

template<class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int count;
public:
    Queue() : front{nullptr}, rear{nullptr}, count{0} {}
    bool IsEmpty() const { return (count==0);}
    int Count() const {return count;}
    Queue<T>* Push(const T& val) {
        auto temp = new Node<T>(val);
        if(front==nullptr) front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
        count += 1;
        return this;
    }
    const T& Front() const {
        assert(count > 0);
        return front->val;
    }
    Queue<T>* Pop() {
        assert(count > 0);
        auto temp = front->next;
        delete front;
        front = temp;
        if(front==nullptr) rear = nullptr;
        count -= 1;
        return this;
    }
    void DestroyQueue() {
        count = 0;
        while(front) {
            auto temp = front->next;
            delete front;
            front = temp;
        }
        rear = nullptr;
    }
    ~Queue() {
        DestroyQueue();
    }
};

template <class T>
class Queue_Array {
private:
    T* arr;
    const int capacity;
    int front;
    int rear;
    int count;
public:
    Queue_Array(int capacity = 10) : capacity{capacity} {
        assert(capacity > 0);
        arr = new T[capacity];
        count = 0;
        front = 0;
        rear = 0;
    }
    bool IsEmpty() const { return (count==0);}
    int Count() const { return count;}
    Queue_Array<T>* Push(const T& val) {
        assert(count < capacity);
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        count += 1;
        return this;
    }
    void Pop() {
        assert(count > 0);
        front = (front + 1) % capacity;
        count -= 1;
    }
    const T& Front() const {
        assert(count > 0);
        return arr[front];
    }
    ~Queue_Array() {
        front = 0;
        rear = 0;
        count = 0;
        delete[] arr;
    }
};

// Queue using 2 stacks : 
// Stack1 for Push, Stack2 for Pop
// Push(X) --> Push element X into Stack1.
// Pop(X) --> If Stack2 currently has an element in it (count > 0), then Pop it.
// Else, if Stack2 is empty, Push every element from Stack1 into Stack2 until Stack1 becomes empty, then Pop from Stack2. 
// Front() --> Same as Pop. If Stack2 currently has an element in it (count > 0), then call Stack2.Top()
// Else, Push every element from Stack1 into Stack2 until Stack1 becomes empty, then call Stack2.Top()
// Time Complexity : 
// Push --> O(1)
// Pop --> Worst case O(n), Average O(1). (O(n) operation is only performed when Stack2 is empty, else O(1) operation is performed.)

template <class T>
class Stack_Using_Two_Queues {
    Queue<T> q1;
    Queue<T> q2;
    int count;
public:
    Stack_Using_Two_Queues() : count{0} {}
    Stack_Using_Two_Queues<T>* Push(const T& val) {
        count += 1;
        q1.Push(val);
    }
    void Transfer() {
        while(q1.Count() != 1) {
            q2.Push(q1.Front());
            q1.Pop();
        }
    }
    void Swap() {
        Queue <T> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void Pop() {
        assert(count > 0);
        Transfer();
        q1.Pop();
        count -= 1;
        Swap();
    }
    T Top() {
        assert(count > 0);
        Transfer();
        auto x = q1.Front();
        q1.Pop();
        q2.Push(x);
        Swap();
        return x;
    }
    ~Stack_Using_Two_Queues() {
        q1.DestroyQueue();
        q2.DestroyQueue();
        count = 0;
    }
};

int main() {
    cout << "Stack\n";
    Stack <int> s;
    s.Push(100)->Push(200)->Push(300);
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    cout << "Queue\n";
    Queue <int> q;
    q.Push(100)->Push(200)->Push(300);
    cout << q.Front() << endl;
    q.Pop();
    cout << q.Front() << endl;
    cout << "Queue Using Array\n";
    Queue_Array<int> qa(5);
    qa.Push(10)->Push(20)->Push(30)->Push(40); // 10 20 30 40 X
    cout << qa.Front() << endl;
    qa.Pop(); // X 20 30 40 X
    qa.Push(50)->Push(60); // 60 20 30 40 50
    qa.Pop(); // 60 X 30 40 50
    qa.Pop(); // 60 X X 40 50
    cout << qa.Front() << endl;
    qa.Pop(); // 60 X X X 50
    qa.Pop(); // 60 X X X X 
    cout << qa.Front() << endl;
    cout << "Stack Using Two Queues\n";
    Stack_Using_Two_Queues <int> sq;
    sq.Push(10);
    sq.Push(20);
    sq.Push(30);
    cout << sq.Top() << endl;
    sq.Pop();
    cout << sq.Top() << endl;
    sq.Push(100);
    sq.Push(200);
    cout << sq.Top() << endl;
    sq.Pop();
    sq.Pop();
    sq.Pop();
    cout << sq.Top() << endl;
}