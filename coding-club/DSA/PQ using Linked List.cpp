#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node() : next{nullptr} {}
    Node(const T &value) : data{value}, next{nullptr} {}
};

template <class T>
class Priority_Queue
{
public:
    Node<T> *head;
    Node<T> *tail;
    int count;
    Priority_Queue() : head{nullptr}, tail{nullptr}, count{0} {}
    Priority_Queue<T> *Push(const T &val)
    {
        // O(n)
        auto temp = new Node<T>(val);
        if (count == 0)
        {
            head = temp;
            tail = temp;
        }
        else if (head->data <= temp->data)
        {
            temp->next = head;
            head = temp;
        }
        else if (tail->data > temp->data)
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            auto temp_forward = head->next;
            auto temp_backward = head;
            for (int i = 1; i < count; i++)
            {
                if (temp_backward->data > temp->data && temp_forward->data <= temp->data)
                {
                    temp_backward->next = temp;
                    temp->next = temp_forward;
                    break;
                }
                temp_backward = temp_backward->next;
                temp_forward = temp_forward->next;
            }
        }
        count++;
    }
    const T Top() const
    {
        assert(count > 0);
        return head->data;
    }
    void Print() const
    {
        // This function is not needed in priority queue but I have added it to easily debug my code.
        auto temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Pop()
    {
        // O(1)
        assert(count > 0);
        if (count == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            auto temp = head->next;
            delete head;
            head = temp;
        }
        count--;
    }
};

int main()
{
    Priority_Queue<int> pq;
    pq.Push(10);
    pq.Print();
    pq.Push(30);
    pq.Print();
    pq.Push(500);
    pq.Print();
    pq.Push(1);
    pq.Print();
    pq.Push(9);
    pq.Print();
    pq.Pop();
    pq.Print();
    pq.Pop();
    pq.Print();
    pq.Pop();
    pq.Print();
}