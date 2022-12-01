#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include <QMessageBox>
#include<QDateTime>
#include<QDebug>
#include<QTableView>
#include<QPixmap>
#include <qrcode.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new  QTimer(this);
    connect( timer , SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(500);
ui->tablvol->setModel(v.afficher());
       QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8;
            qreal tot=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0;

            q1.prepare("SELECT * FROM vol");
            q1.exec();

            q2.prepare("SELECT * FROM vol WHERE airline='American Airlines'");
            q2.exec();

            q3.prepare("SELECT * FROM vol WHERE airline='Air France'");
            q3.exec();

            q4.prepare("SELECT * FROM vol WHERE airline='Fly Emirates'");
            q4.exec();

            q5.prepare("SELECT * FROM vol WHERE airline='Tunisair'");
            q5.exec();

            q6.prepare("SELECT * FROM vol WHERE airline='Lufthansa'");
            q6.exec();

            q7.prepare("SELECT * FROM vol WHERE airline='Turkish Airlines'");
            q7.exec();

            q8.prepare("SELECT * FROM vol WHERE airline='Qatar Airways'");
            q8.exec();


            while (q1.next()){tot++;}
            while (q2.next()){c1++;}
            while (q3.next()){c2++;}
            while (q4.next()){c3++;}
            while (q5.next()){c4++;}
            while (q6.next()){c5++;}
            while (q7.next()){c6++;}
            while (q8.next()){c7++;}

           QBarSet *set1 = new QBarSet("American Airlines");
           QBarSet *set2 = new QBarSet("Air France");
           QBarSet *set3 = new QBarSet("Fly Emirates");
           QBarSet *set4 = new QBarSet("Tunisair");
           QBarSet *set5 = new QBarSet("Lufthansa");
           QBarSet *set6 = new QBarSet("Turkish Airlines");
           QBarSet *set7 = new QBarSet("Qatar Airways");

            *set1 << c1 ;
            *set2 << c2 ;
            *set3 << c3 ;
            *set4 << c4 ;
            *set5 << c5 ;
            *set6 << c6 ;
            *set7 << c7 ;
           QBarSeries *series = new QBarSeries();
           series->append(set1);
           series->append(set2);
           series->append(set3);
           series->append(set4);
           series->append(set5);
           series->append(set6);
           series->append(set7);
           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("AirLines");
           chart->setAnimationOptions(QChart::AllAnimations);
           QStringList categories;
           categories << "Categories";
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();
           chart->setAxisX(axis, series);
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->setMinimumSize(1450,600);
           chartView->setParent(ui->horizontalFrame);
           QPalette pal = qApp->palette();
           qApp->setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lajout_clicked()
{
    int id=ui->lid->text().toInt();
    int id_emp=ui->lidd->text().toInt();
    QString arrive=ui->larrive->text();
    QString classe=ui->lclass->text();
    int day=ui->lday->text().toInt();
    int month=ui->lmonth->text().toInt();
    int year=ui->lyear->text().toInt();
    int day1=ui->lday1->text().toInt();
    int month1=ui->lmonth1->text().toInt();
    int year1=ui->lyear1->text().toInt();
    QString airline=ui->comboBox->currentText();
    int nbr_escl=ui->lnbr->text().toInt();
    vol v(id,id_emp,arrive,classe,day,month,year,day1,month1,year1,airline,nbr_escl);
    if((day<day1)&&(month<=month1)&&(year<=year1))
    {
    bool test=v.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tablvol->setModel(v.afficher());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject::tr("respecter la date.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_suplvol_clicked()
{
  int id=ui->lsup->text().toInt();
  bool test=v.supprimer(id);
if (test)
   {
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("supression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tablvol->setModel(v.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("supression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tablvol_activated(const QModelIndex &index)
{
    QString val=ui->tablvol->model()->data(index).toString();
        QSqlQuery qry;
    qry.prepare("SELECT * FROM vol where ID='"+val+"'");
    if (qry.exec())
     {
        while(qry.next())
        {
        ui->lid->setText(qry.value(0).toString());
        ui->lidd->setText(qry.value(1).toString());
        ui->larrive->setText(qry.value(2).toString());
        ui->lclass->setText(qry.value(3).toString());
        ui->lday->setValue(qry.value(4).toInt());
        ui->lmonth->setValue(qry.value(5).toInt());
        ui->lyear->setValue(qry.value(6).toInt());
        ui->lday1->setValue(qry.value(7).toInt());
        ui->lmonth1->setValue(qry.value(8).toInt());
        ui->lyear1->setValue(qry.value(9).toInt());
        ui->comboBox->setCurrentText(qry.value(10).toString());
        ui->lnbr->setText(qry.value(11).toString());
        }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lmodifier_clicked()
{

    int id=ui->lid->text().toInt();
    int id_emp=ui->lidd->text().toInt();
    QString arrive=ui->larrive->text();
    QString classe=ui->lclass->text();
    int day=ui->lday->text().toInt();
    int month=ui->lmonth->text().toInt();
    int year=ui->lyear->text().toInt();
    int day1=ui->lday1->text().toInt();
    int month1=ui->lmonth1->text().toInt();
    int year1=ui->lyear1->text().toInt();
    QString airline=ui->comboBox->currentText();
    int nbr_escl=ui->lnbr->text().toInt();
    QSqlQuery qry;
    vol v(id,id_emp,arrive,classe,day,month,year,day1,month1,year1,airline,nbr_escl);
    bool test=v.modifier();
    if(test){
                    ui->tablvol->setModel(v.afficher());
                            QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("modification effectué.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                QObject::tr("modification non effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_lreset_clicked()
{
    QSqlQuery qry;
    ui->lid->setText(nullptr);
    ui->lidd->setText(nullptr);
    ui->larrive->setText(nullptr);
    ui->lclass->setText(nullptr);
    ui->lday->setValue(0);
    ui->lmonth->setValue(0);
    ui->lyear->setValue(1);
    ui->lday1->setValue(1);
    ui->lmonth1->setValue(0);
    ui->lyear1->setValue(1);
    ui->comboBox->setCurrentText("tunisair");
    ui->lnbr->setText(nullptr);
}

void MainWindow::myfunction()
{

    QTime time= QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_date_time->setText(time_text);
}


void MainWindow::on_chercher_clicked()
{
 QString id=ui->lmod->text();
 ui->tablvol->setModel(v.rechercher(id));
}

void MainWindow::on_pushButton_clicked()
{
   if (ui->r1->isChecked())

    ui->tablvol->setModel(v.tri_id());
   else if (ui->r2->isChecked())
    ui->tablvol->setModel(v.tri_id_emp());
   else if (ui->r3->isChecked())
       ui->tablvol->setModel(v.tri_airline());
}



void MainWindow::on_lexport_clicked()
{
    QPdfWriter pdf("C:/Users/liste.pdf");

     QPainter painter(&pdf);

     int i = 4000;
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial", 30));
     painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/logo.jpg"));
     painter.drawText(3000,1500,"LISTE DES VOLS");
     painter.setPen(Qt::cyan);
     painter.setFont(QFont("Arial", 50));
     painter.drawRect(3000,10,4100,1600);
     painter.drawRect(0,3000,9600,500);
     painter.setPen(Qt::black);
     painter.setFont(QFont("Arial", 9));
     painter.drawText(300,3300,"id");
     painter.drawText(2300,3300,"id_emp");
     painter.drawText(4300,3300,"arrive");
     painter.drawText(6000,3300,"classe");
     painter.drawText(8300,3300,"date_entree");
     painter.drawText(10300,3300,"emplacement");
     QSqlQuery query;
     query.prepare("select * from vol");
     query.exec();
     while (query.next())
     {
         painter.drawText(300,i,query.value(0).toString());
         painter.drawText(2300,i,query.value(1).toString());
         painter.drawText(4300,i,query.value(2).toString());
         painter.drawText(6300,i,query.value(3).toString());
         painter.drawText(8000,i,query.value(4).toString());
         painter.drawText(10000,i,query.value(5).toString());
         i = i +500;
     }

     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
     if (reponse == QMessageBox::Yes)
     {
         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/liste.pdf"));

         painter.end();
     }
     if (reponse == QMessageBox::No)
     {
         painter.end();
     }
}

void MainWindow::on_lqr_clicked()
{
    QDesktopServices::openUrl(QUrl("https://qrcode.tec-it.com/fr"));
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image=image.scaledToWidth(ui->lbl_image_2->width(), Qt::SmoothTransformation);
                    ui->lbl_image_2->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //ERROR HANDLING
        }
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    vol v;
        don=A.read_from_arduino();

        qDebug() <<"ddddd"<<ch<<*don;

        if(*don=='1')
            ch=ch+'1';
        else if(*don=='2')
            ch=ch+'2';
        else if(*don=='3')
            ch=ch+'3';
        else if(*don=='4')
            ch=ch+'4';
        else if(*don=='5')
            ch=ch+'5';
        else if(*don=='6')
            ch=ch+'6';
        else if(*don=='7')
            ch=ch+'7';
        else if(*don=='8')
            ch=ch+'8';
        else if(*don=='9')
            ch=ch+'9';
        else if(*don=='0')
            ch=ch+'0';



        if(don=="")
        {

            QSqlQuery query;
            QString test=QString(ch);

        if(!v.existance(test))
        {
            qDebug() <<"testing"<<test;
            QString nom,prenom;
            query.prepare("select * from PARTENAIRE where numero_p='"+test+"' ");
            if(query.exec())
            {
                while(query.next())
                {
                     nom=(query.value(1).toString());
                     prenom=(query.value(2).toString());
                }
            query.exec();
            QString tt=nom+"  "+prenom;
            QByteArray z=tt.toUtf8();//qstring to qbtearray
            A.write_to_arduino(z);
        }}
        else
            {
        A.write_to_arduino("WRONG\n");
            }


            ch="";

    }
}
