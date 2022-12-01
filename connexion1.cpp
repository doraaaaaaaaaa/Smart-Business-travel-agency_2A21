#include "connexion1.h"
#include <iostream>
using namespace std;
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("2Aprojet");
db.setUserName("aziz1");//inserer nom de l'utilisateur
db.setPassword("aziz1");//inserer mot de passe de cet utilisateur

if (db.open())
{
test=true;
cout<<"aaaaa";

}


    return  test;
}

