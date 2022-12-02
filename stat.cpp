#include "stat.h"
#include "ui_stat.h"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}


void statistique::choix_bar()
{
    QSqlQuery q0,q1,q2;
int tot=0;
    qreal c1=0,c2=0;

    q0.prepare("SELECT * FROM EMPLOYEE");
    q0.exec();

    //Les classes de type violation
    q1.prepare("SELECT * FROM EMPLOYEE WHERE Genre = 'Homme'");
    q1.exec();

    q2.prepare("SELECT * FROM EMPLOYEE WHERE Genre = 'Femme'");
    q2.exec();


    while (q0.next()){tot++;}
    //total des classes par rapport au type violation
    while (q1.next()){c1++;}
    while (q2.next()){c2++;}



    tot=tot/2;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Homme");
            QBarSet *set1 = new QBarSet("Femme");

            // Assign values for each bar
            *set0 << c1;
            *set1 << c2;



            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *series = new QBarSeries();

            // 2. Stacked bar chart
            series->append(set0);
            series->append(set1);

            // Used to define the bar chart to display, title
            // legend,
            QChart *chart = new QChart();

            // Add the chart
            chart->addSeries(series);
            chart->setTitle("Total des classes par rapport au types");
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTheme( QChart::ChartThemeBlueCerulean);

            QStringList categories;
                categories << "Homme" << "Femme" ;
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
    chartView = new QChartView(chart,ui->stat_2);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(700,600);

    chartView->show();
}

