#include "acceuil.h"
#include "ui_acceuil.h"
#include "violence.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>
#include "chart.h"
#include "ui_chart.h"
#include"violence.h"
#include "accident.h"
#include "smtp.h"

Acceuil::Acceuil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Acceuil)
{
    ui->setupUi(this);
    //refrechir
    ui->tabview->setModel(etd.afficher());
    ui->tabview_2->setModel(etd.afficher());
    ui->comboBox->setModel(etd.afficher());
    //table accident
    ui->comboBox2->setModel(acciden.afficher2());
    ui->tabview2->setModel(acciden.afficher2());
    ui->tabviewcon->setModel(acciden.afficher2());
    ui->tabview_3->setModel(acciden.afficher2());



    player=new QMediaPlayer;
    //animation
    QPropertyAnimation *animation = new QPropertyAnimation(ui->logo, "geometry");
      animation->setDuration(4000);
      animation->setStartValue(ui->logo->geometry());
      animation->setStartValue(QRect(0, 0, 100, 30));
      animation->setEasingCurve(QEasingCurve::OutBounce);
      animation->start();
}

Acceuil::~Acceuil()
{
    delete ui;
}

void Acceuil::on_ajouter_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
    player->play();
    qDebug() << player->errorString();
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->leId->text().toInt(); //convertir une chaine de caractére en un entier
    QString nom=ui->leNom->text();
    QString prenom=ui->lePrenom->text();
    QString email=ui->LeEmail->text();
    QString nomaccuse=ui->LeNomA->text();
    QString autre=ui->commentaire->text();
    int cin=ui->LeCin->text().toInt();
    int tel=ui->LeTel->text().toInt();
    QString type="";

