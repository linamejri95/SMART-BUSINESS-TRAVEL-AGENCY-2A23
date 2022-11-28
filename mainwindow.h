#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"transport.h"
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajout_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_trier_clicked();

    //void on_search_clicked();

    void update_label();

    void on_pb_pdf_clicked();

    void on_pb_stat_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_email_clicked();

    void on_le_chercher_textChanged(const QString &arg1);

    void on_ouvrir_2_clicked();

    void on_ouvrir_clicked();

private:

    Ui::MainWindow *ui;
    transport T;
    stat s;
    QByteArray data;
    QByteArray data2;
      arduino a;
};

#endif // MAINWINDOW_H
