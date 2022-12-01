#include "statistique.h"
#include "ui_stat.h"

statistique::statistique(QWidget *parent) : QDialog(parent),
    ui(new Ui::statistique)
{
   // ui->setupUi(this);
}/*

statistique::~statistique()
{
    delete ui;
}


void statistique::choix_bar()
{
    QSqlQuery q0,q1_1,q1_2
            ,q2_1,q2_2
            ,q3_1,q3_2;
int tot=0;
    qreal c1_1=0,c1_2=0
            ,c2_1=0 ,c2_2=0
            ,c3_1=0 ,c3_2=0;


    q0.prepare("SELECT * FROM BUREAUX");
    q0.exec();

    //Les bureaux de type architecture
    q1_1.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Disponible' and typebureau='Architecture'");
    q1_1.exec();

    q1_2.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Non Disponible' and typebureau='Architecture'");
    q1_2.exec();


    //Les bureaux de type informatique
    q2_1.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Disponible' and typebureau='Informatique'");
    q2_1.exec();

    q2_2.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Non Disponible' and typebureau='Informatique'");
    q2_2.exec();


    //Les bureaux de type autres
    q3_1.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Disponible' and typebureau='Autres'");
    q3_1.exec();

    q3_2.prepare("SELECT * FROM BUREAUX WHERE disponibilite='Non Disponible' and typebureau='Autres'");
    q3_2.exec();


    while (q0.next()){tot++;}

    while (q1_1.next()){c1_1++;}
    while (q1_2.next()){c1_2++;}


    while (q2_1.next()){c2_1++;}
    while (q2_2.next()){c2_2++;}


    while (q3_1.next()){c3_1++;}
    while (q3_2.next()){c3_2++;}


    tot=tot/2;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Architecture");
            QBarSet *set1 = new QBarSet("Informatique");
            QBarSet *set2 = new QBarSet("Autres");


            // Assign values for each bar
            *set0 << c1_1<<c1_2;
            *set1 << c2_1<<c2_2;
            *set2 << c3_1<<c3_2;

            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            series->append(set0);
            series->append(set1);
            series->append(set2);


            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);
            chart->setTitle("Total des bureaux par rapport aux types et disponibilités");
            chart->setAnimationOptions(QChart::SeriesAnimations);

            QStringList categories;
                categories << "Disponibles" << "Non Disponibles";
            // Adds categories to the axes
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                    axisX->append(categories);
                    chart->addAxis(axisX, Qt::AlignBottom);
                    series->attachAxis(axisX);

                    QValueAxis *axisY = new QValueAxis();
                    axisY->setRange(0,tot);
                    chart->addAxis(axisY, Qt::AlignLeft);
                    series->attachAxis(axisY);


            // 1. Bar chart
           // chart->setAxisX(axis, series);

            // Used to change the palette
            QPalette pal = qApp->palette();

            // Change the color around the chart widget and text
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

            // Apply palette changes to the application
            qApp->setPalette(pal);


    // Used to display the chart
    chartView = new QChartView(chart,ui->label);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(800,400);

    chartView->show();
}
*/
