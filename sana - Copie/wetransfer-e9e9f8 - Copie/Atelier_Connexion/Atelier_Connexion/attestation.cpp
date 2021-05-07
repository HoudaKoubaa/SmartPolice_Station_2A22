#include "attestation.h"
#include <QSqlQuery>
#include<QLineEdit>
#include <QFileDialog>
attestation::attestation()
{
  cin="";
  nom="";
  prenom="";

}

attestation::attestation(int id,QString nom,QString prenom,QString cin,QString mail,QString objet,QString desc,QDate d,QString lieu)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->mail=mail;
    this->objet=objet;
    this->caracteristique=desc;
    this->date_attestation=d;
    this->lieu=lieu;
}
attestation::attestation(QString nom,QString prenom,QString cin,QString mail,QString objet,QString desc,QDate d,QString lieu)
{
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->mail=mail;
    this->objet=objet;
    this->caracteristique=desc;
    this->date_attestation=d;
    this->lieu=lieu;
}
int attestation::get_id(){return id;}
QString attestation::get_nom(){return nom;}
QString attestation::get_prenom(){return prenom;}
QString attestation::get_cin(){return cin;}
QString attestation::get_lieu(){return lieu;}
QString attestation::get_mail(){return mail;}
QString attestation::get_description(){return caracteristique;}
QString attestation::get_objet(){return objet;}
QDate attestation::get_date_attestation(){return date_attestation;}
void attestation::set_id(int i){this->id=i;}
void attestation::set_nom(QString n){this->nom=n;}
void attestation::set_prenom(QString p){this->prenom=p;}
void attestation::set_cin(QString c){this->cin=c;}
void attestation::set_mail(QString m){this->mail=m;}
void attestation::set_objet(QString o){this->objet=o;}
void attestation::set_description(QString d){this->caracteristique=d;}
void attestation::set_lieu(QString l){this->lieu=l;}
void attestation::set_date_attestation(QDate d){this->date_attestation=d;}

bool attestation::ajouter()
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("INSERT INTO attestation (cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation)"
                  "VALUES (:cin, :nom, :prenom, :mail, :objet, :description, :lieu,:date)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":objet",objet);
    query.bindValue(":description",caracteristique);
    query.bindValue(":lieu",lieu);
    query.bindValue(":date",date_attestation);
    return query.exec();
}

QSqlQueryModel * attestation::afficher(QString ch,QString t)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(ch=="" && t=="")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation");
    else if(ch=="" && t=="ordre croissant")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation order by date_attestation ASC");
    else if(ch=="" && t=="ordre decroissant")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation order by date_attestation DESC");
    else if(ch!="" && t=="ordre croissant")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation where cin like '"+ch+"%' order by date_attestation ASC");
    else if(ch!="" && t=="ordre decroissant")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation where cin like '"+ch+"%' order by date_attestation DESC");
    else if(ch!="" && t=="")
    model->setQuery("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation where cin like '"+ch+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("OBJET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CARACTERISTIQUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE_ATTESTATION"));
    return model;
}

bool attestation::modifier(QString c)
{
    QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Update attestation set cin = :cin ,nom = :nom ,prenom= :prenom ,mail= :mail ,objet= :objet,caracteristique =:desc,lieu =:lieu,date_attestation =:d where cin=:c");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":objet",objet);
    query.bindValue(":desc",caracteristique);
    query.bindValue(":lieu",lieu);
    query.bindValue(":d",date_attestation);
    query.bindValue(":c",c);
    return query.exec();

}
bool attestation::supprimer(QString c)
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("Delete from attestation where cin = :c ");
    query.bindValue(":c", c);
    return    query.exec();
}
attestation attestation::getByCin(QString c)
{
    QSqlQuery q;
        q.prepare("select cin,nom,prenom,mail,objet,caracteristique,lieu,date_attestation from attestation where cin = :cinn ");
        q.bindValue(":cinn", c);
        q.exec();
        q.first();
       attestation a(q.value(1).toString(),q.value(2).toString(),q.value(0).toString(),q.value(3).toString(),q.value(4).toString(),q.value(5).toString(),q.value(7).toDate(),q.value(6).toString());
       return a;
}

QString attestation:: apercu_pdf()
     {
        QString text="          ****** attestation  ******      \n \n " ;
         QSqlQuery query ;
         QString i,x,z,a,b,c;


          query.exec("select * from attestation ");
          while (query.next())
          {
             i=query.value(0).toString();
             x=query.value(1).toString();
             z=query.value(2).toString();
             a=query.value(3).toString();
             c=query.value(4).toString();

             b=query.value(5).toString();


text += "\n  -cin : "+i+"\n\n - nom : "+ x+"\n - prenom : "+ z+"\n - mail :"+a+"\n - objet:"+c+ "\n - caractéristiques :"+b+ "\n\n" ;
          }   return text ;

}
