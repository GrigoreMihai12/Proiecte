#include "testRepo.h"
#include<iostream>
#include <cassert>
using namespace std;

void testRepo()
{
	Repo<Client> re;
	Client c("PopaIoan", "0000");
	re.addElem(c);
	assert(re.getSize() == 1);
	Client c1("Ionescu Mihai", "1234");
	re.addElem(c1);
	assert(re.getSize() == 2);
	vector <Client> list;
	list = re.getALL();
	assert(list[0].getPassword() == "0000");
	re.deleteElem();
	assert(re.getSize() == 1);
	Client c2("Barbu Mihaela", "7894");
	re.addElem(c2);
	re.getElem(1).setPassword("4561");
	assert(re.getALL().at(1).getPassword() == "4561");
	re.deletePos(0);
	assert(re.getALL().at(0).getUsername() == "Barbu Mihaela");
}