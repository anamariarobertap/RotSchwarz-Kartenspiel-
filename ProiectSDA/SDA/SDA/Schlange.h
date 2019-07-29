#pragma once
template <typename TElem>
class Schlange
{
	TElem info[100];
	int next[100];
	int first;
	int firstEmpty;
	int cap;
	int l;

public:
	Schlange();
	~Schlange() {};
	TElem elemSchlange() { return this->info[first]; } //Rückgibt die erste Wert der Schlange 
	bool ist_leer(); 
	void add_Schlange(TElem wert);
	void del_Schlange();
	int size() { return this->l; }
	void redo() {}
};
template <typename TElem>
Schlange<TElem>::Schlange() {
	this->cap = 100;
	this->first = 0;
	for (int i = 1; i < this->cap; i++)
		this->next[i] = i + 1;
	this->next[this->cap] = 0;
	this->firstEmpty = 1;
	this->l = 0;
}

template <typename TElem>
bool Schlange<TElem>::ist_leer() {
	if (this->l == 0)
		return true;
	return false;
}

template <typename TElem>
void Schlange<TElem>::add_Schlange(TElem val) {
	int i = this->firstEmpty;
	this->info[i] = val;
	this->firstEmpty = this->next[firstEmpty];
	this->next[i] = this->firstEmpty;
	if (this->first == 0)
		this->first = i;
	this->l++;
}

template <typename TElem>
void Schlange<TElem>::del_Schlange() {
	int i = this->first;
	this->first = this->next[first];
	this->l--;
}