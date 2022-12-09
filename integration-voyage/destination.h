#ifndef DESTINATION_H
#define DESTINATION_H
#include"voyage.h"
#include <QDialog>
#include <QSqlDatabase>
#include "arduino_voyage.h"
#include <QSerialPort>



namespace Ui {
class destination;
}

class destination : public QDialog
{
    Q_OBJECT

public:
    explicit destination(QWidget *parent = nullptr);
    ~destination();

private slots:
    void on_pb_ajouter_clicked();

    void on_le_code_supp_clicked();

    void on_pb_modifier_clicked();


    void on_pb_rechercher_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();



    void on_refreshButton_released();

    void on_refreshButton_clicked();

    void on_offButton_pressed();

    void on_offButton_clicked();

private:
    Ui::destination *ui;
    voyage V;
    QByteArray data;

        arduino_voyage C;
};

#endif // DESTINATION_H
