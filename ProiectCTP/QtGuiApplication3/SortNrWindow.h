	#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

#include <string>

class SortNrWindow : public QWidget {
	Q_OBJECT
public:
	
	QLineEdit *sortValueInput;
	QPushButton *doneButton;

	void drawUI(std::string sortValue) {
		QVBoxLayout *layout = new QVBoxLayout(this);

		QWidget *inputWidget = new QWidget();
		QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);

		QLabel *label = new QLabel(QString::fromStdString(sortValue));
		sortValueInput = new QLineEdit();
		doneButton = new QPushButton("Done");

		inputLayout->addWidget(label);
		inputLayout->addWidget(sortValueInput);

		layout->addWidget(inputWidget);
		layout->addWidget(doneButton);

		this->show();

	}

signals:
	void donePressed(std::string sortLineEdit);

public:
	SortNrWindow(std::string sortValue) {
		drawUI(sortValue);
		QObject::connect(doneButton, &QPushButton::clicked, [this]() {
			emit donePressed(sortValueInput->text().toStdString());
			this->close();
		});
	}


};