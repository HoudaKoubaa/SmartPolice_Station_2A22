#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include <QPrinter>
#include <QPrintDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(emp.afficherEmployes());
    update_id();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cin_emp FROM employes");
       querry->exec();
       m->setQuery(*querry);

}

void MainWindow::on_pushButtonAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entie

      QString nom=ui->Lenom->text();
      QString prenom=ui->Leprenom->text();
      QString grade=ui->comboBox->currentText();
      QDateTime date=ui->dateEdit->dateTime();
      QString mdp=ui->lemdp->text();
      QString email=ui->leemail->text();


      //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
      Employes E(id,nom,prenom,grade,date,mdp,email);

      //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

      bool test =E.ajouterEmployes();

      if(test)//si requête executée ==>QMessageBox::information
      {

         //refresh affichage
          ui->tableView->setModel(emp.afficherEmployes());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_pushButtonSupprimer_clicked()
{

                bool test = emp.supprimerEmployes(id_emp);
                if(test)
                {
                    //refresh affichage
                    ui->tableView->setModel(emp.afficherEmployes());
                    update_id();

                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr,QObject::tr("not ok"),

         QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButtonModifier_clicked()
{

    //Récuprération des informations saisies dans les 3 champs
    QString nom=ui->Lenom->text();
    QString prenom=ui->Leprenom->text();
    QString grade=ui->comboBox->currentText();
    QDateTime date=ui->dateEdit->dateTime();
    QString mdp=ui->lemdp->text();
    QString email=ui->leemail->text();

    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
     Employes E(id_emp,nom,prenom,grade,date,mdp,email);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =E.modifierEmployes();



    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(emp.AfficherTrieCIN());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(emp.AfficherTrieNom());
}

void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherCIN(arg1));
}

void MainWindow::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherNom(arg1));
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from Employes where"
                      " cin_emp='"+val+"' or nom_emp='"+val+"' or prenom_emp='"+val+"' or grade='"+val+"' or email ='"+val+"' or mot_de_passe='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->LeId->setText(qry.value(0).toString());
             ui->Lenom->setText(qry.value(1).toString());
             ui->Leprenom->setText(qry.value(2).toString());
             ui->comboBox->setCurrentText(qry.value(3).toString());
             ui->leemail->setText(qry.value(6).toString());
             ui->lemdp->setText(qry.value(5).toString());
             ui->dateEdit->setDateTime(qry.value(4).toDateTime());

           }
            }

}





void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id_emp=ui->tableView->model()->data(index).toInt();
}


void MainWindow::on_Impdos_2_clicked()
{
    Employes c;

                 QString text=c.apercu_pdf();
                 ui->imp->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                 ui->imp->print(&printer);
}

