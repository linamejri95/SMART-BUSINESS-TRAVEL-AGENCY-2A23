#include "Local.h"
#include <QtDebug>
#include <QObject>

Loc::Loc()
{
    id_loc="";
    lieu="";
    phone="";

}




Loc::Loc(QString id_loc,QString lieu,QString phone)
{
    this->id_loc=id_loc;
    this->lieu=lieu;
    this->phone=phone;

}

bool Loc::ajouter()
{
   QSqlQuery Q1;
   Q1.prepare("insert into LOC(id_loc,lieu,phone)" "values(:id_loc, :lieu,:phone)");
   Q1.bindValue(":id_loc",id_loc);
   Q1.bindValue(":lieu",lieu);
   Q1.bindValue(":phone",phone);

   return Q1.exec();
}


bool Loc::supprimer (QString id_loc)
{
QSqlQuery query;
query.prepare("Delete from  LOC where ID_LOC = :id_loc ");
query.bindValue(":id_loc", id_loc);
return query.exec();
}



bool Loc::modifier(QString id_loc)
{
    QSqlQuery Q1;


    Q1.prepare("UPDATE LOC set LIEU=:lieu , PHONE=:phone  WHERE ID_LOC=:id_loc");

    Q1.bindValue(":id_loc",id_loc);
    Q1.bindValue(":lieu",lieu);
    Q1.bindValue(":phone",phone);


    return Q1.exec();

}





QSqlQueryModel* Loc::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT id_loc , lieu , phone  FROM LOC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id_loc"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("lieu"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("phone"));

    return model;
}

QSqlQueryModel * Loc ::rechercherID(QString id_loc)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  LOC where id_loc like '"+id_loc+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_loc"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("lieu "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Phone"));

return model;
}


QSqlQueryModel * Loc::AfficherTrieID()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOC ORDER BY Id_loc ASC");
     return model;
 }

 QSqlQueryModel * Loc::AfficherTrieLieu()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOC ORDER BY lieu ASC");
     return model;
 }
 QSqlQueryModel * Loc::AfficherTriePhone()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOC ORDER BY phone ASC");
     return model;
 }


 QString Loc::exporter()
  {
     QString text=" PRINT \n " ;
     QSqlQuery query ;
     QString i,x,e;
     query.exec("select * from LOC ");
       while (query.next())
       {
          i=query.value(0).toString();
          e=query.value(1).toString();
          x=query.value(2).toString();




         text += "\n ID_Loc : "+i+"\n Lieu : "+e+"\n Phone : "+ x+"";
      }           return text ;
  }


