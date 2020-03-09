#pragma once
#include "Client.h"
#include "Bus.h"
#include "Ticket.h"
#include <vector>
using namespace std;

template <class T> class Repo
{
protected:
	vector<T> list;
public:
	Repo();
	~Repo();
	virtual void addElem(T a);
	virtual void deleteElem();
	virtual vector<T> getALL();
	int getSize();
	void deletePos(int pos);
	T& getElem(int pos);

};

//Descr:	create an empty vector
//In:		none
//Out:		an instance of type Vector (without elements)
template <class T> Repo<T>::Repo()
{
	//cout << "Repo implicit constructor" << endl;
}

//Descr:	destroy a vector
//In:		a vector
//Out:		none
template <class T> Repo<T>::~Repo()
{
	//cout << "Repo destructor" << endl;
}

//Descr:	add an elem into a vector
//In:		a vector and an elem
//Out:		the (changed) vector
template <class T> void Repo<T>::addElem(T a)
{
	this->list.push_back(a);

}

//Descr:	eliminate an element from the vector 
//In:		the vector
//Out:		the vector without the element
template <class T> void Repo<T>::deleteElem()
{
	this->list.pop_back();
}

//Descr:	eliminate an element from the vector on given position
//In:		the vector and a position
//Out:		the vector without the element
template <class T> void Repo<T>::deletePos(int pos)
{
	this->list.erase(list.begin() + pos);
}

//Desc:return the all elem from list
//In: 
//Out: a list 
template <class T>vector<T> Repo<T>::getALL()
{
	return this->list;
}


//Descr:	acces the size of the vector
//In:		the vector
//Out:		the vector's size
template <class T> int Repo<T>::getSize()
{
	return this->list.size();
}

//Desc: get a entity from a given position 
template <class T> T& Repo<T>::getElem(int pos)
{
	return this->list.at(pos);
}