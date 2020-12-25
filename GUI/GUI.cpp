#pragma once
#include "GUI.h"
LMS::App* lmsdata = new LMS::App();


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
    oui=new OfficerUI();
    hide();
    oui->show();
}

void GUI::on_pushButton_2_clicked()
{
    GUI::close();
}
