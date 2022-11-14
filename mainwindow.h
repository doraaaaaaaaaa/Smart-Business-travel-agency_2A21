#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include<QPrinter>
#include <QPrintDialog>
#include "hebergement.h"
#include"statistique.h"
#include"mail.h"
#include "smtp.h"
#include"picture.h"
#include <QChart>
#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QValueAxis>
#include <QWidget>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void choix_bar();
private slots:

void on_pushButton_clicked(); //Ajout

void on_pushButton_5_clicked(); //Suppr

void on_pushButton_2_clicked(); //Modif

void on_tableView_clicked(const QModelIndex &index); //Modif

void on_radioButton_clicked(); //Tri

void on_triNom_clicked();

void on_triPrix_clicked();

void on_lineEdit_Rech_textChanged(const QString &arg1); //Rech

void on_PDF_clicked();

void on_stat_clicked();

void on_Send_mail_clicked();


void on_pushButton_Picture_clicked();

private:
    Ui::MainWindow *ui;
    hebergement H;
    statistique *s;
    QChartView *chartView ;
    QWidget  WebAxWidget;
    Mail *sm;
    Picture *p;
};
#endif // MAINWINDOW_H
