#pragma once
#include "NodeSchlange.h"

class Schlange
{
public: 
	NodeSchlange *elems;
	int cap;
	int head;
	int tail;
	int firstEmpty;
	int len;
	Schlange();
	~Schlange() {};
	int allocate();
	void push(NodeSchlange e);
	void pop();
	std::string top();
	bool isEmpty();
	bool isFull();
	int size();

};

inline Schlange::Schlange()
{
	this->len = 0;
	this->cap = 10;
	this->elems = new NodeSchlange[cap];
	for (int i = 0; i < cap; i++)
	{
		this->elems[i].next = i + 1;
		this->elems[i].prev = i - 1;
	}
	this->elems[cap - 1].next = -1;
	this->firstEmpty = 0;
	this->head = -1;
	this->tail = -1;
}

inline int Schlange::allocate()
{
	{
		int newElem = this->firstEmpty;

		if (newElem != -1)
		{
			this->firstEmpty = this->elems[firstEmpty].next;
			this->elems[this->firstEmpty].prev = -1;
			this->elems[newElem].prev = -1;
			this->elems[newElem].next = -1;
		}

		return newElem;
	}
	return 0;
}


inline void Schlange::push(NodeSchlange e)
{
	if (head == -1)
	{
		if (firstEmpty == -1)
		{
			this->cap = this->cap * 2;
			NodeSchlange* newelems = new NodeSchlange[cap];
			for (int i = 0; i < this->len; i++)
				newelems[i] = this->elems[i];
			for (int i = this->len; i < this->cap; i++)
			{
				newelems[i].next = i + 1;
				newelems[i].prev = i - 1;
			}
			newelems[cap - 1].next = -1;
			firstEmpty = len;
			this->elems = newelems;
		}

		int newElem = this->allocate();
		this->elems[newElem].info = e.info;

		if (this->head == -1)
		{
			this->head = newElem;
			this->tail = newElem;
		}
		else
		{
			this->elems[newElem].next = this->head;
			this->elems[this->head].prev = newElem;
			this->head = newElem;
		}
		this->len++;
	}
}


inline void Schlange::pop()
{
	return;
}

inline bool Schlange::isEmpty()
{
	if (this->head == -1)
		return true;
	return false;
}


inline bool Schlange::isFull()
{
	if (this->firstEmpty == -1)
		return true;
	return false;
}



inline int Schlange::size()
{
	return this->len;
}

