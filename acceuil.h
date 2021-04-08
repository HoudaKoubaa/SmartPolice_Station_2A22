#ifndef ACCEUIL_H
#define ACCEUIL_H
#include <QMainWindow>
#include "violence.h"
#include "accident.h"
#include "envoie.h"
#include <QSqlQuery>
#include <QCheckBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>
#include "chart.h"
//stat
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include "chart.h"
#include <QPropertyAnimation>

namespace Ui {
class Acceuil;
}

class Acceuil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Acceuil(QWidget *parent = nullptr);
    ~Acceuil();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_mailing_2_clicked();

    void on_Modifier_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_tri_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_Supprimer_clicked();

    void on_stat_clicked();


    void on_leBtAjouter_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_Modifier_3_clicked();

    void on_comboBox2_currentIndexChanged(int index);

    void on_supcin_textChanged(const QString &arg1);

    void on_Supprimer_2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_clicked();

    void on_pushButton_envoyerMail_2_clicked();

private:
    Ui::Acceuil *ui;
    violence etd;
   Acceuil* acc;
   QMediaPlayer*	player;
   chart *chartg;
   accident acciden;

   envoie e;


};

#endif // ACCEUIL_H
