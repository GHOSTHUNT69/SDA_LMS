#ifndef OFFICERUI_H
#define OFFICERUI_H

#include <QWidget>

namespace Ui {
class OfficerUI;
}

class OfficerUI : public QWidget
{
    Q_OBJECT

public:
    explicit OfficerUI(QWidget *parent = nullptr);
    ~OfficerUI();

private:
    Ui::OfficerUI *ui;
};

#endif // OFFICERUI_H
