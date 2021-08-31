#include <iostream>
#include <cassert>
#include <queue>
#include <utility>
using namespace std;

template <class T>
class Stack
{
    int count;
    priority_queue<pair<int, T>> pq;

public:
    Stack() : count{0} {}

    Stack<T> *Push(const T &val)
    {
        count++;
        pq.push({count, val});
        return this;
    }

    void Pop()
    {
        assert(count > 0);
        count--;
        pq.pop();
    }
    
    const T Top() const
    {
        assert(count > 0);
        return pq.top().second;
    }
};