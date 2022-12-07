#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("travel_agency");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("Modafukaz69");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;
test=true;
    return  test;
}
