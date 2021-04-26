#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include "dialogemploye.h"
#include "dialogconge.h"
#include "quitter.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include "smtp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //bool b=auto_mail();
       /*notifier = new QSystemTrayIcon(this);
       notifier->setIcon(QIcon(":/notification.jpg"));
       notifier->show();

       if (b == true) {notifier->showMessage(" NOTIFICATION ","Email envoyer",QSystemTrayIcon::Information,10000); ;}*/

    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_3, "geometry");
    animation->setDuration(3500);
    animation->setStartValue(ui->label_3->geometry());
    animation->setStartValue(QRect(0, 0, 100, 30));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    playermusic = new QMediaPlayer;
    player = new QMediaPlayer;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonEmploye_clicked()
{

    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    Dialogemploye E;
    E.exec();

}

void MainWindow::on_pushButtonHistorique_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    Dialogconge H;
    H.exec();
}


void MainWindow::on_start_2_clicked()
{
   playermusic->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/music.mp3"));
   playermusic->play();
   qDebug() << playermusic->errorString();
}


void MainWindow::on_pause_2_clicked()
{

    playermusic->pause();

}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    playermusic->setVolume(position);
}

void MainWindow::on_pushButtonquitter_clicked()
{
    quitter afficher;
    afficher.setModal(true);
    afficher.exec();
}


bool MainWindow::auto_mail()
{

     QSqlQuery query;
     QDate date = QDate::currentDate();
     query.prepare("SELECT email,nom_emp FROM Employes WHERE cin_emp IN ( SELECT cin_emp  FROM conge WHERE fin_conge=:date ) ");
     query.bindValue(":date",date);
     bool b=query.exec();
     while (query.next())
     {

      QString mail = query.value(0).toString();
      QString nom  = query.value(1).toString();
      QString sujet  ="Police Station" ;
      QString message="Bonjour monsieur "+nom+",\n Votre congée expirera bientot,vous devez nous contactez";

      Smtp* smtp = new Smtp("bechir.pastore@gmail.com","19modemalgerie98", "smtp.gmail.com");
      smtp->sendMail("bechir.pastore@gmail.com",mail,sujet,message);

     }
     return b;

}
