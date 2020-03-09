#pragma once
#include "Repo.h"
#include<iostream>
#include<ostream>
#include<fstream>
#include <string>
using namespace std;

template <class T> class RepoFile : public Repo<T>
{
private:
	string numefisier;
	void read();
	void print();
public:
	~RepoFile() {

	}
	RepoFile(string numefisier1)
	{
		numefisier = numefisier1;
	}
	void addElem(T a) override
	{
		Repo<T>::addElem(a);
		print();
	}
	vector <T> getALL() override {
		read();
		return this->list;
	}
};

//Desc: read entities from a file given by its name
//In: name of file
//Out: -
template <class T> void RepoFile<T>::read()
{
	this->list.clear();
	ifstream fin(numefisier);
	T aux;
	while (fin >> aux)
	{
		Repo<T>::addElem(aux);
	}
	fin.close();
}

//Desc: print more lines into a file 
//In: 
//Out: -(printing fc)
template<class T>void RepoFile<T>::print()
{
	ofstream fout(this->numefisier, ofstream::app);
	for (size_t i = 0; i < list.size(); i++)
		fout << list[i] << "\n";
	fout.close();
}