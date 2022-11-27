#include "connection.h"
//tester Git

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_client");
db.setUserName("nourchenee");//inserer nom de l'utilisateur
db.setPassword("esprit80");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection:: closeconnection()
{
    db.close();
}

