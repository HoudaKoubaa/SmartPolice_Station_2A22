#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QSound>
#include "maintenance.h"


#include <QPrinter>
#include <QPrintDialog>

#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>

#include<QShortcut>
#include<QDesktopWidget>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     ui->tableV->setModel(V.afficherVehicule());

      ui->tableM->setModel(M.afficherMaintenance());
      update_id();


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pb_ajouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    QString matricule = ui->matricule->text();
    QString Type = ui->type->currentText();
    QString Nom_chauffeur = ui->nom_ch->text();
    QDateTime datesortie = ui->date->dateTime();


         //instancier un objet de la classe Vehicule en utilisant les informations saisies dans l interfaces
         Vehicule V(matricule,Type,Nom_chauffeur,datesortie);

         //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

         bool test =V.ajouterVehicule();

         if(test)//si requête executée ==>QMessageBox::information
         {

            //refresh affichage
             ui->tableV->setModel(V.afficherVehicule());
             update_id();
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
         }

         else //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_modifier_clicked()
{
    QString matricule = ui->matricule->text();
    QString Type = ui->type->currentText();
    QString Nom_chauffeur = ui->nom_ch->text();
    QString datesortie = ui->date->text();
    QSqlQuery qry;
    qry.prepare("update VEHICULEM  set MATRICULE='"+matricule+"',Type='"+Type+"',Nom_chauffeur='"+Nom_chauffeur+"',DATESORTIE='"+datesortie+"' where MATRICULE='"+matricule+"'");
    if(qry.exec())
    {
        ui->tableV->setModel(V.afficherVehicule());
        update_id();
        QMessageBox::critical(this,tr("Modifier"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }
}


void MainWindow::on_supr_2_clicked()
{

 QString sup = ui->sup_m->text();

 QSqlQuery query;

  query.prepare("alter table MAINTENANCE DROP CONSTRAINT FK");
  query.exec();

 query.prepare("Delete from MAINTENANCE where MATRICULE='"+sup+"'");
 query.exec();

query.prepare("Delete from VEHICULEM where MATRICULE='"+sup+"'");
     query.bindValue(0,"+sup+");
    if(query.exec())
    {
        ui->tableV->setModel(V.afficherVehicule());
          ui->tableM->setModel(M.afficherMaintenance());
         update_id();
        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),query.lastError().text());

    }


/*
    bool test = V.supprimerVehicule();
    if(test)
    {
        //refresh affichage
        ui->tableV->setModel(V.afficherVehicule());
        update_id();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
*/
}

void MainWindow::on_trier_clicked()

    {
         ui->tableV->setModel(V.AfficherTriematricule());
    }


void MainWindow::on_rech_textChanged(const QString &arg1)
{
       ui->tableV->setModel(V.rechercherNom_chauffeur(arg1));
}

void MainWindow::on_audio_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("D:\\maintenance\\sounds\\backgroundmusic.wav"));
    player->setVolume(50);
    player->play();

}

void MainWindow::on_ajouter_m_clicked()
{
    QString matricule = ui->comboBox->currentText();
    QString Type = ui->type_m->currentText();
    QString cout = ui->cout_m->text();
     QString etat = ui->etat->format();
     QDateTime datepanne = ui->date_m->dateTime();


         //instancier un objet de la classe Vehicule en utilisant les informations saisies dans l interfaces
        Maintenance M(matricule,Type,cout,etat,datepanne);

         //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

         bool test =M.ajouterMaintenance();

         if(test)//si requête executée ==>QMessageBox::information
         {

            //refresh affichage
             ui->tableM->setModel(M.afficherMaintenance());
             update_id();
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
         }

         else //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}



void MainWindow::on_suprimer_m_clicked()
{
    QString sup = ui->sup_m->text();

    QSqlQuery qry;
    qry.prepare("Delete from MAINTENANCE where MATRICULE='"+sup+"'");
    if(qry.exec())
    {
        ui->tableM->setModel(M.afficherMaintenance());
        update_id();

        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }
}



void MainWindow::on_trier_m_clicked()
{
      ui->tableM->setModel(M.AfficherTriecout());
}


void MainWindow::on_rech_m_textChanged(const QString &arg1)
{
    ui->tableM->setModel(M.recherchermatricule(arg1));
}




void MainWindow::on_modifier_m_clicked()
{
    {


        QString matricule = ui->comboBox->currentText();
        QString Type = ui->type_m->currentText();
        QString cout = ui->cout_m->text();
         QString etat = ui->etat->text();
         QString datepanne = ui->date_m->text();



        QSqlQuery qry;
        qry.prepare("update MAINTENANCE set MATRICULE='"+matricule+"',Type='"+Type+"',cout='"+cout+"',etat='"+etat+"',DATEPANNE='"+datepanne+"' where MATRICULE='"+matricule+"'");
        if(qry.exec())
        {
            ui->tableM->setModel(M.afficherMaintenance());

            QMessageBox::critical(this,tr("Modifier"),tr("l'opération est effectué avec succès"));
        }
        else
        {
            QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

        }
    }
}


void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("select matricule from VEHICULEM");
       querry->exec();
       m->setQuery(*querry);
ui->comboBox->setModel(m);
}




void MainWindow::on_pdf_clicked()
{
    {
        Maintenance M;

        QString text=M.apercu_pdf();
        ui->imp->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
       ui->imp->print(&printer);

    }
}

void MainWindow::on_tabWidget_tabBarClicked(int)
{
    ui->tableM->setModel(M.afficherMaintenance());
   update_id();
}
