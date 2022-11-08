#include "mainwindow.h"
#include <QSqlDatabase>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("gestion_voyage_organisé");
    db.setUserName("lina");
    db.setPassword("Jiminbiased95");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    connection c;

       bool test=c.createconnection();
       if(test)
       {w.show();
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("connection successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



       return a.exec();
}
