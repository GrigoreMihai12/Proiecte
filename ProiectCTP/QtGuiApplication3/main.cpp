#include "QtGuiApplication3.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "mainWindowGUI.h"
#include"testTicket.h"
#include"testBus.h"
#include"testRepo.h"
#include"testRepoFile.h"
#include"testClient.h"
#include"testController.h"


int main(int argc, char *argv[])
{
	testTicket();
	testBus();
	testClient();
	testRepo();
	testRepoFile();
	testController();
	testFindWeekDy();
	testLogin();
	RepoFile<Bus> repo{ "bus.txt" };
	RepoFile<Client> repoFile{ "clientt.txt" };
	RepoFile<Ticket> repoTickets{ "tickets.txt" };
	Controller controller{ repo,repoFile,repoTickets };
	QApplication a(argc, argv);
	mainWindowGUI w{ controller };
	w.show();
	return a.exec();
}
