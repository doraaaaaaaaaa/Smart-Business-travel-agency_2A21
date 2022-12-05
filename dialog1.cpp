#include "dialog1.h"
#include "arduino.h"
#include"arduino1.h"
#include <QPdfWriter>
#include <QDesktopServices>
#include "partenaire.h"
#include "localisation.h"
#include "exportexcel.h"
#include "localisation.h"
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
#include"ui_dialog1.h"
#include "ui_localisation.h"
#include<QTimer>
#include<vol.h>
#include<QUrl>
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#define file_rx  ("^[A-Za-z ]+$")
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{  ui->setupUi(this)  ;

  ui->tab_chercher->setModel(M.afficher(-1));
ui->code_h-> setValidator( new QIntValidator(0, 999999, this));
ui->id_emp-> setValidator( new QIntValidator(0, 999999, this));
ui->num_part-> setValidator( new QIntValidator(0, 999999, this));
ui->dureee-> setValidator( new QIntValidator(0, 999999, this));
ui->code_m-> setValidator( new QIntValidator(0, 999999, this));
ui->id-> setValidator( new QIntValidator(0, 999999, this));
ui->type_m->setValidator(new QRegExpValidator( QRegExp(file_rx),this));

    //AZIZ

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

     //Ranim
        ui->lineEdit_code_h->setValidator( new QIntValidator(0, 999999, this));
        ui->tableViewH->setModel(H.afficher());
        QRegularExpression rx2("^[A-Za-z]+$");//controle de saisie.
          QValidator *validator2 = new QRegularExpressionValidator(rx, this);
          ui->lineEdit_nom_h->setValidator(validator2);
          ui->lineEdit_FAX_h->setValidator( new QIntValidator(0, 999999, this));
          //Arduino2(Ranim)
         /* int ret2=Ar.connect_arduino(); // lancer la connexion à arduino
                  switch(ret2){
                  case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
                      break;
                  case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
                     break;
                  case(-1):qDebug() << "arduino is not available";
                  }
                   QObject::connect(Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

        //arduino(Refrech update-Dorra)
        int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données)*/
          //yassine
          timer = new  QTimer(this);
          connect( timer , SIGNAL(timeout()),this,SLOT(myfunction()));
          timer->start(500);
      //ui->tablvol->setModel(v.afficher());
             QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8;
                  qreal tot=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0;

                  q1.prepare("SELECT * FROM vol");
                  q1.exec();

                  q2.prepare("SELECT * FROM vol WHERE airline='American Airlines'");
                  q2.exec();

                  q3.prepare("SELECT * FROM vol WHERE airline='Air France'");
                  q3.exec();

                  q4.prepare("SELECT * FROM vol WHERE airline='Fly Emirates'");
                  q4.exec();

                  q5.prepare("SELECT * FROM vol WHERE airline='Tunisair'");
                  q5.exec();

                  q6.prepare("SELECT * FROM vol WHERE airline='Lufthansa'");
                  q6.exec();

                  q7.prepare("SELECT * FROM vol WHERE airline='Turkish Airlines'");
                  q7.exec();

                  q8.prepare("SELECT * FROM vol WHERE airline='Qatar Airways'");
                  q8.exec();


                  while (q1.next()){tot++;}
                  while (q2.next()){c1++;}
                  while (q3.next()){c2++;}
                  while (q4.next()){c3++;}
                  while (q5.next()){c4++;}
                  while (q6.next()){c5++;}
                  while (q7.next()){c6++;}
                  while (q8.next()){c7++;}

                 QBarSet *set1 = new QBarSet("American Airlines");
                 QBarSet *set2 = new QBarSet("Air France");
                 QBarSet *set3 = new QBarSet("Fly Emirates");
                 QBarSet *set4 = new QBarSet("Tunisair");
                 QBarSet *set5 = new QBarSet("Lufthansa");
                 QBarSet *set6 = new QBarSet("Turkish Airlines");
                 QBarSet *set7 = new QBarSet("Qatar Airways");

                  *set1 << c1 ;
                  *set2 << c2 ;
                  *set3 << c3 ;
                  *set4 << c4 ;
                  *set5 << c5 ;
                  *set6 << c6 ;
                  *set7 << c7 ;
                 QBarSeries *series = new QBarSeries();
                 series->append(set1);
                 series->append(set2);
                 series->append(set3);
                 series->append(set4);
                 series->append(set5);
                 series->append(set6);
                 series->append(set7);
                 QChart *chart = new QChart();
                 chart->addSeries(series);
                 chart->setTitle("AirLines");
                 chart->setAnimationOptions(QChart::AllAnimations);
                 QStringList categories;
                 categories << "Categories";
                 QBarCategoryAxis *axis = new QBarCategoryAxis();
                 axis->append(categories);
                 chart->createDefaultAxes();
                 chart->setAxisX(axis, series);
                 chart->legend()->setVisible(true);
                 chart->legend()->setAlignment(Qt::AlignBottom);
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->setMinimumSize(1450,600);
                 //chartView->setParent(ui->horizontalFrame);
                 QPalette pal = qApp->palette();
                 qApp->setPalette(pal);
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
/*
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
}*/


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


//*****************************************Ranim************************************************************
void Dialog::on_Ajouter_h_clicked() //Ajout
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
          ui->tableViewH->setModel(H.afficher());
          QMessageBox::information(nullptr , QObject::tr("OK"),
                                   QObject::tr("Ajout effectué \n"
                                               "Click Cancel to exit.") , QMessageBox::Cancel );
      }

 else //si requete non executée
      QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                            QObject::tr("Ajout non effectué. \n"
                                        "Click Cancel to exit.") , QMessageBox::Cancel);

}


