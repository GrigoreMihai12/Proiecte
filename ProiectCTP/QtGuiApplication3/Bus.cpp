#include "Bus.h"


//Desc: create an empty Bus
//In: -
//OUt: a new Bus
Bus::Bus()
{
	this->nrroute = 0;
	this->day = "";
	this->nr = "";
	this->hour = {};
	this->ticketId = 0;
	this->route = {};
}

//Desc: constuctor with param
//In: a string and int 
//Out: a new entity with useful info
Bus::~Bus()
{
}

//Desc: constuctor with param
//In: a string and int 
//Out: a new entity with useful info
Bus::Bus(int nrroute1, string day, string nr1, vector<string> hour, int id, vector<string>route)
{
	this->nrroute = nrroute1;
	this->day = day;
	this->nr = nr1;
	this->ticketId = id;
	this->route = route;
	this->hour = hour;
}

//Desc: copy constructor
//In: an object c of type Client 
//Out: a new entity with useful info
Bus::Bus(const Bus & p)
{
	this->nrroute = p.nrroute;
	this->day = p.day;
	this->hour = p.hour;
	this->nr = p.nr;
	this->ticketId = p.ticketId;
	this->route = p.route;
}

//Descr: access the timetable of a bus
//In: a bus 
//Out: the timetable
vector<string> Bus::getHour()
{
	return hour;
}

//Descr: access the number of a bus
//In: a bus
//Out: the number
string Bus::getNr()
{
	return this->nr;
}

//Descr: access the ticket id of the bus
//In: a bus
//Out: the ticket id
int Bus::getTicketId()
{
	return this->ticketId;
}

int Bus::getnrroute()
{
	return this->nrroute;
}

string Bus::getDay()
{
	return this->day;
}

//Descr: access the route of a bus
//In: a bus 
//Out: the route
vector<string> Bus::getRoute() const
{
	return this->route;
}

//Desc: change the timetable of a bus
//In: a bus and a string
//Out: the bus with changed timetable
void Bus::setDay(string day)
{
	this->day = day;
}

//Desc: change the timetable of a bus
//In: a bus and a vector of integers 
//Out: the bus with changed timetable
void Bus::setHour(vector<string> timp1)
{
	this->hour = timp1;
}

//Desc: change the nr of a bus
//In: a bus and an integer 
//Out: the bus with changed number
void Bus::setNr(string nr1)
{
	this->nr = nr1;
}

//Desc: change the ticket id of a bus
//In: a bus and an integer 
//Out: the bus with changed ticket id
void Bus::setTicketId(int biletid1)
{
	this->ticketId = biletid1;
}

void Bus::setnrroute(int nrroute1)
{
	this->nrroute = nrroute1;
}

//Desc: change the route of a bus
//In: a bus and a vector of strings 
//Out: the bus with changed route
void Bus::setRoute(vector<string> ruta1)
{
	this->route = ruta1;
}

// Desc: assignment operator
Bus & Bus::operator=(const Bus & c)
{
	if (this != &c)
	{
		this->nrroute = c.nrroute;
		this->day = day;
		this->hour = c.hour;
		this->ticketId = c.ticketId;
		this->nr = c.nr;
		this->route = c.route;
	}
	return *this;
}

bool Bus::operator==(const Bus & c)
{
	if (this->nr == c.nr)return true;
	else return false;
}

bool Bus::operator<(const Bus & c)
{
	if (this->nr < c.nr)return true;
	else return false;
}

bool Bus::operator>(const Bus & c)
{
	if (this->nr > c.nr)return true;
	else return false;
}

ostream & operator<<(ostream & os, const Bus & c)
{
	os << " The Bus " << c.nr << "\n ";
	//for (int i = 0; i < c.route.size(); i++)
		//os << c.route.at(i) << " ";
	os << " ticket id:  " << c.ticketId << endl;
	for (int i = 0; i < c.hour.size(); i++) {
		os << c.hour.at(i) << " ";
		os << c.route.at(i) << endl;
	}
	return os;
}

//Desc: find a given station from the station list
//In: a string
//Out: the position of station A
int Bus::findStation(string A) {
	int pos = -1;
	for (int i = 0; i < this->nrroute; i++) {
		if (this->route.at(i) == A)
			pos = i;
	}
	return pos;
}