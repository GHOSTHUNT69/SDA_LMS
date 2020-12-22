#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = Q_NULLPTR);

private slots:
    void on_actionExit_triggered();

    void on_pushButton_clicked();

private:
    Ui::GUIClass ui;
};
