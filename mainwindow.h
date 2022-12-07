#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "Local.h"
#include <QMainWindow>
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
#include "Arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_maps_clicked();

    void on_pb_etat_clicked();

private:
    Ui::MainWindow *ui;
   QByteArray data;
    Arduino A;
    Loc L;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;

};
#endif // MAINWINDOW_H
