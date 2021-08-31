#include <iostream>
#include <cassert>
#include <queue>
#include <utility>
using namespace std;

template <class T>
class Queue
{
    int count;
    priority_queue<pair<int, T>> pq;
    int ptr;

public:
    Queue() : count{0}, ptr{0} {}
    
    Queue<T> *Insert(const T &val)
    {
        count++;
        ptr--;
        pq.push({ptr, val});
        return this;
    }

    void Pop()
    {
        assert(count > 0);
        count--;
        pq.pop();
    }

    const T Front() const
    {
        assert(count > 0);
        return pq.top().second;
    }
};