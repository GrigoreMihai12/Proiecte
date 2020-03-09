#include "testBus.h"
#include<cassert>
#include<sstream>
using namespace std;
void testBus()
{
	vector<string> a;
	a.push_back("Manastur");
	a.push_back("Iulius");
	Bus p1(2, "Duminica", "Linia 25", { "10:00", "15:31" }, 5, { "Manastur","Iulius" });
	assert(p1.getNr() == "Linia 25");
	assert(p1.getHour()[0] == "10:00");
	assert(p1.getRoute() == a);
	Bus b;
	cout << " All Bus tests are ok " << endl;
}