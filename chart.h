#ifndef CHART_H
#define CHART_H
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QWidget>

namespace Ui {
class chart;
}

class chart : public QWidget
{
    Q_OBJECT

public:
    explicit chart(QWidget *parent = nullptr);
    ~chart();

private:
    Ui::chart *ui;
    chart *chartg;
};

#endif // CHART_H
