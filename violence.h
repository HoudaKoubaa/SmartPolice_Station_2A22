#ifndef VIOLENCE_H
#define VIOLENCE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class violence
{
public:
    violence();
    violence(int,QString,QString,QString,int,int,QString,QString);
    //getters
    int getId();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    int getCIN();
    int getTel();
    QString getNomaccuse();
    //bool getType();
    QString getAutre();


    //Setters
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setEmail(QString);
    void setCin(int);
    void setTel(int);
    void setNomaccuse(QString);
    //void setType(bool);
    void setAutre(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    bool supprimer(int);


private:
    int id,tel,cin;
    QString nom,prenom,email,nomaccuse,autre;

};

#endif // VIOLENCE_H
