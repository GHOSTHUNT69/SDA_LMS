#pragma once
#include "officerui.h"
#include "ui_officerui.h"
#include"string"
#include "LMSData.h"
#include "Student.h"
#include<QMessageBox>

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
    string sname= ui->sname->text().toStdString();
    string semail= ui->semail->text().toStdString();
    string spass= ui->spass->text().toStdString();
    string srollno= ui->srollno->text().toStdString();
    string sdob= ui->sdob->text().toStdString();
    string susername= ui->susername->text().toStdString();
    uint ssize=sname.size()*semail.size()*spass.size()*srollno.size()*sdob.size()*susername.size();
    if(ssize>0)
    lmsdata->addStudent(new LMS::Student(srollno,sname,sdob,semail,susername,spass));
    else
    {
        QMessageBox::information(this,"Invalid Input","Please check your input details");
    }
}
