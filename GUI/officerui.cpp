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
    ui->comboBox->clear();
    ui->comboBox_2->clear();
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
        if(lmsdata->linkCourseSection(scode, sec))
            QMessageBox::information(this, "Successfull", "Course and Section Linked!");
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
    uint ssize = sname.size();
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

void OfficerUI::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VIEWCOURSE);
    on_viewCourseTable_cellActivated(10,3);
}

void OfficerUI::on_viewCourseTable_cellActivated(int r, int c)
{
    vector<LMS::Course *> course = lmsdata->getCourses();
    int row =0;
    ui->viewCourseTable->setRowCount(course.size()+1);
    ui->viewCourseTable->setColumnCount(3);

    for (auto i : course)
    {
        QTableWidgetItem *item;
        for (int column = 0; column < c; column++)
        {
            item = new QTableWidgetItem();

            if (column == 0)
                item->setText(i->get_cname().c_str());
            if (column == 1)
                item->setText(i->get_ccode().c_str());
            string sec;
            for(auto j:i->get_csections())
                sec+=j->get_name()+", ";
            if(!sec.empty())
                sec.pop_back();
            if (column == 2)
                item->setText(sec.c_str());

            ui->viewCourseTable->setItem(row, column, item);
        }
        row++;
    }
}

void OfficerUI::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->VIEWSECTION);
    on_viewSectionTable_cellActivated(10,4);
}

void OfficerUI::on_viewSectionTable_cellActivated(int r, int c)
{
    vector<LMS::Section *> section = lmsdata->getSections();
    int row = 0;
    ui->viewSectionTable->setRowCount(section.size()+1);
    ui->viewSectionTable->setColumnCount(4);

    for (auto i : section)
    {
        QTableWidgetItem *item;
        for (int column = 0; column < c; column++)
        {
            item = new QTableWidgetItem();

            if (column == 0)
                item->setText(i->get_name().c_str());
            if (column == 1 && i->getCourse())
                item->setText(i->getCourse()->get_cname().c_str());
            if (column == 2 && i->getTeacher())
                item->setText(i->getTeacher()->get_name().c_str());
            if (column == 3)
                item->setText(std::to_string(i->getStudentCount()).c_str());

            ui->viewSectionTable->setItem(row, column, item);
        }
        row++;
    }
}

void OfficerUI::on_register_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->REGSTUDENT);
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    for(auto i: lmsdata->getStudents())
        ui->comboBox_3->addItem(i->get_rollno().c_str());
    for (auto i : lmsdata->getSections())
    {
        string sec = i->get_name();
        string cour;
        if (i->getCourse() != nullptr)
            cour = i->getCourse()->get_ccode();
        else 
            cour = "null";
        ui->comboBox_4->addItem((sec + "|" + cour).c_str());
    }
}

void OfficerUI::on_pushButton_27_clicked()
{
    string rollno=ui->comboBox_3->currentText().toStdString();
    QStringList seccour=ui->comboBox_4->currentText().split("|");
    string sec=seccour.at(0).toStdString();
    string cour = seccour.at(1).toStdString();
    uint ssize = rollno.size() * sec.size()*cour.size();
    if (ssize > 0)
    {
        if(lmsdata->linkStudentSection(rollno,cour,sec))
            QMessageBox::information(this, "Successfull", "Student and Section Linked!");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}

void OfficerUI::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ADDTEACHER);
}

void OfficerUI::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TEAINSEC);
    ui->comboBox_5->clear();
    ui->comboBox_6->clear();
    for(auto i: lmsdata->getTeachers())
        ui->comboBox_5->addItem(i->get_name().c_str());
    for (auto i : lmsdata->getSections())
    {
        string sec = i->get_name();
        string cour;
        if (i->getCourse() != nullptr)
            cour = i->getCourse()->get_ccode();
        else
            cour = "null";
        ui->comboBox_6->addItem((sec + "|" + cour).c_str());
    }
}

void OfficerUI::on_pushButton_29_clicked()
{
    string tea=ui->comboBox_5->currentText().toStdString();
    QStringList seccour=ui->comboBox_6->currentText().split("|");
    string sec=seccour.at(0).toStdString();
    string cour = seccour.at(1).toStdString();
    uint ssize =tea.size() * sec.size()*cour.size();
    if (ssize > 0)
    {
        if(lmsdata->linkTeacherSection(tea,cour,sec))
            QMessageBox::information(this, "Successfull", "Teacher and Section Linked!");
    }
    else
    {
        QMessageBox::information(this, "Invalid Input", "Please check your input details");
    }
}
