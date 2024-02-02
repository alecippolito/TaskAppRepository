#include "TaskApp.h"
#include <QtWidgets/QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaskApp w;
    w.show();
    return a.exec();
}
