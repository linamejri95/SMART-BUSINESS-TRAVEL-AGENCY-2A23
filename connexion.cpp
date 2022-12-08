#include "connexion.h"

connexion::connexion() {}
bool connexion ::createconnection()
{
db= QSqlDatabase :: addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A.");
db.setUserName("khada");
db.setPassword("khada");
if(db.open()) test=true;
return test;
}
void connexion::closeConnection(){db.close();}
