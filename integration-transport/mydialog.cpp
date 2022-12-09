#include "mydialog.h"
#include "ui_mydialog.h"
#include "gest_employee.h"
#include "ui_gest_employee.h"
#include "client_workspace.h"
#include"destination.h"
#include "local_workspace.h"
#include "transport_workspace.h"
#include "mainwindow.h"

MYDialog::MYDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MYDialog)
{
    ui->setupUi(this);
}

MYDialog::~MYDialog()
{
    delete ui;
}

void MYDialog::on_pushButton_clicked()
{
    close();
    gest_employee *e= new gest_employee();
    e->show();

}

//client
void MYDialog::on_pushButton_2_clicked()
{
    close();
client_workspace *cw=new client_workspace();
cw->show();
}

//transport
void MYDialog::on_pushButton_3_clicked()
{
    close();
transport_workspace *tw= new transport_workspace();
tw->show();
}

//voyage
void MYDialog::on_pushButton_4_clicked()
{
    close();
destination *d=new destination();
d->show();
}

//locaux
void MYDialog::on_pushButton_5_clicked()
{
    close();
local_workspace *lw= new local_workspace();
lw->show();
}

void MYDialog::on_pushButton_6_clicked()
{
    close();
  MainWindow *mw=new MainWindow();
mw->show();
}
