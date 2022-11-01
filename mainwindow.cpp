#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mission.h"
#include<QIntValidator>
#include<QObject>
#include<QMainWindow>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->line_codem-> setValidator( new QIntValidator(0, 999999, this));
    ui->tableView->setModel(M.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajoute_clicked()
{
    QString code=ui->line_codem->text();
    int ide=ui->ide->text().toInt();
    int num=ui->num->text().toInt();
    QString duree=ui->duree->text();
    QString type = ui->line_type->text();
    int id=ui->line_codeh->text().toInt();

    Mission Mtmp(code,ide,num,type,duree,id);
     bool test=Mtmp.ajouter();
     if (test)
     {
         ui->tableView->setModel(M.afficher());
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                 else
                     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_supprime_clicked()
{
    int id=ui->lineEdit_supp->text().toInt();
    bool test=M.supprimer(id);
    if (test)
    {
        ui->tableView->setModel(M.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_2_clicked()
{
    QString code=ui->line_codem->text();
    int id_modif=ui->line_codem->text().toInt();
    int ide=ui->ide->text().toInt();
    int num=ui->num->text().toInt();
    QString duree=ui->duree->text();
    QString type = ui->line_type->text();
    int id=ui->line_codeh->text().toInt();

    Mission Mtmp(code,ide,num,type,duree,id);
     bool test=Mtmp.modifier(id_modif);
     if (test)
     {
         ui->tableView->setModel(M.afficher());
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("modification effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                 else
                     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                 QObject::tr("modification failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}
