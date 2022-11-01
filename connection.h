#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeConnection();
};
#endif // CONNEXION_H
