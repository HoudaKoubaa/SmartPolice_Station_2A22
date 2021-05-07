/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QTableView *listAtt;
    QLabel *label;
    QPushButton *btnSupp;
    QLineEdit *rech;
    QComboBox *tri;
    QLabel *label_tri;
    QGroupBox *groupBox_2;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *mail;
    QComboBox *cin;
    QLabel *label_2;
    QLineEdit *rue;
    QLineEdit *ville;
    QTextEdit *desc;
    QDateEdit *date;
    QLabel *label_3;
    QLineEdit *objet;
    QPushButton *btnAjout;
    QPushButton *btnModif;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *Impression;
    QWidget *page_2;
    QTableView *tabPass;
    QFrame *line;
    QLabel *label_4;
    QLineEdit *mailP;
    QComboBox *cinP;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *dateP;
    QLineEdit *adresse;
    QComboBox *sexe;
    QLabel *label_8;
    QComboBox *etat;
    QLabel *label_9;
    QPushButton *btnAjout2;
    QPushButton *btnModif2;
    QPushButton *charger;
    QPushButton *btnSupp2;
    QLineEdit *rech2;
    QLabel *label_10;
    QComboBox *tri2;
    QComboBox *raison;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *type;
    QLabel *label_13;
    QComboBox *traitement;
    QPushButton *pushButton_3;
    QPushButton *home;
    QWidget *page_3;
    QPushButton *GestionP;
    QPushButton *gestionA;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(993, 557);
        MainWindow->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(27, 39, 50, 255),stop:1 rgba(47, 53, 74, 255));\n"
"	color: #000000;\n"
"\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: #c2c7d5;\n"
"	font-size: 13px;\n"
"\n"
"}\n"
"QPushButton\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.511, x2:1, y2:0.511, stop:0 rgba(0, 172, 149, 255),stop:0.995192 rgba(54, 197, 177, 255));\n"
"	color: #fff;\n"
"	font-size: 11px;\n"
"	font-weight: bold;\n"
"	border: none;\n"
"	border-radius: 3px;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.511, x2:1, y2:0.511, stop:0 rgba(0, 207, 179, 255),stop:1 rgba(70, 255, 230, 255));\n"
"\n"
"}\n"
"QCheckBox\n"
"{\n"
"	background-color: transparent;\n"
"	color: #fff;\n"
"	font-size: 10px;\n"
"	font-weight: bold;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QCheckBox-----*/\n"
"Q"
                        "CheckBox::indicator\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid darkgray;\n"
"    width: 12px;\n"
"    height: 12px;\n"
"\n"
"}\n"
"\n"
"QCheckBox::indicator\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid darkgray;\n"
"    width: 12px;\n"
"    height: 12px;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.511, x2:1, y2:0.511, stop:0 rgba(0, 172, 149, 255),stop:0.995192 rgba(54, 197, 177, 255));;\n"
"    border: 1px solid #607cff;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"    border: 1px solid #08b099;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::disabled\n"
"{\n"
"	color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:disabled\n"
"{\n"
"	background-color: #656565;\n"
"	color: #656565;\n"
"    border: 1px solid #656565;\n"
"\n"
"}\n"
"QLineEdit\n"
"{\n"
"	background-color: #c2c7d5;\n"
"	color: #000;\n"
"	font-weight: bold"
                        ";\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	padding: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QListView-----*/\n"
"QListView\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(50, 61, 80, 255),stop:1 rgba(44, 49, 69, 255));\n"
"	color: #fff;\n"
"	font-size: 12px;\n"
"	font-weight: bold;\n"
"	border: 1px solid #191919;\n"
"	show-decoration-selected: 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item\n"
"{\n"
"	color: #31cecb;\n"
"	background-color: #454e5e;\n"
"	border: none;\n"
"	padding: 5px;\n"
"	border-radius: 0px;\n"
"	padding-left : 10px;\n"
"	height: 42px;\n"
"\n"
"}\n"
"\n"
"QListView::item:selected\n"
"{\n"
"	color: #31cecb;\n"
"	background-color: #454e5e;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:!selected\n"
"{\n"
"	color:white;\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	padding-left : 10px;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::item:!selected:hover\n"
"{\n"
"	color: #bbbcba;\n"
"	background-color: #454e5e;\n"
"	border: none;\n"
"	padding-left : 10p"
                        "x;\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QTreeView-----*/\n"