//type:
    if(ui->sex_2->isChecked())
    {
        type="sexuelle";
    }
    if(ui->phy_2->isChecked())
    {
        type="physique";
    }
    if(ui->psy_2->isChecked())
    {
        type="psychologique";
    }

    //tester les conditions :
  //  bool test2;
    //test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVideInt(tel)&&controleVideInt(cin)&&controleVideInt(id) );
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    violence v(id,nom,prenom,email,tel,cin,nomaccuse,autre,type);
    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =v.ajouter();
    if(test)//si requête executée ==>QMessageBox::information
    {
        //refresh affichage

        ui->comboBox->setModel(etd.afficher());
        ui->tabview->setModel(etd.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}


void Acceuil::on_Modifier_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
    player->play();
    qDebug() << player->errorString();

    QString cin=ui->comboBox->currentText();
     QString tel=ui->tell->text();
     QString  email=ui->emaill->text();
     QSqlQuery query;
    query.prepare("update violance_arnaque set tel_traffic='"+tel+"',email_traffic='"+email+"'where cin_traffic='"+cin+"'");
if(query.exec())
{
    //refresh affichage
     ui->tabview->setModel(etd.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("Modification effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void Acceuil::on_comboBox_currentIndexChanged(int)
{
       QString name=ui->comboBox->currentText();
         QSqlQuery query;

         query.prepare ("select tel_traffic,email_traffic  from violance_arnaque where cin_traffic='"+name+"'");
         if(query.exec())
         {
             while(query.next())
             {
                 ui->tell->setText(query.value(0).toString());
                 ui->emaill->setText(query.value(1).toString());
             }
         }
    }


void Acceuil::on_pushButton_tri_clicked()
{
player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
player->play();
qDebug() << player->errorString();
ui->tabview->setModel(etd.AfficherTrieCIN());
}



void Acceuil::on_LeIdRT_textChanged(const QString &arg1)
{
     ui->tabview->setModel(etd.rechercherCIN(arg1));
}

void Acceuil::on_Supprimer_clicked()
{
    int id =ui->supcin->text().toInt();
    bool test = etd.supprimer(id);
    if(test)
    {
        //refresh affichage
         ui->tabview_2->setModel(etd.afficher());
         ui->tabview->setModel(etd.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void Acceuil::on_stat_clicked()
{
    chartg=new chart(this);
    chartg->show();
}

// TABLE 2.
void Acceuil::on_leBtAjouter_clicked()
{
    //Récuprération des informations saisies dans les champs
    int id=ui->accid->text().toInt(); //convertir une chaine de caractére en un entier
    int tel=ui->tel->text().toInt();
    int cina=ui->LeCina->text().toInt();
    int vitesse=ui->vitesse->text().toInt();
    QString mat=ui->Mat->text();
    QString mat2=ui->Mat2->text();
    QString localisation=ui->loc->text();
    QString email=ui->Email->text();
     QDateTime date=ui->dateTimeEdit->dateTime();
     QString eclairage="";
     QString intensite="";
     QString etat="";
     QString consequence;
     QString genre;
  //test de checkbox
     //genre de route :
         if(ui->c1->isChecked())
         {
             genre="Autouroute";
         }
         if(ui->c2->isChecked())
         {
             genre="semi autouroute";
         }
         if(ui->c3->isChecked())
         {
             genre="install annexe sur autouroute";
         }
         if(ui->c4->isChecked())
         {
             genre="Route principale";
         }
         if(ui->c5->isChecked())
         {
             genre="Route seconde";
         }
         if(ui->c6->isChecked())
         {
             genre="Autre";
         }
         //consequence
           if(ui->c7->isChecked())
         {
             consequence="pas blesse";
         }
         if(ui->c8->isChecked())
         {
             consequence="Légérement blessé";
         }
         if(ui->c9->isChecked())
         {
             consequence="En danger de morts ";
         }
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    accident a(id,mat,email,cina,tel,mat2,localisation,consequence,genre,vitesse,intensite,etat,eclairage,date);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

    bool test =a.ajouter();
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tabview->setModel(acciden.afficher2());
        ui->comboBox2->setModel(acciden.afficher2());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
}


void Acceuil::on_Modifier_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
    player->play();
    qDebug() << player->errorString();

    QString cin=ui->comboBox2->currentText();
     QString tel=ui->tell->text();
     QString  email=ui->Email->text();
     QSqlQuery query;
    query.prepare("update TRAFFICS_DES_ACCIDENT set tel_acc='"+tel+"',email_acc='"+email+"'where cin_acc='"+cin+"'");
if(query.exec())
{
    //refresh affichage
     ui->tabview2->setModel(acciden.afficher2());
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("Modification effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void Acceuil::on_comboBox2_currentIndexChanged(int )
{
    QString name=ui->comboBox->currentText();
      QSqlQuery query;

      query.prepare ("select tel_acc,email_acc  from TRAFFICS_DES_ACCIDENT where cin_acc='"+name+"'");
      if(query.exec())
      {
          while(query.next())
          {
              ui->tel2->setText(query.value(0).toString());
              ui->email2->setText(query.value(1).toString());
          }
      }

}

void Acceuil::on_Supprimer_2_clicked()
{
    int id =ui->supcin_2->text().toInt();
    bool test = acciden.supprimer(id);
    if(test)
    {
        //refresh affichage
         ui->tabview_3->setModel(acciden.afficher2());
         ui->tabviewcon->setModel(acciden.afficher2());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void Acceuil::on_pushButton_17_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void Acceuil::on_pushButton_19_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);

}

void Acceuil::on_pushButton_clicked()
{
 ui->stackedWidget_2->setCurrentIndex(0);
}


void Acceuil::on_pushButton_mailing_2_clicked()
{
 ui->stackedWidget_2->setCurrentIndex(1);
}


void Acceuil::on_pushButton_envoyerMail_2_clicked()
{

    int identifiant=ui->lineEdit_de_2->text().toInt();
    QString mail_destinataire=ui->comboBox_aqui_2->currentText();
    QString sujet=ui->lineEdit_objet_3->text();
    QString message=ui->lineEdit_mail_2->text();

envoie e(identifiant,mail_destinataire,sujet,message);
bool test=e.ajouter_envoie();
QMessageBox msgBox;
if(test)
   { msgBox.setText("Message envoyer");
Smtp* smtp = new Smtp("houdakoubaa94@gmail.com","Sb50607010", "smtp.gmail.com");
smtp->sendMail("houdakoubaa94@gmail.com",ui->comboBox_aqui_2->currentText(),ui->lineEdit_objet_3->text(),ui->lineEdit_mail_2->text());
  ui->comboBox_aqui_2->clear();
  ui->lineEdit_objet_3->clear();
  ui->lineEdit_mail_2->clear();
}
else
    msgBox.setText("Echec d'envoie");
    msgBox.exec();
}
