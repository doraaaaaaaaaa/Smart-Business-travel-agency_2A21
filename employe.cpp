#include "employe.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>

#include <QMessageBox>
Employe::Employe()
{
ID_EMP=0; MDPS=0; NOM=""; PRENOM=""; DATE_N="",Genre="";
}

Employe::Employe(int ID_EMP,int MDPS,QString NOM,QString PRENOM,QString DATE_N,QString Genre)
{this->ID_EMP=ID_EMP; this->MDPS=MDPS; this-> NOM=NOM; this->PRENOM=PRENOM; this->DATE_N=DATE_N; this->Genre=Genre;}
int Employe:: getID_EMP(){return ID_EMP;};
int Employe:: getMDPS(){return MDPS;};
QString Employe:: getNOM(){return NOM;};
QString Employe:: getPRENOM(){return PRENOM;};
QString Employe:: getDATE_N(){return DATE_N;};
QString Employe:: getGenre(){return Genre;};
void Employe:: setID_EMP(int ED_EMP){this->ID_EMP=ED_EMP;};
void Employe:: setMDPS(int MDPS){this->MDPS=MDPS;};
void Employe:: setNOM(QString NOM){this->NOM=NOM;};
void Employe:: setPRENOM(QString PRENOM){this->PRENOM=PRENOM;};
void Employe:: setDATE_N(QString DATE_N){this->DATE_N=DATE_N;};
void Employe:: setGenre(QString Genre){this->Genre=Genre;};

bool Employe::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(ID_EMP);
    QString mdps_string=QString::number(MDPS);
         query.prepare("INSERT INTO Employee (ID_EMP,MDPS, NOM,PRENOM,DATE_N,Genre) "
                       "VALUES (:ID_EMP, :MDPS,:NOM, :PRENOM, :DATE_N, :Genre)");
         query.bindValue(":ID_EMP",id_string);
         query.bindValue(":MDPS", mdps_string);
         query.bindValue(":NOM", NOM);
         query.bindValue(":PRENOM", PRENOM);
         query.bindValue(":DATE_N", DATE_N);
         query.bindValue(":Genre", Genre);


        return  query.exec();
}
 QSqlQueryModel * Employe::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM Employee");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMP"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("MDPS"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_N"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Genre"));

     return model;
 }
  bool Employe:: supprimer(int id)
  {
      QSqlQuery query;
           query.prepare("delete from Employee where ID_EMP=:ID_EMP");
    query.bindValue(":ID_EMP",id);
        return  query.exec();
  }
bool Employe:: modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EMP);
    QString telephone_string=QString::number(MDPS);
            query.prepare("UPDATE Employee SET  MDPS=:MDPS, NOM=:NOM, PRENOM=:PRENOM, DATE_N=:DATE_N, Genre=:Genre WHERE ID_EMP=:ID_EMP");
            query.bindValue(":ID_EMP",id_string);
            query.bindValue(":MDPS", telephone_string);
            query.bindValue(":NOM", NOM);
            query.bindValue(":PRENOM", PRENOM);
             query.bindValue(":DATE_N",DATE_N);
             query.bindValue(":Genre",Genre);


    return query.exec();
}
QSqlQueryModel * Employe::recherche(QString id)/*cherche un producteur de meme id*/
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM Employee WHERE ID_EMP LIKE '"+id+"'  ");

    return model;
}
QSqlQueryModel * Employe::trier(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;

    if(test==1)
    {
        query.prepare("SELECT *  FROM Employee ORDER BY DATE_N ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM Employee ORDER BY NOM ASC ") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM Employee ORDER BY ID_EMP ASC ") ;
    }

    if (query.exec()&&query.next())
    {
        model->setQuery(query) ;
    }
    return model;

}
