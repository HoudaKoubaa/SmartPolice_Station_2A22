#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vehicule.h"
#include<QMediaPlayer>
#include "maintenance.h"
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void update_id();


private slots:
    void on_pb_ajouter_clicked();

    void on_modifier_clicked();



    void on_supr_2_clicked();

    void on_trier_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_audio_clicked();

    void on_ajouter_m_clicked();

    void on_suprimer_m_clicked();

    void on_rech_m_textChanged(const QString &arg1);

    void on_trier_m_clicked();

    void on_pdf_clicked();

    void on_modifier_m_clicked();




    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    Vehicule V;
   Maintenance M;
};
#endif // MAINWINDOW_H
