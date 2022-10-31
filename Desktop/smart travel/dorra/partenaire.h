#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>

class Partenaire

{
private :
    int numero ;
    int contact;
    QString domaine;
    QString adresse;
public:
    // constructeurs :
    Partenaire();
    Partenaire(int ,int,QString,QString);

    //Getters :
    int getnumero(){return numero;}
    int getcontact(){return contact;}
    QString getadresse(){return adresse;}
    QString getdomaine(){return domaine;}

    //setters
    void setnumero(int n){numero=n;}
    void setcontact(int c){contact=c;}
    void setadresse(QString a){adresse=a;}
    void setdomaine(QString d){domaine=d;}
    //Fonctionalités
     bool ajouter();

     QSqlQueryModel *afficher();
       bool  supprimer(int numero);
       bool modifier(int numero);
};


#endif // PARTENAIRE_H
