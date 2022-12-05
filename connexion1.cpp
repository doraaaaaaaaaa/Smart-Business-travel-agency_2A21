#include "connexion1.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//db.setDatabaseName("Source_Projet2A");
//db.setUserName("ranyme");//inserer nom de l'utilisateur
//db.setPassword("esprit22");//inserer mot de passe de cet utilisateur
db.setDatabaseName("test");
db.setUserName("alaa");//inserer nom de l'utilisateur
db.setPassword("1001");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;



    return  test;
}