void Dialog::on_Modif_h_clicked() //Modif
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
                ui->tableViewH->setModel(H.afficher());
                        QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("modification effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not OK"),
                            QObject::tr("modification failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}




void Dialog::on_tableViewH_clicked(const QModelIndex &index) //Modif
{
    ui->lineEdit_code_h->setText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),0)).toString());
       // ui->lineEdit_type_h->currentText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),1)).toString());
       ui->lineEdit_nom_h->setText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),2)).toString());
         ui->lineEdit_adresse_h->setText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),3)).toString());
         ui->lineEdit_prix_h->setText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),4)).toString());
          ui->lineEdit_FAX_h->setText(ui->tableViewH->model()->data(ui->tableViewH->model()->index(index.row(),5)).toString());

}


void Dialog::on_radioButton_clicked() //Tri Code
{
    ui->tableViewH->setModel(H.triCode());
}


void Dialog::on_triNom_clicked()
{
    ui->tableViewH->setModel(H.triNom());
}


void Dialog::on_triPrix_clicked()
{
    ui->tableViewH->setModel(H.triPrix());
}



void Dialog::on_lineEdit_Rech_textChanged(const QString &arg1) //Recherche
{
    QString rech = ui->lineEdit_Rech->text();
                H.recherche(ui->tableView,rech);
                if (ui->lineEdit_Rech->text().isEmpty())
                {
                    ui->tableViewH->setModel(H.afficher());
                }
}



void Dialog::on_PDF_clicked()
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


void Dialog::on_stat_clicked()
{
    s = new statistique();
    s->setWindowTitle("Statistique des Hebergements");
    s->choix_bar2();
    s->show();
}



void Dialog::on_Send_mail_clicked()
{
    /*sm=new Mail(this);
    sm->show();*/
}

void Dialog::on_pushButton_Picture_clicked()
{
    pt=new Picture(this);
    pt->show();
}


