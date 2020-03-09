#pragma once
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qmessagebox.h>
#include <qformlayout.h>

#include "Controller.h"
#include "SortNrWindow.h"
#include "LoggedInWindow.h"
#include "SortNr1Window.h"

class mainWindowGUI : public QMainWindow {
	Q_OBJECT;
public:
	mainWindowGUI(Controller &controller) : controller { controller} {
		drawUI();
		buttons();
		this->resize(5000, 500);
	}

private:
	Controller &controller;

	QListWidget *listBuss;
	
	QPushButton *sort1Button;
	QPushButton *sort2Button;
	QPushButton *logInButton;
	QPushButton *membruNouButton;
	QPushButton *initialOrder;

	QLineEdit *userName;
	QLineEdit *password;
	
	QLineEdit *newUserName;
	QLineEdit *newPassword;
	QLineEdit *newCardID;
	QLineEdit *newDate;
	QLineEdit *newSecurity;

	

	void drawUI() {
		QWidget* mainWidget = new QWidget();
		QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);

		listBuss = new QListWidget();

		sort1Button = new QPushButton("sortByStation");
		sort2Button = new QPushButton("sortByNumber");
		initialOrder = new QPushButton("initialOrder");

		QWidget *sortButtons = new QWidget();
		QHBoxLayout *sortLayout = new QHBoxLayout(sortButtons);

		sortLayout->addWidget(sort1Button);
		sortLayout->addWidget(sort2Button);


		QWidget *bussWidget = new QWidget();
		QVBoxLayout *bussLayout = new QVBoxLayout(bussWidget);

		bussLayout->addWidget(listBuss);
		bussLayout->addWidget(sortButtons);
		bussLayout->addWidget(initialOrder);

		QWidget *logInWidget = new QWidget();
		QVBoxLayout *logInLayout = new QVBoxLayout(logInWidget);

		logInButton = new QPushButton("Log in");
		membruNouButton = new QPushButton("Membru nou");

		QWidget *logInInput = new QWidget();
		QFormLayout *formLayout = new QFormLayout(logInInput);

		QLabel *user = new QLabel("Username");
		QLabel *pass = new QLabel("Password");

		userName = new QLineEdit();
		password = new QLineEdit();

		formLayout->addRow(user, userName);
		formLayout->addRow(pass, password);

		QLabel *membruNou = new QLabel("Membru Nou");

		QWidget *newlogInInput = new QWidget();
		QFormLayout *newformLayout = new QFormLayout(newlogInInput);


		QLabel *newUserInput = new QLabel("Username");
		QLabel *newPassInput = new QLabel("Password");
		QLabel *newIDInput = new QLabel("Card ID");
		QLabel *newDateInput = new QLabel("Date");
		QLabel *newSecurityInput = new QLabel("Security Code");

		newUserName = new QLineEdit();
		newPassword = new QLineEdit();
		newCardID = new QLineEdit();
		newDate = new QLineEdit();
		newSecurity = new QLineEdit();

		newformLayout->addRow(newUserName, newUserInput);
		newformLayout->addRow(newPassword, newPassInput);
		newformLayout->addRow(newCardID, newIDInput);
		newformLayout->addRow(newDate, newDateInput);
		newformLayout->addRow(newSecurity, newSecurityInput);


		
		logInLayout->addWidget(logInInput);
		logInLayout->addWidget(logInButton);
		logInLayout->addWidget(membruNou);
		logInLayout->addWidget(newlogInInput);
		logInLayout->addWidget(membruNouButton);

		mainLayout->addWidget(bussWidget);
		mainLayout->addWidget(logInWidget);

		setCentralWidget(mainWidget);
	}
	
	void buttons() {
		QObject::connect(initialOrder, &QPushButton::clicked, [this]() {
			printList(controller.getall());
		});
		QObject::connect(sort1Button, &QPushButton::clicked, [this]() {
			SortNr1Window *sortWindow1 = new SortNr1Window("StatiePornire: ", "Destinatie: ", "An: ", "Luna: ", "Zi: ");
			sortWindow1->show();
			QObject::connect(sortWindow1, &SortNr1Window::donePressed, [this](std::string value,
			std::string value1, std::string value2, std::string value3, std::string value4) {
				int value21 = stoi(value2);
				int value31 = stoi(value3);
				int value41 = stoi(value4);
				printList(controller.firstSort(value, value1, value21, value31, value41));
			});
		});
		QObject::connect(sort2Button, &QPushButton::clicked, [this] {
			SortNrWindow *sortWindow = new SortNrWindow("Numarul liniei: ");
			sortWindow->show();

			QObject::connect(sortWindow, &SortNrWindow::donePressed, [this](std::string value) {
				printList(controller.secondSort(value));
			});
		});
		QObject::connect(logInButton, &QPushButton::clicked, [this] {
			Client client{ userName->text().toStdString(),password->text().toStdString() };
			if (controller.logare(client)) {
				//va aparea noua fereastra cos de tichete : class object =  new class 
				LoggedInWindow* wnd = new LoggedInWindow(controller, client);
				wnd->show();
			}
			else {
				QMessageBox* alerta = new QMessageBox;
				alerta->setWindowTitle("Error");
				alerta->setText("User inexistent/ parola gresita");
				alerta->show();
			}
		});
		QObject::connect(membruNouButton, &QPushButton::clicked, [this] {
			Client client{ newUserName->text().toStdString(), 
				newPassword->text().toStdString(),
				newCardID->text().toStdString(),
				newDate->text().toStdString(),
				newSecurity->text().toStdString() };
			controller.adaugareclient(client);
		});
		
	}

	void printList(std::vector<Bus> buss) {
		listBuss->clear();
		for (auto el : buss)
			listBuss->addItem(QString::fromStdString(el.toString()));
	}

};