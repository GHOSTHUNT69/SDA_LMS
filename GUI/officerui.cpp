#include "officerui.h"
#include "ui_officerui.h"

OfficerUI::OfficerUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OfficerUI)
{
    ui->setupUi(this);
}

OfficerUI::~OfficerUI()
{
    delete ui;
}
