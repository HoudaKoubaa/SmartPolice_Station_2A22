#include "chart.h"
#include "ui_chart.h"

chart::chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chart)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append("Violance psychologique% ", 4.28);
    QPieSlice *slice = series->append("Violance psychologique 15.6%", 15.6);

    slice->setExploded();
    slice->setLabelVisible();
    series->append("Violance physique %", 23.8);



    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Statistique selon type de violance ");
    chart->setTheme(QChart::ChartThemeBlueCerulean);


    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);


}

chart::~chart()
{
    delete ui;
}
