 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "destination.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    destination dest;
    dest.setModal(true);
    dest.exec();
}
