#include "destination.h"
#include "ui_destination.h"
#include "voyage.h"
#include"mainwindow.h"
#include <QString>
#include<QValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QIntValidator>

destination::destination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::destination)
{
    ui->setupUi(this);
    ui->tab_voyage->setModel(V.afficher());


}

destination::~destination()
{
    delete ui;
}

void destination::on_pb_ajouter_clicked()
{
    QString CODE=ui->le_code->text();
    QString DESTINATION=ui->le_dest->text();
    QString HEBERGEMENT=ui->le_hebergement->text();
    QString DUREE=ui->le_dure->text();
    QString PRIX=ui->le_prix->text();

        voyage P(CODE ,DESTINATION ,HEBERGEMENT ,DUREE ,PRIX);
        bool test=P.ajouter();
           QMessageBox msgBox;
           if (test)
                {msgBox.setText("Ajout avec succes");
           ui->tab_voyage->setModel(V.afficher());
           }
           else
                msgBox.setText("Echec de l'ajout");
                msgBox.exec();

}



void destination::on_le_code_supp_clicked()
{
    voyage V1; V1.setcode(ui->supprimer->text());
    bool test=V1.supprimer(V1.getcode());
    QMessageBox msgBox;

    if(test){
    msgBox.setText("supression avec succés.");
    ui->tab_voyage->setModel(V.afficher());
     }
    else{
        msgBox.setText("Echec de supression");
        msgBox.exec();
    }
}

void destination::on_pb_modifier_clicked()
{
           QString code=ui->le_code->text();
           QString destination=ui->le_dest->text();
           QString hebergement=ui->le_hebergement->text();
           QString duree=ui->le_dure->text();
           QString prix=ui->le_prix->text();


            voyage P(code ,destination ,hebergement ,duree ,prix);
            if(P.modifier_voyage(code))
            {
            QMessageBox::information(nullptr, QObject::tr("Modifier un voyage"), QObject::tr("Vol modifié.\n"), QMessageBox::Cancel);
                ui->tab_voyage->setModel(P.afficher());
 }
 else
            {QMessageBox::critical(nullptr, QObject::tr("modifier un voyage"), QObject::tr("Erreur !!!\n"), QMessageBox::Cancel);

                ui->le_code->text().toInt();
                ui->le_dest->text();
                ui->le_hebergement->text();
                ui->le_dure->text();
                ui->le_prix->text().toFloat();
            }

}
