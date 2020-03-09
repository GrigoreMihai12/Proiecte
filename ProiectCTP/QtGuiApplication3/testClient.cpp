#include <iostream>
#include "testClient.h"
#include <cassert>
#include <sstream>

using namespace std;

void testClient() {
	Client c;
	assert(c.getPassword() == "");
	c = Client("Pop Ioan", "1234");
	assert(c.getUsername() == "Pop Ioan");
	Client c1;
	c1 = c;
	c1.setPassword("0000");
	assert(c1.getPassword() == "0000");

	stringstream fisi;
	fisi.write("Pop-Ioan 1234", 14);
	Client cl;
	fisi >> cl;

}