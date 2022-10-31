#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QMainWindow>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//ouverture fenetre de l'interface
ui->afficher->setModel(p.afficher());
ui->num_ajout->setValidator (new QIntValidator(0, 99999, this));
}

MainWindow::~MainWindow()
{
    delete ui;

}

//ajout
void MainWindow::on_pushButton_clicked()
{
    int numero=ui->num_ajout->text().toInt();
    int contact=ui->contact_ajout->text().toInt();

           QString domaine=ui->domaine_ajout->text();
            QString adresse=ui->adresse_ajout->text();
            Partenaire p(numero,contact,adresse,domaine);
            bool test=p.ajouter();
            if(test)
            {ui->afficher->setModel(p.afficher());
                QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supp_button_clicked()
{
    int numero =ui->num_supp->text().toInt();
    bool test=p.supprimer(numero);

    QMessageBox msgBox;
    if(test)
         {//REFRESH
            ui->afficher->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppressiont non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_bouton_modif_clicked()
{

    int  numero_mod=ui->num_ajout->text().toInt();
    QString domaine=ui->domaine_ajout->text();
    QString adresse=ui->adresse_ajout->text();
    int contact=ui->contact_ajout->text().toInt();
    Partenaire p(numero_mod,contact,adresse,domaine);
    bool test=p.modifier(numero_mod);
    if(test)
     {
        ui->afficher->setModel(p.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modification effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("modification non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
