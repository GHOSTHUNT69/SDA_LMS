#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Student.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI w;
    w.show();
    return a.exec();
}
