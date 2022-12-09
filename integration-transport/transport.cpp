#include "transport.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>


transport::transport()
{
    Mat=0;
    type=" ";
    prix=0;
    nomcompagnie=" ";
    nbplace=0;
}






transport::transport(int Mat,QString type,QString nomcompagnie,float prix,int nbplace)
{
    this->Mat=Mat;
    this->type=type;
    this->nomcompagnie=nomcompagnie;
    this->prix=prix;
    this->nbplace=nbplace;
}



void transport::incrParking(){
    QSqlQuery query;
   query.prepare("update parking set nbrplaces=nbrplaces+1");
   query.exec();

}

void transport::decrParking(){
    QSqlQuery query;
   query.prepare("update parking set nbrplaces=nbrplaces-1");
   query.exec();

}

QString transport::count(){
    QSqlQuery q("select * from parking");
    while(q.next()){
        return q.value(0).toString();
    }
    return "nothing to show";
}


int transport::getMat()
{
    return Mat;
}
 QString transport:: gettype()
 {
     return type;
 }
 QString transport::getnomcompagnie()
 {
     return nomcompagnie;
 }
  int transport::getnbplace()
  {
      return nbplace;
  }
 float transport::getprix()
  {
      return prix;
  }
 void transport::setMat(int Mat){this->Mat=Mat;}
 void transport::setnomcompagnie(QString nomcompagnie){this->nomcompagnie=nomcompagnie;}
 void transport::settype(QString type){this->type=type;}
 void transport::setnbplace(int nbplace){this->nbplace=nbplace;}
 void transport::setprix(float prix){this->prix=prix;}
bool transport::ajouter()
{
    QString Mat_string=QString::number(Mat);

    QString prix_string=QString::number(prix);
     QString nbplace_string=QString::number(nbplace);
    QSqlQuery  query;
    query.prepare("INSERT INTO transport(mat,type,nomcompagnie,prix,nbplace)""VALUES(:Mat,:type,:nomcompagnie,:prix,:nbplace)");
    query.bindValue(0,Mat_string);
    query.bindValue(1,type);
    query.bindValue(2,nomcompagnie);
    query.bindValue(3,prix_string);
    query.bindValue(4,nbplace_string);
     return query.exec();
}
QSqlQueryModel* transport::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel;
          model->setQuery("SELECT* FROM transport");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matriclue"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de compagnie"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de place"));
   return model;
}

bool transport::supprimer(int Mat)
{
    QSqlQuery query;
    query.prepare("Delete from transport where Mat=:Mat");
    query.bindValue(0,Mat);

    return query.exec();

}

 bool transport::modifier(int Mat,QString type,QString nomcompagnie,float prix,int nbplace)
 {
     QString Mat_string=QString::number(Mat);
     QString nbplace_string=QString::number(nbplace);
     QString prix_string=QString::number(prix);
      QSqlQuery query;
     query.prepare("update transport set Mat=:Mat,type=:type,nomcompagnie=:nomcompagnie,prix=:prix,nbplace=:nbplace where Mat=:Mat");
     query.bindValue(":Mat",Mat_string);
     query.bindValue(":type",type);
     query.bindValue(":nomcompagnie",nomcompagnie);
     query.bindValue(":prix",prix_string);
     query.bindValue(":nbplace",nbplace_string);
     return query.exec();
 }
 QSqlQueryModel * transport::AfficherTrieMat()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM transport ORDER BY Mat DESC");
     return model;
 }

 QSqlQueryModel * transport::AfficherTrietype()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM transport ORDER BY type DESC");
     return model;
 }
 QSqlQueryModel * transport::AfficherTrieprix()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM transport ORDER BY prix DESC");
     return model;
 }




QSqlQueryModel * transport::rechercherMat(QString Mat )
{


          QSqlQueryModel * model= new QSqlQueryModel();
          QString recher=("select * from transport where Mat like '%"+Mat+"%' or type like '%"+Mat+"%' or prix like '%"+Mat+"%'");
          model->setQuery(recher);
          return model;

}





