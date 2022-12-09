#ifndef EMAIL_H
#define EMAIL_H

#include <QDialog>

#include "smtp.h"
#include <QWidget>
#include <QtWidgets/QMessageBox>

namespace Ui {
class Email;
}

class Email : public QDialog
{
    Q_OBJECT

public:
    explicit Email(QWidget *parent = nullptr);
    ~Email();

private:
    Ui::Email *ui;

private slots:
    void sendMail();
    void mailSent(QString);

    void on_sendMailBtn_clicked();

};

#endif // EMAIL_H
