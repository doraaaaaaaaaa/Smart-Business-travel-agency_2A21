#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"hebergement.h"
#include "smtp.h"
#include"ui_smtp.h"
#include"picture.h"
#include<QIntValidator>
#include<QObject>
#include<QMainWindow>
#include<QSqlQuery>
#include <QDesktopServices>
#include<QPrinter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include<QPainter>
#include<QApplication>
#include <QUrl>
#include<QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_code_h->setValidator( new QIntValidator(0, 999999, this));
    ui->tableView->setModel(H.afficher());
    QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.
      QValidator *validator = new QRegularExpressionValidator(rx, this);
      ui->lineEdit_nom_h->setValidator(validator);
      ui->lineEdit_FAX_h->setValidator( new QIntValidator(0, 999999, this));





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()   //Ajout
{
    //Récupération des informations saisies dans les 6 champs
    int code_h=ui->lineEdit_code_h->text().toInt();
    QString type_h=ui->lineEdit_type_h->currentText();
    QString nom_h=ui->lineEdit_nom_h->text();
    QString adresse_h=ui->lineEdit_adresse_h->text();
    int prix_h=ui->lineEdit_prix_h->text().toInt();
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


void MainWindow::on_pushButton_5_clicked() //Supprimer
{
    int code_h=ui->lineEdit_code_h2->text().toInt();
    bool test=H.supprimer(code_h);
    if (test)
    {
        //Refresh
        ui->tableView->setModel(H.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Suppression effectueé. \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée. \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_2_clicked() //Modif
{
    int code_h=ui->lineEdit_code_h->text().toInt();
        QString type_h=ui->lineEdit_type_h->currentText();
        QString nom_h=ui->lineEdit_nom_h->text();
        QString adresse_h=ui->lineEdit_adresse_h->text();
       int prix_h=ui->lineEdit_prix_h->text().toInt();
       int FAX_h=ui->lineEdit_FAX_h->text().toInt();
       hebergement H(code_h,type_h,nom_h,adresse_h,prix_h,FAX_h);
        bool test=H.modifier(code_h);

            if(test){
                ui->tableView->setModel(H.afficher());
                        QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("modification effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not OK"),
                            QObject::tr("modification failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index) //Modif
{
    ui->lineEdit_code_h->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
       // ui->lineEdit_type_h->currentText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
       ui->lineEdit_nom_h->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
         ui->lineEdit_adresse_h->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
         ui->lineEdit_prix_h->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
          ui->lineEdit_FAX_h->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),5)).toString());

}


void MainWindow::on_radioButton_clicked() //Tri Code
{
    ui->tableView->setModel(H.triCode());
}


void MainWindow::on_triNom_clicked()
{
    ui->tableView->setModel(H.triNom());
}


void MainWindow::on_triPrix_clicked()
{
    ui->tableView->setModel(H.triPrix());
}



void MainWindow::on_lineEdit_Rech_textChanged(const QString &arg1) //Recherche
{
    QString rech = ui->lineEdit_Rech->text();
                H.recherche(ui->tableView,rech);
                if (ui->lineEdit_Rech->text().isEmpty())
                {
                    ui->tableView->setModel(H.afficher());
                }
}



void MainWindow::on_PDF_clicked()
{

    QString ach=ui->lineEdit_code_h->text()+".pdf";
               QPdfWriter pdf("C:/Users/user/Documents/untitled/PDF/pdf.pdf"+ach);

                                 QPainter painter(&pdf);
                                int i = 4000;
                                     painter.setPen(Qt::red);
                                     painter.setFont(QFont("Impact", 30));
                                     painter.drawText(2200,1400,"Liste des hebergements "+ui->lineEdit_code_h->text());
                                     painter.setPen(Qt::black);
                                     painter.setFont(QFont("impact", 50));
                                     painter.drawRect(0,3000,9600,500);
                                     painter.setFont(QFont("impact", 11));
                                     painter.drawText(200,3300,"CODE_H");
                                     painter.drawText(1200,3300,"TYPE_H");
                                     painter.drawText(2400,3300,"NOM_H");
                                     painter.drawText(4000,3300,"ADRESSE_H");
                                     painter.drawText(5600,3300,"PRIX_H");
                                     painter.drawText(6900,3300,"FAX_H");


                                     QSqlQuery query;
                                     query.prepare("select * from HEBERGEMENT");
                                     query.exec();
                                     painter.setFont(QFont("Arial",9));
                                     while (query.next())
                                     {
                                         painter.drawText(200,i,query.value(0).toString());
                                         painter.drawText(1200,i,query.value(1).toString());
                                         painter.drawText(2400,i,query.value(2).toString());
                                         painter.drawText(4000,i,query.value(3).toString());
                                         painter.drawText(6000,i,query.value(4).toString());
                                         painter.drawText(7000,i,query.value(5).toString());
                                         painter.drawText(8400,i,query.value(6).toString());



                                        i = i + 500;
                                     }
                                     int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {
                                             QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Documents/untitled/PDF/pdf.pdf"+ach));

                                             painter.end();
                                         }
                                         if (reponse == QMessageBox::No)
                                         {
                                              painter.end();
                                         }



}


void MainWindow::on_stat_clicked()
{
    s = new statistique();
    s->setWindowTitle("Statistique des Hebergements");
    s->choix_bar();
    s->show();
}



void MainWindow::on_Send_mail_clicked()
{
    sm=new Mail(this);
    sm->show();
}

void MainWindow::on_pushButton_Picture_clicked()
{
    p=new Picture(this);
    p->show();
}

