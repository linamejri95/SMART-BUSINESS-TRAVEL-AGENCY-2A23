#ifndef LOCAL_H
#define LOCAL_H

#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDebug>


class Loc
{
private:
    QString id_loc , lieu , phone;


public:
    //Constructeur-destructeur
    Loc();
    Loc(QString,QString,QString);
    ~Loc(){};

    //Getters
    QString getid_loc(){return id_loc;};
    QString getlieu(){return lieu;};
    QString getphone(){return phone;};


    //Setters
    void setid_loc(QString v){id_loc=v;};
    void setpdd(QString pd){lieu=pd;};
    void setpda(QString pa){phone=pa;};

     //fct
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * rechercherID(QString);

    QSqlQueryModel * AfficherTrieID();
    QSqlQueryModel * AfficherTrieLieu();
    QSqlQueryModel * AfficherTriePhone();

    QString exporter();
};

#endif // LOCAL_H
