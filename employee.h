#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QString>

class employee
{
private:
    QString NOM,PRENOM,mail,USERNAME,Sexe,MDP;
    int ID_EMP ;
    int SALAIRE;
public:
    employee(){} ;
    employee(QString,QString,QString,QString,QString,QString,int,int) ;

    QString getnom(){return  NOM ;}
    QString getprenom(){return  PRENOM ;}
    QString getUsername(){return  USERNAME ;}
    QString getEMAIL() {return  mail ;}
    QString getSexe() {return  Sexe ;}
    QString getMDP() {return  MDP ;}
    int getID(){return ID_EMP ;}
    int getsalaire() {return  SALAIRE ;}

    void setnom(QString n){NOM=n ;}
    void setprenom(QString p){PRENOM=p ;}
    void setUsername(QString j){USERNAME= j ;}
    void setEmail(QString e){mail=e ;}
    void setSexe(QString g){Sexe=g ;}
    void setMDP(QString m){MDP=m ;}
    void setID(int i){ID_EMP=i ;}
    void setsaliare(int nt){SALAIRE=nt ;}

    bool ajouter() ;
    QSqlQueryModel *afficher();
    bool supprimer(int) ;
    bool modifierEmployes (int);
    QSqlQueryModel * AfficherTrieID();
    QSqlQueryModel * AfficherTrieNom();
    QSqlQueryModel * rechercherNom(QString);
    QSqlQueryModel * AfficherTriePrenom();
    QString  export_pdf();
};

#endif // EMPLOYEE_H
