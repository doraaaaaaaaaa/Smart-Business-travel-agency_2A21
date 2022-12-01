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
        //arduino refrech update
        int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données)
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
QByteArray don="";
QByteArray ch="";

void MainWindow::update()
{
Partenaire p;
    don=A.read_from_arduino();

    qDebug() <<"ddddd"<<ch<<*don;

    if(*don=='1')
        ch=ch+'1';
    else if(*don=='2')
        ch=ch+'2';
    else if(*don=='3')
        ch=ch+'3';
    else if(*don=='4')
        ch=ch+'4';
    else if(*don=='5')
        ch=ch+'5';
    else if(*don=='6')
        ch=ch+'6';
    else if(*don=='7')
        ch=ch+'7';
    else if(*don=='8')
        ch=ch+'8';
    else if(*don=='9')
        ch=ch+'9';
    else if(*don=='0')
        ch=ch+'0';



    if(*don=='*')
    {

        QSqlQuery query;
        QString test=QString(ch);

    if(!p.existance(test))
    {
        qDebug() <<"testing"<<test;
        QString nom,prenom;
        query.prepare("select * from PARTENAIRE where numero_p='"+test+"' ");
        if(query.exec())
        {
            while(query.next())
            {
                 nom=(query.value(1).toString());
                 prenom=(query.value(2).toString());
            }
        query.exec();
        QString tt=nom+"  "+prenom;
        QByteArray z=tt.toUtf8();//qstring to qbtearray
        A.write_to_arduino(z);
    }}
    else
        {
    A.write_to_arduino("WRONG\n");
        }


        ch="";

}
}

