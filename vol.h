#ifndef VOL_H
#define VOL_H
#include <qstring.h>
#include<QSqlQuery>
#include<QSqlQueryModel>
class vol
{
private:
    int id,id_emp;
    QString depart,arrive,classe,airline;
    int day,month,year,day1,month1,year1,nbr_escl;
public:
    vol();
    vol(int,int,QString,QString,int,int,int,int,int,int,QString,int);
    int getid();
    int getid_emp();
    QString getdepart();
    QString getarrive();
    QString getclasse();
    int getday();
    int getmonth();
    int getyear();
    int getday1();
    int getmonth1();
    int getyear1();
    int getnbr_escl();
    QString getair();
    void setid(int);
    void setid_emp(int);
    void setdepart(QString);
    void setarrive(QString);
    void setclasse(QString);
    void setday(int);
    void setmonth(int);
    void setyear(int);
    void setday1(int);
    void setmonth1(int);
    void setyear1(int);
    void setair(QString);
    void setnbr_escl(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
  QSqlQueryModel* rechercher(QString);
  QSqlQueryModel* tri_id();
  QSqlQueryModel* tri_id_emp();
  QSqlQueryModel* tri_airline();
  bool existance(QString);
};
#endif // VOL_H
