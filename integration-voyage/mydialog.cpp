#include "mydialog.h"
#include "ui_mydialog.h"
#include "gest_employee.h"
#include "ui_gest_employee.h"
#include "client_workspace.h"
#include"destination.h"

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
    gest_employee *e= new gest_employee();
    e->show();

}

//client
void MYDialog::on_pushButton_2_clicked()
{
client_workspace *cw=new client_workspace();
cw->show();
}

//administrateur
void MYDialog::on_pushButton_3_clicked()
{

}
//voyage
void MYDialog::on_pushButton_4_clicked()
{
destination *d=new destination();
d->show();
}
