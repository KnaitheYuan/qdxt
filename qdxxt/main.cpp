#include <QtGui/QApplication>
#include "Widget.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
