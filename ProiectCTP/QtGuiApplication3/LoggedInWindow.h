#pragma once
#include <qwidget.h>
#include <Controller.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qdebug.h>

#include "FinishBuy.h"
#include "Repo.h"


class LoggedInWindow : public QWidget
{
private:
	RepoFile<Ticket> c{ "BileteClient.txt" };



	Controller& cntrl;
	Client& client;
	QLabel* A;
	QLabel* B;
	QLabel* C;
	QListWidget* lstBilete;
	QListWidget* lstCos;
	QListWidget* lstCumparate;
	QPushButton* btnCumpara;
	QPushButton* btnStergeCos;
	QPushButton* btnAddCos;
	QLabel* totalSum;
	void showgui() {
		QHBoxLayout*  layoutPrincipal = new QHBoxLayout;
		setLayout(layoutPrincipal);
		setWindowTitle("Clientul: " + QString::fromStdString(client.getUsername()));

		//lista cu bilete
		QVBoxLayout* layoutStanga = new QVBoxLayout;
		QWidget* widgetStanga = new QWidget;
		widgetStanga->setLayout(layoutStanga);

		lstBilete = new QListWidget;
		btnAddCos = new QPushButton("Adauga in cos");
		A = new QLabel("LISTA BILETE");
		A->setAlignment(Qt::AlignHCenter);

		layoutStanga->addWidget(A);
		layoutStanga->addWidget(lstBilete);
		layoutStanga->addWidget(btnAddCos);

		//lista cos
		QVBoxLayout* layoutCentru = new QVBoxLayout;
		QWidget* widgetCentru = new QWidget;
		widgetCentru->setLayout(layoutCentru);

		B = new QLabel("Cos");
		B->setAlignment(Qt::AlignHCenter);
		btnStergeCos = new QPushButton("Sterge cosul");
		btnCumpara = new QPushButton("Proceseaza tranzactia");
		lstCos = new QListWidget;
		B = new QLabel("BILETE IN COS");
		A->setAlignment(Qt::AlignHCenter);
		layoutCentru->addWidget(B);
		layoutCentru->addWidget(lstCos);
		layoutCentru->addWidget(btnStergeCos);
		layoutCentru->addWidget(btnCumpara);

		//lista cumparate
		QVBoxLayout* layoutDrpt = new QVBoxLayout;
		QWidget* widgetDrpt = new QWidget;
		widgetDrpt->setLayout(layoutDrpt);

		lstCumparate = new QListWidget;
		C = new QLabel("Bilete cumparate");
		C->setAlignment(Qt::AlignHCenter);
		layoutDrpt->addWidget(C);
		layoutDrpt->addWidget(lstCumparate);

		//adaugare la ecran principal
		layoutPrincipal->addWidget(widgetStanga);
		layoutPrincipal->addWidget(widgetCentru);
		layoutPrincipal->addWidget(widgetDrpt);
		//afisarebilete();
		afisarebilet();
	}

	void semnals() {
		QObject::connect(btnStergeCos, &QPushButton::clicked, [this]() {
			lstCos->clear();
		});

		QObject::connect(btnAddCos, &QPushButton::clicked, [this]() {
			auto list = lstBilete->selectedItems();
			for (auto item : list) {
				lstCos->addItem(item->clone());
			}

		});

		QObject::connect(btnCumpara, &QPushButton::clicked, [&]() {
			auto sum = 0;
			for (int i = 0; i < lstCos->count(); i++)
			{
				auto bilet = lstCos->item(i)->text();
				auto elems = bilet.split(" ");
				sum += elems[1].toInt();
			}
			FinishBuy* buy = new FinishBuy(sum, "CardNo", "Date", "Security-Code");
			buy->show();
			QObject::connect(buy, &FinishBuy::donePressed, [this]() {
					for (int i = 0; i < lstCos->count(); i++)
					{
						auto bilet = lstCos->item(i);
						lstCumparate->addItem(bilet->clone());
						auto elems = bilet->text().split(" ");
						ofstream fout("BileteClient.txt", ofstream::app);
						Ticket t{ elems[0].toInt(), elems[1].toInt(), elems[4].toInt() };
						fout << t << "\n";
					}
					lstCos->clear();
			});
		});

	}

	void initbilete() {
		auto list = cntrl.getticktets();
		for (auto el : list) {
			auto item = new QListWidgetItem;
			item->setText(QString::fromStdString(to_string(el.getId()) + " " + to_string(el.getPrice()) + " lei  " + to_string(el.getTime()) + " minute"));
			lstBilete->addItem(item);
		}
	}
	void afisarebilete()
	{
		vector<Ticket> v = cntrl.getticketclient(client);
		lstCumparate->clear();
		for (auto i = 2; i < v.size(); i ++) {
			auto item = new QListWidgetItem;
			lstCumparate->addItem(QString::fromStdString(to_string(v[i].getId()) + " " + to_string(v[i].getPrice()) + " lei  " + to_string(v[i].getTime()) + " minute" + "\n"));
			client.addTicket(v[i]);
			lstCumparate->addItem(item);
		}
	}

	void afisarebilet()
	{
		vector<Ticket> p = c.getALL();
		lstCumparate->clear();
		for (auto el : p)
		{
			auto item = new QListWidgetItem;
			lstCumparate->addItem(QString::fromStdString(to_string(el.getId()) + " " + to_string(el.getPrice()) + " lei  " + to_string(el.getTime()) + " minute"));
			lstCumparate->addItem(item);
		}
	}

public:
	LoggedInWindow(Controller& _c, Client& _cl) : cntrl{ _c }, client{ _cl } {
		showgui();
		semnals();
		initbilete();
	};
	~LoggedInWindow() {};
};

