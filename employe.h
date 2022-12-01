#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include <QMessageBox>
#include <QString>
class Employe
{private:
    int ID_EMP,MDPS;
    QString NOM,PRENOM,DATE_N,Genre;
public:
    Employe();
    Employe(int,int,QString,QString,QString,QString);
    int getID_EMP();
    int getMDPS();
    QString getNOM();
    QString getPRENOM();
    QString getDATE_N();
    QString getGenre();
    void setID_EMP(int);
    void setMDPS(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setDATE_N(QString);
    void setGenre(QString);



    bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
         bool modifier();
QSqlQueryModel * recherche(QString id);
QSqlQueryModel * trier(int test);
bool existance(QString );


};

#endif // EMPLOYE_H
