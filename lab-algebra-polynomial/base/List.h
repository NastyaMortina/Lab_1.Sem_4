#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

const int MAX_SIZE_LIST = 1000;
using namespace std;

template <class type>
class List
{
private:
	template <class type>
	struct Node
	{
		Node* pNext; 
		type data;
		Node(type _data = {}, Node* _pNext = nullptr)
		{
			pNext = _pNext;
			data = _data;
		}
	};
	int numberOfElements;
	Node <type>* pFirst;
	Node <type>* pCurrent;
public:
	class iterator
	{
	private:
		Node<type>* pointer;
	public:
		iterator()
		{
			pointer = new Node<type>;
		}
		iterator(const iterator& it)
		{
			pointer = it.pointer;
		}
		Node<type>* operator->() const
		{
			return pointer;
		}
		bool operator == (const iterator& it) const
		{
			if (pointer == it.pointer)
				return true;
			else return false;
		}
		bool operator != (const iterator& it) const
		{
			return !(*this == it);
		}
		type operator*()const
		{
			if (pointer == nullptr) { throw("nullptr"); }
			return pointer->data;
		}
		iterator& operator ++()
		{
			this->pointer = this->pointer->pNext;
			return *this;
		}
		iterator& operator=(const iterator& temp)
		{
			pointer = temp.pointer;
			return *this;
		}
		friend class List;
	};
	List()
	{
		pFirst = nullptr;
		pCurrent = nullptr;
		numberOfElements = 0;
	}
	List(const List<type>& lst)
	{
		this->pFirst = nullptr;
		this->numberOfElements = 0;
		Node<type>* count = lst.pFirst;
		while (count != nullptr)
		{
			this->PushBack(count->data);
			count = count->pNext;
		}
	}
	List<type>& operator = (const List<type>& lst)
	{
		Node<type>* count = lst.pFirst;
		if (!this->IsEmpty())
			this->Clear();
		while (count != nullptr)
		{
			this->PushBack(count->data);
			count = count->pNext;
		}
		return *this;
	}
	bool operator==(const List& lst)const
	{
		if (this->numberOfElements != lst.numberOfElements)
			return false;
		else
		{
			Node<type>* left = this->pFirst;
			Node<type>* right = lst.pFirst;
			while (right != nullptr)
			{
				if (left->data != right->data)
					return false;
				left = left->pNext;
				right = right->pNext;
			}
			return true;
		}
	}
	bool operator!=(const List& lst)const
	{
		return !(*this == lst);
	}
	void PushBack(type tmp)
	{
		if (IsEmpty())
		{
			pFirst = new Node<type>(tmp);
			pCurrent = pFirst;
			numberOfElements++;
		}
		else
		{
			if (numberOfElements == MAX_SIZE_LIST)
				throw("Polinom full");
			pCurrent->pNext = new Node<type>(tmp);
			pCurrent = pCurrent->pNext;
			numberOfElements++;
		}
	}
	type PopFront()
	{
		type val = pFirst->data;
		Node<type>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		numberOfElements--;
		return val;
	}
	void Insert(iterator it, type val)
	{
		Node<type>* count = pFirst;
		Node<type>* prev = nullptr; 
		Node<type>* insert = new Node<type>(val);
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			Node<type>* tmp = pFirst;
			insert->pNext = tmp;
			pFirst = insert;
			numberOfElements++;
		}
		else
		{
			insert->pNext = count;
			prev->pNext = insert;
			numberOfElements++;
		}
	}
	void Erase(iterator it)
	{
		Node<type>* count = pFirst;
		Node <type>* prev = nullptr; 
		int pos = 0;
		while (count != it.pointer)
		{
			prev = count;
			count = count->pNext;
			pos++;
		}
		if (pos == 0)
		{
			Node<type>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			numberOfElements--;
		}
		else
		{
			prev->pNext = count->pNext;
			delete count;
			numberOfElements--;
		}
	}
	void Clear()
	{
		while (numberOfElements != 0)
			PopFront();
	}
	iterator Begin()
	{
		iterator it;
		it.pointer = pFirst;
		return it;
	}
	iterator End()
	{
		iterator it;
		if (IsEmpty()) {
			it.pointer = pFirst;
			return it;
		}
		it.pointer = pCurrent->pNext;
		return it;
	}
	iterator penultimate() 
	{
		iterator it;
		if (IsEmpty()) {
			it.pointer = pFirst;
			return it;
		}
		it.pointer = pCurrent;
		return it;
	}
	int GetSize()
	{
		return numberOfElements;
	}
	bool IsEmpty()
	{
		if (pFirst == nullptr)
			return true;
		else return false;
	}
	
	Node<type>* GetHead() { return pFirst; }
	
	~List()
	{
		Clear();
	}
	friend class iterator;
};