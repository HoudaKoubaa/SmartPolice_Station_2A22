#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "assistance.h"
#include "citoyen.h"
#include "rdv.h"
#include "arduino.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QSound>
#include<QDate>
#include "QDebug"
#include<QIntValidator>
#include <QComboBox>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QDateEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }


}

MainWindow::~MainWindow()
{


    delete ui;

}



void MainWindow::on_pb_ajouter_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

    int CIN_assis = ui->le_cin_assis->text().toInt();
     ui->le_cin_assis->setMaxLength(8);
    int numero_assis = ui->le_numero_tele->text().toInt();
    QString date_consultation = ui->le_date->date().toString("dd/MM/yyyy");

    QString nom_assis= ui->le_nom_assis->text();
    QString prenom_assis = ui->le_prenom_assis->text();
    QString type_consultation = ui->le_type_consultation->currentText();


    Assistance A(CIN_assis, nom_assis, prenom_assis,numero_assis, date_consultation,type_consultation);

    if((prenom_assis=="")&&(nom_assis=="")&&(type_consultation=="")&&(CIN_assis==0)&&(date_consultation=="")&&(numero_assis==0))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
    //       else if(((numCin>=99999999) && (numCin<=9999999)) )
    //          {
    //              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
    //                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

    //          }
       else if(CIN_assis == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

        }
            else if(nom_assis =="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir le nom d'assistance"), QMessageBox::Ok);

               }
          else if(prenom_assis =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom d'assistance"), QMessageBox::Ok);

             }
            else if(date_consultation=="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date de consultation"), QMessageBox::Ok);

               }
          else if(type_consultation =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le type de consultation"), QMessageBox::Ok);

             }

          else if(numero_assis ==0)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le numero de telephone"), QMessageBox::Ok);

             }

    else {

        if(A.ajouter_consultation())
              {
                   ui->tableAssistance->setModel(tmpassistance.afficher());
                   QMessageBox::information(nullptr, QObject::tr("BIEN"),
                               QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                           ui->le_cin_assis->setText("");
                           ui->le_nom_assis->setText("");
                           ui->le_prenom_assis->setText("");
                           ui->le_numero_tele->setText("");
                           ui->le_date->date().toString();




              }else{
                      QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                  QObject::tr("Citoyen existe déja.\n"), QMessageBox::Cancel);
                  }


    }


}


    /*************************************************************************/




















/*************************************************************************
 * *****************************************************************
 * **************************************************/

void MainWindow::on_ajouter_citoyen_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

 int cin = ui->le_cin->text().toInt() ;
  ui->le_cin->setMaxLength(8);

 QString nom = ui->le_nom->text();
 ui->le_nom->setMaxLength(15);

 QString prenom = ui->le_prenom->text();
 ui->le_prenom->setMaxLength(15);
 int numero_tele = ui->le_numero->text().toInt();
 QString daten = ui->le_daten1->date().toString("dd/MM/yyyy");
 QString sexe = ui->le_sexe1->currentText();
 QString remarque = ui->le_remarque->text();


Citoyen c(cin , nom , prenom, numero_tele , daten , sexe , remarque);

if((prenom=="")&&(nom=="")&&(sexe=="")&&(cin==0)&&(remarque=="")&&(daten==""))
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
       }
       /* else if( (cin>=10000000) && (cin<999999999) )
         {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

          }*/
   else if(cin == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

    }
        else if(nom =="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

           }
      else if(prenom =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le prénom"), QMessageBox::Ok);

         }
        else if(daten=="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir la date de naissance"), QMessageBox::Ok);

           }
      else if(sexe =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez choisir le sexe"), QMessageBox::Ok);

         }

      else if(remarque =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le remarque"), QMessageBox::Ok);

         }

else {

    if(c.ajouter())
          {
               ui->tableCitoyen->setModel(tmpcitoyen.afficher());
             QMessageBox::information(nullptr, QObject::tr("BIEN"),
                         QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                     ui->le_cin->setText("");
                     ui->le_nom->setText("");
                     ui->le_prenom->setText("");
                     ui->le_numero->setText("");
                     //ui->le_daten11->date().toString();
                     //ui->le_sexe11->currentText();
                     ui->le_remarque->setText("");


        }else{
                QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                            QObject::tr("Citoyen existe déja.\n"), QMessageBox::Cancel);
            }


}


}

