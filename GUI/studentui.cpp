#pragma once
#include "studentui.h"
#include "ui_studentui.h"

StudentUI::StudentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentUI)
{
    ui->setupUi(this);
}

StudentUI::~StudentUI()
{
    delete ui;
}
