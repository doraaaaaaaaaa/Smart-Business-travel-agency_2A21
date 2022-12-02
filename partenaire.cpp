#include "partenaire.h"
#include "arduino.h"
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
#include <QPrinter>
#include <QPrintDialog>
#include <QPagedPaintDevice>



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
            query.prepare("UPDATE PARTENAIRE SET domaine=:domaine, adresse=:adresse, contact=:contact, nom_p=:nom_p, prenom_p=:prenom_p WHERE NUMERO_P=:NUMERO_P");
             query.bindValue(":NUMERO_P", mod);
              query.bindValue(":domaine",domaine);
             query.bindValue(":adresse", adresse);
             query.bindValue(":contact", contact);
             query.bindValue(":nom_p",nom_p);
            query.bindValue(":prenom_p",prenom_p);

     return query.exec();
 }
 QSqlQueryModel * Partenaire::recherche(QString numero)/*cherche un partenaire de meme numero*/
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

 void  Partenaire::telechargerPDF(){


                      QPdfWriter pdf("C:/Users/WIKI/Desktop/2EME/pdf partenaire/part0.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);//titre
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"LISTES DES PARTENAIRES");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial",14));
                         // painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"NOM");
                          painter.drawText(1300,3300,"PRENOM");
                          painter.drawText(2700,3300,"ADRESSE");
                          painter.drawText(4000,3300,"CONTACT");
                          painter.drawText(6500,3300,"NUMERO");
                          painter.drawText(7700,3300,"DOMAINE");


                          QSqlQuery query;

                          query.prepare("select * from partenaire");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(1).toString());
                              painter.drawText(1300,i,query.value(0).toString());
                              painter.drawText(2700,i,query.value(2).toString());
                              painter.drawText(4000,i,query.value(3).toString());
                              painter.drawText(6500,i,query.value(4).toString());
                              painter.drawText(7700,i,query.value(5).toString());



                             i = i + 500;
                          }}



 bool Partenaire::existance(QString id)
 {
     QMessageBox msgBox;
     QSqlQuery query;
     int count=0;
     query.prepare("SELECT * FROM PARTENAIRE WHERE numero_p= ?");
     query.addBindValue(id);
     if(query.exec() )
     {
         while (query.next())
         {
             count ++;
         }
         if(count==1)
         {
             //msgBox.setText("numero deja existe");
             //msgBox.exec();
             return 0;
         }

     }
     return 1;
 }