QString ch="";
 void Dialog::update_label()
{
          QSqlQuery query;
          QByteArray data="";
          QString nom="" ,adresse="", prix="",FAX="";

         data=A.read_from_arduino();
          qDebug() <<  " data is " <<data;
          ch=ch+data;
          qDebug() <<  " ch is " <<ch;


         if(ch!="" && ch.length()==12)
            {
             if(ch==" E3 D4 80 A7")
              {
              QString code_h="123";
              query.prepare("SELECT* FROM HEBERGEMENT WHERE code_h='"+code_h+"'  ");
              qDebug() << query.exec();
              while (query.next())
              {
              nom =query.value(2).toString();
              adresse=query.value(3).toString();
              prix=query.value(4).toString();
              FAX=query.value(5).toString();

              }
              qDebug() << nom;
              qDebug() << adresse;
              qDebug() << prix;
              qDebug() << FAX;

              ui->lineEdit_nom_h->setText(nom);
              ui->lineEdit_adresse_h->setText(adresse);
              ui->lineEdit_prix_h->setText(prix);
              ui->lineEdit_FAX_h->setText(FAX);

              QString message ="Bienvenue "+ nom;
              QByteArray br = message.toUtf8();
              A.write_to_arduino(br);
              }


             else if(ch==" B3 AA 9F 92")
             {
             QString code_h="125";
             query.prepare("SELECT* FROM HEBERGEMENT WHERE code_h='"+code_h+"'  ");
             qDebug() << query.exec();
             while (query.next())
             {
             nom =query.value(2).toString();
             adresse=query.value(3).toString();
             prix=query.value(4).toString();
             FAX=query.value(5).toString();

             }
             qDebug() << nom;
             qDebug() << adresse;
             qDebug() << prix;
             qDebug() << FAX;

             ui->lineEdit_nom_h->setText(nom);
             ui->lineEdit_adresse_h->setText(adresse);
             ui->lineEdit_prix_h->setText(prix);
             ui->lineEdit_FAX_h->setText(FAX);

             QString message ="Bienvenue "+ nom;
             QByteArray br = message.toUtf8();
             A.write_to_arduino(br);
             }

             else
             {
                 QString message ="donne inaccessible";
                 QByteArray br = message.toUtf8();
                 A.write_to_arduino(br);
                 QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                         QObject::tr("FAILED TO connected ..........  \n"
                                                      "acces denied \n"

                                                     "Click Cancel to exit."),QMessageBox::Cancel);
             }

            }

         if(ch.length()==12)
          {
          ch="";
          }
}




