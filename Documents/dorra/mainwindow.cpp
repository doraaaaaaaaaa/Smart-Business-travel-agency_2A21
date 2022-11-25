#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"
#include "localisation.h"
#include "exportexcel.h"
#include "localisation.h"
#include "ui_localisation.h"
#include <QFileDialog>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QMainWindow>


#include "QMessageBox"

#include <QtCharts/QChartView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->afficher->setModel(p.afficher());
//controle de saisie.
ui->num_ajout->setValidator (new QIntValidator(0, 99999, this));
ui->contact_ajout->setValidator (new QIntValidator(0, 99999999, this));


    QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.

        QValidator *validator = new QRegularExpressionValidator(rx, this);
        ui->domaine_ajout->setValidator(validator);
        ui->adresse_ajout->setValidator(validator);
        ui->nom_ajout->setValidator(validator);
        ui->pr_ajout_->setValidator(validator);
        }

MainWindow::~MainWindow()
{
    delete ui;

}

//ajout
void MainWindow::on_pushButton_clicked()
{
    int numero_p=ui->num_ajout->text().toInt();
    int contact=ui->contact_ajout->text().toInt();
     QString nom_p=ui->nom_ajout->text();
     QString prenom_p=ui->pr_ajout_->text();
     QString domaine=ui->domaine_ajout->text();
     QString adresse=ui->adresse_ajout->text();
            Partenaire p(numero_p,nom_p,prenom_p,contact,adresse,domaine);
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

    int  numero_p=ui->num_ajout->text().toInt();
    QString nom_p=ui->nom_ajout->text();
    QString prenom_p=ui->pr_ajout->text();
    int contact=ui->contact_ajout->text().toInt();
    QString adresse=ui->adresse_ajout->text();
        QString domaine=ui->domaine_ajout->text();


         Partenaire p(numero_p,nom_p,prenom_p,contact,adresse,domaine);
        bool test=p.modifier(numero_p);


        if(test )
        {

            ui->afficher->setModel(p.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectué \n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else

            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                  QObject::tr("modification non effectué \n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
       }



void MainWindow::on_afficher_activated(const QModelIndex &index)
{
    QString val=ui->afficher->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from PARTENAIRE where NUMERO_P='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->num_ajout->setText(qry.value(0).toString());
            ui->nom_ajout->setText(qry.value(5).toString());
            ui->pr_ajout_->setText(qry.value(4).toString());
            ui->domaine_ajout->setText(qry.value(2).toString());
            ui->adresse_ajout->setText(qry.value(1).toString());
            ui->contact_ajout->setText(qry.value(3).toString());
             }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctué"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_recherche_button_clicked()
{

    int numero=ui->recherche0->text().toInt();
    QString cin= QString::number(numero);
        ui->recherche_2->setModel(p.recherche(cin));


}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
     if(arg1=="Numero")
          ui->recherche_2->setModel(p.trier(1));
      else  if(arg1=="nom")
          ui->recherche_2->setModel(p.trier(2));
      else  if(arg1=="contact")
          ui->recherche_2->setModel(p.trier(3));

}





void MainWindow::on_pushButton_6_clicked()
{

    p.telechargerPDF();

            QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);


    }






void MainWindow::on_pushButton_2_clicked()
{
    l = new localisation();
    l->setWindowTitle("Map");
    //l->map();
    l->show();
}


void MainWindow::on_pushButton_3_clicked()
{
  s = new stat_combo();
  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "data", ui->afficher);

            //colums to export
            obj.addField(0, "numero", "char(20)");
            obj.addField(1, "adresse", "char(20)");
            obj.addField(2, "domaine", "char(20)");
            obj.addField(3, "contact", "char(20)");



            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"), QString(tr("%1 records exported!")).arg(retVal));
            }
}
