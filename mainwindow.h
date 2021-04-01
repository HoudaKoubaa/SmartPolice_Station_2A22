#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "violence.h"

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
    void on_leBtAjouter_clicked();

    void on_leSupp_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_Modifier_2_clicked();

    void on_Supprimer_clicked();

private:
    Ui::MainWindow *ui;
    violence etd;
};
#endif // MAINWINDOW_H
