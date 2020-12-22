#include "StudentLogin.h"
#include "ui_StudentLogin.h"

StudentLogin::StudentLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentLogin)
{
    ui->setupUi(this);
}

StudentLogin::~StudentLogin()
{
    delete ui;
}

void StudentLogin::on_pushButton_2_clicked()
{

}
