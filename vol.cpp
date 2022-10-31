#include "vol.h"
#include <QSqlQuery>
#include <QtDebug>
#include<qobject.h>
vol::vol()
{
id=0;nom=" ";prenom=" ";
}
vol::vol(int id,QString nom,QString prenom)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
}
int vol::getid(){return id;}
QString vol::getnom(){return nom;}
QString vol::getprenom(){return prenom;}
void vol::setid(int id){this->id=id;}
void vol::setnom(QString nom){this->nom=nom;}
void vol::setprenom(QString prenom){this->prenom=prenom;}
bool vol::ajouter()
{

    QString id_string= QString::number(id);
    QSqlQuery query;
    query.prepare("INSERT INTO VOL (ID, NOM, PRENOM) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
    return query.exec();
}

bool vol::supprimer(int id)
{
QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("delete from vol where ID= :id");
   query.bindValue(":id",res);
   return query.exec();
}
QSqlQueryModel * vol::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM vol");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}
bool vol::modifier()
{

    QSqlQuery qry;
    QString res=QString::number(id);
    qry.prepare("update vol set nom=:nom, prenom=:prenom, id=:id where id=:id");
         qry.bindValue(":id",res);
         qry.bindValue(":nom",nom);
         qry.bindValue(":prenom",prenom);
        return qry.exec();

}
