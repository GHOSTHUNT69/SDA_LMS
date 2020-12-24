#pragma once
#include "teacherui.h"
#include "ui_teacherui.h"

TeacherUI::TeacherUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherUI)
{
    ui->setupUi(this);
}

TeacherUI::~TeacherUI()
{
    delete ui;
}
