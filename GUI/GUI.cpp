#include "GUI.h"
#include "StudentLogin.h"

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void GUI::on_actionExit_triggered()
{
    GUI::close();
}

void GUI::on_pushButton_clicked()
{
    StudentLogin slogin;
    slogin.setModel(true);
    slogin.show();
}
