#pragma once
#include <string>
#include"Ticket.h"
#include<vector>
using namespace std;
class Client
{
private:
	string username;
	string password;
	string cardNo;
	string date;
	string security_code;
	vector <Ticket> ticket;
public:
	Client();
	Client(string u, string p, string c, string d, string s);
	Client(string u, string p);
	Client(const Client& c);
	Client& operator=(const Client &c);
	~Client();
	void setUsername(string);
	void setPassword(string);
	string getUsername() const;
	string getPassword() const;
	void setCardNo(string);
	void setDate(string);
	void setSecurity_code(string);
	string getCardNo();
	string getDate();
	string getSecurity_code();
	Ticket& getOneTicket(int pos);
	vector<Ticket> getlista();
	void addTicket(Ticket t);
	void deleteTicket(int pos);
	int getsize();
	bool operator==(const Client& a);
	friend istream& operator >>(istream& is, Client& c);
	friend ostream& operator <<(ostream& os, Client& c);
	int getSum();
};