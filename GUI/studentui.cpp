#pragma once
#include "studentui.h"
#include "ui_studentui.h"
#include "LMSData.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "Section.h"
#include "Registration.h"
#include "Course.h"
#include "Faculty.h"

StudentUI::StudentUI(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::StudentUI)
{
    ui->setupUi(this);
}

void StudentUI::closeEvent(QCloseEvent *event)
{
    lmsdata->Logout();
    event->accept();
}

StudentUI::~StudentUI()
{
    delete ui;
}

void StudentUI::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void StudentUI::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ADDREG);
    ui->comboBox->clear();
    for (auto i : lmsdata->getSections())
    {
        string sec = i->get_name();
        string cour;
        if (i->getCourse() != nullptr)
            cour = i->getCourse()->get_ccode();
        else
            cour = "null";
        ui->comboBox->addItem((sec + "|" + cour).c_str());
    }
}

void StudentUI::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->DELREG);
    for(auto i: lmsdata->getRegistrations())
    {
        string sec = i->getSection()->get_name();
        string cour;
        if (i->getCourse() != nullptr)
            cour = i->getCourse()->get_ccode();
        else
            cour = "null";
        ui->comboBox_2->addItem((sec + "|" + cour).c_str());
    }
}

void StudentUI::on_viewRegTable_cellActivated(int r, int c)
{
    vector<LMS::Registration *> reg = lmsdata->getRegistrations();
    int row = 0;
    ui->viewRegTable->setRowCount(reg.size()+1);
    ui->viewRegTable->setColumnCount(3);

    for (auto i : reg)
    {
        QTableWidgetItem *item;
        for (int column = 0; column < c; column++)
        {
            item = new QTableWidgetItem();

            if (column == 0 && i->getCourse())
                item->setText(i->getCourse()->get_cname().c_str());
            if (column == 1 && i->getSection())
                item->setText(i->getSection()->get_name().c_str());
            if (column == 2 && i->getTeacher())
                item->setText(i->getTeacher()->get_name().c_str());

            ui->viewRegTable->setItem(row, column, item);
        }
        row++;
    }
}

void StudentUI::on_registrations_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VIEWREG);
    on_viewRegTable_cellActivated(10,3);
}

void StudentUI::on_pushButton_4_clicked()
{
    QStringList seccour=ui->comboBox->currentText().split("|");
    string sec=seccour.at(0).toStdString();
    string cour = seccour.at(1).toStdString();
    uint ssize = sec.size()*cour.size();
    if (ssize > 0)
    {
        if(lmsdata->addRegistration(cour,sec))
            QMessageBox::information(this, "Successfull", "Student and Section Linked!");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void StudentUI::on_pushButton_6_clicked()
{
    QStringList seccour=ui->comboBox_2->currentText().split("|");
    string sec=seccour.at(0).toStdString();
    string cour = seccour.at(1).toStdString();
    uint ssize = sec.size()*cour.size();
    if (ssize > 0)
    {
        if(lmsdata->dropRegistration(cour,sec))
            QMessageBox::information(this, "Successfull", "Student and Section Unlinked!");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}
