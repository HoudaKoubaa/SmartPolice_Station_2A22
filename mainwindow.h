#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"employe.h"
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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
