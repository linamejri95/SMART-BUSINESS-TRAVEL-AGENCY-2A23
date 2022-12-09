#include "transport_workspace.h"
#include "ui_transport_workspace.h"
#include "transport.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QPainter>
#include<QFileDialog>
#include<QFileDialog>
#include<QTextStream>
#include<QTextDocument>
#include <QPrinter>
#include <QPixmap>
#include "statistiquetrans.h"
#include "email.h"
#include <QtCore>
#include<QSslSocket>
#include "mydialog.h"

transport_workspace::transport_workspace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::transport_workspace)
{
    ui->setupUi(this);
    qDebug()<<T.count();
    int ret=a.connect_arduino();
          switch (ret) {
          case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
              break;
          case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
              break;
          case(-1):qDebug()<<"arduino is not available";
          }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    ui->le_Mat->setValidator(new QIntValidator(0,99999999,this));
     ui->le_Mat_3->setValidator(new QIntValidator(0,99999999,this));
      ui->le_Mat_supp->setValidator(new QIntValidator(0,99999999,this));
      ui->comboBox->addItem("Mat");
        ui->comboBox->addItem("type");
          ui->comboBox->addItem("prix");
    ui->Tab_transport->setModel(T.afficher());
}

transport_workspace::~transport_workspace()
{
    delete ui;
}


void transport_workspace::update_label()
{
    data=a.read_from_arduino();
    if (data == "2")
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Une voiture veut sortir.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->ouvrir->setEnabled(true);
ui->tabWidget->setCurrentIndex(4);




    }
  if(T.count()=="-1"){
      a.write_to_arduino("-1");
  }


  else{





   if (data == "1")
   {


       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Une voiture veut entrer.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

       ui->ouvrir_2->setEnabled(true);
       ui->tabWidget->setCurrentIndex(4);


   }


}
    }
void transport_workspace::on_pb_ajout_clicked()
{
    int Mat=ui->le_Mat->text().toInt() ;
    QString type=ui->le_type->text();
    QString nomcompagnie=ui->le_nomcompagnie->text();
    float prix=ui->le_prix->text().toFloat();
    int nbplace=ui->le_nbplace->text().toInt() ;


   transport T(Mat,type,nomcompagnie,prix,nbplace);
   bool test=T.ajouter();
   QMessageBox msgBox;
   if (test)
        msgBox.setText("Ajout avec succès");
   else
        msgBox.setText("Echec de l'ajout");
        msgBox.exec();
        ui->Tab_transport->setModel(T.afficher());
}


void transport_workspace::on_pb_supprimer_clicked()
{
    transport T1;
    T1.setMat(ui->le_Mat_supp->text().toInt());
    bool test=T1.supprimer(T1.getMat());
    QMessageBox msgBox;
    if (test)
        msgBox.setText("Suppression avec succès");
    else
        msgBox.setText("Echec de la suppression");
    msgBox.exec();
 ui->Tab_transport->setModel(T.afficher());
}

void transport_workspace::on_pb_modifier_clicked()
{
    int Mat;
    QString type,nomcompagnie;
    float prix;
    int nbplace;


      Mat=ui->le_Mat_3->text().toInt();
      type=ui->le_type_2->text();
      nomcompagnie=ui->le_nomcompagnie_2->text();
      prix=ui->le_prix_2->text().toFloat();
      nbplace=ui->le_nbplace_2->text().toInt();


      bool test=T.modifier(Mat,type,nomcompagnie,prix,nbplace);
      ui->Tab_transport->setModel(T.afficher());


      QMessageBox msgBox;
      if (test)
          msgBox.setText("modification avec succès");
      else
          msgBox.setText("Echec de la modification");
      msgBox.exec();
      ui->Tab_transport->setModel(T.afficher());

}



void transport_workspace::on_pb_trier_clicked()
{
    QString tri=ui->comboBox->currentText();
       if(tri=="Mat"){
        ui->Tab_transport->setModel(T.AfficherTrieMat());}
       else {if (tri=="type"){
           ui->Tab_transport->setModel(T.AfficherTrietype());
       }
       else
           {
           ui->Tab_transport->setModel(T.AfficherTrieprix());
            }
}
}





/*void MainWindow::on_search_clicked()
{

        QString search=ui->le_chercher->text();
         ui->Tab_transport->setModel(T.rechercherMat(search));
        if (search=="")
          {
            ui->Tab_transport->setModel(T.afficher());
          }

}*/

void transport_workspace::on_pb_pdf_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->Tab_transport->model()->rowCount();//retourne le nombre de lignes
                const int columnCount = ui->Tab_transport->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("strTitle")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                    "<center><h1 style='color:#732626;'>Liste des clients</h1></br></br><table border=1 cellspacing=0 cellpadding=2 color=#732626>\n";

                // headers

                //les noms des colonnes
                out << "<thead><tr bgcolor=#f0f0f0> <th style='color:#732626;'>Numero</th>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->Tab_transport->isColumnHidden(column))
                        out << QString("<th style='color:#732626;'>%1</th>").arg(ui->Tab_transport->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";


                //remplir le tableau
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr> <td  bkcolor=0>" << row + 1 << "</td>";
                    for (int column = 0; column < columnCount; column++)
                    {
                        if (!ui->Tab_transport->isColumnHidden(column))
                        {
                            QString data = ui->Tab_transport->model()->data(ui->Tab_transport->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table> </center>\n"
                    "</body>\n"
                    "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty())
                {
                    fileName.append(".pdf");
                }

                QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);

                printer.setOutputFileName(fileName);

                QTextDocument doc;//appliquer le code html
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
    }


void transport_workspace::on_pb_stat_clicked()
{
statistiquetrans *MainWindow=new statistiquetrans(this);
MainWindow ->show();
}


void transport_workspace::on_pushButton_4_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Select Picture"),"home/Desktop");
    QPixmap pic(dir);
    int x = ui->label_18->width();
    int y = ui->label_18->height();
    ui->label_18->setPixmap(pic.scaled(x,y,Qt::KeepAspectRatio));
}


void transport_workspace::on_pushButton_email_clicked()
{
    Email *email=new Email(this);
    email->show();

}


void transport_workspace::on_le_chercher_textChanged(const QString &arg1)
{
    QString search=ui->le_chercher->text();
     ui->Tab_transport->setModel(T.rechercherMat(search));
    if (search=="")
      {
        ui->Tab_transport->setModel(T.afficher());
      }

}

void transport_workspace::on_ouvrir_2_clicked()
{
    T.decrParking();
    data2.clear();
    data2.append("6");
     a.write_to_arduino(data2);
     ui->ouvrir_2->setDisabled(true);
     ui->lcdNumber->display(T.count());
}

void transport_workspace::on_ouvrir_clicked()
{
    T.incrParking();
               data2.clear();
               data2.append("5");
                a.write_to_arduino(data2);
                  ui->ouvrir->setDisabled(true);
ui->lcdNumber->display(T.count());
}

void transport_workspace::on_pushButton_clicked()
{
    close();
  MYDialog *md=new MYDialog();
md->show();
}
