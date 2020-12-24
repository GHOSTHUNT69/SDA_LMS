#pragma once
#include "officerui.h"
#include "ui_officerui.h"

OfficerUI::OfficerUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OfficerUI)
{
    ui->setupUi(this);
}

OfficerUI::~OfficerUI()
{
    delete ui;
}

void OfficerUI::on_students_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//Students
}

void OfficerUI::on_newStudent_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//NEWStudent
}

void OfficerUI::on_pushButton_4_clicked()//add student
{
    //lmsdata->addStudent(new Student());
}
