#ifndef STATISTIQUETRANS_H
#define STATISTIQUETRANS_H

#include <QDialog>
#include "connexion.h"
#include "qcustomplot.h"
#include <QWidget>


namespace Ui {
class statistiquetrans;
}

class statistiquetrans : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquetrans(QWidget *parent = nullptr);
    ~statistiquetrans();
    void makePlot();


private:
    Ui::statistiquetrans *ui;
};

#endif // STATISTIQUETRANS_H
