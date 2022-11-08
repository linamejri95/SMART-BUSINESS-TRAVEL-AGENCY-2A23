#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>



class voyage
{
public:
    voyage();
    voyage(QString,QString,QString,QString,QString);

       QString getcode();
       QString getdest();
       QString getdure();
       QString gethebergement();
       QString getprix();
       void setcode(QString);
       void setdest(QString);
       void setdure(QString);
       void sethebergement(QString);
       void setprix(QString);
       bool ajouter();
          QSqlQueryModel* afficher();
       bool supprimer(QString);
       bool modifier_voyage(QString);

private:
     QString code;
     QString dest;
     QString hebergement;
     QString dure;
     QString prix;
};

#endif // VOYAGE_H