/*************************************************************************/


void MainWindow::on_pb_supp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(300);
               player->play();

    int cin = ui->le_cin_supp->text().toInt();
    bool test=tmpcitoyen.supprimer(cin);
    if(test)
    {ui->tableCitoyen->setModel(tmpcitoyen.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un citoyen"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_cin_supp->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un citoyen"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





/**********************************************************************************/




void MainWindow::on_modifier_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
    player->setVolume(3000);
    player->play();

       int cin=ui->le_cin2->text().toInt();
       QString nom=ui->le_nom2->text();
       QString prenom=ui->le_prenom2->text();
       int numero_tele=ui->le_numero2->text().toInt();
       QString daten=ui->le_daten11->date().toString("dd/MM/yyyy");
       QString sexe=ui->le_sexe11->currentText();
       QString remarque=ui->le_remarque_2->text();

       Citoyen c (cin, nom , prenom, numero_tele , daten , sexe , remarque);
       if((prenom=="")&&(nom=="")&&(sexe=="")&&(cin== 0)&&(remarque=="")&&(daten==""))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
         else if(cin == 0)
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

          }
          else if(prenom =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom"), QMessageBox::Ok);

             }
          else if(nom =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

             }
          else if(sexe =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le sexe"), QMessageBox::Ok);

             }

          else if(remarque =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir l'activité"), QMessageBox::Ok);

             }
       else if(daten=="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir la date de naissance"), QMessageBox::Ok);

          }
       else {

           if(c.modifier(cin))
           {
                    QMessageBox::information(nullptr, QObject::tr("Modifier un Citoyen"),
                                QObject::tr("citoyen modifié.\n"), QMessageBox::Cancel);

                    ui->le_cin2->setText("");
                    ui->le_nom2->setText("");
                    ui->le_prenom2->setText("");
                    ui->le_numero2->setText("");
                    //ui->le_daten11->date().toString();
                    //ui->le_sexe11->currentText();
                    ui->le_remarque_2->setText("");

           }
           else
           {
              QMessageBox::critical(nullptr, QObject::tr("Modifier un Citoyen"),

                                    QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
           }
       }

}

/************************************************************************/

void MainWindow::on_tri_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
     player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
     player->setVolume(3000);
     player->play();

      ui->tableCitoyen->setModel(tmpcitoyen.AfficherTrieNom());
}

void MainWindow::on_le_cin_supp_textChanged(const QString &arg1)
{
    ui->tableCitoyen->setModel(tmpcitoyen.rechercherNom(arg1));
}

/************************************************************************/

void MainWindow::on_pb_consultation_supp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

    int cin = ui->le_consultation_supp->text().toInt();
    bool test=tmpassistance.supprimer(cin);
    if(test)
    {ui->tableAssistance->setModel(tmpassistance.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimerune consultation"),
                    QObject::tr("Consultation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_consultation_supp->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une consultation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


/********************************************************************************/


void MainWindow::on_pb_consultation_modifier_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

    int CIN_assis = ui->le_cin_assis2->text().toInt();
     ui->le_cin_assis->setMaxLength(8);
    int numero_assis = ui->le_numero2_2->text().toInt();
    QString date_consultation = ui->le_date2->date().toString("dd/MM/yyyy");

    QString nom_assis= ui->le_nom_assis2->text();
    QString prenom_assis = ui->le_prenom_assis2->text();
    QString type_consultation = ui->le_type_consultation2->currentText();

    Assistance A(CIN_assis, nom_assis, prenom_assis,numero_assis, date_consultation,type_consultation);

    if((prenom_assis=="")&&(nom_assis=="")&&(type_consultation=="")&&(CIN_assis==0)&&(date_consultation=="")&&(numero_assis==0))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
    //       else if(((numCin>=99999999) && (numCin<=9999999)) )
    //          {
    //              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
    //                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

    //          }
       else if(CIN_assis == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

        }
            else if(nom_assis =="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir le nom d'assistance"), QMessageBox::Ok);

               }
          else if(prenom_assis =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom d'assistance"), QMessageBox::Ok);

             }
            else if(date_consultation=="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date de consultation"), QMessageBox::Ok);

               }
          else if(type_consultation =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le type de consultation"), QMessageBox::Ok);

             }

          else if(numero_assis ==0)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le numero de telephone"), QMessageBox::Ok);

             }

    else {


        if(A.modifier(CIN_assis))
        {
                 QMessageBox::information(nullptr, QObject::tr("Modifier une consultation"),
                             QObject::tr("consultation modifié.\n"), QMessageBox::Cancel);

                 ui->le_cin_assis2->setText("");
                 ui->le_nom_assis2->setText("");
                 ui->le_prenom_assis2->setText("");
                 ui->le_numero2_2->setText("");
                 ui->le_date2->date().toString();
                 ui->le_type_consultation2->currentText();

        }
        else
        {
           QMessageBox::critical(nullptr, QObject::tr("Modifier une consultation"),

                                 QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }
    }

}

