#include "vidreadthread.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "Local.h"
#include "QIntValidator"
#include "connection.h"
#include <QtPrintSupport>
#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include <QSqlQuery>
#include<QtCharts>
#include<QPixmap>


using namespace cv;
extern MainWindow *mainPtr;

vidreadthread::vidreadthread(QString s) : name(s)
{
}

void vidreadthread::run()
{
    QThread::msleep(100);
    VideoCapture cap;
    cap.open("helicopter_with_stickers.mp4");
    while(1)
    {
        Mat image1;
       // Capture frame-by-frame
        cap >> image1;

       // If the frame is empty, break immediately
       if (image1.empty())
         break;

       QImage image2 = QImage((uchar*) image1.data, image1.cols, image1.rows, image1.step, QImage::Format_RGB888);
       mainPtr->ui->label1->setPixmap(QPixmap::fromImage(image2));
    }
}
