#ifndef TRANSPORT_WORKSPACE_H
#define TRANSPORT_WORKSPACE_H

#include <QMainWindow>
#include"transport.h"
#include "arduino_transport.h"

namespace Ui {
class transport_workspace;
}

class transport_workspace : public QMainWindow
{
    Q_OBJECT

public:
    explicit transport_workspace(QWidget *parent = nullptr);
    ~transport_workspace();


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

    void on_pushButton_clicked();

private:

    Ui::transport_workspace *ui;
    transport T;
    stat s;
    QByteArray data;
    QByteArray data2;
      arduino_transport a;

};

#endif // TRANSPORT_WORKSPACE_H

namespace Ui {
class MainWindow;
}
