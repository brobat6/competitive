#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class SingleLinkedListNode
{
public:
	T data;
	SingleLinkedListNode<T>* next;

	SingleLinkedListNode() : next{ nullptr }
	{

	}

	SingleLinkedListNode(const T& value) : SingleLinkedListNode()
	{
		data = value;
	}
};

template <class T>
class SingleLinkedList
{
public:
	SingleLinkedListNode<T>* head;
	SingleLinkedListNode<T>* tail;
	int count;

	// Helpers
	void Initialize(const T& val)
	{

	}

	void DestroyList()
	{

	}

	SingleLinkedListNode<T>* GotoIndex(int index) const
	{

	}

public:
	// Default Constructor
	SingleLinkedList() : head(nullptr), tail(nullptr), count(0)
	{

	}

	// Parametrized Constructor
	SingleLinkedList(const T* arr, int len) : count(len)
	{

	}

	// Copy Constrcutor
	SingleLinkedList(const SingleLinkedList<T>& oldList) :count(oldList.count)
	{

	}

	// Returns Head
	SingleLinkedListNode<T>* First() const
	{
		return head;
	}

	// Returns Tail
	SingleLinkedListNode<T>* Last() const
	{
		return tail;
	}

	// Returns Count
	int Length()
	{
		return count;
	}

	bool IsEmpty() const
	{
		return count == 0;
	}


	// Insert Operations
	SingleLinkedList<T>* AddAtFirst(const T& val)
	{

	}

	SingleLinkedList<T>* AddAfterIndex(const T& val, int index)
	{

	}

	SingleLinkedList<T>* AddBeforeIndex(const T& val, int index)
	{

	}

	SingleLinkedList<T>* AddAtLast(const T& val)
	{

	}

	// Remove Operations
	SingleLinkedList<T>* DeleteAtFirst()
	{

	}

	SingleLinkedList<T>* DeleteAtIndex(int index)
	{

	}

	SingleLinkedList<T>* DeleteAtLast()
	{

	}

	// Destructor
	~SingleLinkedList()
	{

	}

	T* ToArray() const
	{

	}

	T* ToReverseArray() const
	{

	}

	void Print() const
	{

	}
};