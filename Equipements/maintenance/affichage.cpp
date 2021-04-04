#include "affichage.h"
#include "ui_affichage.h"

affichage::affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affichage)
{
    ui->setupUi(this);
}

affichage::~affichage()
{
    delete ui;
}
void affichage::setData(const QString &lineEdit,const QString &lineEdit_2 , const QString &lineEdit_3 , const QDate &dateEdit) {
  ui->lineEdit->setText(lineEdit);
  ui->lineEdit_2->setText(lineEdit_2);
  ui->lineEdit_3->setText(lineEdit_3);
  ui->dateEdit->setDate(dateEdit);
}
