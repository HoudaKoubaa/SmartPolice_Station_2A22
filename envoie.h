#ifndef ENVOIE_H
#define ENVOIE_H
#include<QString>
#include<QSqlQueryModel>

class envoie
{
public:
    envoie();
    envoie(int,QString,QString,QString);
    bool ajouter_envoie();

        int Getidentifiant() { return identifiant; }
           void Setidentifiant(int val) { this->identifiant = val; }
           QString Getmail_destinataire() { return mail_destinataire; }
           void Setmail_destinataire(QString val) { this->mail_destinataire = val; }
           QString Getsujet() { return sujet; }
           void Setsujet(QString val) { this->sujet = val; }
           QString Getmessage() { return message; }
           void Setmessage(QString val) { this->message = val; }

private:
           int identifiant;
           QString mail_destinataire;
           QString  sujet;
           QString  message;

};

#endif // ENVOIE_H
