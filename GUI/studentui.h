#pragma once
#ifndef STUDENTUI_H
#define STUDENTUI_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui
{
    class StudentUI;
}

class StudentUI : public QWidget
{
    Q_OBJECT

public:
    explicit StudentUI(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~StudentUI();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_viewRegTable_cellActivated(int row, int column);

    void on_registrations_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::StudentUI *ui;
};

#endif // STUDENTUI_H
