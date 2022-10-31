#ifndef VOL_H
#define VOL_H
#include <qstring.h>
#include<QSqlQuery>
#include<QSqlQueryModel>
class vol
{
private:
    int id;
    QString nom,prenom;
public:
    vol();
    vol(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getclasse();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setclasse(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
};
#endif // VOL_H
