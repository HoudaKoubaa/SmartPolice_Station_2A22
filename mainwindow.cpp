#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_acceuil.h"
#include "connection.h"
#include "login.h"
#include<QDebug>
#include "acceuil.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playermusic = new QMediaPlayer;




}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_connectpushButton_clicked()
{
  /*  playermusic->setMedia(QUrl::fromLocalFile("SBS:///C:/Users/houda/Desktop/music.wave"));
    playermusic->play();
    qDebug() << playermusic->errorString();
*/
    username=ui->username->text();
    password=ui->password->text();
    QSqlQuery qry;
    acceuil = new Acceuil(this);

    if(qry.exec("SELECT username, password, Role FROM USERS WHERE Username=\'"+ username +"\' AND password=\'" + password + "\'"))
    {
        if(qry.next())
        {
                  ui->label_errur->setText("[+]Valid Username and Password");
                  acceuil->show();

            }
            else{
                  ui->label_errur->setText("[-]UnValid Username and Password");



    }

}}

void MainWindow::on_volume_sliderMoved(int position)
{
playermusic->setVolume(position);
}

void MainWindow::on_play_clicked()
{
//load the file
playermusic->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/music.mp3"));
playermusic->play();
qDebug() << playermusic->errorString();

}

void MainWindow::on_stop_clicked()
{
playermusic->pause();
}

void MainWindow::on_pushButton_clicked()
{
    playermusic->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktopmusic1/music.mp3"));
      playermusic->play();
      qDebug() << playermusic->errorString();
}
