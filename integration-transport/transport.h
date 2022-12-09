#ifndef TRANSPORT_H
#define TRANSPORT_H
#include<QString>
#include<QSqlQueryModel>
class transport
{
public:
    transport();
    transport(int,QString,QString,float,int);
    int getMat();
    QString gettype();
    QString getnomcompagnie();
    float getprix();
    int getnbplace();
    void setMat(int); 
    void settype(QString);
    void setnomcompagnie(QString);
    void setprix(float);
    void setnbplace(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,float,int);
    QSqlQueryModel * AfficherTrieMat();
    QSqlQueryModel * AfficherTrietype();
    QSqlQueryModel * AfficherTrieprix();
    QSqlQueryModel * rechercherMat(QString);

    void incrParking();
    void decrParking();
    QString count();

private:
    int Mat;
    QString type;
    float prix;
    QString nomcompagnie;
    int nbplace;

};

#endif // TRANSPORT_H
