#include "employee.h"

employee::employee(QString b,QString c ,QString e,QString j,QString m,QString g,int d,int s)
{
  NOM=b ;
  PRENOM=c ;
  mail=e;
  USERNAME=j;
  Sexe=g;
  MDP=m;
  ID_EMP=d ;
  SALAIRE=s ;
}

bool employee :: ajouter()
{
    QSqlQuery query ;
    QString res= QString::number(ID_EMP) ;
    QString res2= QString::number(SALAIRE) ;


    query.prepare("insert into EMPLOYÉ (ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE)""values(:ID_EMP,:NOM,:PRENOM,:SALAIRE,:MAIL,:MDP,:USERNAME,:SEXE)") ;

    query.bindValue(":NOM",NOM) ;
    query.bindValue(":PRENOM",PRENOM) ;
    query.bindValue(":MAIL",mail) ;
    query.bindValue(":MDP",MDP) ;
    query.bindValue(":USERNAME",USERNAME) ;
    query.bindValue(":SEXE",Sexe) ;
    query.bindValue(":ID_EMP",res) ;
    query.bindValue(":SALAIRE",res2) ;

    return  query.exec() ;
}

bool  employee::supprimer(int ID_EMP)
{

    QSqlQuery   query;
    QString res=QString::number(ID_EMP) ;
    query.prepare("delete from EMPLOYÉ where ID_EMP=:id_EMP") ;
    query.bindValue(0,res) ;

    return  query.exec() ;
}



QSqlQueryModel * employee:: afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel() ;

  model->setQuery("select ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE from EMPLOYÉ") ;
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP")) ;
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM")) ;
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM")) ;
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("SALAIRE")) ;
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("MAIL")) ;
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("MDP")) ;
  model->setHeaderData(6,Qt::Horizontal,QObject::tr("USERNAME")) ;
  model->setHeaderData(7,Qt::Horizontal,QObject::tr("SEXE")) ;
  return  model ;


}

bool employee::modifierEmployes(int ID_EMP)
{
    QSqlQuery query ;
    QString res= QString::number(ID_EMP) ;
    QString res2= QString::number(SALAIRE) ;

    query.prepare("UPDATE EMPLOYÉ set ID_EMP=:ID_EMP,NOM=:NOM,PRENOM=:PRENOM,SALAIRE=:SALAIRE,MAIL=:MAIL,MDP=:MDP,USERNAME=:USERNAME,SEXE=:SEXE WHERE ID_EMP=:ID_EMP");

    query.bindValue(":NOM",NOM) ;
    query.bindValue(":PRENOM",PRENOM) ;
    query.bindValue(":MAIL",mail) ;
    query.bindValue(":MDP",MDP) ;
    query.bindValue(":USERNAME",USERNAME) ;
    query.bindValue(":SEXE",Sexe) ;
    query.bindValue(":ID_EMP",res) ;
    query.bindValue(":SALAIRE",res2);
    return query.exec();

}

QSqlQueryModel * employee::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE FROM EMPLOYÉ ORDER BY ID_EMP");
    return model;
}

QSqlQueryModel * employee::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE FROM EMPLOYÉ ORDER BY NOM");
    return model;
}
QSqlQueryModel * employee::AfficherTriePrenom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE FROM EMPLOYÉ ORDER BY PRENOM");
    return model;
}



QSqlQueryModel * employee::rechercherNom(QString NOM)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE from EMPLOYÉ where NOM like '%"+ NOM +"%'or ID_EMP like '%"+ NOM +"%' or PRENOM like '%"+ NOM +"%'");
    q.addBindValue("%"+ NOM +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QString employee:: export_pdf()
 {
    QString text="          ** Les employés  **      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,r,t,y,l;


      query.exec("select ID_EMP,NOM,PRENOM,SALAIRE,MAIL,MDP,USERNAME,SEXE FROM EMPLOYÉ ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         r=query.value(4).toString();
         t=query.value(5).toString();
         y=query.value(6).toString();
         l=query.value(7).toString();
         text += "\n ID_EMP : "+i+"\n\n - NOM : "+ x+"\n - PRENOM : "+ z+"\n - SALAIRE :"+a+"\n- MAIL : "+ r+"\n- MDP : "+ t+"\n- USERNAME : "+ y+"\n- SEXE : "+ l+"\n" ;


     }


             return text ;
 }
