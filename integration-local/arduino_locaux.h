#ifndef ARDUINO_LOCAUX_H
#define ARDUINO_LOCAUX_H
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>

class arduino_locaux
{
public:
    arduino_locaux();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
private slots:
    void update_label();
};

#endif // ARDUINO_LOCAUX_H
