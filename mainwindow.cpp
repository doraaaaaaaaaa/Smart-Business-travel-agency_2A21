#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tablvol->setModel(v.afficher());
ui->tablvol_2->setModel(v.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lajout_clicked()
{
    int id=ui->lid->text().toInt();
    QString nom=ui->lnom->text();
    QString prenom=ui->lprenom->text();
    vol v(id,nom,prenom);
    bool test=v.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tablvol->setModel(v.afficher());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_suplvol_clicked()
{
  int id=ui->lsup->text().toInt();
  bool test=v.supprimer(id);
if (test)
   {
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("supression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tablvol->setModel(v.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("supression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tablvol_activated(const QModelIndex &index)
{
    QString val=ui->tablvol->model()->data(index).toString();
        QSqlQuery qry;
    qry.prepare("SELECT * FROM vol where ID='"+val+"'");
    if (qry.exec())
     {
        while(qry.next())
        {
        ui->lid->setText(qry.value(0).toString());
        ui->lnom->setText(qry.value(1).toString());
        ui->lprenom->setText(qry.value(2).toString());
        ui->lclass->setText(qry.value(3).toString());
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_lmodifier_clicked()
{

    int id=ui->lid->text().toInt();
    QString nom=ui->lnom->text();
    QString prenom=ui->lprenom->text();
    QSqlQuery qry;
    vol v(id,nom,prenom);
    bool test=v.modifier();
    if(test){
                    ui->tablvol->setModel(v.afficher());
                            QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("modification effectué.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                QObject::tr("modification non effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}
