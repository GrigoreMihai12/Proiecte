#include "testTicket.h"

void testTicket()
{
	Ticket p;
	Ticket p1(123, 5, 30);
	Ticket p2(p1);
	p = p1;
	assert(p.getId() == 123);
	assert(p.getPrice() == 5);
	assert(p.getTime() == 30);

	p2.setId(321);
	p2.setPrice(10);
	p2.setTime(60);

	assert(p2.getId() == 321);
	assert(p2.getPrice() == 10);
	assert(p2.getTime() == 60);
	assert(p2 > p);
	assert(p < p2);
	assert(p == p1);
	cout << " All Ticket tests are ok " << endl;
}