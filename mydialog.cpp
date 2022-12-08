#include "mydialog.h"
#include "ui_mydialog.h"
#include "gest_employee.h"
#include "ui_gest_employee.h"
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
    gest_employee e;
    e.show();
    e.exec();
}
