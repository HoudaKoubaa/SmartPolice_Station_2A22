#ifndef DIALOGCONGE_H
#define DIALOGCONGE_H
#include <QDialog>
#include "conge.h"
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>

namespace Ui {
class Dialogconge;
}

class Dialogconge : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogconge(QWidget *parent = nullptr);
    ~Dialogconge();

   void update_id();

private slots:

    bool controleVideInt(int test);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialogconge *ui;
    Conge C;
    int id_con=0;
    QMediaPlayer*	player;
};

#endif // DIALOGCONGE_H
