#ifndef CONNECXON_H
#define CONNECXON_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
using namespace std;
class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNEXION_H
