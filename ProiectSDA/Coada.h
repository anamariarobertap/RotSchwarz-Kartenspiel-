template <typename TElem>
class Coada
{
	TElem info[100];
	int urm[100];
	int prim;
	int primLiber;
	int cp;
	int lg;

public:
	/*
	Constructor pentru coada
	*/
	Coada();

	/*
	Destructor pentru coada
	*/
	~Coada() {};

	/*
	Returneaza primul element din coada
	*/
	TElem elementCoada() { return this->info[prim]; }

	/*
	Verifica daca coada este goala
	*/
	bool cVida();

	/*
	Adauga in coada
	*/
	void adaugaCoada(TElem val);

	/*
	Sterge din coada
	*/
	void stergeCoada();

	int size() { return this->lg; }

	void reface() {
		
	}

};

template <typename TElem>
Coada<TElem>::Coada() {
	this->cp = 100;
	this->prim = 0;
	for (int i = 1; i < this->cp; i++)
		this->urm[i] = i + 1;
	this->urm[this->cp] = 0;
	this->primLiber = 1;
	this->lg = 0;
}

template <typename TElem>
bool Coada<TElem>::cVida() {
	if (this->lg == 0)
		return true;
	return false;
}

template <typename TElem>
void Coada<TElem>::adaugaCoada(TElem val) { 
	int i = this->primLiber;
	this->info[i] = val;
	this->primLiber = this->urm[primLiber];
	this->urm[i] = this->primLiber;
	if (this->prim == 0)
		this->prim = i;
	this->lg++;
}

template <typename TElem>
void Coada<TElem>::stergeCoada() {
	int i = this->prim;
	this->prim = this->urm[prim];
	this->lg--;
}