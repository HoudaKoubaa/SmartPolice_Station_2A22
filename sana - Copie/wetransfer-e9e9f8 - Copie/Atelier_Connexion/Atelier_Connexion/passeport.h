#ifndef PASSEPORT_H
#define PASSEPORT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QTableView>

class passeport
{
public:
    passeport();
    passeport(int,QString,QString,QString,QDate,QString,QString,QString,QString,QString);
    passeport(QString,QString,QString,QDate,QString,QString,QString,QString,QString);
    int get_id();
    QString get_sexe();
    QString get_raison();
    QString get_cin();
    QString get_mail();
    QString get_adresse();
    QString get_etat();
    QString get_traitement();
    QDate get_date_naissance();
    QString get_type();
    void set_id(int);
    void set_sexe(QString);
    void set_raison(QString);
    void set_cin(QString);
    void set_mail(QString);
    void set_adresse(QString);
    void set_etat(QString);
    void set_traitement(QString);
    void set_date_naissance(QDate);
    void set_type(QString);
    bool ajouter();
    passeport getByCin(QString c);
    QSqlQueryModel * afficher(QString,QString);
    bool supprimer(QString);
    bool modifier (QString);

private:
    int id;
    QString cin,sexe,raison,adresse,etat,mail,traitement,type;
    QDate date_naissance;
};

#endif // PASSEPORT_H
