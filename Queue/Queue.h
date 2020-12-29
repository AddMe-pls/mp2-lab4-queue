#pragma once
#include<iostream>
template <class T>
class TQueue
{
    int DataCount, MaxSize, tail, head;
    T* pMem;
public:
    TQueue(int s = 10);
    ~TQueue()    {delete[]pMem;}
	TQueue(const TQueue<T>& qu);
	TQueue<T>& operator = (const TQueue<T>& qu);
	bool operator == (const TQueue<T>& qu) const;
	bool operator != (const TQueue<T>& qu) const;
	int GetSize() { return DataCount; }
	int GetMaxSize() { return MaxSize; }
	bool Empty() const;
	bool Full() const;
	void Push(const T elem);
	T SeeHead() const;
	T GetHead();
	T GetNumberHead() { return head; }
};
template <class T>
TQueue<T>::TQueue(int s)
{
	if (s <= 0)
		throw s;
	MaxSize = s;
	DataCount = 0;
	head = 0;
	tail = MaxSize - 1;
	pMem = new T[MaxSize];
	for (int i = 0; i < s; i++)
		pMem[i] = 0;
}
template <class T>
TQueue<T>::TQueue(const TQueue<T>& qu)
{
	MaxSize = qu.MaxSize;
	pMem = new T[MaxSize];
	DataCount = qu.DataCount;
	head = qu.head;
	tail = qu.tail;
	int tmp = head, tmp_size = 0;
	while (tmp_size != DataCount)
	{
		pMem[tmp] = qu.pMem[tmp];
		tmp = (tmp + 1) % MaxSize;
		tmp_size++;
	}
}
template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& qu)
{
	if (this != &qu)
	{
		if (MaxSize != qu.MaxSize)
		{
			MaxSize = qu.MaxSize;
			delete[]pMem;
			pMem = new T[MaxSize];
		}
		DataCount = qu.DataCount;
		head = qu.head;
		tail = qu.tail;
		int tmp = head, tmp_size = 0;
		while (tmp_size != DataCount)
		{
			pMem[tmp] = qu.pMem[tmp];
			tmp = (tmp + 1) % MaxSize;
			tmp_size++;
		}
	}
	return (*this);
}
template<class T>
bool TQueue<T>::operator==(const TQueue<T>& qu) const
{
	if (this != &qu)
	{
		if (MaxSize != qu.MaxSize || DataCount != qu.DataCount)
		{
			return false;
		}
		int tmp = head, qtmp = qu.head, tmp_size = 0;
		while (tmp_size != DataCount)
		{
			if (pMem[tmp] != qu.pMem[qtmp])
			{
				return false;
			}
			tmp = (tmp + 1) % MaxSize;
			qtmp = (qtmp + 1) % MaxSize;
			tmp_size++;
		}
	}
	return true;
}
template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& qu) const
{
	return (!(*this == qu));
}
template<class T>
bool TQueue<T>::Empty() const
{
	if (DataCount == 0)
		return true;
	return false;
}
template<class T>
bool TQueue<T>::Full() const
{
	if (DataCount == MaxSize)
		return true;
	return false;
}
template <class T>
void TQueue<T>::Push(const T elem)
{
	if (DataCount == MaxSize)
		throw DataCount;
	DataCount++;
	tail = (tail + 1) % MaxSize;
	pMem[tail] = elem;
}
template<class T>
T TQueue<T>::SeeHead() const
{
	if (DataCount == 0)
		throw DataCount;
	return pMem[head];
}
template<class T>
T TQueue<T>::GetHead()
{
	if (DataCount == 0)
		throw DataCount;
	DataCount--;
	head = (head + 1) % MaxSize;
	if (head == 0)
		return pMem[MaxSize - 1];
	return pMem[head - 1];
}


