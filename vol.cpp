#include "vol.h"
#include <QSqlQuery>
#include <QtDebug>
#include<qobject.h>
#include<QComboBox>
#include<QMessageBox>
vol::vol()
{
}
vol::vol(int id,int id_emp,QString arrive,QString classe,int day,int month,int year,int day1,int month1,int year1,QString airline,int nbr_escl)
{
    this->id=id;
    this->id_emp=id_emp;
    this->arrive=arrive;
    this->classe=classe;
    this->day=day;
    this->month=month;
    this->year=year;
    this->day1=day1;
    this->month1=month1;
    this->year1=year1;
    this->airline=airline;
    this->nbr_escl=nbr_escl;
}
int vol::getid(){return id;}
int vol::getid_emp(){return id_emp;}
QString vol::getarrive(){return arrive;}
QString vol::getclasse(){return classe;}
QString vol::getair(){return airline;}
int vol::getnbr_escl(){return nbr_escl;}
void vol::setid(int id){this->id=id;}
void vol::setid_emp(int id_emp){this->id_emp=id_emp;}
void vol::setarrive(QString arrive){this->arrive=arrive;}
void vol::setclasse(QString classe){this->classe=classe;}
void vol::setday(int day){this->day=day;}
void vol::setmonth(int month){this->month=month;}
void vol::setyear(int year){this->year=year;}
void vol::setday1(int day1){this->day1=day1;}
void vol::setmonth1(int month1){this->month1=month1;}
void vol::setyear1(int year1){this->year1=year1;}
void vol::setair(QString airline){this->airline=airline;}
void vol::setnbr_escl(int nbr_escl){this->nbr_escl=nbr_escl;}
bool vol::ajouter()
{

    QString id_string= QString::number(id);
    QString idd= QString::number(id_emp);
    QString d= QString::number(day);
    QString m= QString::number(month);
    QString y= QString::number(year);
    QString d1= QString::number(day1);
    QString m1= QString::number(month1);
    QString y1= QString::number(year1);
    QString nb=QString::number(nbr_escl);
    QSqlQuery query;
    query.prepare("INSERT INTO VOL (ID, ID_EMP, ARRIVE, classe, day, month, year, day1, month1, year1, airline, nbr_escl) "
                  "VALUES (:id, :forename, :surname, :classe, :day, :month, :year, :day1, :month1, :year1, :airline, :nbr_escl)");
    query.bindValue(0, id_string);
    query.bindValue(1, idd);
    query.bindValue(2, arrive);
    query.bindValue(3,classe);
    query.bindValue(4,d);
    query.bindValue(5,m);
    query.bindValue(6,y);
    query.bindValue(7,d1);
    query.bindValue(8,m1);
    query.bindValue(9,y1);
    query.bindValue(10, airline);
    query.bindValue(11, nb);
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
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id de vol"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_emp"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("arrive"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("day de depart"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("month de depart"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("year de depart"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("day d'arrive"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("month d'arrive"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("year d'arrive"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("airline"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("nbr_escl"));
    return model;
}

bool vol::modifier()
{
    QSqlQuery qry;
    QString res=QString::number(id);
    QString res1=QString::number(id_emp);
    QString d= QString::number(day);
    QString m= QString::number(month);
    QString y= QString::number(year);
    QString d1= QString::number(day1);
    QString m1= QString::number(month1);
    QString y1= QString::number(year1);
    QString nb=QString::number(nbr_escl);
    qry.prepare("update vol set id_emp=:id_emp, arrive=:arrive, classe=:classe,id=:id,day=:day,month=:month,year=:year,day1=:day1,month1=:month1,year1=:year1,airline=:airline,nbr_escl=:nbr_escl where id=:id");
    qry.bindValue(":id", res);
    qry.bindValue(":id_emp", id_emp);
    qry.bindValue(":arrive", arrive);
    qry.bindValue(":classe",classe);
    qry.bindValue(4,d);
    qry.bindValue(5,m);
    qry.bindValue(6,y);
    qry.bindValue(7,d1);
    qry.bindValue(8,m1);
    qry.bindValue(9,y1);
    qry.bindValue(":airline",airline);
    qry.bindValue(11,nb);
    return qry.exec();

}
QSqlQueryModel * vol::rechercher(QString id)
{

       QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("SELECT * FROM VOL where id like '"+id+"'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id de vol"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_emp"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("arrive"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("classe"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("day de depart"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("month de depart"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("year de depart"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("day d'arrive"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("month d'arrive"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("year d'arrive"));
       model->setHeaderData(10, Qt::Horizontal, QObject::tr("airline"));
       model->setHeaderData(11, Qt::Horizontal, QObject::tr("nbr_escl"));
       return model;
}

QSqlQueryModel * vol::tri_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOL order by id");
    return model;
}
QSqlQueryModel * vol::tri_id_emp()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOL order by id_emp");
    return model;
}
QSqlQueryModel * vol::tri_airline()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOL order by airline");
    return model;
}
bool vol::existance(QString id)
 {
     QMessageBox msgBox;
     QSqlQuery query;
     int count=0;
     query.prepare("SELECT * FROM vol WHERE ID= ?");
     query.addBindValue(id);
     if(query.exec() )
     {
         while (query.next())
         {
             count ++;
         }
         if(count==1)
         {
             msgBox.setText("numero deja existe");
             msgBox.exec();
             return 0;
         }

     }
     return 1;
}
