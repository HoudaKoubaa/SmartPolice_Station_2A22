#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "affichage.h"
#include <QMessageBox>
#include "connection.h"


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
    QString cout = ui->lineEdit_3->text();
    QDate date_panne = ui->dateEdit->date();

    affichage affich;
    affich.setModal(true);
    affich.setData(matricule,Type,cout,date_panne);

    affich.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Connection c;
    QString matricule = ui->lineEdit->text();
    QString Type = ui->comboBox->currentText();
    QString cout = ui->lineEdit_3->text();
    QString date_panne = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("insert into MAINTENANCE (MATRICULE,TYPE,COUT,DATEPANNE) values ('"+matricule+"','"+Type+"','"+cout+"','"+date_panne+"')");
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
    QString cout = ui->lineEdit_3->text();
    QString date_panne = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("update MAINTENANCE set MATRICULE='"+matricule+"',Type='"+Type+"',COUT='"+cout+"',DATEPANNE='"+date_panne+"' where MATRICULE='"+matricule+"'");
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
    QString cout = ui->lineEdit_3->text();
    QString date_panne = ui->dateEdit->text();
    QSqlQuery qry;
    qry.prepare("Delete from MAINTENANCE where MATRICULE='"+matricule+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }
}
