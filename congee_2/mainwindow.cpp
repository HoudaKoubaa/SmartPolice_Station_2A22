#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include "conge.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(C.afficherConge());
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
       ui->comboBox->setModel(m);

}

void MainWindow::on_pushButtonAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs


    int id=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entier
    QDateTime debut_conge=ui->dateEdit->dateTime();
    QDateTime fin_conge=ui->dateEdit_2->dateTime();
    int id2=ui->comboBox->currentText().toInt(); //convertir une chaine de caractére en un entier


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Conge C(id,debut_conge,fin_conge,id2);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

    bool test =C.ajouterConge();

    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(C.afficherConge());
        update_id();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }

    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButtonModifier_clicked()
{
    //Récuprération des informations saisies dans les 3 champs


    QDateTime debut_conge=ui->dateEdit->dateTime();
    QDateTime fin_conge=ui->dateEdit_2->dateTime();
    int id2=ui->comboBox->currentText().toInt(); //convertir une chaine de caractére en un entier

       //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
            Conge C(id_con,debut_conge,fin_conge,id2);

       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
       bool test =C.modifierConge();



       if(test)//si requête executée ==>QMessageBox::information
       {

          //refresh affichage
           ui->tableView->setModel(C.afficherConge());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                   QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
       }
       else //si requête non exécutée ==>QMessageBox::critical
           QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_pushButtonSupprimer_clicked()
{

                    bool test = C.supprimerConge(id_con);
                    if(test)
                    {
                        //refresh affichage
                        ui->tableView->setModel(C.afficherConge());
                        update_id();

                        QMessageBox::information(nullptr,QObject::tr("ok"),
                                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

                    }
                    else
                        QMessageBox::critical(nullptr,QObject::tr("not ok"),

             QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
  ui->tableView->setModel(C.AfficherTrieID());
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->tableView->setModel(C.AfficherTrieDate_debut());
}

void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
 ui->tableView->setModel(C.rechercherID(arg1));
}

void MainWindow::on_LeTitreRT_textChanged(const QString &arg1)
{
   ui->tableView->setModel(C.rechercherID_emp(arg1));
}
//conge(id_conge,id_emp,debut_conge,fin_conge)
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from conge where"
                          " id_conge='"+val+"' or cin_emp='"+val+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->LeId->setText(qry.value(0).toString());
                 ui->dateEdit->setDateTime(qry.value(1).toDateTime());
                 ui->dateEdit_2->setDateTime(qry.value(2).toDateTime());
                 ui->comboBox->setCurrentText(qry.value(3).toString());

                }

}
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id_con=ui->tableView->model()->data(index).toInt();

}
