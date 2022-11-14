#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>


class hebergement
{
private:
    QString nom_h,type_h,adresse_h;
    int code_h,FAX_h;
    int prix_h;
public:
    //Constructeurs
    hebergement();
    hebergement(int,QString,QString,QString,int,int);
   //Getters
    int getCode_H();
    QString getType();
    QString getNom();
    QString getAdresse();
    float getPrix();
    int getFAX();
    //Setters
    void setCode_H (int);
    void setType (QString );
    void setNom(QString);
    void setAdresse (QString);
    void setPrix(int);
    void setFAX(int);
    //Fonctionnalités de Base relatives à entité Hebergement
    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier(int);
    QSqlQueryModel * triCode();
    QSqlQueryModel * triNom();
    QSqlQueryModel * triPrix();
   void recherche(QTableView * , QString );
   void telechargerPDF();
};

#endif // HEBERGEMENT_H
