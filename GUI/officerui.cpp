#pragma once
#include "officerui.h"
#include "ui_officerui.h"
#include "string"
#include "LMSData.h"
#include "Student.h"
#include "Faculty.h"
#include "Course.h"
#include "Section.h"
#include <QMessageBox>

OfficerUI::OfficerUI(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::OfficerUI)
{
    ui->setupUi(this);
}

void OfficerUI::closeEvent(QCloseEvent *event)
{
    lmsdata->Logout();
    event->accept();
}

OfficerUI::~OfficerUI()
{
    delete ui;
    lmsdata->Logout();
}

void OfficerUI::on_students_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //Students
}

void OfficerUI::on_newStudent_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //NEWStudent
}

void OfficerUI::on_pushButton_4_clicked() //add student
{
    string sname = ui->sname->text().toStdString();
    string semail = ui->semail->text().toStdString();
    string spass = ui->spass->text().toStdString();
    string srollno = ui->srollno->text().toStdString();
    string sdob = ui->sdob->text().toStdString();
    string susername = ui->susername->text().toStdString();
    uint ssize = sname.size() * semail.size() * spass.size() * srollno.size() * sdob.size() * susername.size();
    if (ssize > 0)
    {
        QMessageBox::information(this, "Successfull", "Student added");
        lmsdata->addStudent(new LMS::Student(srollno, sname, sdob, semail, susername, spass));
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void OfficerUI::on_sview_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->studentview);
    on_tableWidget_cellActivated(10, 6);
}

void OfficerUI::on_tableWidget_cellActivated(int r, int c)
{
    vector<LMS::Student *> students = lmsdata->getStudents();
    int row = 0;
    for (auto i : students)
    {
        ui->sviewtableWidget->insertRow(ui->sviewtableWidget->rowCount());
        QTableWidgetItem *item;
        for (int column = 0; column < c; column++)
        {
            item = new QTableWidgetItem();

            if (column == 0)
                item->setText(i->get_name().c_str());
            if (column == 1)
                item->setText(i->get_rollno().c_str());
            ;
            if (column == 2)
                item->setText(i->get_dob().c_str());
            if (column == 3)
                item->setText(i->get_email().c_str());
            if (column == 4)
                item->setText(i->get_username().c_str());
            if (column == 5)
                item->setText(i->get_pass().c_str());

            ui->sviewtableWidget->setItem(row, column, item);
        }
        row++;
    }
}

void OfficerUI::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void OfficerUI::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void OfficerUI::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->NEWStudent);
}

void OfficerUI::on_teachers_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TEACHERS);
}

void OfficerUI::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void OfficerUI::on_MainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void OfficerUI::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void OfficerUI::on_pushButton_13_clicked()
{
    string sname = ui->sname_2->text().toStdString();
    string semail = ui->semail_2->text().toStdString();
    string spass = ui->spass_2->text().toStdString();
    string sdob = ui->sdob_2->text().toStdString();
    string susername = ui->susername_2->text().toStdString();
    uint ssize = sname.size() * semail.size() * spass.size() * sdob.size() * susername.size();
    if (ssize > 0)
    {
        QMessageBox::information(this, "Successfull", "Teacher added");
        lmsdata->addTeacher(new LMS::Faculty(sname, sdob, semail, susername, spass));
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void OfficerUI::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VIEWTEACHER);
    on_sviewtableWidget_2_cellActivated(10, 5);
}

void OfficerUI::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ADDTEACHER);
}

void OfficerUI::on_sviewtableWidget_2_cellActivated(int r, int c)
{
    vector<LMS::Faculty *> teachers = lmsdata->getTeachers();
    int row = 0;
    for (auto i : teachers)
    {
        ui->sviewtableWidget_2->insertRow(ui->sviewtableWidget->rowCount());
        QTableWidgetItem *item;
        for (int column = 0; column < c; column++)
        {
            item = new QTableWidgetItem();

            if (column == 0)
                item->setText(i->get_name().c_str());
            if (column == 1)
                item->setText(i->get_dob().c_str());
            if (column == 2)
                item->setText(i->get_email().c_str());
            if (column == 3)
                item->setText(i->get_username().c_str());
            if (column == 4)
                item->setText(i->get_pass().c_str());

            ui->sviewtableWidget_2->setItem(row, column, item);
        }
        row++;
    }
}

void OfficerUI::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ADDCOURSE);
}

void OfficerUI::on_pushButton_21_clicked()
{
    string sname = ui->lineEdit->text().toStdString();
    string scode = ui->lineEdit_2->text().toStdString();
    uint ssize = sname.size() * scode.size();
    if (ssize > 0)
    {
        QMessageBox::information(this, "Successfull", "Teacher added");
        lmsdata->addCourse(new LMS::Course(sname, scode));
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void OfficerUI::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->COURSES);
}

void OfficerUI::on_comboBox_activated(const QString &arg1)
{
}

void OfficerUI::on_comboBox_2_activated(const QString &arg1)
{
}

void OfficerUI::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->SECTIONINCOURSE);
    for(auto i: lmsdata->getCourses())
        ui->comboBox->addItem(i->get_ccode().c_str());
    for(auto i :lmsdata->getSections())
        ui->comboBox_2->addItem(i->get_name().c_str());
}

void OfficerUI::on_pushButton_23_clicked()
{
    string scode=ui->comboBox->currentText().toStdString();
    string sec=ui->comboBox_2->currentText().toStdString();
    uint ssize = scode.size() * sec.size();
    if (ssize > 0)
    {
        if(lmsdata->addCourseToSection(scode, sec))
            QMessageBox::information(this, "Successfull", "Teacher added");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void OfficerUI::on_sections_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->SECTIONS);
}

void OfficerUI::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ADDSECTION);
}

void OfficerUI::on_courses_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->COURSES);
}

void OfficerUI::on_pushButton_26_clicked()
{
    string sname=ui->lineEdit_3->text().toStdString();
    string course=ui->comboBox_3->currentText().toStdString();
    uint ssize = sname.size() * course.size();
    if (ssize > 0)
    {
        if(lmsdata->addSection(new LMS::Section(sname)))
            QMessageBox::information(this, "Successfull", "Section added");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}
