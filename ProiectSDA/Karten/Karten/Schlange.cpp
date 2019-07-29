#include "Schlange.h"

template <typename TElem>
Schlange<TElem>::Schlange()
{
	this->cp = 100;
	this->prim = 0;
	this->ult = 0;
	for (int i = 1; i < this->cp; i++)
		this->urm[i] = i + 1;

	this->trec[i] = 0;
	for (int i = 1; i < this->cp; i++)
		this->trec[i] = i - 1;

	this->urm[this->cp] = 0;
	this->primLiber = 1;
	this->lg = 0;
}

template<typename TElem>
bool Schlange<TElem>::isEmptySchlange()
{
	if (this->lg == 0)
		return true;
	return false;
}

template <typename TElem>
void Schlange<TElem>::addSchlange(TElem val)
{
	int i = this->primLiber;
	
	this->primLiber = this->urm[primLiber];
	this->info[i] = val;
	this->trec[i] = this->ult;
	
	this->urm[i] = this->primLiber;
	if (this->prim == 0)
	{
		this->prim = i;
		this->ult = i;
	}
	else
		this->ult = i;


	this->lg++;
}

template <typename TElem>
void Schlange<TElem>::delSchlange()
{
	int i = this->prim;
	this->prim = this->urm[prim];
	this->urm[i] = this->primLiber;
	this->primLiber = i;
	this->lg--;
}