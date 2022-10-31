#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"hebergement.h"
#include<QIntValidator>
#include<QObject>
#include<QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 999999, this));
    ui->tableView_2->setModel(H.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    //Récupération des informations saisies dans les 3 champs
    int code_h=ui->lineEdit_code_h->text().toInt();
    QString type_h=ui->lineEdit_type_h->text();
    QString nom_h=ui->lineEdit_nom_h->text();
    QString adresse_h=ui->lineEdit_adresse_h->text();
    float prix_h=ui->lineEdit_prix_h->text().toInt();
    int FAX_h=ui->lineEdit_FAX_h->text().toInt();

    hebergement H(code_h,type_h,nom_h,adresse_h,prix_h,FAX_h);
     bool test =H.ajouter();
      if (test) //si requete executée
      {
          //Refresh
          ui->tableView->setModel(H.afficher());
          QMessageBox::information(nullptr , QObject::tr("OK"),
                                   QObject::tr("Ajout effectué \n"
                                               "Click Cancel to exit.") , QMessageBox::Cancel );
      }

 else //si requete non executée
      QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                            QObject::tr("Ajout non effectué. \n"
                                        "Click Cancel to exit.") , QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int code_h=ui->lineEdit_code_h->text().toInt();
    bool test=H.supprimer(code_h);
    if (test)
    {
        //Refresh
        ui->tableView->setModel(H.afficher());
     QMessageBox::inforamtion(nullptr, QObject::tr("OK"),
                              QObject::tr("Suppression effectueé. \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée. \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);

}

