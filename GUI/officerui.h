#pragma once
#ifndef OFFICERUI_H
#define OFFICERUI_H

#include <QWidget>
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

private:
    Ui::OfficerUI *ui;
};

#endif // OFFICERUI_H
