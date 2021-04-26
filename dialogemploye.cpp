#include "dialogemploye.h"
#include "ui_dialogemploye.h"
#include "employe.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include "mailing.h"
#include <QDialog>



Dialogemploye::Dialogemploye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogemploye)
{
     ui->setupUi(this);
     QPropertyAnimation *animation = new QPropertyAnimation(ui->label, "geometry");
     animation->setDuration(4000);
     animation->setStartValue(ui->label->geometry());
     animation->setStartValue(QRect(0, 0, 100, 30));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();

     QPropertyAnimation *animatio = new QPropertyAnimation(ui->label_14, "geometry");
     animatio->setDuration(4000);
     animatio->setStartValue(ui->label_14->geometry());
     animatio->setStartValue(QRect(0, 0, 100, 100));
     animatio->setEasingCurve(QEasingCurve::OutBounce);
     animatio->start();

     ui->tableView->setModel(emp.afficherEmployes());
     update_id();

     player = new QMediaPlayer;

}

Dialogemploye::~Dialogemploye()
{
    delete ui;
}



bool Dialogemploye::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool Dialogemploye::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool Dialogemploye::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}

void Dialogemploye::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cin_emp FROM employes");
       querry->exec();
       m->setQuery(*querry);

}



void Dialogemploye::on_pushButtonAjouter_clicked()
{

    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    //Récuprération des informations saisies dans les 3 champs
    int id=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entie

      QString nom=ui->Lenom->text();
      QString prenom=ui->Leprenom->text();
      QString grade=ui->comboBox->currentText();
      QDateTime date=ui->dateEdit->dateTime();
      QString mdp=ui->lemdp->text();
      QString email=ui->leemail->text();

      bool test2;
          test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(mdp)&&controleVide(email)&&controleVideInt(id) );

      //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
      Employes E(id,nom,prenom,grade,date,mdp,email);

      //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

      bool test =E.ajouterEmployes();
if (test2){

      if(test)//si requête executée ==>QMessageBox::information
      {

         //refresh affichage
          ui->tableView->setModel(emp.afficherEmployes());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                                 QObject::tr("Employé non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }


}


void Dialogemploye::on_pushButtonModifier_clicked()
{

    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    //Récuprération des informations saisies dans les 3 champs
    int idaa =ui->LeId->text().toInt();
    QString nom=ui->Lenom->text();
    QString prenom=ui->Leprenom->text();
    QString grade=ui->comboBox->currentText();
    QDateTime date=ui->dateEdit->dateTime();
    QString mdp=ui->lemdp->text();
    QString email=ui->leemail->text();

    bool test2;
        test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(mdp)&&controleVide(email) );
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
     Employes E(idaa,nom,prenom,grade,date,mdp,email);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =E.modifierEmployes();


if (test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                                 QObject::tr("Employé non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }

}


void Dialogemploye::on_pushButtonSupprimer_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();
 int idaa =ui->LeId->text().toInt();

    bool test = emp.supprimerEmployes(idaa);
    if(test)
    {
        //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        update_id();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void Dialogemploye::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    ui->tableView->setModel(emp.AfficherTrieCIN());
}

void Dialogemploye::on_pushButton_2_clicked()
{
     player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
     player->play();
     qDebug() << player->errorString();
     ui->tableView->setModel(emp.AfficherTrieNom());
}


void Dialogemploye::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherCIN(arg1));
}

void Dialogemploye::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherNom(arg1));
}


void Dialogemploye::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from Employes where"
                      " cin_emp='"+val+"' or nom_emp='"+val+"' or prenom_emp='"+val+"' or grade='"+val+"' or email ='"+val+"' or mot_de_passe='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->LeId->setText(qry.value(0).toString());
             ui->Lenom->setText(qry.value(1).toString());
             ui->Leprenom->setText(qry.value(2).toString());
             ui->comboBox->setCurrentText(qry.value(3).toString());
             ui->leemail->setText(qry.value(6).toString());
             ui->lemdp->setText(qry.value(5).toString());
             ui->dateEdit->setDateTime(qry.value(4).toDateTime());

           }
            }
}

void Dialogemploye::on_tableView_clicked(const QModelIndex &index)
{
    id_emp=ui->tableView->model()->data(index).toInt();
}

void Dialogemploye::on_Impdos_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    Employes c;

                 QString text=c.apercu_pdf();
                 ui->imp->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                 ui->imp->print(&printer);

}





void Dialogemploye::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherGrade(arg1));
}

void Dialogemploye::on_pushButton_3_clicked()
{
 player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
 player->play();
 qDebug() << player->errorString();
 ui->tableView->setModel(emp.AfficherTrieDate());
}

void Dialogemploye::on_pushButton_4_clicked()
{    
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();
    close();
}



void Dialogemploye::on_tabWidget_tabBarClicked(int index)
{
    qDeleteAll(ui->tabWidget_2->widget(0)->children());
    QWidget* barstats = new QWidget(this);
    barstats = barchart();
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(barstats, 0, 0); // Top-Left
    layout->addWidget(NULL, 0, 1); // Top-Right
    layout->addWidget(NULL, 1, 0); // Bottom-Left
    layout->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_6->setLayout(layout);

    qDeleteAll(ui->tabWidget_2->widget(1)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    //ui->tabWidget->widget(0)->setLayout(layout);
    ui->tab_7->setLayout(layout1);
}

void Dialogemploye::on_pushButtonmail_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    mailing m;
    m.exec();
    m.setModal(true);


}

