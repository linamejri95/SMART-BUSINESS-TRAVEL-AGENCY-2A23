#ifndef ARDUINO_VOYAGE_H
#define ARDUINO_VOYAGE_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class arduino_voyage
{
public:
    arduino_voyage();
    int connect_arduino(); // permet de connecter le PC à Arduino
    int close_arduino(); // permet de femer la connexion
    int write_to_arduino( QByteArray ); // envoyer des données vers arduino
    QString read_from_arduino();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=6790;
static const quint16 arduino_uno_producy_id=29987;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;
int hum;// contenant les données lues à partir d'Arduino
};

#endif // ARDUINO_VOYAGE_H
