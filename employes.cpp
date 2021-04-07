#include "employes.h"
#include<QSqlQuery>
#include<QDebug>

Employes::Employes()
{

 this->cin=0;
 this->nom="";
 this->prenom="";
 this->grade="";
 this->mdp="";
 this->email="";

}

Employes::Employes(int cin ,QString nom,QString prenom,QString grade,QDateTime date,QString mdp,QString email)
 {
     this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
     this->grade=grade;
     this->date=date;
     this->mdp=mdp;
     this->email=email;

 }


int Employes::getId()
 {
     return cin;
 }

QString Employes:: getNom(){

   return nom;
 }

QString Employes::getPrenom()
 {
       return prenom;
 }

QString Employes::getEmail()
 {
       return email;
 }
QString Employes::getMdp()
 {
       return mdp;
 }
QString Employes::getGrade()
 {
       return grade;
 }
QDateTime Employes::getDate()
 {
       return date;
 }


void Employes ::setId(int id)
{
    this->cin=id;
}

void Employes::setNom(QString nom)
{
    this->nom=nom;
}

void Employes::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Employes::setGrade(QString grade){
    this->grade=grade;
}

void Employes::setEmail(QString email){
    this->email=email;
}

void Employes::setDate(QDateTime date){
    this->date=date;
}

void Employes::setMdp(QString mdp){
    this->mdp=mdp;
}


bool Employes::ajouterEmployes()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Employes(cin_emp,nom_emp,prenom_emp,grade,date_naissance,mot_de_passe,email)""values(:cin_emp,:nom_emp,:prenom_emp,:grade,:date_naissance,:mot_de_passe,:email)");

    //Création des variables liées
    query.bindValue(":cin_emp",res);
    query.bindValue(":nom_emp",nom);
    query.bindValue(":prenom_emp",prenom);
    query.bindValue(":grade",grade);
    query.bindValue(":date_naissance",date);
    query.bindValue(":mot_de_passe",mdp);
    query.bindValue(":email",email);

    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Employes::afficherEmployes()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from employes");
return model;

}

bool Employes::supprimerEmployes(int idA)
{



                      QSqlQuery query;
                                 QString res=QString::number(idA);

                               /*  query.prepare("alter table conge DROP CONSTRAINT FK");
                                 query.exec();*/

                                 query.prepare("Delete from conge where cin_emp=:idA");
                                 query.bindValue(":idA",res);
                                 query.exec();

                                 query.prepare("Delete from employes where cin_emp=:idA");
                                 query.bindValue(":idA",res);
                                 return query.exec();
}

bool Employes::modifierEmployes()
{
    QSqlQuery query ;
    QString res = QString::number(cin);

    query.prepare("UPDATE employes set cin_emp=:cin_emp,nom_emp=:nom_emp,prenom_emp=:prenom_emp,grade=:grade,date_naissance=:date_naissance,mot_de_passe=:mot_de_passe,email=:email WHERE cin_emp=:cin_emp");

    //Création des variables liées
    query.bindValue(":cin_emp",res);
    query.bindValue(":nom_emp",nom);
    query.bindValue(":prenom_emp",prenom);
    query.bindValue(":grade",grade);
    query.bindValue(":date_naissance",date);
    query.bindValue(":mot_de_passe",mdp);
    query.bindValue(":email",email);
    return query.exec();
}


QSqlQueryModel * Employes::AfficherTrieCIN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Employes ORDER BY grade");
    return model;
}


QSqlQueryModel * Employes::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes ORDER BY nom_emp");
    return model;
}


QSqlQueryModel * Employes::rechercherCIN(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where cin_emp like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}


QSqlQueryModel * Employes::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where nom_emp like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

