#include "connection.h"
#include<QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("123456");
    if (db.open()) test=true;
    return  test;
    }
    void Connection::closeConnection()
            {db.close();}
