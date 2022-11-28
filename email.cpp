#include "email.h"
#include "ui_email.h"
#include <QDebug>
#include <QTimer>
#include "smtp.h"


QTimer *timer_email = new QTimer();

Email::Email(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Email)
{
    ui->setupUi(this);

}

Email::~Email()
{
    delete ui;
}


void Email::sendMail()
{
    Smtp* smtp = new Smtp("emna.ounissi@esprit.tn", "211JFT6379", "smtp.gmail.com", 465);
    //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("emna.ounissi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

    QMessageBox::information(nullptr,QObject::tr("ok"),
                           QObject::tr("Effectue\n"
                                       "Message sent!"),QMessageBox::Cancel);
}

void Email::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("effectue\n"
                                           "Message sent!"),QMessageBox::Cancel);
     //   QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void Email::on_sendMailBtn_clicked()
{
    sendMail();
    //connect(ui->sendMailBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    ui->subject->setText("");
    ui->msg->setPlainText("");

}