void Dialog::on_Supprimer_H_clicked() //Supp
{
    int code_h=ui->lineEdit_code_h2->text().toInt();
    bool test=H.supprimer(code_h);
    if (test)
    {
        //Refresh
        ui->tableViewH->setModel(H.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Suppression effectueé. \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée. \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}
//*****************************************Yassine************************************************************

void Dialog::on_lajout_clicked()
{
    int id=ui->lid_2->text().toInt();
    int id_emp=ui->lidd_2->text().toInt();
    QString arrive=ui->larrive_2->text();
    QString classe=ui->lclass_2->text();
    int day=ui->lday_2->text().toInt();
    int month=ui->lmonth_2->text().toInt();
    int year=ui->lyear_2->text().toInt();
    int day1=ui->lday1_2->text().toInt();
    int month1=ui->lmonth1_2->text().toInt();
    int year1=ui->lyear1_2->text().toInt();
    QString airline=ui->comboBox_2->currentText();
    int nbr_escl=ui->lnbr_2->text().toInt();
    vol v(id,id_emp,arrive,classe,day,month,year,day1,month1,year1,airline,nbr_escl);
    if (e.getID_EMP()==v.getid_emp())
    {
    if((day<day1)&&(month<=month1)&&(year<=year1))
    {
    bool test=v.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tablvol_2->setModel(v.afficher());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject::tr("respecter la date.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("donner votre id"),
                    QObject::tr("respecter la date.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_suplvol_clicked()
{
  int id=ui->lsup_2->text().toInt();
  bool test=v.supprimer(id);
if (test)
   {
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("supression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tablvol_2->setModel(v.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("supression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_tablvol_activated(const QModelIndex &index)
{
    QString val=ui->tablvol_2->model()->data(index).toString();
        QSqlQuery qry;
    qry.prepare("SELECT * FROM vol where ID='"+val+"'");
    if (qry.exec())
     {
        while(qry.next())
        {
        ui->lid_2->setText(qry.value(0).toString());
        ui->lidd_2->setText(qry.value(1).toString());
        ui->larrive_2->setText(qry.value(2).toString());
        ui->lclass_2->setText(qry.value(3).toString());
        ui->lday_2->setValue(qry.value(4).toInt());
        ui->lmonth_2->setValue(qry.value(5).toInt());
        ui->lyear_2->setValue(qry.value(6).toInt());
        ui->lday1_2->setValue(qry.value(7).toInt());
        ui->lmonth1_2->setValue(qry.value(8).toInt());
        ui->lyear1_2->setValue(qry.value(9).toInt());
        ui->comboBox_2->setCurrentText(qry.value(10).toString());
        ui->lnbr_2->setText(qry.value(11).toString());
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_lmodifier_clicked()
{

    int id=ui->lid_2->text().toInt();
    int id_emp=ui->lidd_2->text().toInt();
    QString arrive=ui->larrive_2->text();
    QString classe=ui->lclass_2->text();
    int day=ui->lday_2->text().toInt();
    int month=ui->lmonth_2->text().toInt();
    int year=ui->lyear_2->text().toInt();
    int day1=ui->lday1_2->text().toInt();
    int month1=ui->lmonth1_2->text().toInt();
    int year1=ui->lyear1_2->text().toInt();
    QString airline=ui->comboBox_2->currentText();
    int nbr_escl=ui->lnbr_2->text().toInt();
    QSqlQuery qry;
    vol v(id,id_emp,arrive,classe,day,month,year,day1,month1,year1,airline,nbr_escl);
    bool test=v.modifier();
    if(test){
                    ui->tablvol_2->setModel(v.afficher());
                            QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("modification effectué.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                QObject::tr("modification non effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_lreset_clicked()
{
    QSqlQuery qry;
    ui->lid_2->setText(nullptr);
    ui->lidd_2->setText(nullptr);
    ui->larrive_2->setText(nullptr);
    ui->lclass_2->setText(nullptr);
    ui->lday_2->setValue(0);
    ui->lmonth_2->setValue(0);
    ui->lyear_2->setValue(1);
    ui->lday1_2->setValue(1);
    ui->lmonth1_2->setValue(0);
    ui->lyear1_2->setValue(1);
    ui->comboBox_2->setCurrentText("tunisair");
    ui->lnbr_2->setText(nullptr);
}

void Dialog::myfunction()
{

    QTime time= QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_date_time_2->setText(time_text);
}


void Dialog::on_chercher_clicked()
{
 QString id=ui->lmod_2->text();
 ui->tablvol_2->setModel(v.rechercher(id));
}

void Dialog::on_trie_clicked()
{
    if (ui->r1_2->isChecked())

     ui->tablvol_2->setModel(v.tri_id());
    else if (ui->r2_2->isChecked())
     ui->tablvol_2->setModel(v.tri_id_emp());
    else if (ui->r3_2->isChecked())
        ui->tablvol_2->setModel(v.tri_airline());
}


void Dialog::on_lexport_clicked()
{
    QPdfWriter pdf("C:/Users/liste.pdf");

     QPainter painter(&pdf);

     int i = 4000;
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial", 30));
     painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/logo.jpg"));
     painter.drawText(3000,1500,"LISTE DES VOLS");
     painter.setPen(Qt::cyan);
     painter.setFont(QFont("Arial", 50));
     painter.drawRect(3000,10,4100,1600);
     painter.drawRect(0,3000,9600,500);
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial", 9));
     painter.drawText(300,3300,"id");
     painter.drawText(2300,3300,"id_emp");
     painter.drawText(4300,3300,"arrive");
     painter.drawText(6000,3300,"classe");
     painter.drawText(8300,3300,"date_entree");
     painter.drawText(10300,3300,"emplacement");
     QSqlQuery query;
     query.prepare("select * from vol");
     query.exec();
     while (query.next())
     {
         painter.drawText(300,i,query.value(0).toString());
         painter.drawText(2300,i,query.value(1).toString());
         painter.drawText(4300,i,query.value(2).toString());
         painter.drawText(6300,i,query.value(3).toString());
         painter.drawText(8000,i,query.value(4).toString());
         painter.drawText(10000,i,query.value(5).toString());
         i = i +500;
     }

     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
     if (reponse == QMessageBox::Yes)
     {
         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/liste.pdf"));

         painter.end();
     }
     if (reponse == QMessageBox::No)
     {
         painter.end();
     }
}

void Dialog::on_lqr_clicked()
{
    QDesktopServices::openUrl(QUrl("https://qrcode.tec-it.com/fr"));
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            //image=image.scaledToWidth(ui->lbl_image_2->width(), Qt::SmoothTransformation);
              //      ui->lbl_image_2->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //ERROR HANDLING
        }
    }
}
//
//aziz
void Dialog::on_pb_ajouter_2_clicked()
{
    int code_h= ui->code_h->text().toInt();
   int id_emp= ui->id_emp->text().toInt();
   int num_part= ui->num_part->text().toInt();
   int duree= ui->dureee->text().toInt();
   int code_m= ui->code_m->text().toInt();
   QString strday = ui->date->date().toString("dd") ;
   QString strmonth = ui->date->date().toString("MM") ;
   QString stryear = ui->date->date().toString("yyyy") ;
   int jour= strday.toInt();
   int mois= strmonth.toInt();
   int anne= stryear.toInt();
   int id=ui->id->text().toInt();
   QString type=ui->type_m->text();
   Mission Mtmp(code_h,id_emp,num_part,duree,code_m,jour,mois,anne,id,type);
     bool test=Mtmp.ajouter();
     if (test)
     {
         //ui->tableView->setModel(/*M.afficher()*/);
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                 else
                     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tab_chercher->setModel(M.afficher(-1));
}


void Dialog::on_statistique_clicked()
{
  /*  QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from MISSION WHERE DUREE>100 ");
         float dispo1=model->rowCount();

         model->setQuery("select * from MISSION WHERE DUREE<100 ");
         float dispo=model->rowCount();

         float total=dispo1+dispo;
             QString a=QString("plus . " +QString::number((dispo1*100)/total,'f',2)+"%" );
             QString b=QString("moins .  "+QString::number((dispo*100)/total,'f',2)+"%" );
             QPieSeries *series = new QPieSeries();
             series->append(a,dispo1);
             series->append(b,dispo);
         if (dispo1!=0)
         {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
         if ( dispo!=0)
         {
             QPieSlice *slice1 = series->slices().at(1);
             slice1->setLabelVisible();
         }

         QChart *chart = new QChart();


         chart->addSeries(series);
        // chart->setTitle(""+ QString::number(total));
         chart->legend()->hide();


         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(1000,500);
         chartView->show();*/
}

void Dialog::on_radio_duree_clicked()
{

         ui->tab_chercher->setModel(M.afficher(0));

}

void Dialog::on_radio_mois_clicked()
{
    ui->tab_chercher->setModel(M.afficher(1));

}

void Dialog::on_radio_jour_clicked()
{
    ui->tab_chercher->setModel(M.afficher(2));

}

void Dialog::on_supprimer_mission_clicked()
{
    Mission m1;
    m1=m1.chercher(ui->supprimer_id->text().toInt());

        if(m1.get_type()!="user not found")
      {
 M.supprimer(ui->supprimer_id->text().toInt());
 QMessageBox::information(nullptr, QObject::tr("supprimer une mission"),
  QObject::tr("mission supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->supprimer_id->clear();
 ui->tab_chercher->setModel(M.afficher(-1));
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("supprimer une mission"),
                        QObject::tr("mission introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }





}

void Dialog::on_chercher_modifier_clicked()
{
    Mission m1;
    m1=m1.chercher(ui->id_modifier_2->text().toInt());

        if(m1.get_type()!="user not found")
      {


           ui->id_modifier->setText( QString::number(m1.get_id()));
           ui->id_emp_modifier->setText( QString::number(m1.get_id_emp()));
           ui->numero_part_modifier->setText( QString::number(m1.get_num_part()));
           ui->code_m_modifier->setText( QString::number(m1.get_code_m()));
           ui->type_m_modifier->setText( m1.get_type());
           ui->code_h_modifier->setText( QString::number(m1.get_code_h()));
           ui->duree_modifier->setText( QString::number(m1.get_duree()));
           ui->date_modifier->setDate(QDate(m1.get_anne(),m1.get_mois(),m1.get_jour()));
          // ui->date_modifier->setText( QString::number(m1.get_total_ttc()));

      }
        else
        {ui->duree_modifier->clear();
         ui->code_h_modifier->clear();
         ui->id_emp_modifier->clear();
               ui->numero_part_modifier->clear();
               ui->code_m_modifier->clear();
               ui->code_m->clear();

              ui->date_modifier->clear();
              ui->id_modifier->clear();
              ui->type_m_modifier->clear();
            QMessageBox::critical(nullptr, QObject::tr("chercher une mission"),
                        QObject::tr("mission introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void Dialog::on_pb_modifier_5_clicked()
{
    QString strday = ui->date_modifier->date().toString("dd") ;
    QString strmonth = ui->date_modifier->date().toString("MM") ;
    QString stryear = ui->date_modifier->date().toString("yyyy") ;
   int code_h= ui->code_h_modifier->text().toInt();
   int id_emp= ui->id_emp_modifier->text().toInt();
   int num_part= ui->numero_part_modifier->text().toInt();
   int duree= ui->duree_modifier->text().toInt();
   int code_m= ui->code_m_modifier->text().toInt();
   int jour= strday.toInt();
   int mois= strmonth.toInt();
   int anne= stryear.toInt();
   int id= ui->id_modifier->text().toInt();
   QString type= ui->type_m_modifier->text();

   Mission Mtmp(code_h,id_emp,num_part,duree,code_m,jour,mois,anne,id,type);

  Mission m1;
  bool test=m1.missionExists(id);
  qDebug() <<test;
  if(test==true)
  {int test1=m1.modifier(code_h,id_emp,num_part,duree,code_m,jour,mois,anne,id,type);
      if(test1==true){
          QMessageBox::information(nullptr, QObject::tr("modifier une mession"),
                            QObject::tr("mession modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_chercher->setModel(M.afficher(-1));
      }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                      QObject::tr("Erreur de modification!.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }

  }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
}








void Dialog::on_pb_modifier_6_clicked()
{
 M.imprimer(ui->id_modifier->text());

}

void Dialog::on_reset_ajouter_3_clicked()
{
 ui->code_h->clear();
  ui->id_emp->clear();
  ui->num_part->clear();
  ui->dureee->clear();
  ui->code_m->clear();
  ui->date->clear();
 ui->date->clear();
 ui->id->clear();
 ui->type_m->clear();
}

void Dialog::on_reset_ajouter_4_clicked()
{
ui->duree_modifier->clear();
  ui->code_h_modifier->clear();
     ui->id_emp_modifier->clear();
     ui->numero_part_modifier->clear();
     ui->code_m_modifier->clear();
     ui->code_m->clear();

    ui->date_modifier->clear();
    ui->id_modifier->clear();
    ui->type_m_modifier->clear();
}






