#include "local_workspace.h"
#include "ui_local_workspace.h"

#include <QMessageBox>
#include <QApplication>
#include "Local.h"
#include "QIntValidator"
#include <QtPrintSupport>
#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include <QSqlQuery>
#include<QtCharts>
#include<QPixmap>
#include <QSettings>
#include"webaxwidget.h"
#include "mydialog.h"

local_workspace::local_workspace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::local_workspace)
{
    ui->setupUi(this);
    ui->ShowV->setModel(L.afficher());
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                           QCoreApplication::organizationName(), QCoreApplication::applicationName());

        ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");


    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    int ret=A.connect_arduino();
    switch (ret) {
    case(0):qDebug()<<"arduino is available and connected to:" <<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to : " << A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

local_workspace::~local_workspace()
{
    delete ui;
}


void local_workspace::on_AjouterButton_clicked()
{
    QString id_loc=ui->le_id->text();
    QString lieu=ui->le_lieu->text();
    QString phone=ui->le_phone->text();


    Loc L(id_loc,lieu,phone);

    bool test = L.ajouter();

    if(test)
    {
        ui->ShowV->setModel(L.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("ajout effectué.\n",
                                             "click Cancel to exist."), QMessageBox::Cancel);
    }else{
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                                 QObject::tr("ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void local_workspace::on_del_button_clicked()
{
    Loc L ;
    QString id_loc=ui->Del_line->text();
    bool test=L.supprimer(id_loc);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("delete effectué.\n",
                                             "click Cancel to exist."), QMessageBox::Cancel);
        ui->ShowV->setModel(L.afficher());
    }else{
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                                 QObject::tr("delete non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void local_workspace::on_modifier_clicked()
{
           QString id_loc=ui->le_id->text();
           QString lieu=ui->le_lieu->text();
           QString phone=ui->le_phone->text();


            Loc L(id_loc,lieu,phone);
           if((id_loc=="")&&(lieu=="")&&(phone==""))
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
               }
             else if(id_loc == "")
              {
                  QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Veuillez remplir l'identifiant"), QMessageBox::Ok);

              }
              else if(lieu =="")
                 {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Veuillez remplir le lieu"), QMessageBox::Ok);

                 }
              else if(phone =="")
                 {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Veuillez remplir le telephone"), QMessageBox::Ok);

                 }


           else {

               if(L.modifier(id_loc))
               {
                        QMessageBox::information(nullptr, QObject::tr("Modifier un loc"),
                                    QObject::tr("Loc modifié.\n"), QMessageBox::Cancel);
                        ui->ShowV->setModel(L.afficher());



               }
               else
               {
                  QMessageBox::critical(nullptr, QObject::tr("Modifier un loc"),

                                        QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);

                  ui->le_id->setText("");
                  ui->le_lieu->setText("");
                  ui->le_phone->setText("");
               }
           }
}


void local_workspace::on_recherche_clicked()
{
        QString recherche=ui->Del_line->text();
        ui->ShowV->setModel(L.rechercherID(recherche));
}

void local_workspace::on_pb_trier_clicked()
{
    QString tri=ui->comboBox->currentText();
           if(tri=="Identifiant"){
            ui->ShowV->setModel(L.AfficherTrieID());}
           else {if (tri=="Lieu"){
               ui->ShowV->setModel(L.AfficherTrieLieu());
           }
           else{if(tri=="Phone"){
               ui->ShowV->setModel(L.AfficherTriePhone());
                }
    }
           }
}

void local_workspace::on_exporter_clicked()
{
        Loc L;
        QString text=L.exporter();
        ui->print->setText(text);
        QPrinter printer ;
        printer.setPrinterName("imprim");
        QPrintDialog dialog (&printer,this);
        if(dialog.exec()==QDialog::Rejected) return ;
        ui->print->print(&printer);
}


void local_workspace::on_stat_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from LOC where Phone < 30000000 ");
                         float phone=model->rowCount();
                         model->setQuery("select * from LOC where Phone  between 30000000 and 50000000 ");
                         float phonee=model->rowCount();
                         model->setQuery("select * from LOC where Phone >50000000 ");
                         float phoneee=model->rowCount();
                         float total=phone+phonee+phoneee;
                         QString a=QString("moins de 30000000 \t"+QString::number((phone*100)/total,'f',2)+"%" );
                         QString b=QString("entre 30000000 et 50000000 \t"+QString::number((phonee*100)/total,'f',2)+"%" );
                         QString c=QString("+50000000 \t"+QString::number((phoneee*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,phone);
                         series->append(b,phonee);
                         series->append(c,phoneee);
                 if (phone!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( phonee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(phoneee!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par Phone :Nombre Des Espaces "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();



    }

void local_workspace::on_Pb_video_clicked()
{
    player= new QMediaPlayer;
        vw=new QVideoWidget;

        auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");


        player->setVideoOutput(vw);
        player->setMedia(QUrl::fromLocalFile(filename));
        vw->setGeometry(200,400,300,400);
        vw->show();
        player->play();
    }


void local_workspace::update_label()
{
    data=A.read_from_arduino();

    if(data=="20")
        ui->label_5->setText("OFF");
    else
        ui->label_5->setText("ON");

}

void local_workspace::on_pb_etat_clicked()
{
    QString data=A.read_from_arduino();

    if(data == "20")
        ui->label_5->setText("OFF");
    else
        ui->label_5->setText("ON");
}



void local_workspace::on_pushButton_clicked()
{
    close();
  MYDialog *md=new MYDialog();
md->show();
}
