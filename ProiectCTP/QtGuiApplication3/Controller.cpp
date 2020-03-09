#define _CRT_SECURE_NO_WARNINGS
#include "Controller.h"
#include <stdio.h>      /* printf, scanf */
#include <time.h>       /* time_t, struct tm, time, mktime */
#include<ostream>
#include<fstream>
#include <algorithm>

using namespace std;


Controller::~Controller()
{

}

bool Controller::logare(Client & a)
{
	vector<Client> t = c.getALL();
	for (auto i = 0; i < c.getSize(); i++)
	{
		if (c.getElem(i) == a) return true;
	}
	return false;
}

vector<Bus> Controller::secondSort(string nr)
{
	/*	auto list = bus.getALL();
	vector < Bus > rezultat;
	std::copy_if(list.begin(), list.end(), std::back_inserter(rezultat), [&](Bus& b) { return (b.getNr() == nr); });
	return rezultat*/
	vector<Bus> t = bus.getALL();
	vector<Bus> newlist;
	for (auto i = 0; i < bus.getSize(); i++)
	{
		if (bus.getElem(i).getNr() == nr) newlist.push_back(bus.getElem(i));
	}
	return newlist;
}

//Desc: enter a day and find which week day is
string Controller::findWeekDay(int year, int month, int day) {
	time_t rawtime;
	struct tm * timeinfo;

	const char * weekday[] = { "Duminica", "Luni",
							   "Marti", "Miercuri",
							   "Joi", "Vineri", "Sambata" };
	/* get current timeinfo and modify it to the user's choice */
	time(&rawtime);

	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	/* call mktime: timeinfo->tm_wday will be set */
	mktime(timeinfo);
	return  weekday[timeinfo->tm_wday];
}

int Controller::findStation(string A)
{
	int pos;
	for (int i = 0; i < bus.getSize(); i++) {
		for (int j = 0; j < bus.getElem(i).getRoute().size(); j++) {
			if (bus.getElem(i).getRoute().at(j) == A)
				pos = i;
		}
	}
	return pos;
}

//Desc: sort using a date
//Desc: sort using a date
vector<Bus> Controller::firstSort(string A, string B, int year, int month, int day) {
	vector<Bus> t = bus.getALL();
	vector<Bus> newlist;
	int position_1;
	int position_2;
	string weekDay;
	if ((year == 0) && (month == 0) && (day == 0)) {
		const string DAY[] = { "Duminica", "Luni",
							   "Marti", "Miercuri",
							   "Joi", "Vineri", "Sambata" };
		time_t rawtime;
		tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		int wday = timeinfo->tm_wday;
		weekDay = DAY[wday];

	}
	else weekDay = findWeekDay(year, month, day);
	for (int i = 0; i < bus.getSize(); i++) {
		if ((bus.getElem(i).findStation(A) != -1) && (bus.getElem(i).findStation(B) != -1) && (bus.getElem(i).getDay() == weekDay)) {
			newlist.push_back(bus.getElem(i));
		}
	}
	return newlist;
}

// Desc: scaneaza un bilet si nr de bilete din cont descreste
string Controller::scanning(vector<Ticket> &my_ticket, Ticket t)
{
	int ok = 0;
	int pos;
	for (auto i = 0; i < my_ticket.size(); i++) {
		if (my_ticket.at(i) == t) {
			ok = 1;
			pos = i;
		}
	}
	if (ok == 1) {
		my_ticket.erase(my_ticket.begin() + pos);
		return "Succes";
	}
	return "Error";
}

vector<Bus> Controller::getall()
{
	vector<Bus> c = bus.getALL();
	return c;
}

void Controller::adaugareclient(Client & a)
{
	c.addElem(a);
}
