#include "mission.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>



Mission::Mission()
{code_h=0; ide=0; num=0;type=" ";duree=" ";code_m=" ";}

Mission::Mission(QString code_m,int ide,int num,QString type,QString duree,int code_h)
{
this->code_m=code_m;
this->ide=ide;
this->num=num;
this->type=type;
this->duree=duree;
this->code_h=code_h;
}
bool Mission ::ajouter()
{
    QSqlQuery query;
    QString code_h_string=QString ::number (code_h);
    QString ide_string=QString ::number (ide);
    QString num_string=QString ::number (num);

    query.prepare("INSERT INTO MISSION(CODE_M,ID_EMP,NUMERO_PART,type_m,duree,code_h) VALUES (:id,:ide,:num,:type,:duree,:code)");
          query.bindValue(":id",code_m);
          query.bindValue(":ide", ide_string);
          query.bindValue(":num", num_string);
          query.bindValue(":type", type);
          query.bindValue(":duree",duree);
          query.bindValue(":code",code_h_string);
          return query.exec();
}
bool Mission:: supprimer(int id)
{
    QSqlQuery query;

          query.prepare("DELETE FROM MISSION WHERE CODE_M=:id");

          query.bindValue(":id",id);

           return query.exec();
}
QSqlQueryModel* Mission::afficher()
{
   QSqlQueryModel* Model=new QSqlQueryModel() ;
       Model->setQuery("SELECT*FROM MISSION");
       Model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Code mission"));
       Model->setHeaderData(1, Qt::Horizontal,QObject:: tr("code hebergement"));
       Model->setHeaderData(2, Qt::Horizontal,QObject:: tr("type mission"));
       Model->setHeaderData(3, Qt::Horizontal,QObject:: tr("id employe"));
       Model->setHeaderData(4, Qt::Horizontal,QObject:: tr("numero part"));
       Model->setHeaderData(5, Qt::Horizontal,QObject:: tr("duree"));
   return Model;
}
bool Mission::modifier (int id)
{
    QSqlQuery query;
    QString code_h_string=QString ::number (code_h);
    QString ide_string=QString ::number (ide);
    QString num_string=QString ::number (num);

    query.prepare("UPDATE MISSION SET ID_EMP=:ide,NUMERO_PART=:num,type_m=:type,duree=:duree,code_h=:code WHERE CODE_M=:id");
          query.bindValue(":id",id);
          query.bindValue(":ide", ide_string);
          query.bindValue(":num", num_string);
          query.bindValue(":type", type);
          query.bindValue(":duree",duree);
          query.bindValue(":code",code_h_string);
          return query.exec();
}
