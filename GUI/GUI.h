#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "officerui.h"
#include "studentui.h"
#include "teacherui.h"
#include "LMS.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = Q_NULLPTR);

private slots:
    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GUIClass ui;
    OfficerUI *oui;
    StudentUI *sui;
    TeacherUI *tui;

public:
};
