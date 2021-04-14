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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
