#ifndef TEACHERUI_H
#define TEACHERUI_H

#include <QtWidgets/QDialog>

namespace Ui {
class TeacherUI;
}

class TeacherUI : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherUI(QWidget *parent = nullptr);
    ~TeacherUI();

private:
    Ui::TeacherUI *ui;
};

#endif // TEACHERUI_H
