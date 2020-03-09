#pragma once
#include"Repo.h"
#include"RepoFile.h"
class Controller
{
private:
	RepoFile<Bus>& bus;
	RepoFile<Client>& c;
	RepoFile<Ticket>& ticket;
public:
	Controller(RepoFile<Bus>& _bus, RepoFile<Client>& _c, RepoFile<Ticket>& _ticket) : bus{ _bus }, c{ _c }, ticket{ _ticket } {};
	~Controller();
	bool logare(Client &a);
	vector<Bus> secondSort(string nr);
	string findWeekDay(int year, int month, int day);
	int findStation(string A);
	vector<Bus>firstSort(string A, string B, int year, int month, int day);
	//vector<Ticket> listticket(Client &a);
	string scanning(vector<Ticket> &my_ticket, Ticket t);
	vector<Bus> getall();
	vector<Client> getClienti() {
		return c.getALL();
	}
	void adaugareclient(Client &a);
	vector<Ticket> getticktets()
	{
		return ticket.getALL();
	}
	vector<Ticket> getticketclient(Client &a)
	{
		return a.getlista();
	}
};

