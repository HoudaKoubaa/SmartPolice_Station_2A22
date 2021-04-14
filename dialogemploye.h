#ifndef DIALOGEMPLOYE_H
#define DIALOGEMPLOYE_H
#include "employe.h"
#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>
#include <QtCharts>

namespace Ui {
class Dialogemploye;
}

class Dialogemploye : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogemploye(QWidget *parent = nullptr);
    ~Dialogemploye();

    void update_id();

    int R_BCS1();
    int R_BCS2();
    int R_BCS3();
    int R_BCS4();
    int R_BCS5();
    int R_BCS6();

    int G_PVS1();
    int G_PVS2();
    int G_PVS3();

        QChartView* barchart();
        QChartView* piechart();

private slots:


    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

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



    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::Dialogemploye *ui;
    Employes emp;
    int id_emp=0;
    QMediaPlayer*	player;
};

#endif // DIALOGEMPLOYE_H
