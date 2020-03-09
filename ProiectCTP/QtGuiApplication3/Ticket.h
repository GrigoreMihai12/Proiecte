#pragma once
#include<string>
#include<iostream>

using namespace std;

class Ticket
{
private:
	int price;
	int time;
	int id;

public:
	Ticket();
	Ticket(int, int, int);
	Ticket(const Ticket &c);
	~Ticket();


	int getPrice();
	int getTime();
	int getId();

	void setPrice(int);
	void setTime(int);
	void setId(int);

	Ticket& operator=(const Ticket &c);
	bool operator==(const Ticket &c);
	bool operator<(const Ticket &c);
	bool operator>(const Ticket &c);
	friend ostream& operator<<(ostream &os, Ticket &c);
	friend istream& operator >>(istream& is, Ticket& c);
};