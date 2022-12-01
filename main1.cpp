#include "mainwindow1.h"
#include <QApplication>
#include <QMessageBox>
#include"connexion1.h"
#include <QApplication>
#include "employe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test=c.createconnect();
    MainWindow w;
    w.show();
    if(test)


       {QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
