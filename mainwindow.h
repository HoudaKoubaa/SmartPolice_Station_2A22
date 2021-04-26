#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"employe.h"
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>
#include <QFileDialog>
#include <QtCharts>
#include <QSystemTrayIcon>
#include <qsystemtrayicon.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

 void on_pushButtonEmploye_clicked();
 void on_pushButtonHistorique_clicked();

 void on_start_2_clicked();

 void on_pause_2_clicked();

 void on_horizontalSlider_2_sliderMoved(int position);

 void on_pushButtonquitter_clicked();
 bool auto_mail();

private:
    Ui::MainWindow *ui;
    QMediaPlayer*	playermusic;
    QMediaPlayer*	player;
    QSystemTrayIcon *notifier;

};

#endif // MAINWINDOW_H
