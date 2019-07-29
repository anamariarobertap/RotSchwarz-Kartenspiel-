#include "Node.h"
#pragma once
template<typename t>

class Stack
{
private:

public:
	Node<t>* prim;

	Stack();	//init

	void addStack(t value);	//push
	t elementStack();	//top
	void remove();	//pop

	bool isEmptyStack();

	int size();

	~Stack()
	{
		while (prim != NULL)
		{
			Node<t>*h = prim;
			prim = prim->next;
			delete h;
		}
	}
	
};

template <typename t>
Stack<t>::Stack()
{
	this->prim = nullptr;
}

template<typename t>
void Stack<t>::addStack(t val)
{
	Node<t>* newNode = new Node<t>;
	newNode->setElem(val);
	newNode->setUrm(nullptr);
	newNode->setUrm(this->prim);
	this->prim = newNode;
}

template<typename t>
void Stack<t>::remove()
{
	Node<t>* i = this->prim;
	this->prim = this->prim->getUrm();
	i->delNode(i);
}

template<typename t>
bool Stack<t>::isEmptyStack()
{
	if (this == nullptr || this->prim == nullptr)
		return true;
	return false;
}

template<typename t>
t Stack<t>::elementStack()
{
	Node<t>* nod = this->prim;
	return nod->getElem();
}

template<typename t>
int Stack<t>::size()
{
	int size = 0;
	Node<t> *aux = prim;
	while(aux!=nullptr)
	{
		aux = aux->getUrm();
		size++;
	}

	return size;
}