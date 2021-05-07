#ifndef ATTESTATION_H
#define ATTESTATION_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QTableView>

class attestation
{
public:
    attestation();
    attestation(int,QString,QString,QString,QString,QString,QString,QDate,QString);
    attestation(QString,QString,QString,QString,QString,QString,QDate,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_cin();
    QString get_mail();
    QString get_objet();
    QString get_description();
    QString get_lieu();
    QString  apercu_pdf();
    QDate get_date_attestation();
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);
    void set_cin(QString);
    void set_mail(QString);
    void set_objet(QString);
    void set_description(QString);
    void set_lieu(QString);
    void set_date_attestation(QDate);
    bool ajouter();
    attestation getByCin(QString c);
    QSqlQueryModel * afficher(QString,QString);
    bool supprimer(QString);
    bool modifier (QString);
private:
    int id;
    QString nom,prenom,mail,cin,objet,caracteristique,lieu;
    QDate date_attestation;
};

#endif // ATTESTATION_H
