#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrinterInfo>
#include<QtPrintSupport/QPrintDialog>

class Partenaire

{
private :
    int numero ;
    int contact;
    QString nom_p;
    QString prenom_p;
    QString domaine;
    QString adresse;
public:
    // constructeurs :
    Partenaire();
    Partenaire(int ,QString,QString,int,QString,QString);

    //Getters :
    int getnumero(){return numero;}
    int getcontact(){return contact;}
    QString getadresse(){return adresse;}
    QString getdomaine(){return domaine;}
    QString getnom_p(){return nom_p;}
    QString getprenom_p(){return prenom_p;}


    //setters
    void setnumero(int n){numero=n;}
    void setcontact(int c){contact=c;}
    void setadresse(QString a){adresse=a;}
    void setdomaine(QString d){domaine=d;}
    void setnom_p(QString np){adresse=np;}
    void setprenom_p(QString pr){domaine=pr;}

    //Fonctionalités
     bool ajouter();

     QSqlQueryModel *afficher();
       bool  supprimer(int numero);
       bool modifier(int numero);
        QSqlQueryModel * recherche(QString numero);
        QSqlQueryModel * trier(int test);
        void pdf();


};


#endif // PARTENAIRE_H
