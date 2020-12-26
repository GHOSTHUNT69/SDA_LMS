#pragma once
#include "GUI.h"
#include <QMessageBox>
#include <QEventLoop>
LMS::App *lmsdata = new LMS::App();

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void GUI::on_actionExit_triggered()
{
	GUI::close();
}

void GUI::on_pushButton_clicked()
{
	string uname = ui.username->text().toStdString();
	string pass = ui.password->text().toStdString();
	if (lmsdata->Login(uname, pass))
	{
		oui = new OfficerUI();
		//hide();
		oui->show();
	}
	else
	{
		QMessageBox::information(this, "Invalid", "Invalid username or password\nOr a person is already logged in.");
	}
}

void GUI::on_pushButton_2_clicked()
{
	GUI::close();
}
