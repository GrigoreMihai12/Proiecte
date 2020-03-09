#include "testController.h"
#include <cassert>
using namespace std;

void testFindWeekDy()
{
	RepoFile<Bus> reBus{ "Bus.txt" };
	RepoFile<Client> reClient{ "Client.txt" };
	RepoFile<Ticket> reTicket{ "Ticket.txt" };
	Controller c{ reBus,reClient,reTicket };
	assert(c.findWeekDay(2019, 05, 31) == "Vineri");
}

void testLogin() {
	RepoFile<Bus> reBus{ "Bus.txt" };
	RepoFile<Client> reClient{ "Clientt.txt" };
	RepoFile<Ticket> reTicket{ "Ticket.txt" };
	Controller c{ reBus,reClient,reTicket };
	Client c1("Popescu_Ioana", "1230");
	assert(c.logare(c1) == false);
}

void testScanning() {

	RepoFile<Bus> reBus{ "Bus.txt" };
	RepoFile<Client> reClient{ "Clientt.txt" };
	RepoFile<Ticket> reTicket{ "Ticket.txt" };
	Controller c{ reBus,reClient,reTicket };

	vector<Ticket> list;
	Ticket t(1789, 5, 30);
	Ticket t1(3512, 3, 30);
	list.push_back(t);
	list.push_back(t1);
	int n = list.size();
	assert(n == 2);
	Ticket t2(8989, 5, 12);
	string s = c.scanning(list, t);
	assert(s == "Succes");
	string str = c.scanning(list, t2);
	assert(str == "Error");
	int n1 = list.size();
	assert(n1 == 1);
}

void testController() {
	testFindWeekDy();
	testLogin();
	cout << " All Controller test are ok" << endl;

}