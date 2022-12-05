#include "stat1.h"
#include "ui_stat1.h"

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
                categories << "Genre" ;
            // Adds categories to the axes
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                    axisX->append(categories);
                    chart->addAxis(axisX, Qt::AlignBottom);
                    series->attachAxis(axisX);

                    QValueAxis *axisY = new QValueAxis();

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

void statistique::choix_pie()
{
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM partenaire");
q1.exec();

q2.prepare("SELECT * FROM partenaire WHERE adresse='it'");
q2.exec();

q3.prepare("SELECT * FROM partenaire WHERE adresse='marketing'");
q3.exec();

q4.prepare("SELECT * FROM partenaire WHERE adresse='business' ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;

// Define slices and percentage of whole they take up
QPieSeries *series = new QPieSeries();
series->append("it",c1);
series->append("marketing",c2);
series->append("business",c3);




// Create the chart widget
QChart *chart = new QChart();

// Add data to chart with title and show legend
chart->addSeries(series);
chart->legend()->show();


// Used to display the chart

chartView = new QChartView(chart,ui->stat_2);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);
chartView->show();

}



void statistique::choix_bar2()
{
    QSqlQuery q0,q1_1
            ,q2_1
            ,q3_1;

    qreal tot=0,c1_1=0
            ,c2_1=0
            ,c3_1=0 ;


    q0.prepare("SELECT * FROM HEBERGEMENT");
    q0.exec();

    //Les classes de type Hotel
    q1_1.prepare("SELECT * FROM HEBERGEMENT WHERE TYPE_H='Hotel'");
    q1_1.exec();


    //Les classes de type Maison d'Hote
    q2_1.prepare("SELECT * FROM HEBERGEMENT WHERE TYPE_H='Maison dHote'");
    q2_1.exec();


    //Les classes de type AirBnb
    q3_1.prepare("SELECT * FROM HEBERGEMENT WHERE TYPE_H='AirBnb' ");
    q3_1.exec();


    while (q0.next()){tot++;}
    //total des classes par rapport au type Hotel
    while (q1_1.next()){c1_1++;}
    //total des classes par rapport au type Maison d'Hote
    while (q2_1.next()){c2_1++;}
    //total des classes par rapport au type AirBnb
    while (q3_1.next()){c3_1++;}



    tot=tot/2;


    // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("Hotel");
            QBarSet *set1 = new QBarSet("Maison dHote");
            QBarSet *set2 = new QBarSet("AirBnb");


            // Assign values for each bar
            *set0 <<c1_1;
            *set1 <<c2_1;
            *set2 <<c3_1;



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
            chart->setTitle("Total des classes par rapport au types");
            chart->setAnimationOptions(QChart::SeriesAnimations);

            QStringList categories;
                categories << "Hotel" << "Maison d'Hote" << "AirBnb" ;
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
    chartView->setMinimumSize(700,380);
    chartView->show();
}
