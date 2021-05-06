#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "citoyen.h"
#include "assistance.h"
#include "rdv.h"
#include "arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_ajouter_citoyen_clicked();

    void on_pb_supp_clicked();

    void on_modifier_clicked();

    void on_tri_clicked();

    void on_le_cin_supp_textChanged(const QString &arg1);

    void on_pb_consultation_supp_clicked();

    void on_pb_consultation_modifier_clicked();

    void on_pb_tri_consultation_clicked();

    void on_le_consultation_supp_textChanged(const QString &arg1);

    void on_affec_citoyen_clicked();

    void on_le_citoyen_affec_currentTextChanged(const QString &arg1);

    void on_pb_enregistrer_clicked();

    void on_print_clicked();

    void on_pb_supp_rdv_clicked();

    void on_trie_rdv_clicked();

    void on_le_rdv_supp_textChanged(const QString &arg1);

    void on_pb_open_clicked();

    void on_pb_close_clicked();

private:
    Ui::MainWindow *ui;
    Citoyen tmpcitoyen;
    Assistance tmpassistance;
    rdv tmprdv;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire



};
#endif // MAINWINDOW_H
