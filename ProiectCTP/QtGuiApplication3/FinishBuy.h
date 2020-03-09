#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

#include <string>

class FinishBuy : public QWidget {
	Q_OBJECT
public:
	int& s;
	QLineEdit *card;
	QLineEdit *data;
	QLineEdit *securt;

	QPushButton *doneButton;
	QPushButton *closeButton;

	void drawUI(std::string card1, std::string data1, std::string securt1) {
		QVBoxLayout *layout = new QVBoxLayout(this);
		QWidget *a = new QWidget();
		QWidget *inputWidget = new QWidget();
		QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);
		QHBoxLayout *inputLayout1 = new QHBoxLayout(a);
		auto p = std::to_string(s);
		QLabel *label = new QLabel(QString::fromStdString(card1));
		QLabel *label1 = new QLabel(QString::fromStdString(data1));
		QLabel *label2 = new QLabel(QString::fromStdString(securt1));
		QLabel *label3 = new QLabel(QString::fromStdString("Suma totala este:"));
		QLabel *suma = new QLabel(QString::fromStdString(p));

		closeButton = new QPushButton("Close");
		doneButton = new QPushButton("Done");

		card = new QLineEdit();
		data = new QLineEdit();
		securt = new QLineEdit();

		inputLayout1->addWidget(label3);
		inputLayout1->addWidget(suma);

		inputLayout->addWidget(label);
		inputLayout->addWidget(card);
		inputLayout->addWidget(label1);
		inputLayout->addWidget(data);
		inputLayout->addWidget(label2);
		inputLayout->addWidget(securt);

		layout->addWidget(a);
		layout->addWidget(inputWidget);
		layout->addWidget(doneButton);
		layout->addWidget(closeButton);

		this->show();

	}

signals:
	void donePressed(std::string caard, std::string dataa, std::string securt);
	void closePressed();

public:
	FinishBuy(int & _s, std::string card1, std::string date1, std::string seccod) : s{_s} {
		drawUI(card1, date1, seccod);
		QObject::connect(doneButton, &QPushButton::clicked, [this]() {
			emit donePressed(card->text().toStdString(), data->text().toStdString(), securt->text().toStdString());
			this->close();
		});
		QObject::connect(closeButton, &QPushButton::clicked, [this] {
			emit closePressed();
			this->close();
		});
	}
};