#include "Node.h"

template <typename t>
class Stiva
{
private:
	
public:
	Node<t>* prim;

	/*
	COnstructor pentru stiva
	*/
	Stiva();

	/*
	Adauga un element in stiva
	*/
	void adaugaStiva(t value);

	/*
	Returneaza varful stivei
	*/
	t elementStiva();

	/*
	Sterge varful stivei
	*/
	void remove();

	/*
	Verifica daca stiva e goala
	*/
	bool stVida();

	/*
	Destructor pentru stiva
	*/
	~Stiva() {
		while (prim != NULL) {
			Node<t>*h = prim;
			prim = prim->next;
			delete h;
		}
	}

	int size();
};

template <typename t>
Stiva<t>::Stiva()
{
	this->prim = nullptr;
}


template<typename t>
void Stiva<t>::adaugaStiva(t val)
{
	Node<t>* newNode = new Node<t>;
	newNode->setElem(val);
	newNode->setUrm(nullptr);
	newNode->setUrm(this->prim);
	this->prim = newNode;
}

template<typename t>
void Stiva<t>::remove()
{
	Node<t>* i = this->prim;
	this->prim = this->prim->getUrm();
	i->delNode(i);
	
}


template<typename t>
bool Stiva<t>::stVida() {
	if (this == nullptr || this->prim == nullptr)
		return true;
	return false;

}

template<typename t>
t Stiva<t>::elementStiva()
{
	Node<t>* nod = this->prim;
	return nod->getElem();
}

template<typename t>
int Stiva<t>::size() {
	int size = 0;
	Node<t> *aux = prim;
	while (aux != nullptr) {
		aux = aux->getUrm();
		size++;
	}
	return size;
}
