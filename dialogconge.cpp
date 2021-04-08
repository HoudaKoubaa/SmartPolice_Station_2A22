#include "dialogconge.h"
#include "ui_dialogconge.h"
#include "conge.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include <QPixmap>
#include <QPropertyAnimation>

Dialogconge::Dialogconge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogconge)
{
    ui->setupUi(this);
    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_2, "geometry");
    animation->setDuration(4000);
    animation->setStartValue(ui->label_2->geometry());
    animation->setStartValue(QRect(0, 0, 100, 30));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

    ui->tableView->setModel(C.afficherConge());
    update_id();
    player = new QMediaPlayer;

}

Dialogconge::~Dialogconge()
{
    delete ui;
}

bool Dialogconge::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

void Dialogconge::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cin_emp FROM employes");
       querry->exec();
       m->setQuery(*querry);
       ui->comboBox_2->setModel(m);

}



void Dialogconge::on_pushButtonAjouter_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    //Récuprération des informations saisies dans les 3 champs


    int id=ui->LeId_2->text().toInt(); //convertir une chaine de caractére en un entier
    QDateTime debut_conge=ui->dateEdit->dateTime();
    QDateTime fin_conge=ui->dateEdit_2->dateTime();
    int id2=ui->comboBox_2->currentText().toInt(); //convertir une chaine de caractére en un entier

    bool test2;
        test2=(controleVideInt(id) );
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Conge C(id,debut_conge,fin_conge,id2);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

    bool test =C.ajouterConge();

    if (test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(C.afficherConge());
        update_id();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }

    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}

    else

      {

          QMessageBox::information(nullptr, QObject::tr("Ajouter un conge "),
                                     QObject::tr("conge non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


      }
}




void Dialogconge::on_pushButtonModifier_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    //Récuprération des informations saisies dans les 3 champs


    QDateTime debut_conge=ui->dateEdit->dateTime();
    QDateTime fin_conge=ui->dateEdit_2->dateTime();
    int id2=ui->comboBox_2->currentText().toInt(); //convertir une chaine de caractére en un entier

    bool test2;
        test2=(controleVideInt(id_con) );
       //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
            Conge C(id_con,debut_conge,fin_conge,id2);

       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
       bool test =C.modifierConge();


       if (test2){
       if(test)//si requête executée ==>QMessageBox::information
       {

          //refresh affichage
           ui->tableView->setModel(C.afficherConge());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                   QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
       }
       else //si requête non exécutée ==>QMessageBox::critical
           QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
       else

         {

             QMessageBox::information(nullptr, QObject::tr("Ajouter un conge "),
                                        QObject::tr("conge non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


         }

}

void Dialogconge::on_pushButtonSupprimer_clicked()
{
        player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
        player->play();
        qDebug() << player->errorString();

        bool test = C.supprimerConge(id_con);
        if(test)
        {
            //refresh affichage
            ui->tableView->setModel(C.afficherConge());
            update_id();

            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),

 QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);


}



void Dialogconge::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    ui->tableView->setModel(C.AfficherTrieID());
}

void Dialogconge::on_pushButton_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    ui->tableView->setModel(C.AfficherTrieIDE());
}



void Dialogconge::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(C.rechercherID(arg1));
}

void Dialogconge::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(C.rechercherID_emp(arg1));
}


void Dialogconge::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from conge where"
                          " id_conge='"+val+"' or cin_emp='"+val+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->LeId_2->setText(qry.value(0).toString());
                 ui->dateEdit->setDateTime(qry.value(1).toDateTime());
                 ui->dateEdit_2->setDateTime(qry.value(2).toDateTime());
                 ui->comboBox_2->setCurrentText(qry.value(3).toString());

                }

}

}

void Dialogconge::on_tableView_clicked(const QModelIndex &index)
{

id_con=ui->tableView->model()->data(index).toInt();

}


void Dialogconge::on_pushButton_7_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    close();
}


void Dialogconge::on_pushButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    ui->tableView->setModel(C.AfficherTrieDate_debut());

}
