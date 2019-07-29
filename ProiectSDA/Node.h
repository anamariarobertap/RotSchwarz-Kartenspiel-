#pragma once
#include <stdlib.h>
template <typename t>
class Node
{
private:
	t e;
	Node *urm;
public:
	void setElem(t el) { this->e = el; }
	void setUrm(Node *urm) { this->urm = urm; }
	Node();
	~Node();
	Node creeazaNod(t val);
	t getElem() { return this->e; }
	Node* getUrm() { return this->urm; }
	void delNode(Node *n) { free(n); }
};

template <typename t>
Node<t>::Node()
{
	urm = nullptr;
}

template <typename t>
Node<t>::~Node()
{
}

template <typename t>
Node<t> Node<t>::creeazaNod(t val) {
	Node<t>* newNode = new Node<t>;
	newNode->setElem(e);
	newNode->setUrm(nullptr);
	return* newNode;
}

