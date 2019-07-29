#pragma once
#include <stdlib.h>
template <typename t>
class Node
{
private:
	t e;
	Node *next;
public:
	void setElem(t el) { this->e = el; }
	void setNext(Node *next) { this->next = next; }
	Node();
	~Node();
	Node makeNode(t val);
	t getElem() { return this->e; }
	Node* getNext() { return this->next; }
	void delNode(Node *n) { free(n); }
};

template <typename t>
Node<t>::Node()
{
	next = nullptr;
}

template <typename t>
Node<t>::~Node()
{
}

template <typename t>
Node<t> Node<t>::makeNode(t val) {
	Node<t>* newNode = new Node<t>;
	newNode->setElem(e);
	newNode->setNext(nullptr);
	return*newNode;
}

