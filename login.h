#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "QString"


class Loginn
{
private:
    QString NOM,PRENOM,Email,MDP,USERNAME,Sexe;

public:
    Loginn() ;
    Loginn(QString,QString,QString,QString,QString,QString) ;
    ~Loginn(){}
    QString getnom(){return  NOM ;}
    QString getprenom(){return  PRENOM ;}
    QString getUsername(){return  USERNAME ;}
    QString getEMAIL() {return  Email ;}
    QString getMDP() {return  MDP ;}
    QString getSexe() {return  Sexe ;}

    void setnom(QString n){NOM=n ;}
    void setprenom(QString p){PRENOM=p ;}
    void setUsername(QString j){USERNAME= j ;}
    void setEmail(QString e){Email=e ;}
    void setMDP(QString m){MDP=m;}
    void setSexe (QString  s ){Sexe =s ;}
    bool ajouter() ;
    bool LOGINNN(QString,QString);


};

#endif // LOGIN_H
