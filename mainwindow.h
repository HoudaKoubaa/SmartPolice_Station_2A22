#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QString>
#include <QMainWindow>
#include "employes.h"
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
    void update_id();

private slots:
    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);



    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);


    void on_Impdos_2_clicked();

private:
    Ui::MainWindow *ui;
    Employes emp;
    int id_emp=0;
};

#endif // MAINWINDOW_H
