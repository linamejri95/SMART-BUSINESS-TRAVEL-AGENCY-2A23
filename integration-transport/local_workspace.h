#ifndef LOCAL_WORKSPACE_H
#define LOCAL_WORKSPACE_H

#include <QMainWindow>
#include "Local.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include "arduino_locaux.h"

namespace Ui {
class local_workspace;
}

class local_workspace : public QMainWindow
{
    Q_OBJECT

public:
    explicit local_workspace(QWidget *parent = nullptr);
    ~local_workspace();

private slots:

    void update_label();

    void on_AjouterButton_clicked();


    void on_del_button_clicked();


    void on_modifier_clicked();

    void on_recherche_clicked();

    void on_pb_trier_clicked();

    void on_exporter_clicked();

    void on_stat_clicked();

    void on_Pb_video_clicked();


    void on_pb_etat_clicked();

    void on_pushButton_clicked();

private:
    Ui::local_workspace *ui;
   QByteArray data;
    arduino_locaux A;
    Loc L;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;

};

#endif // LOCAL_WORKSPACE_H
