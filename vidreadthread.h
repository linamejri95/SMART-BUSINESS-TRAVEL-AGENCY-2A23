#ifndef VIDREADTHREAD_H
#define VIDREADTHREAD_H

#include <QDialog>


#include <QWidget>
#include <QtWidgets/QMessageBox>

namespace Ui {
class vidreadthread;
}

class vidreadthread : public QDialog
{
    Q_OBJECT

public:
    explicit vidreadthread(QWidget *parent = nullptr);
    ~vidreadthread();

private:
    Ui::vidreadthread *ui;

private slots:


    void on_Pb_video_clicked();

};

#endif // VIDREADTHREAD_H
