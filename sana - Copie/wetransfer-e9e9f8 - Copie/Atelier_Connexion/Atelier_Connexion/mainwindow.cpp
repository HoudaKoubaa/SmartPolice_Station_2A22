#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "attestation.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QLineEdit>
QString ch="";
QString cin="";
QString t="";
QString ch2="";
QString cin2="";
QString t2="";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);
    ui->listAtt->hide();
    ui->btnSupp->hide();
    ui->btnModif->hide();
    ui->cin->addItem("09635352");
    ui->cin->addItem("09635350");
    ui->cin->addItem("09635354");
    ui->date->setDate(QDate::currentDate());
    ui->label_tri->hide();
    ui->rech->hide();
    ui->tri->hide();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/wiki/Desktop/wetransfer-e9e9f8/Atelier_Connexion/Atelier_Connexion/bgsound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *player=new QMediaPlayer();
    player->setPlaylist(playlist);
    player->play();

        }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAjout_clicked()
{
QString nom=ui->nom->text();
QString prenom=ui->prenom->text();
QString cin=ui->cin->currentText();
QString mail=ui->mail->text();
QString lieu=ui->rue->text()+" "+ui->ville->text();
QString objet=ui->objet->text();
QDate d=ui->date->date();
QString desc=ui->desc->document()->toPlainText();
attestation a(nom,prenom,cin,mail,objet,desc,d,lieu);
if(ControleSaisie()==0 && a.ajouter()){
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("attestation ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
     ui->listAtt->setModel(att.afficher(ch,t));
}
else if(ControleSaisie()==0){
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("attestation pour ce personne existe deja.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
}
int MainWindow::ControleSaisie(){
    int test=0;
    QString msg="";
    if(ui->nom->text()==""){
        test=1;
        QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                                  QObject::tr("le champs nom est obligatoire.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
if(ui->nom->text().length()>19){
    test=2;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le nom ne doit pas depasser 20 caracteres.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->nom->setText("");
    if(test==0)
    ui->nom->setFocus();
}
if(ui->prenom->text()==""){
    test=3;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs prenom est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->prenom->text().length()>19){
test=4;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le prenom ne doit pas depasser 20 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->prenom->setText("");
if(test==0)
ui->prenom->setFocus();
}
if(ui->mail->text()==""){
    test=5;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs mail est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->mail->text().length()>24){
test=6;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le mail ne doit pas depasser 25 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->mail->setText("");
if(test==0)
ui->mail->setFocus();
}
if(ui->rue->text()==""){
    test=7;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs rue est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->rue->text().length()>14){
test=8;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le nom de rue ne doit pas depasser 15 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->rue->setText("");
if(test==0)
ui->rue->setFocus();
}
if(ui->ville->text()==""){
    test=9;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs ville est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->ville->text().length()>14){
test=10;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le nom de la ville ne doit pas depasser 15 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->ville->setText("");
if(test==0)
ui->ville->setFocus();
}
if(ui->objet->text()==""){
    test=11;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs objet est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->objet->text().length()>19){
test=12;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le nom de l objet ne doit pas depasser 20 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->objet->setText("");
if(test==0)
ui->objet->setFocus();
}
if(ui->desc->document()->toPlainText()==""){
    test=13;
    QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                              QObject::tr("le champs description est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->desc->document()->toPlainText().length()>299){
test=14;
QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                          QObject::tr("le nom ne doit pas depasser 300 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->desc->document()->setHtml("");
if(test==0)
ui->desc->setFocus();
}

return test;
}
bool chaineNum(QString ch)
{
    bool test=true;
        for(int i=0;i<ch.length();i++)
        {
            if((ch[i]<'0')||(ch[i]>'9'))
                test=false;
        }
        return test;
}
bool chaineAlpha(QString ch)
{bool test=true;
    for(int i=0;i<ch.length();i++)
    {
        if((ch[i]<'A')||(ch[i]>'z')||((ch[i]>'Z')&&(ch[i]<'a')))
        {test=false;
        }
    }
    return test;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_tri->show();
    ui->rech->show();
    ui->tri->show();
    ui->listAtt->show();
    ui->listAtt->setModel(att.afficher(ch,t));
}

void MainWindow::on_rech_textEdited(const QString &arg1)
{
    ch=arg1;
    ui->listAtt->setModel(att.afficher(ch,t));
}

void MainWindow::on_tri_currentTextChanged(const QString &arg1)
{
    if(arg1=="-")
        t="";
    else if(arg1=="Date(ordre croissant)")
        t="ordre croissant";
    else t="ordre decroissant";
    ui->listAtt->setModel(att.afficher(ch,t));
}

void MainWindow::on_listAtt_activated(const QModelIndex &index)
{
    ui->btnModif->show();
    ui->btnAjout->hide();
    ui->btnSupp->show();
    QString val=ui->listAtt->model()->data(index).toString();
    cin=val;
    attestation a=att.getByCin(val);
    ui->cin->setCurrentText(cin);
    ui->cin->setDisabled(true);
    ui->nom->setText(a.get_nom());
    ui->prenom->setText(a.get_prenom());
    ui->mail->setText(a.get_mail());
    ui->date->setDate(a.get_date_attestation());
    ui->objet->setText(a.get_objet());
    ui->desc->document()->setHtml(a.get_description());
    QString rue=a.get_lieu().mid(0,a.get_lieu().indexOf(" "));
    ui->rue->setText(rue);
    QString ville=a.get_lieu().mid(a.get_lieu().indexOf(" ")+1,a.get_lieu().length());
    ui->ville->setText(ville);
}

void MainWindow::on_btnSupp_clicked()
{
    if(cin!=""){
        att.supprimer(cin);
        ui->btnAjout->show();
        ui->btnModif->hide();
        ui->btnSupp->hide();
        ui->listAtt->setModel(att.afficher(ch,t));
        ui->cin->setDisabled(false);
    }

}

void MainWindow::on_btnModif_clicked()
{
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString ci=ui->cin->currentText();
    QString mail=ui->mail->text();
    QString lieu=ui->rue->text()+" "+ui->ville->text();
    QString objet=ui->objet->text();
    QDate d=ui->date->date();
    QString desc=ui->desc->document()->toPlainText();
    attestation a(nom,prenom,ci,mail,objet,desc,d,lieu);
    if(ControleSaisie()==0 && a.modifier(cin)){
        QMessageBox::information(nullptr, QObject::tr("Ajouter une attestation"),
                                  QObject::tr("attestation modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
         ui->listAtt->setModel(att.afficher(ch,t));
         ui->btnAjout->show();
         ui->btnModif->hide();
         ui->btnSupp->hide();
         ui->cin->setDisabled(false);
         cin="";
         initier();
    }

}
void MainWindow::initier()
{
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->mail->setText("");
    ui->date->setDate(QDate::currentDate());
    ui->objet->setText("");
    ui->desc->document()->setHtml("");
    ui->rue->setText("");
    ui->ville->setText("");
}

void MainWindow::on_btnAjout2_clicked()
{
    QString c=ui->cinP->currentText();
    QString sexe=ui->sexe->currentText();
    QString raison=ui->raison->currentText();
    QString etat=ui->etat->currentText();
    QString traitement=ui->traitement->currentText();
    QString type=ui->type->currentText();
    QString mail=ui->mailP->text();
    QDate d=ui->dateP->date();
    QString adr=ui->adresse->text();
    passeport p(c,traitement,raison,d,sexe,etat,adr,mail,type);
    if(ControleSaisie2()==0 && p.ajouter()){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                                  QObject::tr("passeport ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tabPass->setModel(pass.afficher(ch2,t2));
    }
    else if(ControleSaisie2()==0){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                                  QObject::tr("passeport de ce personne existe deja.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

int MainWindow::ControleSaisie2(){
    int test=0;
    QString msg="";
    if(ui->mailP->text()==""){
        test=1;
        QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                                  QObject::tr("le champs mail est obligatoire.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
if(ui->mailP->text().length()>29){
    test=2;
    QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                              QObject::tr("le mail ne doit pas depasser 30 caracteres.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->mailP->setText("");
    if(test==0)
    ui->mailP->setFocus();
}
if(ui->adresse->text()==""){
    test=3;
    QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                              QObject::tr("le champs adresse est obligatoire.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ui->adresse->text().length()>29){
test=4;
QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                          QObject::tr("l adresse ne doit pas depasser 30 caracteres.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
ui->adresse->setText("");
if(test==0)
ui->adresse->setFocus();
}
if(ui->dateP->date()>QDate::currentDate()){
    test=5;
    QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                              QObject::tr("la date de naissance ne doit pas depaaser la date actuelle.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
return test;
}

void MainWindow::on_charger_clicked()
{   ui->rech2->show();
    ui->tri2->show();
    ui->label_10->show();
    ui->tabPass->show();
    ui->tabPass->setModel(pass.afficher(ch2,t2));
}

void MainWindow::on_tabPass_activated(const QModelIndex &index)
{QString val=ui->tabPass->model()->data(index).toString();
    cin2=val;
    passeport p=pass.getByCin(cin2);
    ui->label_6->setText("Modif Passeport");
    ui->btnSupp2->show();
    ui->btnAjout2->hide();
    ui->btnModif2->show();
    ui->cinP->setCurrentText(p.get_cin());
    ui->cinP->setDisabled(true);
    ui->mailP->setText(p.get_mail());
    ui->dateP->setDate(p.get_date_naissance());
    ui->sexe->setCurrentText(p.get_sexe());
    ui->type->setCurrentText(p.get_type());
    ui->adresse->setText(p.get_adresse());
    ui->traitement->setCurrentText(p.get_traitement());
    ui->raison->setCurrentText(p.get_raison());
    ui->etat->setCurrentText(p.get_etat());
}


void MainWindow::on_btnSupp2_clicked()
{
    if(cin2!=""){
        pass.supprimer(cin2);
        ui->tabPass->setModel(pass.afficher(ch2,t2));
        vider();
    }

}


void MainWindow::on_btnModif2_clicked()
{
    QString c=ui->cinP->currentText();
    QString sexe=ui->sexe->currentText();
    QString raison=ui->raison->currentText();
    QString etat=ui->etat->currentText();
    QString traitement=ui->traitement->currentText();
    QString type=ui->type->currentText();
    QString mail=ui->mailP->text();
    QDate d=ui->dateP->date();
    QString adr=ui->adresse->text();
    passeport p(c,traitement,raison,d,sexe,etat,adr,mail,type);
    if(ControleSaisie2()==0 && p.modifier(cin2)){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un passeport"),
                                  QObject::tr("passeport modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tabPass->setModel(pass.afficher(ch2,t2));
         vider();

    }
}
void MainWindow::vider(){
    ui->label_6->setText("Ajout Passeport");
    ui->btnSupp2->hide();
    ui->btnAjout2->show();
    ui->btnModif2->hide();
    ui->cinP->setCurrentIndex(1);
    ui->cinP->setDisabled(false);
    ui->mailP->setText("");
    ui->dateP->setDate(QDate::currentDate());
    ui->sexe->setCurrentIndex(1);
    ui->type->setCurrentIndex(1);
    ui->adresse->setText("");
    ui->traitement->setCurrentIndex(1);
    ui->raison->setCurrentIndex(1);
    ui->etat->setCurrentIndex(1);
    cin2="";
}


void MainWindow::on_rech2_textEdited(const QString &arg1)
{
    ch2=arg1;
    ui->tabPass->setModel(pass.afficher(ch2,t2));
}

void MainWindow::on_tri2_currentTextChanged(const QString &arg1)
{
    if(arg1=="-")
        t2="";
    else if(arg1=="Date Naissance(ordre croissant)")
        t2="ordre croissant";
    else t2="ordre decroissant";
    ui->tabPass->setModel(pass.afficher(ch2,t2));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->listAtt->hide();
    ui->btnSupp->hide();
    ui->btnModif->hide();
    ui->cin->addItem("09635352");
    ui->cin->addItem("09635350");
    ui->cin->addItem("09635354");
    ui->date->setDate(QDate::currentDate());
    ui->label_tri->hide();
    ui->rech->hide();
    ui->tri->hide();
}


void MainWindow::on_GestionP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->btnModif2->hide();
    ui->btnSupp2->hide();
    ui->rech2->hide();
    ui->tri2->hide();
    ui->tabPass->hide();
    ui->label_10->hide();
    ui->dateP->setDate(QDate::currentDate());
}

void MainWindow::on_gestionA_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->listAtt->hide();
    ui->btnSupp->hide();
    ui->btnModif->hide();
    ui->cin->addItem("09635352");
    ui->cin->addItem("09635350");
    ui->cin->addItem("09635354");
    ui->date->setDate(QDate::currentDate());
    ui->label_tri->hide();
    ui->rech->hide();
    ui->tri->hide();
}

void MainWindow::on_home_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_imprimer_clicked()
{
    attestation att;

               QString text=att.apercu_pdf();

               ui->Impression->setText(text);


               QPrinter printer ;
               printer.setPrinterName("imprim");
               QPrintDialog dialog (&printer,this);
               if(dialog.exec()==QDialog::Rejected) return ;
               ui->Impression->print(&printer);
}

void MainWindow::on_pushButton_2_clicked()
{
    QTableView *table;
                     table = ui->listAtt;

                     QString filters("CSV files (.csv);;All files (.*)");
                     QString defaultFilter("CSV files (*.csv)");
                     QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                        filters, &defaultFilter);
                     QFile file(fileName);

                     QAbstractItemModel *model =  table->model();
                     if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                         QTextStream data(&file);
                         QStringList strList;
                         for (int i = 0; i < model->columnCount(); i++) {
                             if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                 strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                             else
                                 strList.append("");
                         }
                         data << strList.join(";") << "\n";
                         for (int i = 0; i < model->rowCount(); i++) {
                             strList.clear();
                             for (int j = 0; j < model->columnCount(); j++) {

                                 if (model->data(model->index(i, j)).toString().length() > 0)
                                     strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                 else
                                     strList.append("");
                             }
                             data << strList.join(";") + "\n";
                         }
                         file.close();
                         QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                   QObject::tr("Export avec succes .\n"
                                                               "Click OK to exit."), QMessageBox::Ok);
                     }
}
