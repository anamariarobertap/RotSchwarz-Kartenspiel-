#pragma once
#include "Node.h"


template <typename t>
class Stack
{
private:

public:
	Node<t>* first;

	Stack();

	void add_Stack(t value);

	t stackElem();

	void remove();


	bool stEmpty();


	~Stack() {
		while (first != NULL) {
			Node<t>*h = first;
			first = first->next;
			delete h;
		}
	}

	int size();
};

template <typename t>
Stack<t>::Stack()
{
	this->first = nullptr;
}


template<typename t>
void Stack<t>::add_Stack(t val)
{
	Node<t>* newNode = new Node<t>;
	newNode->setElem(val);
	newNode->setNext(nullptr);
	newNode->setNext(this->first);
	this->first = newNode;
}

template<typename t>
void Stack<t>::remove()
{
	Node<t>* i = this->first;
	this->first = this->first->getNext();
	i->delNode(i);

}


template<typename t>
bool Stack<t>::stEmpty() {
	if (this == nullptr || this->first == nullptr)
		return true;
	return false;

}

template<typename t>
t Stack<t>::stackElem()
{
	Node<t>* nod = this->first;
	return nod->getElem();
}

template<typename t>
int Stack<t>::size() {
	int size = 0;
	Node<t> *aux = first;
	while (aux != nullptr) {
		aux = aux->getNext();
		size++;
	}
	return size;
}
