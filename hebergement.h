#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QString>


class hebergement
{
private:
    QString nom_h,type_h,adresse_h;
    int code_h,FAX_h;
    float prix_h;
public:
    //Constructeurs
    hebergement();
    hebergement(int,QString,QString,QString,float,int);
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
    void setPrix(float);
    void setFAX(int);
    //Fonctionnalités de Base relatives à entité Hebergement
    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int);

};

#endif // HEBERGEMENT_H
