#include "login.h"
#include <QSqlQuery>






Loginn::Loginn()
{
    NOM="";
    PRENOM="";
    USERNAME="";
    Email="";
    MDP="";
    Sexe="";
}



Loginn::Loginn(QString NOM,QString PRENOM,QString Email,QString MDP,QString USERNAME,QString Sexe)
{
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->Email=Email;
    this->MDP=MDP;
    this->USERNAME=USERNAME;
    this->Sexe=Sexe;
}

bool Loginn::ajouter()
{

    QSqlQuery qry;
    qry.prepare("INSERT INTO EMPLOYÉ(NOM,PRENOM,MAIL,MDP,USERNAME,SEXE)""values(:NOM,:PRENOM,:MAIL,:MDP,:USERNAME,:SEXE)");
    qry.bindValue(":NOM",NOM);
    qry.bindValue(":PRENOM",PRENOM);
    qry.bindValue(":MAIL",Email);
    qry.bindValue(":MDP",MDP);
    qry.bindValue(":USERNAME",USERNAME);
    qry.bindValue(":SEXE",Sexe);
    return qry.exec();
}


bool Loginn::LOGINNN(QString USERNAME , QString MDP)
{
    QSqlQuery qry;
    qry.prepare("SELECT USERNAME, MDP FROM EMPLOYÉ WHERE USERNAME=\'"+ USERNAME +"\' AND MDP=\'" + MDP + "\'");
    qry.addBindValue(USERNAME);
    qry.addBindValue(MDP);
    if(qry.exec())
        if(qry.next())
            {
                QString user = QVariant(qry.value(0)).toString();
            if(user==USERNAME)
            {return true;}
        }
    return false;

}
