#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vol.h"
#include <QMainWindow>
#include<QTimer>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
#include<arduino.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lajout_clicked();

    void on_suplvol_clicked();

    void on_tablvol_activated(const QModelIndex &index);

    void on_lmodifier_clicked();

    void on_lreset_clicked();

    void myfunction();

    void on_chercher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lexport_clicked();

    void on_lqr_clicked();

private:
    Ui::MainWindow *ui;
    vol v;
    QTimer *timer;
    QByteArray don="";
    QByteArray ch="";
    Arduino A;
};

#endif // MAINWINDOW_H
