#pragma once
#ifndef OFFICERUI_H
#define OFFICERUI_H

#include <QWidget>
#include<QTableWidget>
#include<QTableWidgetItem>
//#include "LMS.h"

namespace Ui {
class OfficerUI;
}


//extern LMS::LMS* lmsdata;

class OfficerUI : public QWidget
{
    Q_OBJECT

public:
    explicit OfficerUI(QWidget *parent = nullptr);
    ~OfficerUI();

private slots:
    void on_students_2_clicked();

    void on_newStudent_clicked();

    void on_pushButton_4_clicked();

    void on_sview_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    //void on_sviewtableWidget_cellActivated(int row, int column);

    void on_teachers_clicked();

    void on_pushButton_3_clicked();

    void on_MainMenu_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

    void on_sviewtableWidget_2_cellActivated(int row, int column);

private:
    Ui::OfficerUI *ui;
};

#endif // OFFICERUI_H
