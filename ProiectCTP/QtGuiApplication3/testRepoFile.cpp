#include "testRepoFile.h"
#include<cassert>
using namespace std;

void testRepoFile()
{
	RepoFile<Client> re{ "Clientt.txt" };
	vector<Client> list = re.getALL();
	//assert(list.size() == 3);
	//assert(list.at(0).getPassword() == "1230");
}
