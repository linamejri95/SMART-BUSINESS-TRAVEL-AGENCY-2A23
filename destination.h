#ifndef DESTINATION_H
#define DESTINATION_H
#include"voyage.h"
#include <QDialog>
#include <QSqlDatabase>



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

private:
    Ui::destination *ui;
    voyage V;
};

#endif // DESTINATION_H
