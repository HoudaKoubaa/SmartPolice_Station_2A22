#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "affichage.h"
#include <QMessageBox>
#include "connection.h"
#include<QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    QString matricule = ui->lineEdit->text();
    QString Type = ui->comboBox->currentText();
    QString Nom_chaffeur = ui->lineEdit_3->text();
    QDate date_sortie = ui->dateEdit->date();

    affichage affich;
    affich.setModal(true);
    affich.setData(matricule,Type,Nom_chaffeur,date_sortie);

    affich.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Connection c;
    QString matricule = ui->lineEdit->text();
    QString Type = ui->comboBox->currentText();
    QString Nom_chaffeur = ui->lineEdit_3->text();
    QString date_sortie = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("insert into VEHICULEM (MATRICULE,TYPE,NOMCHAUFFEUR,DATESORTIE) values ('"+matricule+"','"+Type+"','"+Nom_chaffeur+"','"+date_sortie+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Enregistrer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }




}

void MainWindow::on_pushButton_4_clicked()
{
    Connection c;
    QString matricule = ui->lineEdit->text();
    QString Type = ui->comboBox->currentText();
    QString Nom_chaffeur = ui->lineEdit_3->text();
    QString date_sortie = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("update VEHICULEM  set MATRICULE='"+matricule+"',Type='"+Type+"',NOMCHAUFFEUR='"+Nom_chaffeur+"',DATESORTIE='"+date_sortie+"' where MATRICULE='"+matricule+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Modifier"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }

}

void MainWindow::on_pushButton_5_clicked()
{
    Connection c;
    QString matricule = ui->lineEdit->text();
    QString Type = ui->comboBox->currentText();
    QString Nom_chaffeur = ui->lineEdit_3->text();
    QString date_sortie = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("Delete from VEHICULEM where MATRICULE='"+matricule+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }

}

