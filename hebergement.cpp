#include "hebergement.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>

hebergement::hebergement()
{code_h=0; type_h=" "; nom_h=" ";adresse_h=" ";prix_h=0;FAX_h=0;}
hebergement::hebergement(int code_h ,QString type_h ,QString nom_h,QString adresse_h,int prix_h,int FAX_h)
{
    this->code_h=code_h;
    this->type_h=type_h;
    this->nom_h=nom_h;
    this->adresse_h=adresse_h;
    this->prix_h=prix_h;
    this->FAX_h=FAX_h;
}
//Getters
 int hebergement::getCode_H(){return code_h;}
 QString hebergement::getType(){return type_h;}
 QString hebergement::getNom(){return nom_h;}
 QString hebergement::getAdresse(){return adresse_h;}
 float hebergement::getPrix(){return prix_h;}
 int hebergement::getFAX(){return FAX_h;}

 //Setters
 void hebergement::setCode_H (int code_h){this->code_h=code_h;}
 void hebergement::setType (QString t){type_h=t;}
 void hebergement::setNom(QString n){nom_h=n;}
 void hebergement::setAdresse (QString ad){adresse_h=ad;}
 void hebergement::setPrix(int prix){this->prix_h=prix;}
 void hebergement::setFAX(int FAX){this->FAX_h=FAX;}

 bool hebergement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(code_h);
    QString res1=QString::number(prix_h);
    query.prepare("insert into hebergement (code_h,type_h,nom_h,adresse_h,prix_h,FAX_h)"
                  "values(:code_h,:type_h,:nom_h,:adresse_h,:prix_h,:FAX_h)");
    //Création des variables liées
    query.bindValue(":code_h",res);
    query.bindValue(":type_h",type_h);
    query.bindValue(":nom_h",nom_h);
    query.bindValue(":adresse_h",adresse_h);
    query.bindValue(":prix_h",res1);
    query.bindValue(":FAX_h",FAX_h);

    return query.exec();
}
 QSqlQueryModel * hebergement::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from hebergement");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Code"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("FAX"));
     return model;
 }
 bool hebergement::supprimer(int code_h)
 {
     QSqlQuery query;
     QString res=QString::number(code_h);
     query.prepare("Delete from hebergement where Code_H= :code_h");
     query.bindValue(":code_h",res);
     return query.exec();
 }
 bool hebergement ::modifier(int code_h)
 {
                        QSqlQuery query;
                        QString res=QString::number(code_h);
                        QString res1=QString::number(prix_h);

     query.prepare("UPDATE HEBERGEMENT SET type_h=:type_h,nom_h=:nom_h,adresse_h=:adresse_h,prix_h=:prix_h,FAX_h=:FAX_h WHERE code_h=:code_h ");
     query.bindValue(":code_h",res);
     query.bindValue(":type_h",type_h);
     query.bindValue(":nom_h",nom_h);
     query.bindValue(":adresse_h",adresse_h);
     query.bindValue(":prix_h",res1);
     query.bindValue(":FAX_h",FAX_h);

                      return query.exec();}
