#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QDialog>

namespace Ui {
class affichage;
}

class affichage : public QDialog
{
    Q_OBJECT

public:
    explicit affichage(QWidget *parent = nullptr);
    ~affichage();
    void setData(const QString &lineEdit,const QString &lineEdit_2 , const QString &lineEdit_3 , const QDate &dateEdit);

private:
    Ui::affichage *ui;
};

#endif // AFFICHAGE_H