/*****************************************************************************/



void MainWindow::on_pb_tri_consultation_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

    ui->tableAssistance->setModel(tmpassistance.AfficherTrieNom());
}

void MainWindow::on_le_consultation_supp_textChanged(const QString &arg1)
{
     ui->tableAssistance->setModel(tmpassistance.rechercherNom(arg1));

}


/********************************************************************************/


void MainWindow::on_affec_citoyen_clicked()
{

    rdv V;
    ui->le_citoyen_affec->setModel(V.affecter_citoyen());
    ui->le_assis_affec->setModel(V.affecter_assistance());

}

void MainWindow::on_le_citoyen_affec_currentTextChanged(const QString &arg1)
{

}

/*********************************************************************************/


void MainWindow::on_pb_enregistrer_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

 int id_rdv = ui->le_id_rdv->text().toInt() ;
 ui->le_id_rdv->setMaxLength(8);

 QString nom_citoyen = ui->le_citoyen_affec->currentText();

 QString nom_assis = ui->le_assis_affec->currentText();
 QDateTime date_rdv = ui->le_date_RDV->dateTime();

 QString type_rdv = ui->le_type_RDV->currentText();



rdv v (id_rdv, nom_citoyen,nom_assis ,date_rdv, type_rdv );
QDateTime system_date = QDateTime::currentDateTime();

if((nom_citoyen=="")&&(nom_assis=="")&&(date_rdv<=system_date)&&(id_rdv==0)&&(type_rdv==""))
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
       }


   else if(id_rdv == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Veuillez remplir le numéro de id de rdv"), QMessageBox::Ok);

    }
        else if(nom_citoyen =="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le nom citoyen"), QMessageBox::Ok);

           }
      else if(nom_assis =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le nom assis"), QMessageBox::Ok);

         }
        else if(date_rdv<=system_date)
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Vérifier le date de RDV!!!"), QMessageBox::Ok);

           }
      else if(type_rdv =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez choisir le type de rdv"), QMessageBox::Ok);

         }


else {

    if(v.ajouter())
          {
               ui->tableRDV->setModel(v.afficher());
             QMessageBox::information(nullptr, QObject::tr("BIEN"),
                         QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                     ui->le_id_rdv->setText("");



        }else{
                QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                            QObject::tr("rdv existe déja.\n"), QMessageBox::Cancel);
            }


}



}

/*******************************************************************************************/


void MainWindow::on_print_clicked()
{
    QPrinter print;
    print.setPrinterName("imprimer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableRDV->render(&print);
}

/***********************************************************************************************/
void MainWindow::on_pb_supp_rdv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(300);
               player->play();

    int id_rdv = ui->le_rdv_supp->text().toInt();
    bool test=tmprdv.supprimer(id_rdv);
    if(test)
    {ui->tableRDV->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("rdv supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_rdv_supp->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


/***************************************************************************************************/

void MainWindow::on_trie_rdv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/music/sound.mp3"));
               player->setVolume(3000);
               player->play();

    ui->tableRDV->setModel(tmprdv.AfficherTrieId());
}

void MainWindow::on_le_rdv_supp_textChanged(const QString &arg1)
{
    ui->tableRDV->setModel(tmprdv.rechercherId(arg1));
}


/**********************************************************************************************************/

void MainWindow::on_pb_open_clicked()
{
    Arduinoo A;
    A.write_to_arduino("1"); //envoyer 1 à arduino voiture entrer
}

void MainWindow::on_pb_close_clicked()
{ Arduinoo A;
  A.write_to_arduino("0"); //envoyer 0 à arduino
}

