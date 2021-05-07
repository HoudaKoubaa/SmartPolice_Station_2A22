#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "attestation.h"
#include "passeport.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int ControleSaisie();
    int ControleSaisie2();
    void vider();
    void initier();
private slots:
    void on_btnAjout_clicked();

    void on_pushButton_clicked();

    void on_rech_textEdited(const QString &arg1);

    void on_tri_currentTextChanged(const QString &arg1);

    void on_listAtt_activated(const QModelIndex &index);

    void on_btnSupp_clicked();

    void on_btnModif_clicked();


    void on_btnAjout2_clicked();

    void on_charger_clicked();

    void on_tabPass_activated(const QModelIndex &index);

    void on_btnSupp2_clicked();

    void on_btnModif2_clicked();

    void on_rech2_textEdited(const QString &arg1);

    void on_tri2_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_GestionP_clicked();

    void on_gestionA_clicked();

    void on_home_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_2_clicked();

    void on_imprimer_clicked();

private:
    Ui::MainWindow *ui;
    attestation att;
    passeport pass;
};

#endif // MAINWINDOW_H
