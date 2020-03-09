#include "Client.h"


//Desc: create an empty Client
//In: -
//OUt: a new client
Client::Client()
{
	this->username = "";
	this->password = "";
	this->ticket = {};

}
//Desc: constuctor with param
//In: a string and int 
//Out: a new entity with useful info
Client::Client(string u, string p, string c, string d, string s)
{
	this->username = u;
	this->password = p;
	this->ticket = {};
	this->cardNo = c;
	this->date = d;
	this->security_code = s;
}
Client::Client(string u, string p)
{
	this->username = u;
	this->password = p;
}
//Desc: copy constructor
//In: an object c of type Client 
//Out: a new entity with useful info 
Client::Client(const Client & c)
{
	this->password = c.password;
	this->username = c.username;
	this->cardNo = c.cardNo;
	this->date = c.date;
	this->security_code = c.security_code;
	this->ticket = c.ticket;
}
//Desc: assignment operator
Client & Client::operator=(const Client &c)
{
	if (this != &c) {
		this->setUsername(c.username);
		this->setPassword(c.password);
		this->setCardNo(c.cardNo);
		this->setDate(c.date);
		this->setSecurity_code(c.security_code);
	}
	return*this;
}

//Desc: update the card number 
//In: a string
//Out:the new info about client
void Client::setCardNo(string cn) {
	this->cardNo = cn;
}

//Desc:update the expiration date of the card
//In: a string
//Out: the new info about client
void Client::setDate(string d) {
	this->date = d;
}

//Desc: update the security code
//In: a string
//Out: the new info about client
void Client::setSecurity_code(string sc) {
	this->security_code = sc;
}

//Desc: return the card number
//In: an object type of Client
//Out: the card number
string Client::getCardNo() {
	return this->cardNo;
}

//Desc: return the expiration date of the card
//In: an object type of Client
//Out: the date
string Client::getDate() {
	return this->date;
}

//Desc: return the Security code of the card
//In: an  object type of Client
//Out: the security code
string Client::getSecurity_code() {
	return this->security_code;
}

//Desc: return a ticket from tickets list
//In: an object type of Client
//Out: the ticket
Ticket & Client::getOneTicket(int pos)
{
	return ticket.at(pos);
}

//Desc: add a ticket in my ticket list
//In: a ticket
//Out: the list
void Client::addTicket(Ticket t)
{
	ticket.push_back(t);
}

//Desc: delete an elemet
void Client::deleteTicket(int pos)
{
	ticket.erase(ticket.begin() + pos);
}

//Desc: return the size of the ticket list
int Client::getsize()
{
	return ticket.size();
}


//Desc: destroy an entity
//In: -
//Out: -
Client::~Client()
{
	this->username = "";
	this->password = "";
}
//Desc: change the username of a client 
//In: a client and a string 
//Out: the client with changed username
void Client::setUsername(string u)
{
	this->username = u;
}
//Desc: change the password of a client 
//In: a client and a string
//Out: the client with changed password
void Client::setPassword(string p)
{
	this->password = p;
}

//Descr: access the username of a client
//In: a client 
//Out: the username
string Client::getUsername() const
{
	return this->username;
}

//Descr: access the password of a client
//In: a client 
//Out: the password
string Client::getPassword() const
{
	return this->password;
}

bool Client::operator==(const Client & a)
{
	if (this->password == a.password && this->username == a.username) return true;
	else return false;
}

//Desc: return the ticket list
vector<Ticket> Client::getlista()
{
	return ticket;
}

//IO operators...
//Desc: save an entity from an input stream
//In: an input stream
//Out: a new entity
istream& operator >>(istream& is, Client& c)
{
	is >> c.username >> c.password;// >> c.cardNo >> c.date >> c.security_code;
	//for (auto i = 0; i < c.getsize(); i++)
	//{
		//is >>	
	//}
	return is;
}
//Desc: save an entity from an input stream
//In: an input stream
//Out: a new entity
ostream & operator<<(ostream & os, Client & c)
{
	os << c.username << " " << c.password;
	return os;
}

//Desc: return the total price from my tickets list
//In: a list of tickets
//Out: an integer
int Client::getSum()
{
	int sum = 0;
	for (int i = 0; i < this->getsize(); i++) {

		sum = sum + this->getOneTicket(i).getPrice();
	}
	return sum;
}