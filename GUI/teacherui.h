#pragma once
#ifndef TEACHERUI_H
#define TEACHERUI_H

#include <QWidget>

namespace Ui
{
    class TeacherUI;
}

class TeacherUI : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherUI(QWidget *parent = nullptr);
    ~TeacherUI();

private:
    Ui::TeacherUI *ui;
};

#endif // TEACHERUI_H
