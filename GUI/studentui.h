#pragma once
#ifndef STUDENTUI_H
#define STUDENTUI_H

#include <QWidget>

namespace Ui {
class StudentUI;
}

class StudentUI : public QWidget
{
    Q_OBJECT

public:
    explicit StudentUI(QWidget *parent = nullptr);
    ~StudentUI();

private:
    Ui::StudentUI *ui;
};

#endif // STUDENTUI_H
