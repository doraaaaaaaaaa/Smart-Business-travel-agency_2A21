                                                                                                                                #ifndef MISSION_H
#define MISSION_H

#include<QString>
#include<QSqlQueryModel>
class Mission
{
public:
    Mission();
    Mission(QString,int,int,QString,QString,int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
private:
    int code_h,ide,num;
    QString type,duree ,code_m;

};



#endif // MISSION_H
