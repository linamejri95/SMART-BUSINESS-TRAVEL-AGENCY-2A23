#ifndef GEST_EMPLOYEE_H
#define GEST_EMPLOYEE_H
#include "employee.h"
#include <QTcpSocket>
#include "arduino.h"
#include <QtSerialPort>

#include <QDialog>

namespace Ui {
class gest_employee;
}

class gest_employee : public QDialog
{
    Q_OBJECT

public:
    explicit gest_employee(QWidget *parent = nullptr);
    ~gest_employee();
    private slots:

    void on_bouton1_2_clicked();

    void on_SuppButt_clicked();

    void on_b2_2_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void onReadyRead();

    void onSendButtonPressed();

    void on_pushButton_3_clicked();

    void on_offButton_clicked();


private:
    Ui::gest_employee *ui;
    employee E;
    QTcpSocket socket;
    QByteArray data;

            arduino C;
};

#endif // GEST_EMPLOYEE_H