"QTreeView \n"
"{\n"
"	background-color: #232939;\n"
"	show-decoration-selected: 0;\n"
"	color: #c2c8d7;\n"
"\n"
"}\n"
"\n"
"\n"
"QTreeView::item \n"
"{\n"
"	border-top-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"\n"
"}\n"
"\n"
"\n"
"QTreeView::item:hover \n"
"{\n"
"	background-color: #606060;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QTreeView::item:selected \n"
"{\n"
"	background-color: #0ab19a;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QTreeView::item:selected:active\n"
"{\n"
"	background-color: #0ab19a;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings \n"
"{\n"
"	image: url(://tree-closed.png);\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings  \n"
"{\n"
"	image: url(://tree-open.png);\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QTableView & QTableWidget-----*/\n"
"QTabl"
                        "eView\n"
"{\n"
"    background-color: #232939;\n"
"	border: 1px solid gray;\n"
"    color: #f0f0f0;\n"
"    gridline-color: #232939;\n"
"    outline : 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::disabled\n"
"{\n"
"    background-color: #242526;\n"
"    border: 1px solid #32414B;\n"
"    color: #656565;\n"
"    gridline-color: #656565;\n"
"    outline : 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:hover \n"
"{\n"
"    background-color: #606060;\n"
"    color: #f0f0f0;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:selected \n"
"{\n"
"	background-color: #0ab19a;\n"
"    color: #F0F0F0;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:selected:disabled\n"
"{\n"
"    background-color: #1a1b1c;\n"
"    border: 2px solid #525251;\n"
"    color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableCornerButton::section\n"
"{\n"
"	background-color: #343a49;\n"
"    color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	color: #fff;\n"
"	border-top: 0px;\n"
"	border-bottom: 1px solid gray;\n"
"	border-right: 1px solid gray;\n"
"	bac"
                        "kground-color: #343a49;\n"
"    margin-top:1px;\n"
"	margin-bottom:1px;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:disabled\n"
"{\n"
"    background-color: #525251;\n"
"    color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"    color: #fff;\n"
"    background-color: #0ab19a;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked:disabled\n"
"{\n"
"    color: #656565;\n"
"    background-color: #525251;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one\n"
"{\n"
"    border-top: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical\n"
"{\n"
"    border-top: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one\n"
"{\n"
"    border-left: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal\n"
"{\n"
"    border-left: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QScrollBar-----*/\n"
""
                        "QScrollBar:horizontal \n"
"{\n"
"    background-color: transparent;\n"
"    height: 8px;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:horizontal \n"
"{\n"
"    border: none;\n"
"	min-width: 100px;\n"
"    background-color: #56576c;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:horizontal, \n"
"QScrollBar::sub-line:horizontal,\n"
"QScrollBar::add-page:horizontal, \n"
"QScrollBar::sub-page:horizontal \n"
"{\n"
"    width: 0px;\n"
"    background-color: transparent;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical \n"
"{\n"
"    background-color: transparent;\n"
"    width: 8px;\n"
"    margin: 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical \n"
"{\n"
"    border: none;\n"
"	min-height: 100px;\n"
"    background-color: #56576c;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical, \n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-page:vertical, \n"
"QScrollBar::sub-page:vertical \n"
"{\n"
"    height: 0px;\n"
"    background-color: transparent;\n"
"\n"
"}\n"
""
                        "\n"
