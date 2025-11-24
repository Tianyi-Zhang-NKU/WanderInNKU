#include "mainwindow.h"
#include "nankaiintropage.h"
#include "admissionpage.h"
#include "vrpage_lite.h"
#include "culturepage.h"
#include <qstackedwidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    //NankaiIntroPage w;
    //AdmissionPage w;
    //VRPageLite w;
    //CulturePage w;

    w.setWindowTitle("南开大学文化信息平台");
    w.setWindowIcon(QIcon(":/main_picture/picture/pic_icon.png"));
    w.show();
    return app.exec();
}
