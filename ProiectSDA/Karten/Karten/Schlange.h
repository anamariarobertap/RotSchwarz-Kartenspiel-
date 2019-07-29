#pragma once
template <typename TElem>
class Schlange
{
	TElem info[100];
	int urm[100];	//next
	int trec[100];	//prev

	int prim;	//head
	int ult;	//tail

	int primLiber;	//first empty

	int cp; //capacitate
	int lg; //lungime

public:
	Schlange();		//init
	~Schlange() {};		//destroy
	TElem elemSchlange() { return this->info[prim]; }	//top

	bool isEmptySchlange();

	void addSchlange(TElem val);	//push

	void delSchlange();		//pop

	int size() { return this->lg; }

	void reface()
	{

	}
};

