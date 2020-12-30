#pragma once
#ifndef OFFICERUI_H
#define OFFICERUI_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCloseEvent>
//#include "LMS.h"

namespace Ui
{
    class OfficerUI;
}

//extern LMS::LMS* lmsdata;

class OfficerUI : public QWidget
{
    Q_OBJECT

public:
    explicit OfficerUI(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
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

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_sections_clicked();

    void on_pushButton_24_clicked();

    void on_courses_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_17_clicked();

    void on_viewCourseTable_cellActivated(int row, int column);

    void on_pushButton_25_clicked();

    void on_viewSectionTable_cellActivated(int row, int column);

    void on_register_2_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

private:
    Ui::OfficerUI *ui;
};

#endif // OFFICERUI_H
