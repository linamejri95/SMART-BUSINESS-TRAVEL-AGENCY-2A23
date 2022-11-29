#include "voyage.h"
#include <QString>
#include<QSqlQuery>
#include <QtDebug>
#include"destination.h"
#include<QObject>

voyage::voyage()
{
       code="";
       dest="";
       hebergement="";
       dure="";
       prix="";
}
voyage::voyage (QString code,QString dest,QString hebergement,QString dure ,QString prix)
{
    this -> code =code;
    this ->dest =dest ;
    this -> hebergement=hebergement;
    this -> dure =dure;
    this -> prix =prix;
}
QString voyage::getcode()
{
    return code;
}
QString  voyage::getdest()
{
    return dest;
}
QString voyage::gethebergement()
{
    return hebergement;
}
QString voyage::getdure()
{
    return dure;
}

QString voyage::getprix()
{
    return prix;
}
void voyage::setcode(QString code)
{
    this ->code = code;
}
void voyage::setdest(QString dest)
{
    this ->dest=dest;
}
void voyage::sethebergement(QString hebergement)
{
    this -> hebergement= hebergement;
}
void voyage::setdure(QString dure)
{
    this -> dure=dure ;
}
void voyage::setprix(QString prix)
{
    this -> prix = prix;
}
bool voyage::ajouter()
{

    QSqlQuery query;

          query.prepare("INSERT INTO voyage (CODE,DESTINATION, HEBERGEMENT, DUREE,PRIX) "
                        "VALUES (:CODE, :DESTINATION, :HEBERGEMENT, :DUREE, :PRIX)");
          query.bindValue(":CODE", code);
          query.bindValue(":DESTINATION", dest);
          query.bindValue(":HEBERGEMENT", hebergement);
          query.bindValue(":DUREE", dure);
          query.bindValue(":PRIX", prix);
          return query.exec();


}
QSqlQueryModel* voyage::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM voyage");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEBERGEMENT"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

 return model;
}

bool voyage::supprimer(QString CODE)
{
    QSqlQuery query;

          query.prepare("Delete from voyage where CODE=:CODE");
          query.bindValue(":CODE", CODE);

          return query.exec();
}
bool voyage::modifier_voyage(QString code){
    QSqlQuery query;

   query.prepare("update VOYAGE set DESTINATION=:DESTINATION,HEBERGEMENT=:HEBERGEMENT,DUREE=:DUREE,PRIX=:PRIX where CODE=:CODE");
   query.bindValue(":CODE",code);
   query.bindValue(":DESTINATION", dest);
    query.bindValue(":HEBERGEMENT", hebergement);
    query.bindValue(":DUREE", dure);
    query.bindValue(":PRIX", prix);

    return    query.exec();

}
QSqlQueryModel * voyage::rechercherCode(QString code)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from voyage where code like '"+code+"%' or destination like '"+code+"%'  ");
    q.addBindValue("%"+ code +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
QSqlQueryModel * voyage::Triecode()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOYAGE ORDER BY CODE");
    return model;
}



QSqlQueryModel * voyage::Triedest()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOYAGE ORDER BY DEST");
    return model;
}

QString voyage:: exporter()
 {
    QString text=" PRINT \n " ;
    QSqlQuery query ;
    QString i,x,z,a,e;
    query.exec("select * from voyage ");
      while (query.next())
      {
         i=query.value(0).toString();
         e=query.value(1).toString();
         x=query.value(2).toString();
         z=query.value(3).toString();
         a=query.value(4).toString();



        text += "\n CODE : "+i+"\n DEST : "+e+"\n HEBERGEMENT : "+ x+"\n DURE : "+ z+"\n PRIX:"+a+"\n " ;
     }           return text ;
 }


