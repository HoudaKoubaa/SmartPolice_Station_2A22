#include "violence.h"
#include<QSqlQuery>
#include<QDebug>

violence::violence()
{
id=0;
nom="";
prenom="";
email="";
cin=0;
tel=0;
nomaccuse="";
autre="";
//type="";
//preuve="";
}
violence ::violence(int id,QString nom,QString prenom,QString email,int tel,int cin,QString nomaccuse,QString autre)
                    {
                        this->id=id;
                        this->nom=nom;
                        this->prenom=prenom;
                        this->email=email;
                        this->tel=tel;
                        this->cin=cin;
                        this->nomaccuse=nomaccuse;
                        this->autre=autre;
                    }

 int violence::getId()
    {
     return id;
    }
QString violence:: getNom(){

   return nom;
 }
 QString violence::getPrenom()
 {
       return prenom;
 }

 QString violence::getEmail()
   {
                        return email;
   }
 int violence::getTel()
  {
        return tel;
  }
   int violence::getCIN()
   {
      return cin;
   }
  QString violence::getNomaccuse()
   {
     return nomaccuse;
    }
   QString violence::getAutre()
    {
                       return autre;
    }

void violence ::setId(int id)
{
    this->id=id;
}
void violence::setNom(QString nom)
{
    this->nom=nom;
}
void violence::setPrenom(QString prenom){
    this->prenom=prenom;
}
void violence::setEmail(QString email){
    this->email=email;
}

void violence::setTel(int Tel){
    this->tel=tel;
}
void violence::setCin(int cin){
     this->cin=cin;
 }

void violence::setNomaccuse(QString nomaccuse){
                        this->nomaccuse=nomaccuse;
                    }
void violence::setAutre(QString autre){
     this->autre=autre;
}
bool violence::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString tel1 = QString::number(tel);
    QString cin1 = QString::number(cin);
     //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into violance_arnaque(id_traffic,nom_traffic,prenom_traffic,email_traffic,cin_traffic,tel_traffic,nom_accuses,autre_tr)""values(:id, :nom , :prenom, :email, :cin, :tel, :nomaccuse, :autre)");

    //Création des variables liées
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
   query.bindValue(":tel",tel1);
   query.bindValue(":cin",cin1);
   query.bindValue(":nomaccuse",nomaccuse);
   query.bindValue(":autre",autre);

    return query.exec();//exec() envoie la requête pour l'exécution
}
QSqlQueryModel * violence::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from violance_arnaque");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traffic"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("cin"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("nomaccuse"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("autre"));
                        return model;
}

QSqlQueryModel * violence::afficher2()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select cin_traffic from violance_arnaque");

                        return model;
}


 bool violence::supprimer(int cin)
      {
     QSqlQuery query;
     QString res=QString::number(cin);
     query.prepare("Delete from violance_arnaque  where cin_traffic=:cin ");
     query.bindValue(":cin",res);
     return query.exec();

       }

