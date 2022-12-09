#include "connexion.h"

connexion::connexion() {}
bool connexion ::createconnection()
{
db= QSqlDatabase :: addDatabase("QODBC");
bool test=false;
db.setDatabaseName("proj");
db.setUserName("revolver");
db.setPassword("revolver");
if(db.open()) test=true;
return test;
}
void connexion::closeConnection(){db.close();}
