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

private:
    Ui::MainWindow *ui;
    QMediaPlayer*	playermusic;
    QMediaPlayer*	player;

};

#endif // MAINWINDOW_H
