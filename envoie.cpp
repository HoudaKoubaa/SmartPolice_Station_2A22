#include "envoie.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
envoie::envoie()
{
    identifiant=0;
   mail_destinataire="";
   sujet="";
   message="";
}
envoie:: envoie(int id,QString mail,QString sujet,QString msg)
{this->identifiant=id;
   this-> mail_destinataire=mail;
  this->  sujet=sujet;
   this-> message=msg;

}


bool envoie::ajouter_envoie()
{
    QSqlQuery query;
    QString id_string=QString::number(identifiant);
     query.prepare("INSERT INTO email (identifiant, mail_destinataire, sujet, message) "
                       "VALUES (:identifiant, :mail_destinataire, :sujet, :message)");
         query.bindValue(":identifiant", id_string);
         query.bindValue(":mail_destinataire", mail_destinataire);
         query.bindValue(":sujet", sujet);
         query.bindValue(":message", message);


    return  query.exec();
}
