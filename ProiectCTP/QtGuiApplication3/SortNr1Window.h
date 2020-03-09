#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

#include <string>

class SortNr1Window : public QWidget {
	Q_OBJECT
public:

	QLineEdit *StationA;
	QLineEdit *StationB;
	QLineEdit *year;
	QLineEdit *month;
	QLineEdit *day;
	QPushButton *doneButton;

	void drawUI(std::string StationA1, std::string StationB1, std::string year1, std::string month1, std::string day1) {
		QVBoxLayout *layout = new QVBoxLayout(this);

		QWidget *inputWidget = new QWidget();
		QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);

		QLabel *label = new QLabel(QString::fromStdString(StationA1));
		QLabel *label1 = new QLabel(QString::fromStdString(StationB1));
		QLabel *label2 = new QLabel(QString::fromStdString(year1));
		QLabel *label3 = new QLabel(QString::fromStdString(month1));
		QLabel *label4 = new QLabel(QString::fromStdString(day1));
		
		StationA = new QLineEdit();
		StationB = new QLineEdit();
		year = new QLineEdit();
		month = new QLineEdit();
		day = new QLineEdit();
		doneButton = new QPushButton("Done");

		inputLayout->addWidget(label);
		inputLayout->addWidget(StationA);
		inputLayout->addWidget(label1);
		inputLayout->addWidget(StationB);
		inputLayout->addWidget(label2);
		inputLayout->addWidget(year);
		inputLayout->addWidget(label3);
		inputLayout->addWidget(month);
		inputLayout->addWidget(label4);
		inputLayout->addWidget(day);

		layout->addWidget(inputWidget);
		layout->addWidget(doneButton);

		this->show();

	}

signals:
	void donePressed(std::string sortLineEdit, std::string sortLineEdit1, std::string SrotLineedit2, std::string SortLineedit3,
		std::string SortLineedit4);

public:
	SortNr1Window(std::string StationA1, std::string StationB1, std::string year1, std::string month1, std::string day1) {
		drawUI(StationA1, StationB1, year1, month1, day1);
		QObject::connect(doneButton, &QPushButton::clicked, [this]() {
			emit donePressed(StationA->text().toStdString(), StationB->text().toStdString(), year->text().toStdString(), 
				month->text().toStdString(), day->text().toStdString());
			this->close();
		});
	}


};