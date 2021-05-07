#include "passeport.h"
#include <QSqlQuery>
passeport::passeport()
{

}
passeport::passeport(int i,QString cin,QString traitement,QString raison,QDate d,QString sexe,QString etat,QString adresse,QString mail,QString type)
{
this->id=i;
this->cin=cin;
this->traitement=traitement;
this->raison=raison;
this->date_naissance=d;
this->sexe=sexe;
this->etat=etat;
this->adresse=adresse;
this->mail=mail;
this->type=type;
}
passeport::passeport(QString cin,QString traitement,QString raison,QDate d,QString sexe,QString etat,QString adresse,QString mail,QString type)
{
this->cin=cin;
this->traitement=traitement;
this->raison=raison;
this->date_naissance=d;
this->sexe=sexe;
this->etat=etat;
this->adresse=adresse;
this->mail=mail;
this->type=type;
}
int passeport::get_id(){return this->id;}
QString passeport::get_sexe(){return this->sexe;}
QString passeport::get_raison(){return this->raison;}
QString passeport::get_cin(){return this->cin;}
QString passeport::get_mail(){return this->mail;}
QString passeport::get_adresse(){return this->adresse;}
QString passeport::get_etat(){return this->etat;}
QString passeport::get_traitement(){return this->traitement;}
QDate passeport::get_date_naissance(){return this->date_naissance;}
QString passeport::get_type(){return this->type;}
void passeport::set_id(int i){this->id=i;}
void passeport::set_sexe(QString s){this->sexe=s;}
void passeport::set_raison(QString r){this->raison=r;}
void passeport::set_cin(QString c){this->cin=c;}
void passeport::set_mail(QString m){this->mail=m;}
void passeport::set_adresse(QString a){this->adresse=a;}
void passeport::set_etat(QString e){this->etat=e;}
void passeport::set_traitement(QString t){this->traitement=t;}
void passeport::set_date_naissance(QDate d){this->date_naissance=d;}
void passeport::set_type(QString t){this->type=t;}
bool passeport::ajouter()
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("INSERT INTO passeport (cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type)"
                  "VALUES (:cin, :t, :r, :d, :s, :e, :a,:m,:type)");
    query.bindValue(":cin",cin);
    query.bindValue(":t",traitement);
    query.bindValue(":r",raison);
    query.bindValue(":d",date_naissance);
    query.bindValue(":s",sexe);
    query.bindValue(":e",etat);
    query.bindValue(":a",adresse);
    query.bindValue(":m",mail);
    query.bindValue(":type",type);
    return query.exec();
}

QSqlQueryModel * passeport::afficher(QString ch,QString t)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(ch=="" && t=="")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport");
    else if(ch=="" && t=="ordre croissant")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport order by date_naissance ASC");
    else if(ch=="" && t=="ordre decroissant")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport order by date_naissance DESC");
    else if(ch!="" && t=="ordre croissant")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport where cin like '"+ch+"%' order by date_naissance ASC");
    else if(ch!="" && t=="ordre decroissant")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport where cin like '"+ch+"%' order by date_naissance DESC");
    else if(ch!="" && t=="")
    model->setQuery("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport where cin like '"+ch+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TRAITEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("RAISON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT_CIVIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

bool passeport::modifier(QString c)
{
    QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Update passeport set cin = :cin ,traitement = :t ,raison= :r,date_naissance= :d ,sexe= :s,etat_civil =:e,adress =:a,mail =:m,type=:type where cin=:c");
    query.bindValue(":cin",cin);
    query.bindValue(":t",traitement);
    query.bindValue(":r",raison);
    query.bindValue(":d",date_naissance);
    query.bindValue(":s",sexe);
    query.bindValue(":e",etat);
    query.bindValue(":a",adresse);
    query.bindValue(":m",mail);
    query.bindValue(":type",type);
    query.bindValue(":c",c);
    return query.exec();

}
bool passeport::supprimer(QString c)
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("Delete from passeport where cin = :c ");
    query.bindValue(":c", c);
    return    query.exec();
}
passeport passeport::getByCin(QString c)
{
    QSqlQuery q;
        q.prepare("select cin,traitement,raison,date_naissance,sexe,etat_civil,adress,mail,type from passeport where cin = :cinn ");
        q.bindValue(":cinn", c);
        q.exec();
        q.first();
       passeport p(q.value(0).toString(),q.value(1).toString(),q.value(2).toString(),q.value(3).toDate(),q.value(4).toString(),q.value(5).toString(),q.value(6).toString(),q.value(7).toString(),q.value(8).toString());
       return p;
}
