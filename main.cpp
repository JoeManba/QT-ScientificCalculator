#include "scientificcalculatordialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScientificCalculatorDialog w;
    w.show();

    return a.exec();
}
