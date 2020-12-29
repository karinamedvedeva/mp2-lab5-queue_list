#pragma once
#include <iostream>

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

template <class T>
class TQueue
{
	TLink<T>* pHead, * pTail;
public:
	TQueue()
	{
		pHead = NULL;
		pTail = NULL;
	}

	TQueue(const TQueue<T>& q)  //конструктор копирования
	{
		if (q.pHead != NULL)
		{
			TLink<T>* tmp = q.pHead;
			TLink<T>* prev = new TLink<T>;
			prev->val = tmp->val;
			pHead = prev;
			tmp = tmp->pNext;
			while (tmp != NULL)
			{
				TLink<T>* p = new TLink<T>;
				p->val = tmp->val;
				prev->pNext = p;
				tmp = tmp->pNext;
				prev->pNext = NULL;
				pTail = prev;
			}
		}
		else
		{
			pHead = NULL;
			pTail = NULL;
		}
	}

	~TQueue() //деструктор
	{
		while (pHead != NULL)
		{
			TLink <T>* tmp = pHead;
			pHead = pHead->pNext;
			delete tmp;
		}
	}

	TQueue<T>& operator=(const TQueue<T>& q)
	{
			while (pHead != NULL)
			{
				TLink<T>* tmp = pHead;
				pHead = pHead->pNext;
				delete tmp;
			}
			if (q.pHead != NULL)
			{
				TLink<T>* prev = new TLink<T>;
				TLink<T>* tmp = q.pHead;
				pHead = prev;
				prev->val = q.pHead->val;
				tmp = tmp->pNext;
				while (tmp != NULL)
				{
					TLink<T>* p = new TLink<T>;
					p->val = tmp->val;
					prev->pNext = p;
					prev = prev->pNext;
					tmp = tmp->pNext;
				}
				pTail = prev;
				prev->pNext = NULL;
			}
			else
			{
				pHead = NULL;
				pTail = NULL;
			}
		return *this;
	}

	bool Empty()
	{
		if (pHead == NULL)
		{
			return true;
		}
		return false;
	}

	void Push(T a) //добавить элемент в очередь
	{
		TLink <T>* tmp = new TLink <T>;
		tmp->val = a;
		tmp->pNext = NULL;
		if (pTail != NULL)
		{
			pTail->pNext = tmp;
			pTail = tmp;
		}
		else
		{
			pHead = tmp;
			pTail = tmp;
		}
	}

	T Pop() 
	{
		if (Empty())
		{
			throw 0;
		}
		T tmp = pHead->val;
		TLink<T>* t = pHead;
		pHead = pHead->pNext;
		delete t;
		return tmp;
	}

	bool operator==(const TQueue<T>& q) const
	{
		TLink<T>* tmp = pHead;
		TLink<T>* p = q.pHead;
		do
		{
			if (p == NULL && tmp == NULL)
			{
				return true;
			}
			if (p == NULL || tmp == NULL)
			{
				return false;
			}
			if (p->val != tmp->val)
			{
				return false;
			}
			tmp = tmp->pNext;
			p = p->pNext;
		} while (true);
		return true;
	}

	bool operator!=(const TQueue<T>& q) const
	{
		return !(*this == q);
	}

	T GetHead()
	{
		if (Empty())
		{
			throw 0;
		}
		return pHead->val;;
	}
};
