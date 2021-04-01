#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "violence.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tabview->setModel(etd.afficher());
    ui->comboBox->setModel(etd.afficher2());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_leBtAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->leId->text().toInt(); //convertir une chaine de caractére en un entier
    QString nom=ui->leNom->text();
    QString prenom=ui->lePrenom->text();
    QString email=ui->LeEmail->text();
    QString nomaccuse=ui->LeNomA->text();
    QString autre=ui->commentaire->text();
    int cin=ui->LeCin->text().toInt();
    int tel=ui->LeTel->text().toInt();


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    violence v(id,nom,prenom,email,tel,cin,nomaccuse,autre);
    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =v.ajouter();
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tabview->setModel(etd.afficher());
        ui->comboBox->setModel(etd.afficher2());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_leSupp_clicked()
{
    int id =ui->leIdSupp->text().toInt();
    bool test = etd.supprimer(id);
    if(test)
    {
        //refresh affichage
         ui->tabview->setModel(etd.afficher());
         ui->comboBox->setModel(etd.afficher2());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}






void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
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



void MainWindow::on_Modifier_2_clicked()
{
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

void MainWindow::on_Supprimer_clicked()
{
    int cin=ui->comboBox->currentText().toInt();
    bool test = etd.supprimer(cin);
    if(test)
    {
        //refresh affichage
         ui->tabview->setModel(etd.afficher());
         ui->comboBox->setModel(etd.afficher2());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}
