#include "partenaire.h"
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QPainter>
#include<QString>
#include <QMessageBox>
#include <QMainWindow>
#include <QIntValidator>
#include <QApplication>
#include <QTextEdit>
#include <QFileDialog>
#include <QApplication>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>


Partenaire::Partenaire()//constructeur par defaut
{    this->numero=0;
     this->contact=0;
     this->adresse="";
     this->domaine="";
     this->nom_p="";
     this->prenom_p="";
}
 Partenaire::Partenaire(int n ,QString np,QString pr,int c,QString d,QString a)//constructeur de copie
 {this->numero=n;
  this->nom_p=np;
  this->prenom_p=pr;
 this->contact=c;
 this->adresse=a;
 this->domaine=d;

 }
 bool Partenaire::ajouter()
 {

     QSqlQuery query;
     QString numero_string=QString::number(numero);
     QString contact_string=QString::number(contact);
     query.prepare("INSERT INTO PARTENAIRE (NUMERO_P,domaine,adresse,contact,nom_p,prenom_p) ""VALUES (:NUMERO_P, :DOMAINE, :ADRESSE, :CONTACT,:NOM_P,:PRENOM_P)");
     query.bindValue(":NUMERO_P",numero_string);
     query.bindValue(":NOM_P", nom_p);
     query.bindValue(":PRENOM_P", prenom_p);
     query.bindValue(":CONTACT",contact_string);
     query.bindValue(":DOMAINE", domaine);
     query.bindValue(":ADRESSE", adresse);


         return  query.exec();
 }



 QSqlQueryModel * Partenaire::afficher()
  {
      QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("SELECT * FROM PARTENAIRE ");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO_P"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_P"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRENOM_P"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONTACT"));

      return model;
  }
 bool Partenaire:: supprimer(int numero)
 {
     QSqlQuery query;
      QString res=QString::number(numero);
     query.prepare("delete from partenaire where NUMERO_P= :NUMERO_P");
     query.bindValue(":NUMERO_P",res);
       return  query.exec();
 }

 bool Partenaire::modifier(int numero)
 {
     QSqlQuery query;
     QString mod= QString::number(numero);
             query.prepare("UPDATE PARTENAIRE SET domaine=:domaine, adresse=:adresse, contact=:contact WHERE NUMERO_P=:NUMERO_P");
             query.bindValue(":NUMERO_P", mod);
             query.bindValue(":adresse", adresse);
             query.bindValue(":domaine",domaine);
             query.bindValue(":contact", contact);

     return query.exec();
 }
 QSqlQueryModel * Partenaire::recherche(QString numero)/*cherche un producteur de meme numero*/
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM PARTENAIRE WHERE NUMERO_P LIKE '"+numero+"'  ");

     return model;
 }
 QSqlQueryModel * Partenaire::trier(int test)
 {
     QSqlQueryModel *model=new QSqlQueryModel() ;
     QSqlQuery query ;
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO_P"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_P"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRENOM_P"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONTACT"));
     if(test==1)
     {
         query.prepare("SELECT *  FROM PARTENAIRE ORDER BY NUMERO_P ASC ") ;
     }
     else if(test==2)
     {
         query.prepare("SELECT *  FROM PARTENAIRE ORDER BY NOM_P ASC ") ;
     }
     else if(test==3)
     {
         query.prepare("SELECT *  FROM PARTENAIRE ORDER BY CONTACT ASC ") ;
     }

     if (query.exec()&&query.next())
     {
         model->setQuery(query) ;
     }
     return model;

 }
 void Partenaire::pdf()
 {
     QPrinter printer;
     printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setOutputFileName("C:/Users/WIKI/Downloads/new_document.pdf");
     QPainter painter;
                painter.begin(&printer);
              painter.drawText(30, 80, "partenaire ");
               painter.drawText(10, 100, "test ");
               QString str="yess pdf";
               painter.drawText(10,120,str);
               painter.end();

               QString filename="D:/Downloads/new_document.pdf";
               qDebug()<<"Print file name is "<<filename;
               if(!filename.isEmpty())
               {


                  QPrinter printer;
                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setOutputFileName(filename);

                   QPrintDialog dialog;
                   dialog.setWindowTitle("print document");
                   dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
                   dialog.exec();
               }
               else
                   qDebug()<<"ereur";

 }
