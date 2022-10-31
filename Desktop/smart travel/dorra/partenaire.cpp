#include "partenaire.h"
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>

Partenaire::Partenaire()
{    this->numero=0;
     this->contact=0;
     this->adresse="";
     this->domaine="";}
 Partenaire::Partenaire(int n ,int c,QString d,QString a)
 {this->numero=n;
 this->contact=c;
 this->adresse=a;
 this->domaine=d;
 }
 bool Partenaire::ajouter()
 {

     QSqlQuery query;
     QString numero_string=QString::number(numero);
     QString contact_string=QString::number(contact);
     query.prepare("INSERT INTO PARTENAIRE (numero,domaine,adresse,contact) ""VALUES (:NUMERO_P, :DOMAINE, :ADRESSE, :CONTACT)");
     query.bindValue(":NUMERO_P",numero_string);
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
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("DOMAINE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
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

