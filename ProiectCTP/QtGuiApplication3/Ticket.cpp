#include "Ticket.h"

//Descr: create a Ticket 
//In: -
//Out: an instance of  Ticket 
Ticket::Ticket()
{
	this->price = 0;
	this->time = 30;
	this->id = 0;
}

//Descr: create a Ticket
//In: a name, a price, a time and an id
//Out: an instance (with info) of Ticket
Ticket::Ticket(int id, int p, int t)
{
	this->id = id;
	this->price = p;
	this->time = t;

}
// Descr: create a Ticket using info from another Ticket
//In: a Ticket c
//Out: an instance of Ticket with info from c
Ticket::Ticket(const Ticket & c)
{
	this->price = c.price;
	this->time = c.time;
	this->id = c.id;
}

//Descr: distroy a Ticket
//In: a Ticket 
//Out: - (destructor)
Ticket::~Ticket()
{

}

//Desc: assignment operator...

Ticket & Ticket::operator=(const Ticket & c)
{
	if (this != &c)
	{
		this->price = c.price;
		this->time = c.time;
		this->id = c.id;
	}
	return *this;
}

bool Ticket::operator==(const Ticket & c)
{
	if (this->id == c.id) return true;
	else return false;
}

bool Ticket::operator<(const Ticket & c)
{
	if (this->price < c.price) return true;
	else return false;
}

bool Ticket::operator>(const Ticket & c)
{
	if (this->price > c.price) return true;
	else return false;
}


//Descr: access the price of a Ticket 
//In: a Ticket 
//Out: the price
int Ticket::getPrice()
{
	return this->price;
}

//Descr: access the time of a Ticket 
//In: a Ticket 
//Out: the time
int Ticket::getTime()
{
	return this->time;
}

//Descr: access the id of a Ticket 
//In: a Ticket 
//Out: the id
int Ticket::getId()
{
	return this->id;
}

//Descr: change the price of a ticket 
//In: a ticket and a price
//Out: the ticket with changed price
void Ticket::setPrice(int p)
{
	this->price = p;
}

//Descr: change the time of a ticket 
//In: a ticket and a time
//Out: the ticket with changed time
void Ticket::setTime(int t)
{
	this->time = t;
}

//Descr: change the id of a ticket 
//In: a ticket and an id
//Out: the ticket with changed id
void Ticket::setId(int id1)
{
	this->id = id1;
}

ostream & operator<<(ostream & os, Ticket & c)
{
	os << c.id << " " << c.price << " " << c.time;
	return os;
}

istream& operator>>(istream& is, Ticket& b) {
	is >> b.id >> b.price >> b.time;
	return is;
}