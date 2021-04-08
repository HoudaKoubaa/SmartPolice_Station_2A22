#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>
#include "login.h"
#include "acceuil.h"
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectpushButton_clicked();

    void on_volume_sliderMoved(int position);

    void on_play_clicked();

    void on_stop_clicked();



    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString username="",password="";
    //QMediaPlayer* player;
     Acceuil* acceuil;
     QMediaPlayer*	playermusic;
};
#endif // MAINWINDOW_H
