#include "dialog1.h"
#include "ui_dialog1.h"
#include <QPdfWriter>
#include <QDesktopServices>


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


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //AZIZ
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());

    ui->le_mdp->setValidator(new QIntValidator(0,999999,this));
    ui->le_IDemploye->setValidator(new QIntValidator(0,999999,this));

    QRegularExpression rw("^[A-Z a-z]+$");
    QValidator *validator = new  QRegularExpressionValidator(rw,this);

    ui->le_nom->setValidator(validator);
    ui->le_nom->setMaxLength(12);
    ui->le_prenom->setValidator(validator);
    ui->le_prenom->setMaxLength(12);

    //Dorra
    ui->afficher_p->setModel(p.afficher());
    //controle de saisie.
    ui->num_ajout->setValidator (new QIntValidator(0, 99999, this));
    ui->contact_ajout->setValidator (new QIntValidator(0, 99999999, this));


    QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.

        QValidator *validator1 = new QRegularExpressionValidator(rx, this);
        ui->domaine_ajout->setValidator(validator1);
        ui->adresse_ajout->setValidator(validator1);
        ui->nom_ajout->setValidator(validator1);
        ui->pr_ajout_->setValidator(validator1);
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



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString d=ui->dateEdit->text();
    QString Genre=ui->Genre_select->currentText();
    int ID_emp=ui->le_IDemploye->text().toInt();
    int MDPS=ui->le_mdp->text().toInt();
    Employe e(ID_emp,MDPS,NOM,PRENOM,d,Genre);
    bool test=e.ajouter();
    if(test)
    {    ui->tableView->setModel(e.afficher());

        QMessageBox::information(nullptr,QObject::tr("add completed"),
                                       QObject::tr("add completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                                       QObject::tr("add not completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
}

void Dialog::on_pb_supp_clicked()
{
    Employe e;
         bool test1;
         int ID=ui->le_IDemploye->text().toInt();

         test1 =e.supprimer(ID);
         if(test1)
         {    ui->tableView->setModel(e.afficher());

             ui->tableView->setModel(e.afficher());

             QMessageBox::information(nullptr, QObject::tr("SUPP effuctué"),
                                      QObject::tr("connection successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("supp n'est pas effuctué"),
                                   QObject::tr("connection failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supp_2_clicked()
{

}

void Dialog::on_pb_modifier_clicked()
{
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString d=ui->dateEdit->text();
     QString Genre=ui->Genre_select->currentText();
    int ID_emp=ui->le_IDemploye->text().toInt();
    int MDPS=ui->le_mdp->text().toInt();
    Employe e(ID_emp,MDPS,NOM,PRENOM,d,Genre);
    bool test=e.modifier();
    if(test)
    {
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("add completed"),
                                       QObject::tr("add completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                                       QObject::tr("add not completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
}

void Dialog::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from EMPLOYEE where ID_EMP='"+val+"'");
       if(qry.exec())
       {
           while(qry.next())
           {
               ui->le_IDemploye->setText(qry.value(0).toString());
               ui->Genre_select->setCurrentText(qry.value(5).toString());
               ui->le_nom->setText(qry.value(2).toString());
               ui->le_prenom->setText(qry.value(3).toString());
               ui->dateEdit->setDate(qry.value(4).toDate());
               ui->le_mdp->setText(qry.value(1).toString());

           }
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctué"),
                                 QObject::tr("connection failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void Dialog::on_pb_recher_clicked()
{
    int id=ui->lineEdit->text().toInt();
      QString cin= QString::number(id);
      if(id!=0)
          ui->tableView->setModel(e.recherche(cin));
      else
          ui->tableView->setModel(e.afficher());

}

void Dialog::on_comboBox_2_activated(const QString &arg1)
{
    if(arg1=="date d'ajout")
        ui->tableView->setModel(e.afficher());
    else  if(arg1=="id")
        ui->tableView->setModel(e.trier(3));
    else  if(arg1=="nom")
        ui->tableView->setModel(e.trier(2));
    else  if(arg1=="date de naissance")
        ui->tableView->setModel(e.trier(1));
}

void Dialog::on_Afficher_stat_clicked()
{
    s = new statistique();

        s->setWindowTitle("statistique des employés");
        s->choix_bar();
        s->show();
}

void Dialog::on_pb_pdf_clicked()
{
    QString ach=".pdf";
            QPdfWriter pdf("C:/Users/Aziz Chlif/Desktop/validation"+ach);


                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Impact", 30));
                                  painter.drawText(2200,1400,"Liste des employés ");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("impact", 50));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("impact", 11));
                                  painter.drawText(200,3300,"ID_Emp");
                                  painter.drawText(1200,3300,"Nom");
                                  painter.drawText(2400,3300,"Prenom");
                                  painter.drawText(4400,3300,"date");
                                  painter.drawText(5900,3300,"Genre");
                                  painter.drawText(6900,3300,"MDP");




                                  QSqlQuery query;
                                  query.prepare("select * from EMPLOYEE");
                                  query.exec();
                                  painter.setFont(QFont("Arial",9));
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1200,i,query.value(2).toString());
                                      painter.drawText(2400,i,query.value(3).toString());
                                      painter.drawText(4000,i,query.value(4).toString());
                                      painter.drawText(6000,i,query.value(5).toString());
                                      painter.drawText(7000,i,query.value(1).toString());



                                     i = i + 500;
                                  }
                                  painter.drawRect(0,3000,9600,i-3000);
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Aziz Chlif/Desktop/validation"+ach));

                                          painter.end();
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }

}


//*******************************dorra*********************************************
void Dialog::on_pushButton_clicked()
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
            {ui->afficher_p->setModel(p.afficher());
                QMessageBox::information(nullptr, QObject::tr("ajout effuctué"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("ajout n'est pas effuctué"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_supp_button_clicked()
{
    int numero =ui->num_supp->text().toInt();
    bool test=p.supprimer(numero);

    QMessageBox msgBox;
    if(test)
         {//REFRESH
            ui->afficher_p->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppressiont non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}





void Dialog::on_bouton_modif_clicked()
{

    int  numero_p=ui->num_ajout->text().toInt();
    QString nom_p=ui->nom_ajout->text();
    QString prenom_p=ui->pr_ajout_->text();
    int contact=ui->contact_ajout->text().toInt();
    QString adresse=ui->adresse_ajout->text();
        QString domaine=ui->domaine_ajout->text();


         Partenaire p(numero_p,nom_p,prenom_p,contact,adresse,domaine);
        bool test=p.modifier(numero_p);


        if(test )
        {

            ui->afficher_p->setModel(p.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectué \n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else

            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                  QObject::tr("modification non effectué \n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
       }





void Dialog::on_recherche_button_clicked()
{

    int numero=ui->recherche0->text().toInt();
    QString cin= QString::number(numero);
        ui->afficher_p->setModel(p.recherche(cin));


}






void Dialog::on_pushButton_6_clicked()
{

    p.telechargerPDF();

            QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);


    }






void Dialog::on_pushButton_2_clicked()
{
    l = new localisation();
    l->setWindowTitle("Map");
    //l->map();
    l->show();
}


void Dialog::on_pushButton_3_clicked()
{
  s = new statistique();
  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}


void Dialog::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "data", ui->afficher_p);

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

void Dialog::update()
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


void Dialog::on_tri_button_clicked()
{QString arg1=ui->comboBox_3->currentText();

    if(arg1=="Numero")
         ui->afficher_p->setModel(p.trier(1));
     else  if(arg1=="Nom_p")
         ui->afficher_p->setModel(p.trier(2));
     else  if(arg1=="contact")
         ui->afficher_p->setModel(p.trier(3));
}

void Dialog::on_afficher_p_clicked(const QModelIndex &index)
{
    QString val=ui->afficher_p->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from PARTENAIRE where NUMERO_P='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->num_ajout->setText(qry.value(0).toString());
            ui->nom_ajout->setText(qry.value(4).toString());
            ui->pr_ajout_->setText(qry.value(5).toString());
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
