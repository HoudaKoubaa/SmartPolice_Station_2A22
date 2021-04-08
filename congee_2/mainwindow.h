#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"conge.h"

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

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);




    bool controleVideInt(int test);


private:
    Ui::MainWindow *ui;
    Conge C;
    int id_con=0;
};

#endif // MAINWINDOW_H
