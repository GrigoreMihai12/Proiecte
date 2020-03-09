#pragma once
#include<string>
#include<iostream>
#include <vector>
using namespace std;

class Bus
{
private:
	int  nrroute;
	string day;
	string nr;
	vector<string>hour;
	int ticketId;
	vector<string> route;
public:
	Bus();
	Bus(int nrroute1, string day, string nr1, vector<string> hour, int bilet, vector<string>route);
	Bus(const Bus &p);
	~Bus();

	vector<string> getHour();
	string getNr();
	int getTicketId();
	int getnrroute();
	string getDay();
	vector<string> getRoute() const;
	void setDay(string day);
	void setHour(vector<string> timp1);
	void setNr(string nr1);
	void setTicketId(int biletid1);
	void setnrroute(int nrroute1);
	void setRoute(vector<string> ruta1);

	Bus& operator=(const Bus &c);
	bool operator==(const Bus &c);
	bool operator<(const Bus &c);
	bool operator>(const Bus &c);

	int findStation(string A);


	friend ostream & operator<<(ostream & os, const Bus & c);
	friend istream& operator >> (istream& is, Bus &c) {
		int bileteid, nrroute;
		string nr;
		string day;
		string h;
		vector<string> hour;
		vector<string> route;

		//nr rute
		is >> c.nrroute;
		//ziua
		is >> c.day;
		//nume bus
		is >> c.nr;
		//orar
		for (int i = 0; i < c.nrroute; i++) {
			is >> h;
			hour.push_back(h);
		}
		c.setHour(hour);
		//bilet id
		is >> bileteid;
		c.setTicketId(bileteid);
		//statii
		for (int i = 0; i < c.nrroute; i++) {
			is >> h;
			route.push_back(h);
		}
		c.setRoute(route);

		return is;
	}

	std::string toString() {
		std::string toReturn = std::to_string(nrroute) + " " + std::to_string(ticketId) + "\n ";
		
		toReturn += day + " " + nr + "\n";
		
		
		
		for (int i = 0; i < hour.size(); i++)
			toReturn += hour.at(i) + " " + route.at(i)  + "\n ";

		

		return toReturn;
	}
};