"\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 991, 501));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 411, 451));
        listAtt = new QTableView(groupBox);
        listAtt->setObjectName(QStringLiteral("listAtt"));
        listAtt->setGeometry(QRect(10, 90, 391, 311));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 9, 381, 31));
        label->setAlignment(Qt::AlignCenter);
        btnSupp = new QPushButton(groupBox);
        btnSupp->setObjectName(QStringLiteral("btnSupp"));
        btnSupp->setGeometry(QRect(150, 410, 75, 23));
        rech = new QLineEdit(groupBox);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(40, 60, 131, 20));
        tri = new QComboBox(groupBox);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(260, 60, 131, 22));
        label_tri = new QLabel(groupBox);
        label_tri->setObjectName(QStringLiteral("label_tri"));
        label_tri->setGeometry(QRect(200, 60, 61, 21));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(630, 20, 351, 461));
        nom = new QLineEdit(groupBox_2);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(30, 20, 113, 20));
        prenom = new QLineEdit(groupBox_2);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(230, 20, 111, 20));
        mail = new QLineEdit(groupBox_2);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(230, 80, 111, 20));
        cin = new QComboBox(groupBox_2);
        cin->setObjectName(QStringLiteral("cin"));
        cin->setGeometry(QRect(70, 80, 71, 22));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(36, 80, 31, 21));
        rue = new QLineEdit(groupBox_2);
        rue->setObjectName(QStringLiteral("rue"));
        rue->setGeometry(QRect(30, 140, 113, 20));
        ville = new QLineEdit(groupBox_2);
        ville->setObjectName(QStringLiteral("ville"));
        ville->setGeometry(QRect(230, 140, 111, 20));
        desc = new QTextEdit(groupBox_2);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(23, 280, 321, 91));
        date = new QDateEdit(groupBox_2);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(60, 200, 81, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(26, 200, 41, 21));
        objet = new QLineEdit(groupBox_2);
        objet->setObjectName(QStringLiteral("objet"));
        objet->setGeometry(QRect(230, 200, 111, 20));
        btnAjout = new QPushButton(groupBox_2);
        btnAjout->setObjectName(QStringLiteral("btnAjout"));
        btnAjout->setGeometry(QRect(210, 410, 91, 23));
        btnModif = new QPushButton(groupBox_2);
        btnModif->setObjectName(QStringLiteral("btnModif"));
        btnModif->setGeometry(QRect(210, 410, 91, 23));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 410, 101, 23));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 410, 191, 23));
        Impression = new QTextEdit(page);
        Impression->setObjectName(QStringLiteral("Impression"));
        Impression->setGeometry(QRect(430, 140, 181, 101));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tabPass = new QTableView(page_2);
        tabPass->setObjectName(QStringLiteral("tabPass"));
        tabPass->setGeometry(QRect(30, 100, 351, 341));
        line = new QFrame(page_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(403, 10, 20, 471));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 10, 321, 31));
        label_4->setAlignment(Qt::AlignCenter);
        mailP = new QLineEdit(page_2);
        mailP->setObjectName(QStringLiteral("mailP"));
        mailP->setGeometry(QRect(810, 210, 151, 21));
        cinP = new QComboBox(page_2);
        cinP->setObjectName(QStringLiteral("cinP"));
        cinP->setGeometry(QRect(500, 90, 141, 22));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 90, 41, 21));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(570, 10, 321, 31));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 210, 91, 16));
        dateP = new QDateEdit(page_2);
        dateP->setObjectName(QStringLiteral("dateP"));
        dateP->setGeometry(QRect(530, 210, 110, 22));
        adresse = new QLineEdit(page_2);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(500, 330, 141, 21));
        sexe = new QComboBox(page_2);
        sexe->setObjectName(QStringLiteral("sexe"));
        sexe->setGeometry(QRect(850, 90, 111, 22));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(810, 90, 41, 21));
        etat = new QComboBox(page_2);
        etat->setObjectName(QStringLiteral("etat"));
        etat->setGeometry(QRect(870, 150, 91, 22));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(810, 150, 51, 21));
        btnAjout2 = new QPushButton(page_2);
        btnAjout2->setObjectName(QStringLiteral("btnAjout2"));
        btnAjout2->setGeometry(QRect(690, 400, 121, 31));
        btnModif2 = new QPushButton(page_2);
        btnModif2->setObjectName(QStringLiteral("btnModif2"));
        btnModif2->setGeometry(QRect(690, 400, 121, 31));
        charger = new QPushButton(page_2);
        charger->setObjectName(QStringLiteral("charger"));
        charger->setGeometry(QRect(50, 460, 101, 31));
        btnSupp2 = new QPushButton(page_2);
        btnSupp2->setObjectName(QStringLiteral("btnSupp2"));
        btnSupp2->setGeometry(QRect(160, 460, 101, 31));
        rech2 = new QLineEdit(page_2);
        rech2->setObjectName(QStringLiteral("rech2"));
        rech2->setGeometry(QRect(40, 70, 121, 21));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(220, 70, 31, 21));
        tri2 = new QComboBox(page_2);
        tri2->setObjectName(QStringLiteral("tri2"));
        tri2->setGeometry(QRect(250, 70, 121, 22));
        raison = new QComboBox(page_2);
        raison->setObjectName(QStringLiteral("raison"));
        raison->setGeometry(QRect(498, 150, 141, 22));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(440, 150, 61, 21));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(810, 270, 41, 21));
        type = new QComboBox(page_2);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(848, 270, 111, 22));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(440, 270, 71, 21));
        traitement = new QComboBox(page_2);
        traitement->setObjectName(QStringLiteral("traitement"));
        traitement->setGeometry(QRect(510, 270, 131, 22));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(694, 450, 121, 31));
        home = new QPushButton(page_2);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(270, 460, 101, 31));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        GestionP = new QPushButton(page_3);
        GestionP->setObjectName(QStringLiteral("GestionP"));
        GestionP->setGeometry(QRect(350, 142, 261, 51));
        gestionA = new QPushButton(page_3);
        gestionA->setObjectName(QStringLiteral("gestionA"));
        gestionA->setGeometry(QRect(350, 270, 261, 51));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 993, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Liste Des Attestations", Q_NULLPTR));
        btnSupp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        rech->setText(QString());
        rech->setPlaceholderText(QApplication::translate("MainWindow", "Chercher par CIN", Q_NULLPTR));
        tri->clear();
        tri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "-", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date(ordre croissant)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date(ordre decroissant)", Q_NULLPTR)
        );
        label_tri->setText(QApplication::translate("MainWindow", "Trier par:", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        nom->setPlaceholderText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        prenom->setPlaceholderText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        mail->setPlaceholderText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "CIN:", Q_NULLPTR));
        rue->setPlaceholderText(QApplication::translate("MainWindow", "Rue", Q_NULLPTR));
        ville->setPlaceholderText(QApplication::translate("MainWindow", "Ville", Q_NULLPTR));
        desc->setPlaceholderText(QApplication::translate("MainWindow", "Description (300 mots maximum)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        objet->setText(QString());
        objet->setPlaceholderText(QApplication::translate("MainWindow", "Objet", Q_NULLPTR));
        btnAjout->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        btnModif->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Charger La Liste", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Imprimer Demande Attestation", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Liste Passeport", Q_NULLPTR));
        mailP->setPlaceholderText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        cinP->clear();
        cinP->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "09635352", Q_NULLPTR)
         << QApplication::translate("MainWindow", "08456122", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Ajout Passeport", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Date Naissance", Q_NULLPTR));
        adresse->setPlaceholderText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        sexe->clear();
        sexe->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Male", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Female", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autre", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "Sexe", Q_NULLPTR));
        etat->clear();
        etat->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Celibataire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Marie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Divorce", Q_NULLPTR)
         << QString()
        );
        label_9->setText(QApplication::translate("MainWindow", "Etat Civil", Q_NULLPTR));
        btnAjout2->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        btnModif2->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        charger->setText(QApplication::translate("MainWindow", "Charger Liste", Q_NULLPTR));
        btnSupp2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        rech2->setPlaceholderText(QApplication::translate("MainWindow", "Chercher Par CIN", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        tri2->clear();
        tri2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "-", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date Naissance(ordre croissant)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date Naissance(ordre decroissant)", Q_NULLPTR)
        );
        raison->clear();
        raison->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Premier Passeport", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Passeport Sature", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Passeport vole", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Passeport Perdu", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Renouvellement", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Changement Renseignements", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "Raison", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Regulier", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Officiel", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Diplomatique", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("MainWindow", "Traitement", Q_NULLPTR));
        traitement->clear();
        traitement->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Normal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Urgent", Q_NULLPTR)
        );
        pushButton_3->setText(QApplication::translate("MainWindow", "Gestion Attestation", Q_NULLPTR));
        home->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        GestionP->setText(QApplication::translate("MainWindow", "Gestion Passeport", Q_NULLPTR));
        gestionA->setText(QApplication::translate("MainWindow", "Gestion Attestation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
