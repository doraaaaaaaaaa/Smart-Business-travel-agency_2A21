#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;

db.setDatabaseName("Projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("99593596");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


return  test;
}

