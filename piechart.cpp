#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>
#include "dialogemploye.h"

QChartView* Dialogemploye::piechart()
{

    QPieSeries *series = new QPieSeries();
    series->append("2021", 1);
    series->append("2020", 2);
    series->append("2019", 3);


    series->slices().at(0)->setValue(G_PVS1());
    series->slices().at(1)->setValue(G_PVS2());
    series->slices().at(2)->setValue(G_PVS3());
    series->slices().at(0)->setBrush(Qt::darkMagenta);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Conge par Annee");


    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);

    return chartView1;
}

int Dialogemploye::G_PVS1()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT ID_CONGE FROM CONGE WHERE EXTRACT(YEAR FROM DEBUT_CONGE)=2021");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}
int Dialogemploye::G_PVS2()
{
    int c20=0;
    QSqlQuery qry20;
    qry20.exec("SELECT ID_CONGE FROM CONGE WHERE EXTRACT(YEAR FROM DEBUT_CONGE)=2020");
    while(qry20.next())
    {
        c20++;
    }
    return c20;
}
int Dialogemploye::G_PVS3()
{
    int c19=0;
    QSqlQuery qry19;
    qry19.exec("SELECT ID_CONGE FROM CONGE WHERE EXTRACT(YEAR FROM DEBUT_CONGE)=2019");
    while(qry19.next())
    {
        c19++;
    }
    return c19;
}
